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

WorldTaskGroupIngredients::WorldTaskGroupIngredients()
{
    return;
}

WorldTaskGroupIngredients::WorldTaskGroupIngredients(const COMMANDLINE::CommandLineArguments & cmdline,
                                                     const std::unique_ptr<COMMUNICATOR::Communicator> & world_communicator ) :
    commandLineArguments_(cmdline),
    worldCommunicator_(nullptr)
{
    // We clone the world_communicator and move-copy the clone to "this->world_communicator_".
    std::unique_ptr<COMMUNICATOR::Communicator> tmp_world_communicator(world_communicator->duplicateCommunicator());
    this->worldCommunicator_ = std::move(tmp_world_communicator);
    return;
}

WorldTaskGroupIngredients::WorldTaskGroupIngredients( WorldTaskGroupIngredients const & other) 
{
    if (this != &other)
    {
        this->commandLineArguments_=  other.commandLineArguments_;

        // We clone the world_communicator and move-copy the clone to "this->world_communicator_".
        std::unique_ptr<COMMUNICATOR::Communicator> tmp_world_communicator(other.worldCommunicator_->duplicateCommunicator());
        this->worldCommunicator_ = std::move(tmp_world_communicator);
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

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

WorldTaskGroupIngredients& WorldTaskGroupIngredients::operator= ( const WorldTaskGroupIngredients &other )
{
    if (this != &other)
    {
        this->commandLineArguments_ = other.commandLineArguments_;
        std::unique_ptr<COMMUNICATOR::Communicator> tmp_world_communicator(other.worldCommunicator_->duplicateCommunicator());
        this->worldCommunicator_ = std::move(tmp_world_communicator);
    }
    return *this;
} // assignment operator

WorldTaskGroupIngredients& WorldTaskGroupIngredients::operator= ( WorldTaskGroupIngredients && other )
{
    if (this != &other)
    {
        this->commandLineArguments_ = std::move(other.commandLineArguments_);
        this->worldCommunicator_ = std::move(other.worldCommunicator_);
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
