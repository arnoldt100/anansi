#ifndef ANANSI_XMLFileReader_INC
#define ANANSI_XMLFileReader_INC
//! \file XMLFileReader.h
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

class XMLFileReader
{
    public:
        // ====================  LIFECYCLE     =======================================

        XMLFileReader ();   // constructor

        XMLFileReader (const XMLFileReader & other);   // copy constructor

        XMLFileReader (XMLFileReader && other);   // copy-move constructor

        ~XMLFileReader ();  // destructor

        // ====================  ACCESSORS     =======================================
        XMLFileReader * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        XMLFileReader& operator= ( const XMLFileReader &other ); // assignment operator

        XMLFileReader& operator= ( XMLFileReader && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class XMLFileReader  -----


}; // namespace ANANSI

#endif // ANANSI_XMLFileReader_INC
