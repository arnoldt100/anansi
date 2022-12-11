#ifndef ANANSI_STRINGLITERAL_FIXTURES_INC
#define ANANSI_STRINGLITERAL_FIXTURES_INC

//! @file stringliteral_fixtures.h
//!
//! Provides test case for the StringLiteral tests.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "StringLiteral.hpp"

namespace ANANSI
{

// =====================================================================================
//        Class:  StringLiteralTestFixture
//  Description:  
//  =====================================================================================
class StringLiteralTestFixture
{
    public:
        constexpr static std::size_t MY_SIZE = 100;
        constexpr static char LETTER_A[MY_SIZE]  = {"A"};
        constexpr static char LETTER_B[MY_SIZE]  = {"B"};

        // ====================  LIFECYCLE     =======================================

        StringLiteralTestFixture ();   // constructor

        ~StringLiteralTestFixture ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        // ====================  DATA MEMBERS  =======================================
        STRINGLITERAL::StringLiteral<MY_SIZE> a;
        STRINGLITERAL::StringLiteral<MY_SIZE> b;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class StringLiteralTestFixture  -----


}; // namespace ANANSI

#endif // ANANSI_STRINGLITERAL_FIXTURES_INC
