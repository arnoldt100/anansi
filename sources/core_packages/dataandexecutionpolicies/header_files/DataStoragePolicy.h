#ifndef ANANSI_DataStoragePolicy_INC
#define ANANSI_DataStoragePolicy_INC
//! \file DataStoragePolicy.h
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

namespace ANANSI
{

class DataStoragePolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        DataStoragePolicy ();   // constructor

        //! The copy constructor.
        DataStoragePolicy (const DataStoragePolicy & other);   // copy constructor

        //! The move constructor.
        DataStoragePolicy (DataStoragePolicy && other);   // copy-move constructor

        ~DataStoragePolicy ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        DataStoragePolicy * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        DataStoragePolicy& operator= ( const DataStoragePolicy &other ); // assignment operator

        //! The move assignment operator.
        DataStoragePolicy& operator= ( DataStoragePolicy && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class DataStoragePolicy  -----


}; // End of namespace ANANSI

#endif // ANANSI_DataStoragePolicy_INC
