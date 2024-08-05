#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! \file __header_filename__
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

namespace __NAMESPACE__
{

class __classname__ : public AnansiTask
{
    public:
        // ====================  LIFECYCLE     =======================================

        __classname__ ();   // constructor

        __classname__ (const __classname__ & other);   // copy constructor

        __classname__ (__classname__ && other);   // copy-move constructor

        virtual ~__classname__ ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        __classname__& operator= ( const __classname__ &other ); // assignment operator

        __classname__& operator= ( __classname__ && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----- End of class __classname__  -----
}; // ----- End of namespace __NAMESPACE__ -----
#endif // __filepreprocessordefine__
