#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! \file __classname__ResultsTraits.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace __NAMESPACE__
{

class __classname__ResultsTraits
{
    public:
        // ====================  ALIASES       =======================================
        //! C\todo  Fill in the result type.
        using result_t = ... ;

        // ====================  LIFECYCLE     =======================================

        __classname__ResultsTraits ();   // constructor

        __classname__ResultsTraits (const __classname__ResultsTraits & other);   // copy constructor

        __classname__ResultsTraits (__classname__ResultsTraits && other);   // copy-move constructor

        ~__classname__ResultsTraits ();  // destructor

        // ====================  ACCESSORS     =======================================
        __classname__ResultsTraits * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        __classname__ResultsTraits& operator= ( const __classname__ResultsTraits &other ); // assignment operator

        __classname__ResultsTraits& operator= ( __classname__ResultsTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class __classname__ResultsTraits  -----
}; // End of namespace ANANSI

#endif // ANANSI___classname__ResultsTraits_INC
