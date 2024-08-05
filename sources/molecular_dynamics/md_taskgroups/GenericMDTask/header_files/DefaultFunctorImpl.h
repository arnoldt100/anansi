#ifndef  ANANSI_DefaultFunctorImpl_INC
#define  ANANSI_DefaultFunctorImpl_INC

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
class DefaultFunctorImpl 
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

#endif   // ----- #ifndef ANANSI_DefaultFunctorImpl_INC  ----- 
