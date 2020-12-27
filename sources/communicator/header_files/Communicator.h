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

namespace COMMUNICATOR {

static constexpr std::size_t MASTER_TASK_ID=0;

class Communicator
{
public:
    //===== LIFECYCLE ======
    Communicator();

    virtual ~Communicator();

    Communicator(Communicator const & other);

    Communicator(Communicator&& other);

    //===== DATA MEMBERS ===

    //===== ACCESSORS ======
    int 
    getWorldCommunicatorRank() const
    {
        return this->_getWorldCommunicatorRank();
    }

    int
    getSubCommunicatorRank(const std::string & tag) const
    {
        return this->_getSubCommunicatorRank(tag);
    }

    bool
    sameWorldRank( const int aRank) const
    {
        int my_world_rank = this->getWorldCommunicatorRank();
        return ( aRank == my_world_rank ? true : false);
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

    std::unique_ptr<COMMUNICATOR::Communicator> 
    duplicateCommunicator() const
    {
        return this->_duplicateCommunicator();
    }

    void 
    createSubcommunicator(const std::string & tag)
    {
        this->_createSubcommunicator(tag);
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
    _getWorldCommunicatorRank() const=0;

    virtual int 
    _getSubCommunicatorRank(const std::string & tag) const=0;

    virtual std::unique_ptr<COMMUNICATOR::Communicator>
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

} /* namespace MPICOMMUNICATOR */

#endif /* COMMUNICATOR_HEADER_FILES_COMMUNICATOR_H_ */
