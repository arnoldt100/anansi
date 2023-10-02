#ifndef ANANSI_XMLFileWriter_INC
#define ANANSI_XMLFileWriter_INC
//! \file XMLFileWriter.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ptree.hpp>

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

        //! \brief Writes a Boost::property_tree::ptree in XML format to a file.
        //!
        //! tree[in] The Boost propert tree that is written.
        //! filename[in] The file to write the Boost::property_tree.
        void write( const boost::property_tree::ptree & tree, const std::string filename) const;

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
