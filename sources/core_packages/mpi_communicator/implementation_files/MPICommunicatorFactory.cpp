
#include "MPICommunicatorFactory.h"

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

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace ANANSI */
