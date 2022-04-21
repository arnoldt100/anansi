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
#include "MDInitInitialConditionsVisitor.h"
#include "MDInitInitialConditions.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDInitInitialConditions::MDInitInitialConditions() :
    InitInitialConditions()
{
    return;
}

MDInitInitialConditions::MDInitInitialConditions( MDInitInitialConditions const & other) :
    InitInitialConditions(other)
{
    return;
}

MDInitInitialConditions::MDInitInitialConditions( MDInitInitialConditions && other) :
    InitInitialConditions(std::move(other))
{
    return;
}		// -----  end of method MDInitInitialConditions::MDInitInitialConditions  -----


MDInitInitialConditions::~MDInitInitialConditions()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDInitInitialConditions& MDInitInitialConditions::operator= ( const MDInitInitialConditions &other )
{
    if (this != &other)
    {
        InitInitialConditions::operator=(other);
    }
    return *this;
} // assignment operator

MDInitInitialConditions& MDInitInitialConditions::operator= ( MDInitInitialConditions && other )
{
    if (this != &other)
    {
        InitInitialConditions::operator=(std::move(other));
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
void MDInitInitialConditions::Execute_(Simulation * const a_simulation) const 
{
    MDInitInitialConditionsVisitor a_visitor;
    a_simulation->Accept(a_visitor);
    return;
};

void MDInitInitialConditions::Execute_() const 
{
    return;
};

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
