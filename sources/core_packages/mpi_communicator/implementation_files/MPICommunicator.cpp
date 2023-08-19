/*
 * MPICommunicator.cpp
 *
 *  Created on: Oct 15, 2018
 *      Author: arnoldt
 */

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <functional>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/asio.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AssertValidValueForType.hpp"
#include "MPICommunicator.h"
#include "MPIInitException.h"
#include "MPIGenericException.h"
#include "MPICommDuplicateException.h"
#include "MPIFreeException.h"
#include "MPIAllGatherException.h"
#include "MPICommSplitException.h"
#include "MPICommSizeException.h"
#include "MPIReductionOperation.h"
#include "MPIReduce.h"
#include "MPIAllgather.h"
#include "MPIGather.h"
#include "MPIBroadcast.h"
#include "MPIBarrier.h"
#include "convert_sequence_of_chars_to_vector_string.h"
#include "convert_string_vector_to_char_array.h"
#include "ErrorMPIBroadcast.h"
#include "Array1d.hpp"

namespace ANANSI
{

std::string MPICommunicator::HOSTNAME_NOT_DEFINED("Hostname not defined");


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPICommunicator::MPICommunicator() : 
    Communicator(),
    _mpiCommunicator(MPI_COMM_NULL),
    _hostname(MPICommunicator::HOSTNAME_NOT_DEFINED)
{
    return;
}

MPICommunicator::MPICommunicator(MPICommunicator && other)
{
    if ( this != &other)
    {
        *this = std::move(other);
    }
}

MPICommunicator::MPICommunicator(const MPI_Comm & mpi_world_communicator, 
                const std::string & host_name) :
    Communicator(),
    _mpiCommunicator(mpi_world_communicator),
    _hostname(host_name)
{
    return;
}

MPICommunicator::~MPICommunicator()
{
    this->freeCommunicator_();
    return;
}

//============================= ACCESSORS ====================================

//============================= STATIC =======================================

//============================= MUTATORS =====================================

void
MPICommunicator::_initializeWorldCommunicator()
{

    // Create a copy of the MPI world communicator.
    try
    {
        int mpi_return_code = MPI_Comm_dup(MPI_COMM_WORLD,
                                           &(this->_mpiCommunicator));
        if (mpi_return_code != MPI_SUCCESS)
        {
            throw ANANSI::MPICommDuplicateException();       
        }
    }
    catch (ANANSI::MPICommDuplicateException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

    // Set the hostname of this MPI communicator.
    this->_hostname = boost::asio::ip::host_name();

    return;
}

void
MPICommunicator::freeCommunicator_()
{
    // We now destroy/free all communicators.
    this->freeMPICommunicator_(this->_mpiCommunicator);
    this->_hostname = std::string(MPICommunicator::HOSTNAME_NOT_DEFINED);
    return;
}

void
MPICommunicator::resetName_(const std::string & name)
{
    this->_hostname = name;
    return;
}

//============================= OPERATORS ====================================


MPICommunicator& MPICommunicator::operator=(MPICommunicator && other)
{
    if (this != &other )
    {
        Communicator::operator=(std::move(other));
        this->_mpiCommunicator = other._mpiCommunicator;
        this->_hostname = other._hostname;

        other._mpiCommunicator = MPI_COMM_NULL;
        other._hostname = std::string(MPICommunicator::HOSTNAME_NOT_DEFINED);
    }
    else
    {
        // :TODO:11/18/2022 04:00:49 PM:: Write some error handling code.
    }
    return *this;
}

MPICommunicator& MPICommunicator::operator=(Communicator && other) 
{
    if (this != &other )
    {
        if (auto* other1 = dynamic_cast<MPICommunicator*>(&other))
        {
            *this = std::move(*other1);
        }
    }
    return *this;
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= ACCESSORS ====================================


void MPICommunicator::synchronizationPoint_() const
{
    ANANSI::MPIBarrier::Barrier(this->_mpiCommunicator);
    return;
}


std::string
MPICommunicator::_broadcastStdString(const std::string & str_to_bcast, const std::size_t bcast_rank) const
{
    std::string ret_value;
    try 
    {
        // First broadcast the length of the string that is to be broadcasted.
        // The variable str_len1 is only properly defined on the communicator
        // with rank bcast_rank. 
        const std::size_t str_len1 = str_to_bcast.length();
        const std::size_t bcast_str_len = ANANSI::MPI_Broadcast<std::size_t>::Broadcast(str_len1,
                                                                              this->_mpiCommunicator,
                                                                              bcast_rank);

        // Broadcast the string to all other ranks.
        ret_value = ANANSI::MPI_Broadcast<std::string>::Broadcast(str_to_bcast,
                                                                  bcast_str_len,
                                                                  this->_mpiCommunicator,
                                                                  bcast_rank);
    }
    catch (ANANSI::ErrorMPIBroadcast<char> const & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch (ANANSI::ErrorMPIBroadcast<int> const & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

    return ret_value;
}


std::size_t
MPICommunicator::_getSizeofCommunicator(const std::string & id) const
{
    std::size_t my_size;
    try
    {
        if (id == "world_communicator")
        {
            int world_comm_group_size;
            int mpi_return_code = MPI_Comm_size(this->_mpiCommunicator,&world_comm_group_size);

            if (mpi_return_code != MPI_SUCCESS)
            {
                throw ANANSI::MPICommSizeException();
            }
            my_size = static_cast<std::size_t>(world_comm_group_size);
        }
    }
    catch (ANANSI::MPICommSizeException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return my_size;
}

// :TODO:05/21/2022 02:17:12 PM:: This needs to return a communicator.
void
MPICommunicator::_createSubcommunicator(const std::string & tag) 
{
    std::map<std::string, std::size_t> aglobaltagmap = 
        COMMUNICATOR::Communicator::formGlobalMap(tag,*this);

    // Get the hash for this global tag.
    std::size_t my_hash = aglobaltagmap[tag];
    
    try 
    {
        int mpi_return_code;
        MPI_Comm tmp_mpi_comm=MPI_COMM_NULL;
        mpi_return_code = MPI_Comm_split(this->_mpiCommunicator,
                                         static_cast<int>(my_hash),
                                         static_cast<int>(DEFAULT_MPI_MASTER_RANK_ID),
                                         &tmp_mpi_comm);

        if (mpi_return_code != MPI_SUCCESS)
        {
            throw ANANSI::MPICommSplitException();
        }
    }
    catch ( ANANSI::MPICommSplitException const  & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return;
}

int
MPICommunicator::_getCommunicatorRank() const
{
    int rank;
    try
    {
        int mpi_return_code;
        mpi_return_code = MPI_Comm_rank(this->_mpiCommunicator,&rank);
        if (mpi_return_code != MPI_SUCCESS)
        {
            throw ANANSI::MPIGenericException();
        }
    }
    catch ( ANANSI::MPIGenericException const & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

   return rank;
}

COMMUNICATOR::Communicator*
MPICommunicator::_duplicateCommunicator() const 
{
  MPICommunicator* aMPICommunicator = nullptr;

  try 
  {
	    MPI_Comm mpi_comm_duplicate;
	    const auto mpi_return_code = MPI_Comm_dup(_mpiCommunicator,&mpi_comm_duplicate);
      
      if (mpi_return_code != MPI_SUCCESS)
      {
        throw ANANSI::MPIGenericException();
      }
    
      // We now form the new MPICommunicator.
      aMPICommunicator = 
          new MPICommunicator(mpi_comm_duplicate,this->_hostname);
  }
  catch (ANANSI::MPIGenericException const & my_mpi_exception) 
  {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
  }
    return aMPICommunicator;
}

std::size_t
MPICommunicator::_getMaximum(std::size_t const value) const 
{
    std::vector<std::size_t> vec = {value};
    std::vector<std::size_t> vec_maximum;

    try 
    {
      vec_maximum = ANANSI::MPI_ALLREDUCE<std::size_t,ANANSI::MPIReductionOperation::reduction_operation_type>::REDUCE(
                                          this->_mpiCommunicator,
                                          vec,
                                          ANANSI::MPIReductionOperation::maximum);
    }
    catch ( const  ANANSI::MPIAllReduceException & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

    return vec_maximum[0];
}


char*
MPICommunicator::_allGather(
        char const * aCString,
        const std::size_t aLengthMaximum,
        std::size_t & offset_size,
        std::size_t* & start_offsets_ptr,
        std::size_t* & end_offsets_ptr) const
{

    MEMORY_MANAGEMENT::Array1d<std::size_t> my_int_array_factory;
    char* recv_buffer_ptr = nullptr;

    try 
    {
        recv_buffer_ptr = ANANSI::MPI_ALL_GATHER<char>::allGather(this->_mpiCommunicator,
                                                                        offset_size,
                                                                        aCString,
                                                                        aLengthMaximum);

        if ( start_offsets_ptr != nullptr )
        {
            my_int_array_factory.destroyArray(start_offsets_ptr);
        }
        start_offsets_ptr = my_int_array_factory.createArray(offset_size);

        if (end_offsets_ptr != nullptr)
        {
            my_int_array_factory.destroyArray(end_offsets_ptr);
        }
        end_offsets_ptr = my_int_array_factory.createArray(offset_size);

        this->_calculateStartAndEndOffsets(offset_size,
                                           aLengthMaximum,
                                           start_offsets_ptr,
                                           end_offsets_ptr);

    }
    catch ( const ANANSI::MPICommSizeException & my_mpi_exception ) 
    {      
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch( const ANANSI::MPIAllGatherException & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

    return recv_buffer_ptr;
}

char*
MPICommunicator::_gather(const std::size_t task_id_to_gather_data_on,
                         char const * aCString,
                         const std::size_t aLengthMaximum,
                         std::size_t & offset_size, 
                         std::size_t* & start_offsets_ptr,
                         std::size_t* & end_offsets_ptr ) const 
{


    #ifdef ANANASI_DBD_VALID_VALUES
    DEBUGGING::AssertValidValueForType::isValidValueForCast<std::size_t,int>(task_id_to_gather_data_on);
    #endif
    MEMORY_MANAGEMENT::Array1d<std::size_t> my_int_array_factory;
    char* recv_buffer_ptr = nullptr;
    try
    {
        recv_buffer_ptr = ANANSI::MPI_GATHER<char>::Gather(static_cast<int>(task_id_to_gather_data_on),
                                                           this->_mpiCommunicator,
                                                           offset_size,
                                                           aCString,
                                                           aLengthMaximum);

        if ( start_offsets_ptr != nullptr )
        {
            my_int_array_factory.destroyArray(start_offsets_ptr);
        }
        start_offsets_ptr = my_int_array_factory.createArray(offset_size);

        if (end_offsets_ptr != nullptr)
        {
            my_int_array_factory.destroyArray(end_offsets_ptr);
        }
        end_offsets_ptr = my_int_array_factory.createArray(offset_size);

        this->_calculateStartAndEndOffsets(offset_size,
                                           aLengthMaximum,
                                           start_offsets_ptr,
                                           end_offsets_ptr);
    }
    catch( const ANANSI::MPICommSizeException & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch( const ANANSI::MPIGatherException & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

    return recv_buffer_ptr;
}

std::unique_ptr<char[]>
MPICommunicator::_gather(const std::size_t task_id_to_gather_data_on,
                         const std::unique_ptr<char[]> & aCString,
                         const std::size_t aLengthMaximum,
                         std::size_t & offset_size, 
                         std::unique_ptr<std::size_t[]> & start_offsets,
                         std::unique_ptr<std::size_t[]> & end_offsets) const 
{
    MEMORY_MANAGEMENT::Array1d<std::size_t> my_int_array_factory;
    std::unique_ptr<char[]> recv_buffer;
    try
    {
        // Call the MPI_Gather for char arrays.
        #ifdef ANANSI_DBG_VALID_VALUE
        DEBUGGING::AssertValidValueForType::isValidValueForCast<std::size_t,int>(task_id_to_gather_data_on);
        #endif
        char* tmp_recieve_buffer =
            ANANSI::MPI_GATHER<char>::Gather(static_cast<int>(task_id_to_gather_data_on),
                                             this->_mpiCommunicator,
                                             offset_size,
                                             aCString.get(),
                                             aLengthMaximum);

        recv_buffer.reset(tmp_recieve_buffer);

        std::size_t* tmp_start_offsets_ptr = my_int_array_factory.createArray(offset_size);
        start_offsets.reset(tmp_start_offsets_ptr);

        std::size_t* tmp_end_offsets_ptr = my_int_array_factory.createArray(offset_size);
        end_offsets.reset(tmp_end_offsets_ptr);

        this->_calculateStartAndEndOffsets(offset_size,
                                           aLengthMaximum,
                                           start_offsets.get(),
                                           end_offsets.get());
    }
    catch( const ANANSI::MPICommSizeException & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch( const ANANSI::MPIGatherException & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return recv_buffer;
}


std::vector<std::string>
MPICommunicator::_gatherString(const std::string & data_to_gather,
                               const std::size_t task_id_to_gather_data_on ) const
{
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;

    const bool my_rank_equals_taskid = 
        ANANSI::MPIUtilityFunctions::same_rank(task_id_to_gather_data_on,this->_mpiCommunicator);

    // Get the maximum length of tag with respect to the communicator group.
    const std::size_t slength = data_to_gather.length();
    const std::size_t slength_maximum = this->_getMaximum(slength);

    // Form and c string with length tag_length + 1, and 
    // then copy the tag in a c string.
    const std::size_t slength_maximum_adj = slength_maximum + 1;
    char* data_ptr = my_char_array_factory.createArray(data_to_gather,
                                                       slength_maximum_adj);

    std::unique_ptr<char[]> data(data_ptr);

    std::size_t offset_size;
    std::unique_ptr<std::size_t[]> start_offsets;
    std::unique_ptr<std::size_t[]> end_offsets;
    
    std::unique_ptr<char[]> all_data = this->_gather(task_id_to_gather_data_on,
                                                     data,
                                                     static_cast<std::size_t> (slength_maximum_adj),
                                                     offset_size,
                                                     start_offsets,
                                                     end_offsets);

    // Form vector string array of the hostnames.
    std::vector<std::string> gathered_data;
    if ( my_rank_equals_taskid )
    {
        gathered_data = 
            STRING_UTILITIES::convert_sequence_of_chars_to_vector_string(offset_size,
                                                                         start_offsets.get(),
                                                                         end_offsets.get(),
                                                                         const_cast<char* >(all_data.get()) );
    }

    return gathered_data; 
}

std::vector<int>
MPICommunicator::_gatherInt(const int & data_to_gather,
                            const std::size_t task_id_to_gather_data_on) const
{
    MEMORY_MANAGEMENT::Array1d<int> my_int_array_factory;

    // For an integer array for the send buffer.
    // We are only sending 1 integer.
    const size_t send_buffer_count = 1;
    int* send_buffer_ptr = my_int_array_factory.createArray(send_buffer_count);
    send_buffer_ptr[0] = data_to_gather;
    std::unique_ptr<int[]> send_buffer(send_buffer_ptr);

    const auto mpi_task_to_gather_data_on = static_cast<int>(task_id_to_gather_data_on);

    std::vector<int> gathered_data = ANANSI::MPI_GATHER<int>::Gather(
                                                            mpi_task_to_gather_data_on,
                                                            this->_mpiCommunicator,
                                                            send_buffer.get(),
                                                            send_buffer_count);
    return gathered_data; 
}


std::map<std::string,std::string>
MPICommunicator::broadcastStdMap_( const std::map<std::string,std::string> & a_map, const std::size_t bcast_rank) const
{
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;

    // Form a vector of the keys and values of the map "a_map".
    std::vector<std::string> map_keys;
    std::vector<std::string> map_values;
    for (auto it = a_map.begin(); it != a_map.end(); ++it)
    {
        auto key = it->first;
        map_keys.push_back(key);

        auto value = it->second;
        map_values.push_back(value);
    }
    // Broadcast string vector of keys.
    STRING_UTILITIES::convert_string_vector_to_char_array();

    // Broadcast string vector of values.
    STRING_UTILITIES::convert_string_vector_to_char_array();

    // Reform the map object form the broadcasted keys  and values.

    return a_map;
}


//============================= MUTATORS =====================================

//============================= STATIC =======================================

void
MPICommunicator::_calculateStartAndEndOffsets(
    const std::size_t & offset_size,
    const std::size_t & aLengthMaximum,
    std::size_t* const & start_offsets_ptr,
    std::size_t* const & end_offsets_ptr)
{
    for (std::size_t ip=static_cast<std::size_t>(0); ip < offset_size; ++ip)
    {
        start_offsets_ptr[ip] = aLengthMaximum*ip;
        end_offsets_ptr[ip] = aLengthMaximum*(ip+1) - 1;
    }
    return;
}

void
MPICommunicator::freeMPICommunicator_(MPI_Comm & a_communicator)
{
    try 
    {
        if ( a_communicator != MPI_COMM_NULL )
        {
            int mpi_return_code = MPI_Comm_free(&(a_communicator));
            
            if ( mpi_return_code != MPI_SUCCESS ) 
            {
                throw ANANSI::MPIFreeException();
            }

            a_communicator = MPI_COMM_NULL;

        }
    }
    catch (  ANANSI::MPIFreeException const & my_mpi_exception ) 
    {
        std::cout << "Freeing the communicator failed in MPICommunicator::_freeMPICommunicator." << std::endl;
        std::abort();
    }
    return;
}


} /* namespace ANANSI */
