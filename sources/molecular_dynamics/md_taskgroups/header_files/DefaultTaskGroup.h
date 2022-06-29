#ifndef  ANANSI_DefaultTaskGroup_INC
#define  ANANSI_DefaultTaskGroup_INC


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

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

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
        void addCommunicator_() override;
        
        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class DefaultTaskGroup  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_DefaultTaskGroup_INC  ----- */
