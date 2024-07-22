
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "VariableKeyFormatPolicy.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

VariableKeyFormatPolicy::VariableKeyFormatPolicy()
{
    return;
}

VariableKeyFormatPolicy::VariableKeyFormatPolicy( VariableKeyFormatPolicy const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

VariableKeyFormatPolicy::VariableKeyFormatPolicy( VariableKeyFormatPolicy && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method VariableKeyFormatPolicy::VariableKeyFormatPolicy  -----


VariableKeyFormatPolicy::~VariableKeyFormatPolicy()
{
    return;
}

//============================= ACCESSORS ====================================

VariableKeyFormatPolicy * VariableKeyFormatPolicy::clone() const
{
    return new VariableKeyFormatPolicy(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

VariableKeyFormatPolicy& VariableKeyFormatPolicy::operator= ( const VariableKeyFormatPolicy &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

VariableKeyFormatPolicy& VariableKeyFormatPolicy::operator= ( VariableKeyFormatPolicy && other )
{
    if (this != &other)
    {

    }
    return *this;
} // assignment-move operator

std::string VariableKeyFormatPolicy::operator()(const std::string & old_key, const std::vector<std::string> & key_frmt_args) const
{
    std::string new_key{old_key};
    return new_key;
}

std::string VariableKeyFormatPolicy::operator()(const std::string & old_key) const
{
    std::string new_key{old_key};
    return new_key;
}

//============================= STATIC    ====================================
std::string VariableKeyFormatPolicy::create_variable_internal_key(const std::string & internal_key,const std::vector<std::string> & key_frmt_args)
{
    return std::string{};
}

std::tuple<std::string,std::vector<std::string>> split_variable_internal_key(const std::string & internal_key)
{
    return std::tuple<std::string,std::vector<std::string>>{};
}

std::string create_external_xml_key(const std::string & variable_external_xml_key,const std::vector<std::string> & key_frmt_args)
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
