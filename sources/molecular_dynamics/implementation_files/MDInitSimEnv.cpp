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
#include "MDInitSimEnv.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MDInitSimEnv::MDInitSimEnv() :
    InitSimEnv()
{
    return;
}

MDInitSimEnv::MDInitSimEnv( MDInitSimEnv const & other) :
    InitSimEnv(other)
{
    return;
}

MDInitSimEnv::MDInitSimEnv( MDInitSimEnv && other) :
    InitSimEnv(std::move(other))
{
    return;
}		// -----  end of method MDInitSimEnv::MDInitSimEnv  -----


MDInitSimEnv::~MDInitSimEnv()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MDInitSimEnv& MDInitSimEnv::operator= ( MDInitSimEnv const & other ) 
{
    if (this != &other)
    {
        InitSimEnv::operator=(other);
    }
    return *this;
} // assignment operator

MDInitSimEnv& MDInitSimEnv::operator= ( MDInitSimEnv && other )
{
    if (this != &other)
    {
        InitSimEnv::operator=(std::move(other));
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
void MDInitSimEnv::Execute_(Simulation * const a_simulation) const 
{
    return;
};

void MDInitSimEnv::AddCommand_() const 
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
