
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorFilePickler.h"
#include "GenericErrorClass.hpp"
#include "NullFilePicklerPropertyTreeMap.hpp"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================
NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>::NullFilePickler()   // constructor
{
    return;
}

NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>::NullFilePickler(NullFilePickler const & other)
{
    if (this != &other)
    {
    }
    return;
}

NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>::NullFilePickler( NullFilePickler && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method NullFilePicklerPropertyTreeMap::NullFilePicklerPropertyTreeMap  -----


NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>::~NullFilePickler()
{
    return;
}

//============================= ACCESSORS ====================================

NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>> * NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>::clone() const
{
    return new NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>(*this);
}

template<typename MasterKeyPolicy_t>
std::map<std::string,std::string> 
NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>::pickle(const boost::property_tree::ptree & tree) const
{
    std::string err_message;  
    err_message = "A NullFilePickler is being invoked to do a pickle.\n";
    err_message += "This is contradictory and could lead to an undefined result.\n";
    throw ErrorFilePickler(err_message);
    return std::map<std::string,std::string>{}; 
}

template<typename MasterKeyPolicy_t>
boost::property_tree::ptree 
NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>::unpickle(const std::map<std::string,std::string>& a_map) const
{
    std::string err_message;  
    err_message = "A NullFilePickler is being invoked to do an upickle.\n";
    err_message += "This is contradictory and could lead to an undefined result.\n";
    throw ErrorFilePickler(err_message);
    return boost::property_tree::ptree{};
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>& 
NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>::operator=( const NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>> &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>& 
NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>>::operator=( NullFilePickler<boost::property_tree::ptree,std::map<std::string,std::string>> && other )
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
