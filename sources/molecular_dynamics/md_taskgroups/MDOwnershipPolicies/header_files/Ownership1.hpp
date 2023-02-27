#ifndef RECEIVER_CopyResult_INC
#define RECEIVER_CopyResult_INC
//! @file __filename__
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

namespace RECEIVER
{

// =====================================================================================
//        Class:  Ownership1
//  Description:  
//  =====================================================================================
class Ownership1
{
    public:
        // ====================  LIFECYCLE     =======================================

        Ownership1 ();   // constructor

        Ownership1 (const Ownership1 & other);   // copy constructor

        Ownership1 (Ownership1 && other);   // copy-move constructor

        ~Ownership1();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        Ownership1& operator= ( const Ownership1 &other ); // assignment operator

        Ownership1& operator= ( Ownership1 && other ); // assignment-move operator

        template <typename UnderLyingType,typename ResultType,typename CopiedType>
        CopiedType operator( )(ResultType const & result)
        {
            UnderLyingType* tmp_obj = new UnderLyingType(*result);
            CopiedType obj(tmp_obj);
            return obj; 
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class Ownership1  -----


}; // namespace RECEIVER

#endif // RECEIVER_CopyResult_INC
