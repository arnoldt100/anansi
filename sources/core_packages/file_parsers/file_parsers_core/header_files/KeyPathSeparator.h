#ifndef ANANSI_KeyPathSeparator_INC
#define ANANSI_KeyPathSeparator_INC
//! \file KeyPathSeparator.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class KeyPathSeparator
{
    public:
        // ====================  LIFECYCLE     =======================================

        KeyPathSeparator ();  // Constructor

        KeyPathSeparator (const KeyPathSeparator & other);   // Copy constructor

        KeyPathSeparator (KeyPathSeparator && other);   // Copy-move constructor

        ~KeyPathSeparator ();  // Destructor

        // ====================  ACCESSORS     =======================================
        KeyPathSeparator * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        KeyPathSeparator& operator= ( const KeyPathSeparator &other ); // Assignment operator

        KeyPathSeparator& operator= ( KeyPathSeparator && other ); // Assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  STATIC        =======================================
        static constexpr char separator_char[] = ".";

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class KeyPathSeparator  -----


}; // namespace ANANSI

#endif // ANANSI_KeyPathSeparator_INC
