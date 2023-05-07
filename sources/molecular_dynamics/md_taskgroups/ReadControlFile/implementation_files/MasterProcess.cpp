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
#include "MasterProcess.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MasterProcess::MasterProcess() :
    masterProcess_(false)
{
    return;
}

MasterProcess::MasterProcess (const bool master_process) :
    masterProcess_(master_process)
{
    return;
}

MasterProcess::MasterProcess( MasterProcess const & other) :
    masterProcess_(other.masterProcess_)
{
    if (this != &other)
    {
        
    }
    return;
}

MasterProcess::MasterProcess( MasterProcess && other) :
    masterProcess_(std::move(other.masterProcess_))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method MasterProcess::MasterProcess  -----


MasterProcess::~MasterProcess()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MasterProcess& MasterProcess::operator= ( const MasterProcess &other )
{
    if (this != &other)
    {
        this->masterProcess_= other.masterProcess_;
    }
    return *this;
} // assignment operator

MasterProcess& MasterProcess::operator= ( MasterProcess && other )
{
    if (this != &other)
    {
        this->masterProcess_ = std::move(other.masterProcess_);
    }
    return *this;
} // assignment-move operator

bool MasterProcess::operator()() const
{
    return this->masterProcess_;
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
