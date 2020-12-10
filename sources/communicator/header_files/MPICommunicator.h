/*
 * MPICommunicator.h
 *
 *  Created on: Oct 15, 2018
 *      Author: arnoldt
 */

#ifndef  COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPICOMMUNICATOR_H_
#define  COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_MPICOMMUNICATOR_H_

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"
#include <iostream>
#include <map>
#include <functional>
#include <boost/asio.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"
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



namespace COMMUNICATOR
{

using SUBCOMMUNICATOR_MAP_T = std::map<std::string,MPI_Comm>;


class MPICommunicator final : public Communicator
{
public:

    //===== LIFECYCLE ======
    MPICommunicator();
    
    MPICommunicator(MPICommunicator const & other);

    MPICommunicator(MPICommunicator && other);

    ~MPICommunicator();

    //===== ACCESSORS ======

    //===== STATIC METHODS ======

    //===== MUTATORS =======
    //
    //===== OPERATORS ======

    MPICommunicator& operator=(MPICommunicator const & other);

    MPICommunicator& operator=(MPICommunicator && other);

private:
    //===== ACCESSORS ======
    std::size_t
    _getSizeofCommunicator(const std::string & id) const final override;

    int
    _getWorldCommunicatorRank() const final override;

    int 
	_getSubCommunicatorRank(const std::string & tag) const final override;

    std::unique_ptr<COMMUNICATOR::Communicator>
    _duplicateCommunicator() const final override;

    int
     _getMaximum(int const value) const override;
    
    char*
    _allGather(char const * aCString,
               const std::size_t aLengthMaximum,
               std::size_t & offset_size,
               int* & start_offsets_ptr,
               int* & end_offsets_ptr ) const final override;

    char*
    _gather(const std::size_t task_id_gather_data,
            char const * aCString,
            const std::size_t aLengthMaximum,
            std::size_t & offset_size, 
            int* & start_offsets_ptr,
            int* & end_offsets_ptr) const final override;

    virtual std::unique_ptr<char[]>
    _gather(const std::size_t task_id_gather_data,
            const std::unique_ptr<char[]> & aCString,
            const std::size_t aLengthMaximum,
            std::size_t & offset_size, 
            std::unique_ptr<int[]> & start_offsets_ptr,
            std::unique_ptr<int[]> & end_offsets_ptr) const final override;


    std::vector<std::string>
    _gatherString(const std::string & data_to_gather,
                  const std::size_t task_id_gather_data) const final override;

    std::vector<int>
    _gatherInt(const int & data_to_gather,
               const std::size_t task_id_gather_data) const final override;

    //===== MUTATORS =======
    void
    _initializeWorldCommunicator() final override;

    void _freeCommunicator() final override;
   
    void
    _addCommunicator(std::string const & key, MPI_Comm const & my_mpi_comm);

    void
    _eraseCommunicator(std::string const & key);

    void 
    _createSubcommunicator(const std::string & tag) final override;

    //===== STATIC METHODS ======
    static void
    _freeMPICommunicator(MPI_Comm & a_communicator);

    static void
    _calculateStartAndEndOffsets(
            const std::size_t & offset_size,
            const std::size_t & aLengthMaximum,
            int* const & start_offsets_ptr,
            int* const & end_offsets_ptr);

    //===== DATA MEMBERS ===
    MPI_Comm _mpiWorldCommunicator;
    SUBCOMMUNICATOR_MAP_T _mpicommHandles;
    std::string _hostname;
    static std::string HOSTNAME_NOT_DEFINED;
};

}; /* namespace COMMUNICATOR */

#endif   /* ----- #ifndef COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_COMMUNICATOR_H_ ----- */
