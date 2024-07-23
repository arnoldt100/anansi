
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "VariableXMLKeyFormatPolicy.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

VariableXMLKeyFormatPolicy::VariableXMLKeyFormatPolicy()
{
    return;
}

VariableXMLKeyFormatPolicy::VariableXMLKeyFormatPolicy( VariableXMLKeyFormatPolicy const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

VariableXMLKeyFormatPolicy::VariableXMLKeyFormatPolicy( VariableXMLKeyFormatPolicy && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method VariableXMLKeyFormatPolicy::VariableXMLKeyFormatPolicy  -----


VariableXMLKeyFormatPolicy::~VariableXMLKeyFormatPolicy()
{
    return;
}

//============================= ACCESSORS ====================================

VariableXMLKeyFormatPolicy * VariableXMLKeyFormatPolicy::clone() const
{
    return new VariableXMLKeyFormatPolicy(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

VariableXMLKeyFormatPolicy& VariableXMLKeyFormatPolicy::operator= ( const VariableXMLKeyFormatPolicy &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

VariableXMLKeyFormatPolicy& VariableXMLKeyFormatPolicy::operator= ( VariableXMLKeyFormatPolicy && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

std::string VariableXMLKeyFormatPolicy::operator()(const std::string & old_key, const std::vector<std::string> & key_frmt_args) const
{
    std::string new_key{old_key};
    return new_key;
}

std::string VariableXMLKeyFormatPolicy::operator()(const std::string & old_key) const
{
    std::string new_key{old_key};
    return new_key;
}

//============================= STATIC    ====================================
std::string VariableXMLKeyFormatPolicy::create_variable_internal_xml_key(const std::string & internal_key,const std::vector<std::string> & key_frmt_args)
{
    std::string ret_value(internal_key);
    for(auto var : key_frmt_args)
    {
        ret_value += "%";
        ret_value += var;
    } 
    return ret_value;
}

std::tuple<std::string,std::vector<std::string>> VariableXMLKeyFormatPolicy::split_variable_internal_xml_key(const std::string & internal_key)
{
    return std::tuple<std::string,std::vector<std::string>>{};
}

std::string VariableXMLKeyFormatPolicy::create_external_xml_key(const std::string & variable_external_xml_key,const std::vector<std::string> & key_frmt_args)
{
    return std::string{};
}
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
