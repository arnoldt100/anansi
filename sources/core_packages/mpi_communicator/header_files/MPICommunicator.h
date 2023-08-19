//! \file MPICommunicator.h
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

//! \brief MPICommunicator is an abstraction for the MPI communicator and is derived 
//!        from COMMUNICATOR::Communicator.
//!
//! The Template Pattern with the Non-Virtual Interface Idiom is employed for
//! MPICommunicator and COMMUNICATOR::Communicator. The public interface is defined in
//! the public methods of COMMUNICATOR::Communicator, and the implementation is defined in the
//! private methods of MPICommunicator. The table below lists the private
//! implementation methods of MPICommunicator and the corrsponding
//! public interface methods in COMMUNICATOR::Communicator.
//!
//! | Private Implementation in Derived Class MPICommunicator      | Public Interface in COMMUNICATOR::Communicator             |
//! | ------------------------------------------------------------ | ---------------------------------------------------------- |
//! | void synchronizationPoint_ const final override              | Communicator::synchronizationPoint                         |
//! | int getCommunicatorRank_ const final override                | Communicator::getCommunicatorRank const                    |
//! | std::vector<int> gatherInt_ const final override             | std::vector<int> gatherInt_ gatherInt const                |

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

    void synchronizationPoint_() const final override;

    std::size_t
    getSizeofCommunicator_(const std::string & id) const final override;

    int
    getCommunicatorRank_() const final override;

    COMMUNICATOR::Communicator*
    duplicateCommunicator_() const final override;

    std::size_t
    getMaximum_(std::size_t const value) const override;
    
    char*
    allGather_(char const * aCString,
               const std::size_t aLengthMaximum,
               std::size_t & offset_size,
               std::size_t* & start_offsets_ptr,
               std::size_t* & end_offsets_ptr ) const final override;

    char*
    gather_(const std::size_t task_id_gather_data,
            char const * aCString,
            const std::size_t aLengthMaximum,
            std::size_t & offset_size, 
            std::size_t* & start_offsets_ptr,
            std::size_t* & end_offsets_ptr) const final override;

    std::unique_ptr<char[]>
    gather_(const std::size_t task_id_gather_data,
            const std::unique_ptr<char[]> & aCString,
            const std::size_t aLengthMaximum,
            std::size_t & offset_size, 
            std::unique_ptr<std::size_t[]> & start_offsets_ptr,
            std::unique_ptr<std::size_t[]> & end_offsets_ptr) const final override;


    std::vector<std::string>
    gatherString_(const std::string & data_to_gather,
                  const std::size_t task_id_gather_data) const final override;

    std::vector<int>
    gatherInt_(const int & data_to_gather,
               const std::size_t task_id_gather_data) const final override;

    template<typename T>
    T _getGlobalStatusCustomReduction( T const & data_to_transform) const;

    std::string
    broadcastStdString_(const std::string & data_to_broadcast, const std::size_t bcast_rank) const final override;

    std::map<std::string,std::string>
    broadcastStdMap_( const std::map<std::string,std::string> & a_map, const std::size_t bcast_rank) const final override;

    //===== MUTATORS =======
    void
    initializeWorldCommunicator_() final override;

    void freeCommunicator_() final override;
   
    // :TODO:05/21/2022 02:17:12 PM:: This needs to return a communicator.
    void 
    createSubcommunicator_(const std::string & tag) final override;

    void
    resetName_(const std::string & name) final override;

    //===== STATIC METHODS ======
    static void
    freeMPICommunicator_(MPI_Comm & a_communicator);

    static void
    _calculateStartAndEndOffsets(
            const std::size_t & offset_size,
            const std::size_t & aLengthMaximum,
            std::size_t* const & start_offsets_ptr,
            std::size_t* const & end_offsets_ptr);

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
