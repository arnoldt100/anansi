#ifndef  ANANSI_ControlFile_INC
#define  ANANSI_ControlFile_INC

//! @file ControlFile.h
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

class ControlFile : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFile ();   // constructor

        ControlFile (const ControlFile & other);   // copy constructor

        ControlFile (ControlFile && other);   // copy-move constructor

        virtual ~ControlFile ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFile& operator= ( const ControlFile &other ); // assignment operator

        ControlFile& operator= ( ControlFile && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFile  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFile_INC  ----- 
