#ifndef  ANANSI_DefaultTaskGroup_INC
#define  ANANSI_DefaultTaskGroup_INC

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
#include "CommunicatorIngredientTraits.h"
#include "ConsoleLoggerTraits.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  DefaultTaskGroup
//  Description:  
//  =====================================================================================
class DefaultTaskGroup final : public TaskGroup
{
    public:
        // ====================  LIFECYCLE     =======================================

        DefaultTaskGroup ();   // constructor

        DefaultTaskGroup (const DefaultTaskGroup & other)=delete;   // copy constructor

        DefaultTaskGroup (DefaultTaskGroup && other);   // copy-move constructor

        ~DefaultTaskGroup ();  // destructor
        
        // ====================  ALIASES       =======================================
        using baseclass = TaskGroup;
        using NeededIngredients = MPL::mpl_typelist<CommunicatorIngredientTraits::type>;

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        template <typename T>
        void addIngredient(T && ingredient);

        // ====================  OPERATORS     =======================================

        DefaultTaskGroup& operator= ( const DefaultTaskGroup &other )=delete; // assignment operator

        DefaultTaskGroup& operator= ( DefaultTaskGroup && other ); // assignment-move operator

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
        std::unique_ptr<COMMUNICATOR::Communicator> communicator_;
        ConsoleLoggerTraits::type consoleLogger_;

}; // -----  end of class DefaultTaskGroup  -----

template <>
void DefaultTaskGroup::addIngredient(CommunicatorIngredientTraits::type && ingredient);

}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_DefaultTaskGroup_INC  ----- */
