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

WorldTaskGroupIngredients::WorldTaskGroupIngredients(const COMMANDLINE::CommandLineArguments & cmdline) :
    commandLineArguments_(cmdline)
{
    return;
}

WorldTaskGroupIngredients::WorldTaskGroupIngredients( WorldTaskGroupIngredients const & other) 
{
    if (this != &other)
    {
        this->commandLineArguments_=  other.commandLineArguments_;

    }
    return;
}

WorldTaskGroupIngredients::WorldTaskGroupIngredients( WorldTaskGroupIngredients && other) 
{
    if (this != &other)
    {
        this->commandLineArguments_ = std::move(other.commandLineArguments_);
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
       this->commandLineArguments_ = std::move(other.commandLineArguments_); 
    }
    return *this;
} // assignment operator

WorldTaskGroupIngredients& WorldTaskGroupIngredients::operator= ( WorldTaskGroupIngredients && other )
{
    if (this != &other)
    {
        this->commandLineArguments_ = std::move(other.commandLineArguments_);
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
