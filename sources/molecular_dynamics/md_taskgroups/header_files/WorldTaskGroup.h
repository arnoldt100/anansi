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
#include "BaseVisitable.hpp"
#include "CommandLineArgumentsIngredientTraits.h"
#include "WorldCommunicatorIngredientTraits.h"

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
        using NeededIngredients = MPL::mpl_typelist<CommandLineArgumentsIngredientTraits::type,
                                                   WorldCommunicatorIngredientTraits::type>;

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        // This macro defines the Accept member function.
        DEFINE_VISITABLE()

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
        void addCommunicator_(std::unique_ptr<COMMUNICATOR::Communicator> && my_comm) override;

        void addLogger_() override;
        
        // ====================  DATA MEMBERS  =======================================
        CommandLineArgumentsIngredientTraits::type commandLineArguments_;
        WorldCommunicatorIngredientTraits::type worldCommunicator_;
}; // -----  end of class WorldTaskGroup  -----

template <>
void WorldTaskGroup::addIngredient(WorldCommunicatorIngredientTraits::type && ingredient);

template <>
void WorldTaskGroup::addIngredient(CommandLineArgumentsIngredientTraits::type && ingredient);

}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_WorldTaskGroup_INC  ----- */
