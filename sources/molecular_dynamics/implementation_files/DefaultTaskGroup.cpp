//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "DefaultTaskGroup.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

DefaultTaskGroup::DefaultTaskGroup() :
   TaskGroup() 
{
    return;
}


DefaultTaskGroup::DefaultTaskGroup( DefaultTaskGroup && other) :
    TaskGroup(std::move(other))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method DefaultTaskGroup::DefaultTaskGroup  -----


DefaultTaskGroup::~DefaultTaskGroup()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

DefaultTaskGroup& DefaultTaskGroup::operator= ( DefaultTaskGroup && other )
{
    if (this != &other)
    {
        TaskGroup::operator=(std::move(other));
    }
    return *this;
} // assignment-move operator

//============================= STATIC METHODS ===============================
TaskGroup* DefaultTaskGroup::create()
{
    return new DefaultTaskGroup;
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

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
