//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIEnvTask.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MPIEnvTask::MPIEnvTask() :
    InterProcessCommEnv(),
    commandLineArgs_()
{
    return;
}

MPIEnvTask::MPIEnvTask( MPIEnvTask const & other) :
   InterProcessCommEnv(other),
   commandLineArgs_(other.commandLineArgs_) 
{
    if (this != &other)
    {
        this->commandLineArgs_ = other.commandLineArgs_;
    }
    return;
}

MPIEnvTask::MPIEnvTask( MPIEnvTask && other) : 
    InterProcessCommEnv(std::move(other))
{
    if (this != &other)
    {
        this->commandLineArgs_ = std::move(other.commandLineArgs_);
    }
    return;
}		// -----  end of method MPIEnvTask::MPIEnvTask  -----


MPIEnvTask::~MPIEnvTask()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

MPIEnvTask& MPIEnvTask::operator=( const MPIEnvTask &other )
{
    if (this != &other)
    {
        InterProcessCommEnv::operator=(other);
    }
    return *this;
} // assignment operator

MPIEnvTask& MPIEnvTask::operator=( MPIEnvTask && other )
{
    if (this != &other)
    {
        InterProcessCommEnv::operator=(std::move(other));
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
void MPIEnvTask::enable_()
{
    std::cout << "Enabling MPI environment." << std::endl;
    return;
}

void MPIEnvTask::disable_()
{
    std::cout << "Disabling MPI environment." << std::endl;
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
