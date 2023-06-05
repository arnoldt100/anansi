#ifndef  ANANSI_ControlFileTask_INC
#define  ANANSI_ControlFileTask_INC

//! @file ControlFileTask.h
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

class ControlFileTask : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFileTask ();   // constructor

        ControlFileTask (const ControlFileTask & other);   // copy constructor

        ControlFileTask (ControlFileTask && other);   // copy-move constructor

        virtual ~ControlFileTask ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileTask& operator= ( const ControlFileTask &other ); // assignment operator

        ControlFileTask& operator= ( ControlFileTask && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFileTask  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileTask_INC  ----- 
