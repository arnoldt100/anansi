
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
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


NullFilePicklerPropertyTreeMap<boost::property_tree::ptree,std::map<std::string,std::string>>::~NullFilePicklerPropertyTreeMap()
{
    return;
}

//============================= ACCESSORS ====================================

NullFilePicklerPropertyTreeMap * NullFilePicklerPropertyTreeMap::clone() const
{
    return new NullFilePicklerPropertyTreeMap(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

NullFilePicklerPropertyTreeMap& NullFilePicklerPropertyTreeMap::operator= ( const NullFilePicklerPropertyTreeMap &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

NullFilePicklerPropertyTreeMap& NullFilePicklerPropertyTreeMap::operator= ( NullFilePicklerPropertyTreeMap && other )
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
