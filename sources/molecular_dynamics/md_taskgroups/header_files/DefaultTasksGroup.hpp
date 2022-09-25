#ifndef  ANANSI_DefaultTasksGroup_INC
#define  ANANSI_DefaultTasksGroup_INC

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
#include "TasksGroup.hpp"
#include "MPLAliases.hpp"
#include "CommunicatorIngredientTraits.h"
#include "ConsoleLoggerTraits.h"

namespace ANANSI
{

class DefaultTasksGroup final : public TasksGroup<DefaultTasksGroup>
{
    public:
        // ====================  LIFECYCLE     =======================================

        DefaultTasksGroup ();   // constructor

        DefaultTasksGroup (const DefaultTasksGroup & other)=delete;   // copy constructor

        DefaultTasksGroup (DefaultTasksGroup && other);   // copy-move constructor

        ~DefaultTasksGroup ();  // destructor
        
        // ====================  ALIASES       =======================================
        using baseclass = TasksGroup;
        using NeededIngredients = MPL::mpl_typelist<CommunicatorIngredientTraits::type>;

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DefaultTasksGroup& operator= ( const DefaultTasksGroup &other )=delete; // assignment operator

        DefaultTasksGroup& operator= ( DefaultTasksGroup && other ); // assignment-move operator

        // ====================  STATIC METHODS ======================================

        // ====================  DATA MEMBERS  =======================================

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  MUTATORS      =======================================

        void enable_();

        void disable_();

        // ====================  DATA MEMBERS  =======================================
        CommunicatorIngredientTraits::type communicator_;
        ConsoleLoggerTraits::type consoleLogger_;

}; // -----  end of class DefaultTasksGroup  -----

}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_DefaultTasksGroup_INC  ----- */
