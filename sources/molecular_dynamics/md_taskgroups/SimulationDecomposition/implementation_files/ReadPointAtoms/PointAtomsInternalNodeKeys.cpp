
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

std::string PointAtomsInternalNodeKeys::getInternalNodeKey(const std::string_view global_key) const
{
    std::string tkey(global_key.data(),global_key.size());
    return this->myKeys_.at(tkey);
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
    this->myKeys_["Region_Name"] = "Region_Name";
    this->myKeys_["Coordinate_System"] = "Coordinate_System";
    this->myKeys_["Number_Atoms_In_File"] = "Total_Number_of_Atoms";
}

//============================= OPERATORS ====================================


} // namespace ANANSI
