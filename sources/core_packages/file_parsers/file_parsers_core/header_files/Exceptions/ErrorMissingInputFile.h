#ifndef ANANSI_ErrorMissingInputFile_INC
#define ANANSI_ErrorMissingInputFile_INC
//! \file ErrorMissingInputFile.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BaseException.h"

namespace ANANSI
{

class ErrorMissingInputFile : public MOUSEION::BaseException
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        ErrorMissingInputFile ();   // constructor

        explicit ErrorMissingInputFile(const std::string message);

        //! The copy constructor.
        ErrorMissingInputFile (const ErrorMissingInputFile & other);   // copy constructor

        //! The move constructor.
        ErrorMissingInputFile (ErrorMissingInputFile && other);   // copy-move constructor

        ~ErrorMissingInputFile ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        ErrorMissingInputFile * clone () const;

        const char* what() const noexcept override;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        ErrorMissingInputFile& operator= ( const ErrorMissingInputFile &other ); // assignment operator

        //! The move assignment operator.
        ErrorMissingInputFile& operator= ( ErrorMissingInputFile && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;

}; // -----  End of class ErrorMissingInputFile  -----


}; // End of namespace ANANSI

#endif // ANANSI_ErrorMissingInputFile_INC
