//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ConsoleLoggingTaskIngredients.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ConsoleLoggingTaskIngredients::ConsoleLoggingTaskIngredients() :
    Ingredients<ANANSI::ConsoleLoggingTaskIngredients>()
{
    return;
}

ConsoleLoggingTaskIngredients::ConsoleLoggingTaskIngredients( const COMMANDLINE::CommandLineArguments & cmdline,
                                                              const WorldCommunicatorIngredientTraits::type & world_communicator ) :
    Ingredients<ANANSI::ConsoleLoggingTaskIngredients>(),
    commandLineArguments_(cmdline),
    worldCommunicator_(nullptr)
{
    // We clone the world_communicator and move-copy the clone to "this->world_communicator_".
    WorldCommunicatorIngredientTraits::type tmp_world_communicator(world_communicator->duplicateCommunicator());
    this->worldCommunicator_ = std::move(tmp_world_communicator);
    return;
}

ConsoleLoggingTaskIngredients::ConsoleLoggingTaskIngredients( ConsoleLoggingTaskIngredients const & other)
{
    if (this != &other)
    {
        *this = other;
    }
    return;
}

ConsoleLoggingTaskIngredients::ConsoleLoggingTaskIngredients( ConsoleLoggingTaskIngredients && other)
{
    if (this != &other)
    {
        *this = std::move(other);
    }
    return;
}		// -----  end of method ConsoleLoggingTaskIngredients::ConsoleLoggingTaskIngredients  -----


ConsoleLoggingTaskIngredients::~ConsoleLoggingTaskIngredients()
{
    return;
}

//============================= ACCESSORS ====================================
ConsoleLoggingTaskIngredients* ConsoleLoggingTaskIngredients::clone() const
{
    ANANSI::ConsoleLoggingTaskIngredients * tmp_ptr = new ANANSI::ConsoleLoggingTaskIngredients(*this); 
    return tmp_ptr;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ConsoleLoggingTaskIngredients& ConsoleLoggingTaskIngredients::operator=( const ConsoleLoggingTaskIngredients &other )
{
    if (this != &other)
    {
        Ingredients<ANANSI::ConsoleLoggingTaskIngredients>::operator=(other);
        this->commandLineArguments_ = other.commandLineArguments_;
        WorldCommunicatorIngredientTraits::type tmp_world_communicator(other.worldCommunicator_->duplicateCommunicator());
        this->worldCommunicator_ = std::move(tmp_world_communicator);
    }
    return *this;
} // assignment operator

ConsoleLoggingTaskIngredients& ConsoleLoggingTaskIngredients::operator=( ConsoleLoggingTaskIngredients && other )
{
    if (this != &other)
    {
        Ingredients<ANANSI::ConsoleLoggingTaskIngredients>::operator=(std::move(other));
        this->commandLineArguments_ = std::move(other.commandLineArguments_);
        this->worldCommunicator_ = std::move(other.worldCommunicator_);
    }
    return *this;
} // assignment-move operator

template <>
WorldCommunicatorIngredientTraits::type ConsoleLoggingTaskIngredients::giveIngredient__<typename WorldCommunicatorIngredientTraits::type> () const
{
    WorldCommunicatorIngredientTraits::type tmp_world_communicator(this->worldCommunicator_->duplicateCommunicator());
    return tmp_world_communicator;
}

template <>
CommandLineArgumentsIngredientTraits::type ConsoleLoggingTaskIngredients::giveIngredient__<typename CommandLineArgumentsIngredientTraits::type> () const
{
    CommandLineArgumentsIngredientTraits::type tmp_command_line(this->commandLineArguments_);
    return tmp_command_line;
}

template <>
int ConsoleLoggingTaskIngredients::giveIngredient__<int> () const
{
    return 1;
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
