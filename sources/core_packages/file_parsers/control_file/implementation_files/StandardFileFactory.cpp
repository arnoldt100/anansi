//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "StandardFileFactory.h"
#include "ControlFile.hpp"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

StandardFileFactory::StandardFileFactory()
{
    return;
}

StandardFileFactory::StandardFileFactory( StandardFileFactory const & other)
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method StandardFileFactory::StandardFileFactory  -----

StandardFileFactory::StandardFileFactory( StandardFileFactory && other)
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method StandardFileFactory::StandardFileFactory  -----


StandardFileFactory::~StandardFileFactory()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

StandardFileFactory& StandardFileFactory::operator=( const StandardFileFactory &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

StandardFileFactory& StandardFileFactory::operator=( StandardFileFactory && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

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

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
