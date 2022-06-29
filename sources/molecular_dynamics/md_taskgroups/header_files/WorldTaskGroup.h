#ifndef  ANANSI_WorldTaskGroup_INC
#define  ANANSI_WorldTaskGroup_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskGroup.h"
#include "BaseVisitable.hpp"

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

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        // This macro defines the Accept member function.
        DEFINE_VISITABLE()

        void addCommandLineArguments();

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
        void addCommunicator_() override;

        void addLogger_() override;
        
        // ====================  DATA MEMBERS  =======================================



}; // -----  end of class WorldTaskGroup  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_WorldTaskGroup_INC  ----- */
