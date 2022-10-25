//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GenericTaskInvoker.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

GenericTaskInvoker::GenericTaskInvoker() :
    commandSlots_()
{
    return;
}

GenericTaskInvoker::GenericTaskInvoker( GenericTaskInvoker && other) :
    commandSlots_(std::move(other.commandSlots_))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method GenericTaskInvoker::GenericTaskInvoker  -----


GenericTaskInvoker::~GenericTaskInvoker()
{
    this->commandSlots_.clear();
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void GenericTaskInvoker::addCommand(std::string const & key,
                               std::shared_ptr<ANANSI::AnansiTask> aCommand)
{
	this->commandSlots_[key] = aCommand;
    return;
}

void GenericTaskInvoker::doTask(std::string const & command_key)
{
    // this->commandSlots_[command_key]->action();
    return;
}

void GenericTaskInvoker::undoTask(std::string const & command_key)
{
    // this->commandSlots_[command_key]->undoAction();
    return;
}

//============================= OPERATORS ====================================

GenericTaskInvoker& GenericTaskInvoker::operator= ( GenericTaskInvoker && other )
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
