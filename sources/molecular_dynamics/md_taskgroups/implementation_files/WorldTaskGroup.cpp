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
#include "WorldTaskGroup.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

WorldTaskGroup::WorldTaskGroup() :
   TaskGroup() 
{
    return;
}


WorldTaskGroup::WorldTaskGroup( WorldTaskGroup && other) :
    TaskGroup(std::move(other))
{
    if (this != &other)
    {
        *this = std::move(other);
    }
    return;
}		// -----  end of method WorldTaskGroup::WorldTaskGroup  -----


WorldTaskGroup::~WorldTaskGroup()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void WorldTaskGroup::addCommandLineArguments(COMMANDLINE::CommandLineArguments && cmdline)
{
    std::cout << "Adding command line arguments to WorldTaskGroup." << std::endl;
    this->commandLineArguments_ = std::move(cmdline);
    return;
}

//============================= OPERATORS ====================================

WorldTaskGroup& WorldTaskGroup::operator= ( WorldTaskGroup && other )
{
    if (this != &other)
    {
        TaskGroup::operator=(std::move(other));
        this->commandLineArguments_ = std::move(other.commandLineArguments_);
        this->worldCommunicator_ = std::move(other.worldCommunicator_);
    }
    return *this;
} // assignment-move operator

//============================= STATIC METHODS ===============================
TaskGroup* WorldTaskGroup::create()
{
    return new WorldTaskGroup;
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
template <typename IngredientType>
void obtainIngredient_( )
{
    return;
}

void WorldTaskGroup::addCommunicator_(std::unique_ptr<COMMUNICATOR::Communicator> && my_comm )
{
    this->worldCommunicator_ = std::move(my_comm);
    std::cout << "Adding communicator to WorldTaskGroup." << std::endl;
    return;
}

void WorldTaskGroup::addLogger_()
{
    std::cout << "Adding logger to WorldTaskGroup." << std::endl;
    return;
}


//============================= OPERATORS ====================================


} // namespace ANANSI
