#ifndef  ANANSI_CommunicatorTask_INC
#define  ANANSI_CommunicatorTask_INC

//! @file CommunicatorTask.h
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiTask.h"

namespace ANANSI
{

class CommunicatorTask : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        CommunicatorTask ();   // constructor

        CommunicatorTask (const CommunicatorTask & other);   // copy constructor

        CommunicatorTask (CommunicatorTask && other);   // copy-move constructor

        virtual ~CommunicatorTask ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CommunicatorTask& operator= ( const CommunicatorTask &other ); // assignment operator

        CommunicatorTask& operator= ( CommunicatorTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class CommunicatorTask  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_CommunicatorTask_INC  ----- 
