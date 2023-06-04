//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "StandardFileParserFactory.h"
#include "ControlFile.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

StandardFileParserFactory::StandardFileParserFactory()
{
    return;
}

StandardFileParserFactory::StandardFileParserFactory( StandardFileParserFactory const & other)
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method StandardFileParserFactory::StandardFileParserFactory  -----

StandardFileParserFactory::StandardFileParserFactory( StandardFileParserFactory && other)
{
    if (this != &other)
    {

    }
    return;
}		// -----  end of method StandardFileParserFactory::StandardFileParserFactory  -----


StandardFileParserFactory::~StandardFileParserFactory()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

StandardFileParserFactory& StandardFileParserFactory::operator=( const StandardFileParserFactory &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

StandardFileParserFactory& StandardFileParserFactory::operator=( StandardFileParserFactory && other )
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
