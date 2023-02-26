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
//        Class:  CopyResult
//  Description:  
//  =====================================================================================
class CopyResult
{
    public:
        // ====================  LIFECYCLE     =======================================

        CopyResult ();   // constructor

        CopyResult (const CopyResult & other);   // copy constructor

        CopyResult (CopyResult && other);   // copy-move constructor

        ~CopyResult();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CopyResult& operator= ( const CopyResult &other ); // assignment operator

        CopyResult& operator= ( CopyResult && other ); // assignment-move operator

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

}; // -----  end of class CopyResult  -----


}; // namespace RECEIVER

#endif // RECEIVER_CopyResult_INC
