#ifndef  ANANSI_WorldTaskGroupIngredients_INC
#define  ANANSI_WorldTaskGroupIngredients_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPLAliases.hpp"
#include "Ingredients.hpp"
#include "WorldCommunicatorIngredientTraits.h"
#include "CommandLineArguments.h"
#include "Communicator.h"
#include "CommandLineArgumentsIngredientTraits.h"
#include "WorldCommunicatorIngredientTraits.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  WorldTaskGroupIngredients
//  Description:  
//  =====================================================================================
class WorldTaskGroupIngredients : public ANANSI::Ingredients<ANANSI::WorldTaskGroupIngredients>
{
    public:
        // ====================  LIFECYCLE     =======================================

        WorldTaskGroupIngredients ();   // constructor
                                                                                         //
        WorldTaskGroupIngredients (const CommandLineArgumentsIngredientTraits::type & cmdline,
                                   const WorldCommunicatorIngredientTraits::type & world_communicator);   // constructor

        WorldTaskGroupIngredients (const WorldTaskGroupIngredients & other);   // copy constructor

        WorldTaskGroupIngredients (WorldTaskGroupIngredients && other);   // copy-move constructor

        ~WorldTaskGroupIngredients ();  // destructor

        // ====================  ACCESSORS     =======================================
        WorldTaskGroupIngredients* clone() const; 

        CommandLineArgumentsIngredientTraits::type giveIngredient__( MPL::mpl_typelist<CommandLineArgumentsIngredientTraits::type> dummy_t ) const
        {
           return this->commandLineArguments_;
        }

        WorldCommunicatorIngredientTraits::type giveIngredient__( MPL::mpl_typelist<WorldCommunicatorIngredientTraits::type> dummy_t ) const
        {
            auto tmp_mpicommunicator = std::move(this->worldCommunicator_->duplicateCommunicator());
            std::unique_ptr<COMMUNICATOR::Communicator> aMPICommunicator(tmp_mpicommunicator);
            return aMPICommunicator;
        }

        template<typename T>
        T giveIngredient__() const ;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WorldTaskGroupIngredients& operator= ( const WorldTaskGroupIngredients &other ); // assignment operator

        WorldTaskGroupIngredients& operator= ( WorldTaskGroupIngredients && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        CommandLineArgumentsIngredientTraits::type commandLineArguments_;
        WorldCommunicatorIngredientTraits::type worldCommunicator_;

}; // -----  end of class WorldTaskGroupIngredients  -----

// template <>
// inline WorldCommunicatorIngredientTraits::type WorldTaskGroupIngredients::giveIngredient__<typename WorldCommunicatorIngredientTraits::type> () const
// {
//     WorldCommunicatorIngredientTraits::type tmp_world_communicator(this->worldCommunicator_->duplicateCommunicator());
//     return tmp_world_communicator;
// }

// template <>
// inline CommandLineArgumentsIngredientTraits::type WorldTaskGroupIngredients::giveIngredient__<typename CommandLineArgumentsIngredientTraits::type> () const
// {
//     CommandLineArgumentsIngredientTraits::type tmp_command_line(this->commandLineArguments_);
//     return tmp_command_line;
// }

// template <>
// inline int WorldTaskGroupIngredients::giveIngredient__<int> () const
// {
//     return 1;
// }

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_WorldTaskGroupIngredients_INC  ----- 
