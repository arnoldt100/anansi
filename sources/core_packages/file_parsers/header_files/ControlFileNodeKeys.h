#ifndef ANANSI_ControlFileNodeKeys_INC
#define ANANSI_ControlFileNodeKeys_INC
//! \file ControlFileNodeKeys.h
//!
//! \brief Brief description
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

class ControlFileNodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFileNodeKeys ();   // constructor

        ControlFileNodeKeys (const ControlFileNodeKeys & other);   // copy constructor

        ControlFileNodeKeys (ControlFileNodeKeys && other);   // copy-move constructor

        virtual ~ControlFileNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileNodeKeys& operator= ( const ControlFileNodeKeys &other ); // assignment operator

        ControlFileNodeKeys& operator= ( ControlFileNodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFileNodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_ControlFileNodeKeys_INC
