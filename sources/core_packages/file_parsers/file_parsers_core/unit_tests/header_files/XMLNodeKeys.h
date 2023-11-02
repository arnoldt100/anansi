#ifndef ANANSI_XMLNodeKeys_INC
#define ANANSI_XMLNodeKeys_INC
//! \file XMLNodeKeys.h
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

class XMLNodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        XMLNodeKeys ();   // constructor

        XMLNodeKeys (const XMLNodeKeys & other);   // copy constructor

        XMLNodeKeys (XMLNodeKeys && other);   // copy-move constructor

        ~XMLNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================
        XMLNodeKeys * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        XMLNodeKeys& operator= ( const XMLNodeKeys &other ); // assignment operator

        XMLNodeKeys& operator= ( XMLNodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class XMLNodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_XMLNodeKeys_INC
