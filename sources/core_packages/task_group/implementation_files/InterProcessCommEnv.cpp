//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "InterProcessCommEnv.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

InterProcessCommEnv::InterProcessCommEnv() :
    AnansiTask()
{
    return;
}

InterProcessCommEnv::InterProcessCommEnv( InterProcessCommEnv const & other) :
   AnansiTask(other) 
{
    if (this != &other)
    {
        
    }
    return;
}

InterProcessCommEnv::InterProcessCommEnv( InterProcessCommEnv && other) : 
    AnansiTask(std::move(other))
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method InterProcessCommEnv::InterProcessCommEnv  -----


InterProcessCommEnv::~InterProcessCommEnv()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

InterProcessCommEnv& InterProcessCommEnv::operator=( const InterProcessCommEnv &other )
{
    if (this != &other)
    {
        AnansiTask::operator=(other);
    }
    return *this;
} // assignment operator

InterProcessCommEnv& InterProcessCommEnv::operator=( InterProcessCommEnv && other )
{
    if (this != &other)
    {
        AnansiTask::operator=(std::move(other));
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

void InterProcessCommEnv::enable_()
{
    return;
}
        
void InterProcessCommEnv::disable_() 
{
    return;
}
//============================= OPERATORS ====================================


} // namespace ANANSI
