
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GeneralLogger.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

GeneralLogger::GeneralLogger()
{
    return;
}

GeneralLogger::GeneralLogger( GeneralLogger const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

GeneralLogger::GeneralLogger( GeneralLogger && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method GeneralLogger::GeneralLogger  -----

GeneralLogger::~GeneralLogger()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

GeneralLogger& GeneralLogger::operator= ( const GeneralLogger &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

GeneralLogger& GeneralLogger::operator= ( GeneralLogger && other )
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
