#ifndef ANANSI_XMLReaderFixture_INC
#define ANANSI_XMLReaderFixture_INC
//! \file XMLReaderFixture.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "XMLFileReader.h"

namespace ANANSI
{

class XMLReaderFixture
{
    public:
        // ====================  LIFECYCLE     =======================================

        XMLReaderFixture ();   // constructor

        XMLReaderFixture (const XMLReaderFixture & other);   // copy constructor

        XMLReaderFixture (XMLReaderFixture && other);   // copy-move constructor

        ~XMLReaderFixture ();  // destructor

        // ====================  ACCESSORS     =======================================
        XMLReaderFixture * clone () const;

        boost::property_tree::ptree getPropertyTree() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        XMLReaderFixture& operator= ( const XMLReaderFixture &other ); // assignment operator

        XMLReaderFixture& operator= ( XMLReaderFixture && other ); // assignment-move operator

        // ====================  DATA MEMBERS  =======================================
        XMLFileReader xmlFileReader;
        
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class XMLReaderFixture  -----


}; // namespace ANANSI

#endif // ANANSI_XMLReaderFixture_INC
