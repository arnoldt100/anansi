#ifndef ANANSI_XMLFileWriter_INC
#define ANANSI_XMLFileWriter_INC
//! \file XMLFileWriter.h

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

class XMLFileWriter
{
    public:
        // ====================  LIFECYCLE     =======================================

        XMLFileWriter ();   // constructor

        XMLFileWriter (const XMLFileWriter & other);   // copy constructor

        XMLFileWriter (XMLFileWriter && other);   // copy-move constructor

        ~XMLFileWriter ();  // destructor

        // ====================  ACCESSORS     =======================================
        XMLFileWriter * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        XMLFileWriter& operator= ( const XMLFileWriter &other ); // assignment operator

        XMLFileWriter& operator= ( XMLFileWriter && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class XMLFileWriter  -----


}; // namespace ANANSI

#endif // ANANSI_XMLFileWriter_INC
