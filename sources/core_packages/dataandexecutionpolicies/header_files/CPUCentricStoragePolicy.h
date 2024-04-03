#ifndef ANANSI_CPUCentricStoragePolicy_INC
#define ANANSI_CPUCentricStoragePolicy_INC
//! \file CPUCentricStoragePolicy.h

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

class CPUCentricStoragePolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        CPUCentricStoragePolicy ();   // constructor

        //! The copy constructor.
        CPUCentricStoragePolicy (const CPUCentricStoragePolicy & other);   // copy constructor

        //! The move constructor.
        CPUCentricStoragePolicy (CPUCentricStoragePolicy && other);   // copy-move constructor

        ~CPUCentricStoragePolicy ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        CPUCentricStoragePolicy * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        CPUCentricStoragePolicy& operator= ( const CPUCentricStoragePolicy &other ); // assignment operator

        //! The move assignment operator.
        CPUCentricStoragePolicy& operator= ( CPUCentricStoragePolicy && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class CPUCentricStoragePolicy  -----


}; // End of namespace ANANSI

#endif // ANANSI_CPUCentricStoragePolicy_INC
