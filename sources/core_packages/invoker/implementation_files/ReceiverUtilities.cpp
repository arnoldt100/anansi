
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GenericTaskUtilities.hpp"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ReceiverUtilities::ReceiverUtilities()
{
    return;
}

ReceiverUtilities::ReceiverUtilities( ReceiverUtilities const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ReceiverUtilities::ReceiverUtilities( ReceiverUtilities && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method ReceiverUtilities::ReceiverUtilities  -----


ReceiverUtilities::~ReceiverUtilities()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ReceiverUtilities& ReceiverUtilities::operator= ( const ReceiverUtilities &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

ReceiverUtilities& ReceiverUtilities::operator= ( ReceiverUtilities && other )
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
