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
    mpiEnvironment_(nullptr)
{
    return;
}

MPIEnvTask::MPIEnvTask( MPIEnvTask const & other) :
   InterProcessCommEnv(other),
   mpiEnvironment_(other.mpiEnvironment_) 
{
    if (this != &other)
    {
    }
    return;
}

MPIEnvTask::MPIEnvTask( MPIEnvTask && other) : 
    InterProcessCommEnv(std::move(other)),
    mpiEnvironment_(std::move(other.mpiEnvironment_)) 
{
    if (this != &other)
    {
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
        this->mpiEnvironment_ = other.mpiEnvironment_; 
    }
    return *this;
} // assignment operator

MPIEnvTask& MPIEnvTask::operator=( MPIEnvTask && other )
{
    if (this != &other)
    {
        InterProcessCommEnv::operator=(std::move(other));
        this->mpiEnvironment_ = std::move(other.mpiEnvironment_); 
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

template <>
void MPIEnvTask::bindAReceiver(std::shared_ptr<ANANSI::MPIEnvironment> & receiver)
{
    std::cout << "Binding a specfic mpi environment receiver." << std::endl;
    this->mpiEnvironment_ = receiver;
}

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
