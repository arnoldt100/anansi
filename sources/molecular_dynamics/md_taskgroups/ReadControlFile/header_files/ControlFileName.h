#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! @file ControlFileName.h
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

// =====================================================================================
//        Class:  ControlFileName
//  Description:  
//  =====================================================================================
class ControlFileName
{
    public:
        // ====================  LIFECYCLE     =======================================
        ControlFileName ();   // constructor

        ControlFileName (const std::string file_name);   // constructor

        ~ControlFileName ();   // constructor

        ControlFileName (const ControlFileName & other);   // copy constructor

        ControlFileName (ControlFileName && other);   // copy-move constructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        std::string operator()() const ;

        ControlFileName& operator= ( const ControlFileName &other ); // assignment operator

        ControlFileName& operator= ( ControlFileName && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        std::string fileName_; 

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFileName  -----


}; // namespace ANANSI

#endif // __filepreprocessordefine__
