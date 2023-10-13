#ifndef ANANSI_ErrorKeyPathSeparator_INC
#define ANANSI_ErrorKeyPathSeparator_INC
//! \file ErrorKeyPathSeparator.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>
#include <array>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! \brief Error for key string containing the separator char.
class ErrorKeyPathSeparator : public std::exception
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorKeyPathSeparator ();   // constructor

        ErrorKeyPathSeparator ( const std::array<char,2> & sep_char, const std::string & path_key);   // constructor

        ErrorKeyPathSeparator (const ErrorKeyPathSeparator & other);   // copy constructor

        ErrorKeyPathSeparator (ErrorKeyPathSeparator && other);   // copy-move constructor

        ~ErrorKeyPathSeparator ();  // destructor

        // ====================  ACCESSORS     =======================================
        ErrorKeyPathSeparator * clone () const;

        const char* what() const noexcept override;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorKeyPathSeparator& operator= ( const ErrorKeyPathSeparator &other ); // assignment operator

        ErrorKeyPathSeparator& operator= ( ErrorKeyPathSeparator && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::array<char,2> sepChar_;
        std::string pathKey_;
        std::string errorMessage_;

}; // -----  end of class ErrorKeyPathSeparator  -----


}; // namespace ANANSI

#endif // ANANSI_ErrorKeyPathSeparator_INC
