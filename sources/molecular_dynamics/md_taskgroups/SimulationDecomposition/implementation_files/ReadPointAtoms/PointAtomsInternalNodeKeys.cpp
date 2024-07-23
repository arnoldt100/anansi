
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PointAtomsInternalNodeKeys.h"
#include "VariableXMLKeyFormatPolicy.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PointAtomsInternalNodeKeys::PointAtomsInternalNodeKeys() :
    myKeys_{}
{
    this->setAllKeys_();
    return;
}

PointAtomsInternalNodeKeys::PointAtomsInternalNodeKeys( PointAtomsInternalNodeKeys const & other) :
    myKeys_{other.myKeys_}
{
    if (this != &other)
    {
        
    }
    return;
}

PointAtomsInternalNodeKeys::PointAtomsInternalNodeKeys( PointAtomsInternalNodeKeys && other) :
    myKeys_{std::move(other.myKeys_)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method PointAtomsInternalNodeKeys::PointAtomsInternalNodeKeys  -----


PointAtomsInternalNodeKeys::~PointAtomsInternalNodeKeys()
{
    return;
}

//============================= ACCESSORS ====================================

PointAtomsInternalNodeKeys * PointAtomsInternalNodeKeys::clone() const
{
    return new PointAtomsInternalNodeKeys(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PointAtomsInternalNodeKeys& PointAtomsInternalNodeKeys::operator= ( const PointAtomsInternalNodeKeys &other )
{
    if (this != &other)
    {
        this->myKeys_ = other.myKeys_;
    }
    return *this;
} // assignment operator

PointAtomsInternalNodeKeys& PointAtomsInternalNodeKeys::operator= ( PointAtomsInternalNodeKeys && other )
{
    if (this != &other)
    {
        this->myKeys_ = std::move(other.myKeys_);
    }
    return *this;
} // assignment-move operator

std::string PointAtomsInternalNodeKeys::getInternalNodeKey(const std::string_view & global_key,
                                                           const std::vector<std::string> & key_frmt_args) const
{
    std::string key_value;
    if (key_frmt_args.empty())
    {
        std::string tkey(global_key.data(),global_key.size());
        key_value =  this->myKeys_.at(tkey);
    }
    else
    {
        std::string tkey(global_key.data(),global_key.size());
        VariableXMLKeyFormatPolicy my_key_frmt_policy{};
        key_value = my_key_frmt_policy(tkey,key_frmt_args);
    }
    return key_value;
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
void PointAtomsInternalNodeKeys::setAllKeys_()
{
    this->myKeys_[std::string(PointAtomsInternalNodeKeys::Region_Name)] = std::string(PointAtomsInternalNodeKeys::Region_Name);
    this->myKeys_[std::string(PointAtomsInternalNodeKeys::Coordinate_System)] = std::string(PointAtomsInternalNodeKeys::Coordinate_System);
    this->myKeys_[std::string(PointAtomsInternalNodeKeys::Number_Atoms_In_File)] = std::string(PointAtomsInternalNodeKeys::Number_Atoms_In_File);
}

//============================= OPERATORS ====================================


} // namespace ANANSI
