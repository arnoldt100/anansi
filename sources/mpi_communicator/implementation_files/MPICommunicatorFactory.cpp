/*
 * MPICommunicatorFactory.cpp
 *
 *  Created on: 12/05/18
 *      Authors: Arnold Tharrington
 */

#include "MPICommunicatorFactory.h"

namespace COMMUNICATOR {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPICommunicatorFactory::MPICommunicatorFactory() : 
    CommunicatorFactory()
{
    return;
}

MPICommunicatorFactory::~MPICommunicatorFactory() {
    return;
}

MPICommunicatorFactory::MPICommunicatorFactory(const MPICommunicatorFactory& other)
{
    if (this != &other)
    {
    }
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
std::unique_ptr<COMMUNICATOR::Communicator> MPICommunicatorFactory::_createWorldCommunicator() const
{
    std::unique_ptr<COMMUNICATOR::Communicator> aCommunicator = 
        std::make_unique<COMMUNICATOR::MPICommunicator>();

    aCommunicator->initializeWorldCommunicator();
    return aCommunicator;
}

std::unique_ptr<COMMUNICATOR::Communicator> 
MPICommunicatorFactory::_cloneCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> const & otherCommunicator) const
{
    auto tmp_mpicommunicator = std::move(otherCommunicator->duplicateCommunicator());
    std::unique_ptr<COMMUNICATOR::Communicator> aMPICommunicator(tmp_mpicommunicator);
    return aMPICommunicator;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} /* namespace COMMUNICATOR */
