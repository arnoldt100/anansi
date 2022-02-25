
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
#include "convert_sequence_of_chars_to_vector_string.h"
#include "ErrorMPIBroadcast.h"
#include "Array1d.hpp"

namespace COMMUNICATOR
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
                const std::string & host_name,
                const SUBCOMMUNICATOR_MAP_T & subcommunicator_handles ) :
    Communicator(),
    _mpiCommunicator(mpi_world_communicator),
    _mpicommHandles(subcommunicator_handles),
    _hostname(host_name)
{
    return;
}

MPICommunicator::~MPICommunicator()
{
    this->_freeCommunicator();
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
            throw COMMUNICATOR::MPICommDuplicateException();       
        }
    }
    catch (COMMUNICATOR::MPICommDuplicateException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

    // Set the hostname of this MPI communicator.
    this->_hostname = boost::asio::ip::host_name();

    return;
}

void
MPICommunicator::_freeCommunicator()
{
    // We now destroy/free all communicators.
    this->_freeMPICommunicator(this->_mpiCommunicator);

    for (auto const & it : this->_mpicommHandles )
    {
        auto key = it.first;
        auto value = it.second;

        if (  value == MPI_COMM_NULL )
        {
            this->_eraseCommunicator(key);
        }
        else
        {
            this->_freeMPICommunicator(value);
            this->_eraseCommunicator(key);
        }
    }

    return;
}

//============================= OPERATORS ====================================


MPICommunicator& MPICommunicator::operator=(MPICommunicator && other)
{
    if (this != &other )
    {
        Communicator::operator=(std::move(other));
        this->_mpiCommunicator = other._mpiCommunicator;
        this->_mpicommHandles = other._mpicommHandles;
        this->_hostname = other._hostname;

        other._mpiCommunicator = MPI_COMM_NULL;
        other._mpicommHandles.clear();
        other._hostname = std::string(MPICommunicator::HOSTNAME_NOT_DEFINED);
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


std::string
MPICommunicator::_broadcastStdString(const std::string & str_to_bcast, const std::size_t bcast_rank) const
{
    std::string ret_value;
    try 
    {
        // First broadcast the length of the string that is to be broadcasted.
        // The variable str_len1 is only properly defined on the communicator
        // with rank bcast_rank. 
        const int str_len1 = str_to_bcast.length();
        const std::size_t bcast_str_len = COMMUNICATOR::MPI_Broadcast<int>::Broadcast(str_len1, 
                                                                              this->_mpiCommunicator,
                                                                              bcast_rank);

        // Broadcast the string to all other ranks.
        ret_value = COMMUNICATOR::MPI_Broadcast<std::string>::Broadcast(str_to_bcast,
                                                                        bcast_str_len,
                                                                        this->_mpiCommunicator,
                                                                        bcast_rank);
    }
    catch (COMMUNICATOR::ErrorMPIBroadcast<char> const & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch (COMMUNICATOR::ErrorMPIBroadcast<int> const & my_mpi_exception )
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
                throw COMMUNICATOR::MPICommSizeException();
            }

            my_size = static_cast<std::size_t>(world_comm_group_size);
        }
        else
        {
            int sub_comm_group_size;
            int mpi_return_code = MPI_Comm_size( (this->_mpicommHandles).at(id),
                                                  &sub_comm_group_size);

            if (mpi_return_code != MPI_SUCCESS)
            {
                throw COMMUNICATOR::MPICommSizeException();
            }

            my_size = static_cast<std::size_t>(sub_comm_group_size);
             
        }
    }
    catch (COMMUNICATOR::MPICommSizeException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    return my_size;
}

void
MPICommunicator::_createSubcommunicator(const std::string & tag) 
{
    std::map<std::string, std::size_t> aglobaltagmap = 
        COMMUNICATOR::Communicator::formGlobalMap(tag,
                                                  *this);

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
            throw COMMUNICATOR::MPICommSplitException();
        }

        this->_addCommunicator(tag,tmp_mpi_comm);

    }
    catch ( COMMUNICATOR::MPICommSplitException const  & my_mpi_exception )
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
            throw COMMUNICATOR::MPIGenericException();
        }
    }
    catch ( COMMUNICATOR::MPIGenericException const & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

   return rank;
}

int 
MPICommunicator::_getSubCommunicatorRank(const std::string & tag) const
{
    int rank;
    try
    {
        int mpi_return_code;
        MPI_Comm my_comm_handle = (this->_mpicommHandles).at(tag);
        mpi_return_code = MPI_Comm_rank(my_comm_handle,&rank);
        if (mpi_return_code != MPI_SUCCESS)
        {
            throw COMMUNICATOR::MPIGenericException();
        }
    }
    catch ( COMMUNICATOR::MPIGenericException const & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

   return rank;
}

COMMUNICATOR::Communicator*
MPICommunicator::_duplicateCommunicator() const 
{
	// First make a duplicate of the communicator
	MPI_Comm mpi_comm_duplicate;
	auto mpi_return_code = MPI_Comm_dup(_mpiCommunicator,&mpi_comm_duplicate);

	// Duplicate the subcommunicators.
	SUBCOMMUNICATOR_MAP_T mpi_comm_handles_duplicate;

    try
    {
        for ( auto const & [tmp_key,tmp_mpi_comm] : this->_mpicommHandles )
        {
            MPI_Comm dup_mpi_comm;
            mpi_return_code = MPI_Comm_dup(tmp_mpi_comm,&dup_mpi_comm);
            if (mpi_return_code != MPI_SUCCESS)
            {
                throw COMMUNICATOR::MPICommDuplicateException();       
            }
            mpi_comm_handles_duplicate[tmp_key] = dup_mpi_comm;
        }
    }
    catch (COMMUNICATOR::MPICommDuplicateException const & my_mpi_exception)
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

    // We now form the new MPICommunicator.
    MPICommunicator* aMPICommunicator = 
        new MPICommunicator(mpi_comm_duplicate,this->_hostname,mpi_comm_handles_duplicate);

    return aMPICommunicator;
}

int
MPICommunicator::_getMaximum(int const value) const 
{
    std::vector<int> vec = {value};
    std::vector<int> vec_maximum;

    try 
    {
      vec_maximum = COMMUNICATOR::MPI_ALLREDUCE<int,COMMUNICATOR::MPIReductionOperation::reduction_operation_type>::REDUCE(
                                                this->_mpiCommunicator,
                                                vec,
                                                COMMUNICATOR::MPIReductionOperation::maximum);
    }
    catch ( const  COMMUNICATOR::MPIAllReduceException & my_mpi_exception )
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
        int* & start_offsets_ptr,
        int* & end_offsets_ptr) const
{

    MEMORY_MANAGEMENT::Array1d<int> my_int_array_factory;
    char* recv_buffer_ptr = nullptr;

    try 
    {
        recv_buffer_ptr = COMMUNICATOR::MPI_ALL_GATHER<char>::allGather(this->_mpiCommunicator,
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
    catch ( const COMMUNICATOR::MPICommSizeException & my_mpi_exception ) 
    {      
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch( const COMMUNICATOR::MPIAllGatherException & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }

    return recv_buffer_ptr;
}

char*
MPICommunicator::_gather(const std::size_t task_id_to_gather_dat_on,
                         char const * aCString,
                         const std::size_t aLengthMaximum,
                         std::size_t & offset_size, 
                         int* & start_offsets_ptr,
                         int* & end_offsets_ptr ) const 
{

    MEMORY_MANAGEMENT::Array1d<int> my_int_array_factory;
    char* recv_buffer_ptr = nullptr;
    try
    {
        recv_buffer_ptr = COMMUNICATOR::MPI_GATHER<char>::Gather(task_id_to_gather_dat_on,
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
    catch( const COMMUNICATOR::MPICommSizeException & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch( const COMMUNICATOR::MPIGatherException & my_mpi_exception )
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
                         std::unique_ptr<int[]> & start_offsets,
                         std::unique_ptr<int[]> & end_offsets) const 
{
    MEMORY_MANAGEMENT::Array1d<int> my_int_array_factory;
    std::unique_ptr<char[]> recv_buffer;
    try
    {
        // Call the MPI_Gather for char arrays.
        char* tmp_recieve_buffer =
            COMMUNICATOR::MPI_GATHER<char>::Gather(task_id_to_gather_data_on,
                                                   this->_mpiCommunicator,
                                                   offset_size,
                                                   aCString.get(),
                                                   aLengthMaximum);

        recv_buffer.reset(tmp_recieve_buffer);

        int* tmp_start_offsets_ptr = my_int_array_factory.createArray(offset_size);
        start_offsets.reset(tmp_start_offsets_ptr);

        int* tmp_end_offsets_ptr = my_int_array_factory.createArray(offset_size);
        end_offsets.reset(tmp_end_offsets_ptr);

        this->_calculateStartAndEndOffsets(offset_size,
                                           aLengthMaximum,
                                           start_offsets.get(),
                                           end_offsets.get());
    }
    catch( const COMMUNICATOR::MPICommSizeException & my_mpi_exception )
    {
        std::cout << my_mpi_exception.what() << std::endl;
        std::abort();
    }
    catch( const COMMUNICATOR::MPIGatherException & my_mpi_exception )
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
        COMMUNICATOR::MPIUtilityFunctions::same_rank(task_id_to_gather_data_on,this->_mpiCommunicator);

    // Get the maximum length of tag with respect to the communicator group.
    const int slength = data_to_gather.length();
    const int slength_maximum = this->_getMaximum(slength);

    // Form and c string with length tag_length + 1, and 
    // then copy the tag in a c string.
    const int slength_maximum_adj = slength_maximum  + 1;
    char* data_ptr = my_char_array_factory.createArray(data_to_gather,
                                                       slength_maximum_adj);

    std::unique_ptr<char[]> data(data_ptr);

    std::size_t offset_size;
    std::unique_ptr<int[]> start_offsets;
    std::unique_ptr<int[]> end_offsets;
    
    std::unique_ptr<char[]> all_data = this->_gather(task_id_to_gather_data_on,
                                                     data,
                                                     static_cast<std::size_t> (slength_maximum_adj),
                                                     offset_size,
                                                     start_offsets,
                                                     end_offsets) ;

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

    std::vector<int> gathered_data = COMMUNICATOR::MPI_GATHER<int>::Gather(
                                                            mpi_task_to_gather_data_on,
                                                            this->_mpiCommunicator,
                                                            send_buffer.get(),
                                                            send_buffer_count);
    return gathered_data; 
}

bool
MPICommunicator::_getGlobalStatus(const bool & data_to_reduce) const 
{
    std::vector<bool> in_buffer = {data_to_reduce};
    MPIReductionOperation::reduction_operation_type mpi_op(MPIReductionOperation::logical_and); 
    const std::vector<bool> my_global_status = 
        COMMUNICATOR::MPI_ALLREDUCE<bool,MPIReductionOperation::reduction_operation_type>::REDUCE(this->_mpiCommunicator,
                                                                                                  in_buffer,
                                                                                                  mpi_op); 
    return my_global_status[0];
}

//============================= MUTATORS =====================================

void
MPICommunicator::_addCommunicator(std::string const & key, MPI_Comm const & my_mpi_comm)
{
    this->_mpicommHandles[key] = my_mpi_comm;
    return;
}

void
MPICommunicator::_eraseCommunicator(std::string const & key)
{
    (this->_mpicommHandles).erase(key);
    return;
}

//============================= STATIC =======================================

void
MPICommunicator::_calculateStartAndEndOffsets(
    const std::size_t & offset_size,
    const std::size_t & aLengthMaximum,
    int* const & start_offsets_ptr,
    int* const & end_offsets_ptr)
{
    for (std::size_t ip=0; ip < offset_size; ++ip)
    {
        start_offsets_ptr[ip] = aLengthMaximum*ip;
        end_offsets_ptr[ip] = aLengthMaximum*(ip+1) - 1;
    }
    return;
}

void
MPICommunicator::_freeMPICommunicator(MPI_Comm & a_communicator)
{
    try 
    {
        if ( a_communicator != MPI_COMM_NULL )
        {
            int mpi_return_code = MPI_Comm_free(&(a_communicator));
            
            if ( mpi_return_code != MPI_SUCCESS ) 
            {
                throw COMMUNICATOR::MPIFreeException();
            }

            a_communicator = MPI_COMM_NULL;

        }
    }
    catch (  COMMUNICATOR::MPIFreeException const & my_mpi_exception ) 
    {
        std::cout << "Freeing the communicator failed in MPICommunicator::_freeMPICommunicator." << std::endl;
        std::abort();
    }
    return;
}


} /* namespace COMMUNICATOR */
