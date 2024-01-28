#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! @file __filename__
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace __NAMESPACE__
{

// =====================================================================================
//        Class:  __classname__
//  Description:  
//  =====================================================================================
class __classname__ : public __derivedclass__
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  __classname__
        //      Method:  __classname__ :: __classname__
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        __classname__ ();   // constructor

        __classname__ (const __classname__ & other);   // copy constructor

        __classname__ (__classname__ && other);   // copy-move constructor

        virtual ~__classname__ ();  // destructor

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

}; // -----  end of class __classname__  -----


}; // namespace __NAMESPACE__

#endif // __filepreprocessordefine__
