
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FilePicklerPropertyTreeMap.hpp"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

FilePickler<boost::property_tree::ptree,
            std::map<std::string,std::string>>::FilePickler()
{
    return;
}

FilePickler<boost::property_tree::ptree, 
            std::map<std::string,std::string>>::FilePickler( FilePickler const & other)
{
    if (this != &other)
    {
    }
    return;
}

FilePickler<boost::property_tree::ptree,
            std::map<std::string,std::string>>::FilePickler( FilePickler && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method FilePickler::FilePickler  -----


FilePickler<boost::property_tree::ptree,
            std::map<std::string,std::string>>::~FilePickler()
{
    return;
}

//============================= ACCESSORS ====================================

FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>> *
FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>>::clone() const
{
    return new FilePickler(*this);
}

boost::property_tree::ptree
FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>>::unPickle(const std::map<std::string,std::string> & a_map) const
{
    boost::property_tree::ptree tree;
    return tree;
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>>&
FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>>::operator= ( const FilePickler &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>>&
FilePickler<boost::property_tree::ptree, std::map<std::string,std::string>>::operator= ( FilePickler && other )
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
