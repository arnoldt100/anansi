
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <regex>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "VariableXMLKeyFormatPolicy.h"
#include "XMLKeyPathFormatSymbol.h"
#include "split_string_by_delimiter.h"

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

std::tuple<std::string,std::vector<std::string>> VariableXMLKeyFormatPolicy::split_variable_internal_xml_key(const std::string & frmt_internal_xml_key)
{
    std::string delimiter(XMLKeyPathFormatSymbol::format_symbol);
    std::vector<std::string> words = STRING_UTILITIES::split_string_by_delimiter(frmt_internal_xml_key,delimiter);
    std::string internal_xml_key = *(words.begin());
    auto fargs = [my_words=words](){
        std::vector<std::string> args;
        for (auto iter = my_words.begin(); iter != my_words.end(); ++iter)
        {
            if (iter != my_words.begin())
            {
                args.push_back(*iter);
            }
        }
        return args;
    };
    std::vector<std::string> frmt_args = fargs(); 
    return {internal_xml_key,frmt_args};
}

std::string VariableXMLKeyFormatPolicy::create_external_xml_key(const std::string & external_xml_key,const std::vector<std::string> & key_frmt_args)
{
    std::string ret_value(external_xml_key);
    if (! key_frmt_args.empty())
    {
        auto counter = 0;
        for (auto iter = key_frmt_args.begin(); iter != key_frmt_args.end(); ++iter)
        {
            // For the 0'th iteration
            // we replacing the character sequence '<1>' with the valuie of *iter  with respect to the string
            // external_xml_key. This replacement pattern is repeated for subsequent iterations.
            ++counter;
            std::string pattern = "<" + std::to_string(counter) + ">";
            auto regex_pattern = std::regex(pattern);
            ret_value = std::regex_replace(ret_value,regex_pattern,*iter);
        }
    }
    return ret_value;
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
