#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! \file __header_filename__
//!
//! \brief Brief description
//!
//! \details Detailed description

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
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        __classname__ ();   // constructor

        //! The copy constructor.
        __classname__ (const __classname__ & other);   // copy constructor

        //! The move constructor.
        __classname__ (__classname__ && other);   // copy-move constructor

        virtual ~__classname__ ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        __classname__ * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        __classname__& operator= ( const __classname__ &other ); // assignment operator

        //! The move assignment operator.
        __classname__& operator= ( __classname__ && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class __classname__  -----


}; // End of namespace __NAMESPACE__

#endif // __filepreprocessordefine__
