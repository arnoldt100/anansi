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

        KeyPathSeparator ();   // constructor

        KeyPathSeparator (const KeyPathSeparator & other);   // copy constructor

        KeyPathSeparator (KeyPathSeparator && other);   // copy-move constructor

        ~KeyPathSeparator ();  // destructor

        // ====================  ACCESSORS     =======================================
        KeyPathSeparator * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        KeyPathSeparator& operator= ( const KeyPathSeparator &other ); // assignment operator

        KeyPathSeparator& operator= ( KeyPathSeparator && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class KeyPathSeparator  -----


}; // namespace ANANSI

#endif // ANANSI_KeyPathSeparator_INC
