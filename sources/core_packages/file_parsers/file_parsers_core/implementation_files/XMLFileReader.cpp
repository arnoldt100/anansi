
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "XMLFileReader.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

XMLFileReader::XMLFileReader()
{
    return;
}

XMLFileReader::XMLFileReader( XMLFileReader const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

XMLFileReader::XMLFileReader( XMLFileReader && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method XMLFileReader::XMLFileReader  -----


XMLFileReader::~XMLFileReader()
{
    return;
}

//============================= ACCESSORS ====================================

XMLFileReader * XMLFileReader::clone() const
{
    return new XMLFileReader(*this);
}

boost::property_tree::ptree XMLFileReader::read(const std::string filename) const
{ 
    boost::property_tree::ptree tree;
    boost::property_tree::read_xml(filename, tree);
    return tree;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

XMLFileReader& XMLFileReader::operator= ( const XMLFileReader &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

XMLFileReader& XMLFileReader::operator= ( XMLFileReader && other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

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
