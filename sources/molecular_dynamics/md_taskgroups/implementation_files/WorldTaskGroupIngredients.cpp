//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "WorldTaskGroupIngredients.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

WorldTaskGroupIngredients::WorldTaskGroupIngredients() :
    Ingredients<ANANSI::WorldTaskGroupIngredients>()
{
    return;
}

WorldTaskGroupIngredients::WorldTaskGroupIngredients(const COMMANDLINE::CommandLineArguments & cmdline,
                                                     const WorldCommunicatorIngredientTraits::type & world_communicator ) :
    Ingredients<ANANSI::WorldTaskGroupIngredients>(),
    commandLineArguments_(cmdline),
    worldCommunicator_(nullptr)
{
    // We clone the world_communicator and move-copy the clone to "this->world_communicator_".
    WorldCommunicatorIngredientTraits::type tmp_world_communicator(world_communicator->duplicateCommunicator());
    this->worldCommunicator_ = std::move(tmp_world_communicator);
    return;
}

WorldTaskGroupIngredients::WorldTaskGroupIngredients( WorldTaskGroupIngredients const & other)
{
    if (this != &other)
    {
        *this = other;
    }
    return;
}

WorldTaskGroupIngredients::WorldTaskGroupIngredients( WorldTaskGroupIngredients && other)
{
    if (this != &other)
    {
        *this = std::move(other);
    }
    return;
}		// -----  end of method WorldTaskGroupIngredients::WorldTaskGroupIngredients  -----


WorldTaskGroupIngredients::~WorldTaskGroupIngredients()
{
    return;
}

//============================= ACCESSORS ====================================
WorldTaskGroupIngredients* WorldTaskGroupIngredients::clone() const
{
    ANANSI::WorldTaskGroupIngredients * tmp_ptr = new ANANSI::WorldTaskGroupIngredients(*this); 
    return tmp_ptr;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

WorldTaskGroupIngredients& WorldTaskGroupIngredients::operator=( const WorldTaskGroupIngredients &other )
{
    if (this != &other)
    {
        Ingredients<ANANSI::WorldTaskGroupIngredients>::operator=(other);
        this->commandLineArguments_ = other.commandLineArguments_;
        WorldCommunicatorIngredientTraits::type tmp_world_communicator(other.worldCommunicator_->duplicateCommunicator());
        this->worldCommunicator_ = std::move(tmp_world_communicator);
    }
    return *this;
} // assignment operator

WorldTaskGroupIngredients& WorldTaskGroupIngredients::operator=( WorldTaskGroupIngredients && other )
{
    if (this != &other)
    {
        Ingredients<ANANSI::WorldTaskGroupIngredients>::operator=(std::move(other));
        this->commandLineArguments_ = std::move(other.commandLineArguments_);
        this->worldCommunicator_ = std::move(other.worldCommunicator_);
    }
    return *this;
} // assignment-move operator

template <>
WorldCommunicatorIngredientTraits::type WorldTaskGroupIngredients::giveIngredient__<typename WorldCommunicatorIngredientTraits::type> () const
{
    WorldCommunicatorIngredientTraits::type tmp_world_communicator(this->worldCommunicator_->duplicateCommunicator());
    return tmp_world_communicator;
}

template <>
CommandLineArgumentsIngredientTraits::type WorldTaskGroupIngredients::giveIngredient__<typename CommandLineArgumentsIngredientTraits::type> () const
{
    CommandLineArgumentsIngredientTraits::type tmp_command_line(this->commandLineArguments_);
    return tmp_command_line;
}

template <>
int WorldTaskGroupIngredients::giveIngredient__<int> () const
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
