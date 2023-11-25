
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "XMLReaderFixture.h"
#include "PathToDataFilesFileParserCore.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

XMLReaderFixture::XMLReaderFixture() :
    xmlFileReader()
{
    return;
}

XMLReaderFixture::XMLReaderFixture( XMLReaderFixture const & other) :
    xmlFileReader()
{
    if (this != &other)
    {
        this->xmlFileReader = other.xmlFileReader;
    }
    return;
}

XMLReaderFixture::XMLReaderFixture( XMLReaderFixture && other)
{
    if (this != &other)
    {
        this->xmlFileReader = std::move(other.xmlFileReader);
    }
    return;
}   // -----  end of method XMLReaderFixture::XMLReaderFixture  -----


XMLReaderFixture::~XMLReaderFixture()
{
    return;
}

//============================= ACCESSORS ====================================

XMLReaderFixture * XMLReaderFixture::clone() const
{
    return new XMLReaderFixture(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

XMLReaderFixture& XMLReaderFixture::operator= ( const XMLReaderFixture &other )
{
    if (this != &other)
    {
        this->xmlFileReader = other.xmlFileReader;
    }
    return *this;
} // assignment operator

XMLReaderFixture& XMLReaderFixture::operator= ( XMLReaderFixture && other )
{
    if (this != &other)
    {
        this->xmlFileReader = std::move(other.xmlFileReader);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================
boost::property_tree::ptree XMLReaderFixture::getPropertyTree() const
{
    std::string path = ANANSI::PathToDataFilesFileParserCore::pathToXMLControlFile();
    return this->xmlFileReader.read(path);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
