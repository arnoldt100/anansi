#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! @file DefaultFunctorImpl.h
//!
//! Brief description
//!
//! Detailed description

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

// =====================================================================================
//        Class:  DefaultFunctorImpl
//  Description:  
//  =====================================================================================
class DefaultFunctorImpl final
{
    public:
        // ====================  LIFECYCLE     =======================================
        using ResultType = void;

        DefaultFunctorImpl ();   // constructor

        DefaultFunctorImpl (const DefaultFunctorImpl & other);   // copy constructor

        DefaultFunctorImpl (DefaultFunctorImpl && other);   // copy-move constructor

        ~DefaultFunctorImpl ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DefaultFunctorImpl& operator= ( const DefaultFunctorImpl &other ); // assignment operator

        DefaultFunctorImpl& operator= ( DefaultFunctorImpl && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class DefaultFunctorImpl  -----


}; // namespace ANANSI

#endif // __filepreprocessordefine__
