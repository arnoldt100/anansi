#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! \file __header_filename__
//!
//! \brief Brief description
//!
//! \details  Detailed description

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

class __classname__
{
    public:
        // ====================  ALIASES       =======================================
        //! \todo  Fill in the result type.
        using result_t = ... ;
        using copy_result_t = result_t;
        using share_result_t = result_t;
        using transfer_result_t = result_t;

        // ====================  LIFECYCLE     =======================================

        __classname__ ();   // constructor

        __classname__ (const __classname__ & other);   // copy constructor

        __classname__ (__classname__ && other);   // copy-move constructor

        ~__classname__ ();  // destructor

        // ====================  ACCESSORS     =======================================
        __classname__ * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        __classname__& operator= ( const __classname__ &other ); // assignment operator

        __classname__& operator= ( __classname__ && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----  End of class __classname__  -----
}; // ----- End of namespace __NAMESPACE__ -----

#endif // __filepreprocessordefine__
