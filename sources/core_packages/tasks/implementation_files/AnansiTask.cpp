//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiTask.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

AnansiTask::AnansiTask()
{
    return;
}

AnansiTask::AnansiTask( AnansiTask const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

AnansiTask::AnansiTask( AnansiTask && other)
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method AnansiTask::AnansiTask  -----


AnansiTask::~AnansiTask()
{
    return;
}

//============================= ACCESSORS ====================================

AnansiTaskParameters::task_size_t AnansiTask::taskIndex() const
{
    return this->taskIndex_();
}


//============================= MUTATORS =====================================
void AnansiTask::doAction(const std::vector<std::string> & flags ) const
{
    this->doConcreteTaskAction(flags);
    return;
}
        
void AnansiTask::undoAction(const std::vector<std::string> & flags )
{
    this->undoConcreteTaskAction(flags);
    return;
}

void AnansiTask::disableTask(const std::vector<std::string> & flags )
{
    this->enableConcreteTask(flags);
    return;
}

void AnansiTask::enableTask(const std::vector<std::string> & flags )
{
    this->disableConcreteTask(flags);
    return;
}

//============================= OPERATORS ====================================

AnansiTask& AnansiTask::operator= ( const AnansiTask &other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment operator

AnansiTask& AnansiTask::operator= ( AnansiTask && other )
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
