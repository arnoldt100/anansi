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

void GenericTaskInvoker::doTask(std::vector<std::string> const & command_keys)
{
    const std::vector<std::string> flags = {"default"};
    for (auto key : command_keys)
    {
        (this->commandSlots_.at(key))->doAction(flags);
    }
    return;
}

void GenericTaskInvoker::undoTask(std::vector<std::string> const & command_keys)
{
    const std::vector<std::string> flags = {"default"};
    for (auto key : command_keys)
    {
        (this->commandSlots_.at(key))->undoAction(flags);
    }
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
