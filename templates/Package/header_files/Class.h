#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__

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

// =====================================================================================
//        Class:  __classname__
//  Description:  
//  =====================================================================================
class __classname__
{
    public:
        // ====================  LIFECYCLE     =======================================

        __classname__ ();   // constructor

        __classname__ (const __classname__ & other);   // copy constructor

        __classname__ (__classname__ && other);   // copy-move constructor

        virtual ~__classname__ ();  // destructor

        // ====================  ACCESSORS     =======================================

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
