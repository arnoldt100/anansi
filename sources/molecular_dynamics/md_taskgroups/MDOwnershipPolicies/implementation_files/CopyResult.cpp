//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CopyResult.hpp"

namespace RECEIVER {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CopyResult::CopyResult()
{
    return;
}

CopyResult::CopyResult( CopyResult const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

CopyResult::CopyResult( CopyResult && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method CopyResult::CopyResult  -----


CopyResult::~CopyResult()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CopyResult& CopyResult::operator= ( const CopyResult &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

CopyResult& CopyResult::operator= ( CopyResult && other )
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


} // namespace RECEIVER
