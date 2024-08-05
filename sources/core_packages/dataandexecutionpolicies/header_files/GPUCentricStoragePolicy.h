#ifndef ANANSI_GPUCentricStoragePolicy_INC
#define ANANSI_GPUCentricStoragePolicy_INC
//! \file GPUCentricStoragePolicy.h

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

class GPUCentricStoragePolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        GPUCentricStoragePolicy ();   // constructor

        //! The copy constructor.
        GPUCentricStoragePolicy (const GPUCentricStoragePolicy & other);   // copy constructor

        //! The move constructor.
        GPUCentricStoragePolicy (GPUCentricStoragePolicy && other);   // copy-move constructor

        ~GPUCentricStoragePolicy ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        GPUCentricStoragePolicy * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        GPUCentricStoragePolicy& operator= ( const GPUCentricStoragePolicy &other ); // assignment operator

        //! The move assignment operator.
        GPUCentricStoragePolicy& operator= ( GPUCentricStoragePolicy && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class GPUCentricStoragePolicy  -----


}; // End of namespace ANANSI

#endif // ANANSI_GPUCentricStoragePolicy_INC
