#ifndef ANANSI_PointAtomsInternalNodeKeys_INC
#define ANANSI_PointAtomsInternalNodeKeys_INC
//! \file PointAtomsInternalNodeKeys.h
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

class PointAtomsInternalNodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        PointAtomsInternalNodeKeys ();   // constructor

        //! The copy constructor.
        PointAtomsInternalNodeKeys (const PointAtomsInternalNodeKeys & other);   // copy constructor

        //! The move constructor.
        PointAtomsInternalNodeKeys (PointAtomsInternalNodeKeys && other);   // copy-move constructor

        ~PointAtomsInternalNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        PointAtomsInternalNodeKeys * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        PointAtomsInternalNodeKeys& operator= ( const PointAtomsInternalNodeKeys &other ); // assignment operator

        //! The move assignment operator.
        PointAtomsInternalNodeKeys& operator= ( PointAtomsInternalNodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class PointAtomsInternalNodeKeys  -----


}; // End of namespace ANANSI

#endif // ANANSI_PointAtomsInternalNodeKeys_INC
