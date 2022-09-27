#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! @file MDAnansiTaskFactory.h
//!
//! This files implements the Anansi task factory. The factory
//! use the object factory design pattern.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ConsoleLoggingTask.h"
#include "MPLAliases.hpp"
#include "AbstractFactory.hpp"
#include "ConcreteFactory.hpp"

namespace ANANSI
{

class MDAnansiTaskFactory final
{
    public:
        // ====================  LIFECYCLE     =======================================

        MDAnansiTaskFactory ();   // constructor

        MDAnansiTaskFactory (const MDAnansiTaskFactory & other);   // copy constructor

        MDAnansiTaskFactory (MDAnansiTaskFactory && other);   // copy-move constructor

        ~MDAnansiTaskFactory ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDAnansiTaskFactory& operator= ( const MDAnansiTaskFactory &other ); // assignment operator

        MDAnansiTaskFactory& operator= ( MDAnansiTaskFactory && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MDAnansiTaskFactory  -----


}; // namespace ANANSI

#endif // __filepreprocessordefine__
