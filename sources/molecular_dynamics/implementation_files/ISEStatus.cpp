//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ISEStatus.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ISEStatus::ISEStatus() :
    TaskStatus()
{
    return;
}

ISEStatus::ISEStatus( ISEStatus const & other) :
    TaskStatus(other)
{
    return;
}		// -----  end of method ISEStatus::ISEStatus  -----

ISEStatus::ISEStatus( ISEStatus && other) :
    TaskStatus(std::move(other))

{
    return;
}		// -----  end of method ISEStatus::ISEStatus  -----


ISEStatus::~ISEStatus()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ISEStatus& ISEStatus::operator= ( const ISEStatus &other )
{
    if (this != &other)
    {
        TaskStatus::operator=(other);
    }
    return *this;
} // assignment operator

ISEStatus& ISEStatus::operator= ( ISEStatus && other )
{
    if (this != &other)
    {
        TaskStatus::operator=(std::move(other));
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