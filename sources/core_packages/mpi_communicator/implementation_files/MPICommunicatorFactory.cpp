//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPICommunicatorFactory.h"
#include "create_cartesian_mpi_communicator.hpp"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPICommunicatorFactory::MPICommunicatorFactory() : 
    COMMUNICATOR::CommunicatorFactory()
{
    return;
}

MPICommunicatorFactory::MPICommunicatorFactory(const MPICommunicatorFactory& other) :
    COMMUNICATOR::CommunicatorFactory(other)
{
    if (this != &other)
    {
    }
    return;
}

MPICommunicatorFactory::MPICommunicatorFactory(MPICommunicatorFactory && other) : 
    COMMUNICATOR::CommunicatorFactory(std::move(other))
{
    if (this != &other)
    {
    }
    return;
}

MPICommunicatorFactory::~MPICommunicatorFactory() 
{
    return;
}


//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================
MPICommunicatorFactory& 
MPICommunicatorFactory::operator=(const MPICommunicatorFactory& other)
{
    if (this != &other)
    {
        CommunicatorFactory::operator=(other);
    }
    return *this;
}

MPICommunicatorFactory& 
MPICommunicatorFactory::operator=(MPICommunicatorFactory && other)
{
    if (this != &other)
    {
        CommunicatorFactory::operator=(std::move(other));
    }
    return *this;
}

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
std::unique_ptr<COMMUNICATOR::Communicator> MPICommunicatorFactory::createWorldCommunicator_() const
{
    std::unique_ptr<COMMUNICATOR::Communicator> aCommunicator = 
        std::make_unique<ANANSI::MPICommunicator>();

    aCommunicator->initializeWorldCommunicator();
    return aCommunicator;
}

std::unique_ptr<COMMUNICATOR::Communicator> MPICommunicatorFactory::createNullWorldCommunicator_() const
{
    std::unique_ptr<COMMUNICATOR::Communicator> aCommunicator = 
        std::make_unique<ANANSI::MPICommunicator>();

    return aCommunicator;
}

std::unique_ptr<COMMUNICATOR::Communicator> 
MPICommunicatorFactory::cloneCommunicator_(std::unique_ptr<COMMUNICATOR::Communicator> const & otherCommunicator) const
{
    auto tmp_mpicommunicator = std::move(otherCommunicator->duplicateCommunicator());
    std::unique_ptr<COMMUNICATOR::Communicator> aMPICommunicator(tmp_mpicommunicator);
    return aMPICommunicator;
}

std::unique_ptr<COMMUNICATOR::Communicator> 
MPICommunicatorFactory::cloneCommunicator_(std::shared_ptr<COMMUNICATOR::Communicator> const & otherCommunicator) const
{
    auto tmp_mpicommunicator = std::move(otherCommunicator->duplicateCommunicator());
    std::unique_ptr<COMMUNICATOR::Communicator> aMPICommunicator(tmp_mpicommunicator);
    return aMPICommunicator;
}

std::unique_ptr<COMMUNICATOR::Communicator> 
MPICommunicatorFactory::createCommunicator_(std::unique_ptr<COMMUNICATOR::Communicator> const & otherCommunicator,
                                            COMMUNICATOR::CommunicatorEmbryo const & comm_embryo) const
{
    using Communicator_Types = COMMUNICATOR::CommunicatorEmbryo::communicator_types;
    std::unique_ptr<COMMUNICATOR::Communicator> a_communicator;
    std::string communicator_name = comm_embryo.communicatorName();
    switch ( comm_embryo.typeOfCommunicator() ) 
    {
        case Communicator_Types::rectangular :
            const auto comm_dimensions = comm_embryo.communicatorDimensions();
            a_communicator = std::move(create_cartesian_mpi_communicator(otherCommunicator,comm_dimensions)); 
            break;
    }

    return a_communicator;
}
//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace ANANSI */
