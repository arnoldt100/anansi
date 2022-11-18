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
#include <map>
#include <memory>
#include <string>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"


namespace ANANSI
{

static constexpr std::size_t DEFAULT_MPI_MASTER_RANK_ID=0;

class MPICommunicator final : public COMMUNICATOR::Communicator
{
public:

    //===== LIFECYCLE ======
    MPICommunicator();
    
    MPICommunicator(MPICommunicator const & other)=delete;

    MPICommunicator(MPICommunicator && other);

    MPICommunicator(const MPI_Comm & mpi_world_communicator, 
                    const std::string & host_name);

    ~MPICommunicator();

    //===== ACCESSORS ======

    //===== STATIC METHODS ======

    //===== MUTATORS =======

    //===== OPERATORS ======

    MPICommunicator& operator=(MPICommunicator const & other)=delete;

    MPICommunicator& operator=(MPICommunicator && other);

    MPICommunicator& operator=(Communicator && other) override;

private:
    //===== ACCESSORS ======
    std::size_t
    _getSizeofCommunicator(const std::string & id) const final override;

    int
    _getCommunicatorRank() const final override;

    COMMUNICATOR::Communicator*
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

    bool
    _getGlobalStatus(const bool & data_to_reduce) const final override;

    template<typename T>
    T _getGlobalStatusCustomReduction( T const & data_to_transform) const;

    std::string
    _broadcastStdString(const std::string & data_to_broadcast, const std::size_t bcast_rank) const final override;

    //===== MUTATORS =======
    void
    _initializeWorldCommunicator() final override;

    void freeCommunicator_() final override;
   
    // :TODO:05/21/2022 02:17:12 PM:: This needs to return a communicator.
    void 
    _createSubcommunicator(const std::string & tag) final override;

    void
    resetName_(const std::string & name) final override;

    //===== STATIC METHODS ======
    static void
    freeMPICommunicator_(MPI_Comm & a_communicator);

    static void
    _calculateStartAndEndOffsets(
            const std::size_t & offset_size,
            const std::size_t & aLengthMaximum,
            int* const & start_offsets_ptr,
            int* const & end_offsets_ptr);

    //===== DATA MEMBERS ===
    MPI_Comm _mpiCommunicator;
    std::string _hostname;
    static std::string HOSTNAME_NOT_DEFINED;
};

template<typename T>
T MPICommunicator::_getGlobalStatusCustomReduction( T const & data_to_transform) const 
{
    return data_to_transform;
}

}; /* namespace ANANSI */

#endif   /* ----- #ifndef COMMUNICATOR_SOURCE_IMPLEMENTATION_FILES_COMMUNICATOR_H_ ----- */
