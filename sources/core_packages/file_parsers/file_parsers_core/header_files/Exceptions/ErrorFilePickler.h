#ifndef ANANSI_ErrorFilePickler_INC
#define ANANSI_ErrorFilePickler_INC
//! \file ErrorFilePickler.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BaseException.h"

namespace ANANSI
{

class ErrorFilePickler : public MOUSEION::BaseException
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        ErrorFilePickler ();   // constructor
        
        explicit ErrorFilePickler (const std::string message);

        //! The copy constructor.
        ErrorFilePickler (const ErrorFilePickler & other);   // copy constructor

        //! The move constructor.
        ErrorFilePickler (ErrorFilePickler && other);   // copy-move constructor

        ~ErrorFilePickler ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        ErrorFilePickler * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        ErrorFilePickler& operator= ( const ErrorFilePickler &other ); // assignment operator

        //! The move assignment operator.
        ErrorFilePickler& operator= ( ErrorFilePickler && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;

}; // -----  End of class ErrorFilePickler  -----


}; // End of namespace ANANSI

#endif // ANANSI_ErrorFilePickler_INC
