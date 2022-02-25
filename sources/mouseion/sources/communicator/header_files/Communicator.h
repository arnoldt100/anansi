/*
 * Communicator.h
 *
 *  Created on: Oct 15, 2018
 *      Authors: Arnold Tharrington
 */

#ifndef COMMUNICATOR_HEADER_FILES_COMMUNICATOR_H_
#define COMMUNICATOR_HEADER_FILES_COMMUNICATOR_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"
#include <string>
#include <vector>
#include <memory>
#include <map>
#include <cstring>
#include <iostream>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "RegistryAnansiMDStatus.h"

namespace COMMUNICATOR {

static constexpr std::size_t MASTER_TASK_ID=0;

class Communicator
{
public:
    //===== LIFECYCLE ======
    Communicator();

    virtual ~Communicator()=0;

    Communicator(Communicator const & other);

    Communicator(Communicator&& other);

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    int 
    getCommunicatorRank() const
    {
        return this->_getCommunicatorRank();
    }

    int
    getSubCommunicatorRank(const std::string & tag) const
    {
        return this->_getSubCommunicatorRank(tag);
    }

    bool
    sameCommunicatorRank( const int aRank) const
    {
        int my_world_rank = this->getCommunicatorRank();
        return ( aRank == my_world_rank ? true : false);
    }

    std::vector<std::string>
    gatherString(const std::string & data_to_gather,
                 const std::size_t task_id_gather_data) const
    {
        return this->_gatherString(data_to_gather,task_id_gather_data);
    }

    std::vector<int>
    gatherInt(const int & data_to_gather,
              const std::size_t task_id_gather_data) const
    {
        return this->_gatherInt(data_to_gather,task_id_gather_data);
    }

    bool
    getGlobalStatus(const bool & data_to_reduce) const
    {
        return this->_getGlobalStatus(data_to_reduce);
    }

    template<typename T>
    T getGlobalStatusCustomReduction( T const & data_to_transform) const
    {
        return this->_getGlobalStatusCustomReduction(data_to_transform);
    }

    std::string
    broadcastStdString(const std::string & data_to_broadcast, const std::size_t bcast_rank) const
    {
        return this->_broadcastStdString(data_to_broadcast,bcast_rank);
    }

    //===== MUTATORS =======
    void
    initializeWorldCommunicator()
    {
        this->_initializeWorldCommunicator();
        return;
    }

    void 
    freeCommunicator()
    {
        this->_freeCommunicator();
        return;
    }

    COMMUNICATOR::Communicator* 
    duplicateCommunicator() const
    {
        return this->_duplicateCommunicator();
    }

    void 
    createSubcommunicator(const std::string & tag)
    {
        this->_createSubcommunicator(tag);
    }


    //===== OPERATORS ======
    Communicator& operator=(Communicator const & other);

    Communicator& operator=(Communicator && other);

    //===== STATIC FUNCTIONS ======
    static std::map<std::string, std::size_t>
    formGlobalMap(std::string const & tag,
                  Communicator const  & aCommunicator);

protected:

private:
    //===== ACCESSORS ======
    virtual std::size_t
    _getSizeofCommunicator(const std::string & id) const=0;

    virtual int
    _getMaximum(int const aValue) const=0;

    virtual int 
    _getCommunicatorRank() const=0;

    virtual int 
    _getSubCommunicatorRank(const std::string & tag) const=0;

    virtual COMMUNICATOR::Communicator*
    _duplicateCommunicator() const =0;

    virtual char*
    _allGather(char const * aCString,
               const std::size_t aLengthMaximum,
               std::size_t & offset_size, 
               int* & start_offsets_ptr,
               int* & end_offsets_ptr) const=0;

    virtual char*
    _gather(const std::size_t task_id_gather_data,
            char const * aCString,
            const std::size_t aLengthMaximum,
            std::size_t & offset_size, 
            int* & start_offsets_ptr,
            int* & end_offsets_ptr) const=0;

    virtual std::unique_ptr< char[] >
    _gather(const std::size_t task_id_gather_data,
            const std::unique_ptr<char[]> & aCString,
            const std::size_t aLengthMaximum,
            std::size_t & offset_size, 
            std::unique_ptr<int[]> & start_offsets_ptr,
            std::unique_ptr<int[]> & end_offsets_ptr) const=0;

    virtual std::vector<std::string>
    _gatherString(const std::string & data_to_gather,
                  const std::size_t task_id_gather_data) const=0;


    virtual std::vector<int>
    _gatherInt(const int & data_to_gather,
               const std::size_t task_id_gather_data) const=0;

    virtual bool
    _getGlobalStatus(const bool & data_to_reduce) const=0;


    template<typename T>
    T _getGlobalStatusCustomReduction( T const & data_to_transform) const; 

    virtual std::string
    _broadcastStdString(const std::string & data_to_broadcast, const std::size_t bcast_rank) const=0;

    //===== MUTATORS =======
    virtual void
    _initializeWorldCommunicator()=0;

    virtual void
    _createSubcommunicator(const std::string & tag)=0;

    virtual void 
    _freeCommunicator()=0;

    //===== STATIC =======
    static constexpr std::size_t MAX_HOSTNAME_LENGTH=100;
};


// #####   EXPORTED FUNCTION DECLARATIONS   #########################################

// ===  FUNCTION  ======================================================================
//         Name:  gatherData
//  Description:  Gathering data to a single rank.
// 
//   Parameters: 
//
//        Return:
// =====================================================================================
template<typename T>
std::vector<T> gatherData(
       T const & data_to_gather,
       Communicator const  & aCommunicator,
       const std::size_t task_id_gather_data);

template<>
std::vector<std::string> gatherData(
       std::string const & data_to_gather,
       Communicator const  & aCommunicator,
       const std::size_t task_id_gather_data);

template<>
std::vector<int> gatherData(
       int const & data_to_gather,
       Communicator const  & aCommunicator,
       const std::size_t task_id_gather_data);


// ===  FUNCTION  ======================================================================
//         Name:  getGlobalStatus
//  Description:  Returns the global status by doing a collective transformation
//                of the status of each processer to a single value
//                which is returned to all processors.
// 
//   Template Parameters : T The type of data to transform
//  
//   Parameters: data_to_transform - The data on this rank which is part of the 
//                                   collective transformation.
//               aCommunicator - The communicator used in this data transformation. 
//
//        Return: A scalar value of the transformed data.
// =====================================================================================
template<typename T>
T getGlobalStatus( T const & data_to_transform,
                   Communicator const & aCommunicator);

// ===  FUNCTION  ======================================================================
//         Name:  getGlobalStatus
//  Description:  A specialiaization of boolean type for getGlobalStatus.
// 
//   Parameters: data_to_transform - The data on this rank which is part of the 
//                                   collective transformation.
//               aCommunicator - The communicator used in this data transformation. 
//
//        Return: The transformed data
// =====================================================================================
template<>
bool getGlobalStatus( bool const & data_to_transform,
                      Communicator const & aCommunicator);

// ===  FUNCTION  ======================================================================
//         Name:  getGlobalStatusCustomReduction
//  Description:  Global reduction with a custome reducer.
// 
//   Parameters: data_to_transform - The data on this rank which is part of the 
//                                   collective transformation.
//
//               aCommunicator - The communicator used in this data transformation. 
//
//        Return: The transformed data
// =====================================================================================
template<typename T>
T getGlobalStatusCustomReduction( T const & data_to_transform,
                                  Communicator const & aCommunicator);

// ===  FUNCTION  ======================================================================
//         Name:  getGlobalStatusCustomReduction
//  Description:  A specialiaization for global reduction of MD status, 
//                type RegistryAnansiMDStatus, with the custom reducer ISEReductionFunctor 
//
//   Parameters: data_to_transform - The data on this rank which is part of the 
//                                   collective transformation.
//
//               aCommunicator - The communicator used in this data transformation. 
//
//        Return: The transformed data.
// =====================================================================================
template<>
int getGlobalStatusCustomReduction( int const & data_to_transform,
                                    Communicator const & aCommunicator);

// ===  FUNCTION  ======================================================================
//         Name:  broadcast
//  Description:  Broadcast data to all other ranks in communicator.
// 
//   Parameters: data_to_broadcast - The data to broadcast. Only the master rank broadcasts
//               it's data to the other ranks.
//               aCommunicator - The communicator used in this broadcast.
//				 bcast_rank - The rank of the communicator doing the broadcasting.
//
//        Return: The broadcasted data.
// =====================================================================================
template<typename T>
T broadcast(T const & data_to_broadcast,
                   Communicator const & aCommunicator,
				   const std::size_t bcast_rank);

// ===  FUNCTION  ======================================================================
//         Name:  broadcast
//  Description:  Specialization for broadcasting a std::string.
// 
//   Parameters: data_to_broadcast - The data to broadcast. Only the master rank broadcasts
//               it's data to the other ranks.
//               aCommunicator - The communicator used in this broadcast.
//               bcast_rank - The rank of the communicator doing the broadcasting.
//
//        Return: The broadcasted data.
// =====================================================================================
template<>
std::string broadcast(std::string const & data_to_broadcast,
                      Communicator const & aCommunicator,
					  const std::size_t bcast_rank);

} // namespace MPICOMMUNICATOR

#endif /* COMMUNICATOR_HEADER_FILES_COMMUNICATOR_H_ */
