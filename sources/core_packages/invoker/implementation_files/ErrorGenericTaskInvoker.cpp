
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorGenericTaskInvoker.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ErrorGenericTaskInvoker::ErrorGenericTaskInvoker()
{
    return;
}

ErrorGenericTaskInvoker::ErrorGenericTaskInvoker( ErrorGenericTaskInvoker const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ErrorGenericTaskInvoker::ErrorGenericTaskInvoker( ErrorGenericTaskInvoker && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ErrorGenericTaskInvoker::ErrorGenericTaskInvoker  -----


ErrorGenericTaskInvoker::~ErrorGenericTaskInvoker()
{
    return;
}

//============================= ACCESSORS ====================================

ErrorGenericTaskInvoker * ErrorGenericTaskInvoker::clone() const
{
    return new ErrorGenericTaskInvoker(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ErrorGenericTaskInvoker& ErrorGenericTaskInvoker::operator= ( const ErrorGenericTaskInvoker &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

ErrorGenericTaskInvoker& ErrorGenericTaskInvoker::operator= ( ErrorGenericTaskInvoker && other )
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
