#ifndef ANANSI_KeyPathSeparatorPeriod_INC
#define ANANSI_KeyPathSeparatorPeriod_INC
//! \file KeyPathSeparatorPeriod.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <array>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class KeyPathSeparatorPeriod
{
    public:
       
        // ====================  STATIC        =======================================

        static constexpr std::array<char,2> separator_char = {"."};

        // ====================  LIFECYCLE     =======================================

        KeyPathSeparatorPeriod ();   // constructor

        KeyPathSeparatorPeriod (const KeyPathSeparatorPeriod & other);   // copy constructor

        KeyPathSeparatorPeriod (KeyPathSeparatorPeriod && other);   // copy-move constructor

        ~KeyPathSeparatorPeriod ();  // destructor

        // ====================  ACCESSORS     =======================================
        KeyPathSeparatorPeriod * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        KeyPathSeparatorPeriod& operator= ( const KeyPathSeparatorPeriod &other ); // assignment operator

        KeyPathSeparatorPeriod& operator= ( KeyPathSeparatorPeriod && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class KeyPathSeparatorPeriod  -----


}; // namespace ANANSI

#endif // ANANSI_KeyPathSeparatorPeriod_INC
