#ifndef  ANANSI_WorldTaskGroup_INC
#define  ANANSI_WorldTaskGroup_INC


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
#include "TaskGroup.h"
#include "MPLAliases.hpp"
#include "CommandLineArgumentsIngredientTraits.h"
#include "WorldCommunicatorIngredientTraits.h"
#include "ConsoleLoggerTraits.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  WorldTaskGroup
//  Description:  
//  =====================================================================================
class WorldTaskGroup final : public TaskGroup
{
    public:
        // ====================  LIFECYCLE     =======================================

        WorldTaskGroup ();   // constructor

        WorldTaskGroup (const WorldTaskGroup & other)=delete;   // copy constructor

        WorldTaskGroup (WorldTaskGroup && other);   // copy-move constructor

        ~WorldTaskGroup ();  // destructor

        // ====================  ALIASES       =======================================
        using baseclass = TaskGroup;
        using NeededIngredients = MPL::mpl_typelist<CommandLineArgumentsIngredientTraits::type,
                                                    WorldCommunicatorIngredientTraits::type>;

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        template <typename T>
        void addIngredient(T && ingredient);

        // ====================  OPERATORS     =======================================

        WorldTaskGroup& operator= ( const WorldTaskGroup &other )=delete; // assignment operator

        WorldTaskGroup& operator= ( WorldTaskGroup && other ); // assignment-move operator

        // ====================  STATIC METHODS ======================================
        static TaskGroup* create();

        // ====================  DATA MEMBERS  =======================================

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  MUTATORS      =======================================
        void enable_() override;

        void disable_() override;

        // ====================  DATA MEMBERS  =======================================
        CommandLineArgumentsIngredientTraits::type commandLineArguments_;
        WorldCommunicatorIngredientTraits::type worldCommunicator_;
        ConsoleLoggerTraits::type consoleLogger_;

}; // -----  end of class WorldTaskGroup  -----

template <>
void WorldTaskGroup::addIngredient(WorldCommunicatorIngredientTraits::type && ingredient);

template <>
void WorldTaskGroup::addIngredient(CommandLineArgumentsIngredientTraits::type && ingredient);

}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_WorldTaskGroup_INC  ----- */
