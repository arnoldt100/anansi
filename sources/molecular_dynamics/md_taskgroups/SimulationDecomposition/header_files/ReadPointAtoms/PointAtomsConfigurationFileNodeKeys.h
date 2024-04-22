#ifndef ANANSI_PointAtomsConfigurationFileNodeKeys_INC
#define ANANSI_PointAtomsConfigurationFileNodeKeys_INC
//! \file PointAtomsConfigurationFileNodeKeys.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PointAtoms.h"

namespace ANANSI
{

class PointAtomsConfigurationFileNodeKeys
{
    public:
        using InternalRepresentationTrait = PointAtoms;

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        PointAtomsConfigurationFileNodeKeys ();   // constructor

        //! The copy constructor.
        PointAtomsConfigurationFileNodeKeys (const PointAtomsConfigurationFileNodeKeys & other);   // copy constructor

        //! The move constructor.
        PointAtomsConfigurationFileNodeKeys (PointAtomsConfigurationFileNodeKeys && other);   // copy-move constructor

        ~PointAtomsConfigurationFileNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        PointAtomsConfigurationFileNodeKeys * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        PointAtomsConfigurationFileNodeKeys& operator= ( const PointAtomsConfigurationFileNodeKeys &other ); // assignment operator

        //! The move assignment operator.
        PointAtomsConfigurationFileNodeKeys& operator= ( PointAtomsConfigurationFileNodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class PointAtomsConfigurationFileNodeKeys  -----


}; // End of namespace ANANSI

#endif // ANANSI_PointAtomsConfigurationFileNodeKeys_INC
