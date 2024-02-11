
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PhysicalDataStructure.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PhysicalDataStructure::PhysicalDataStructure() :
    valuePtr_(nullptr)
{
    return;
}

PhysicalDataStructure::PhysicalDataStructure( PhysicalDataStructure const & other)
{
    if (this != &other)
    {
        this->valuePtr_ = other.valuePtr_->clone();
    }
    return;
}

PhysicalDataStructure::PhysicalDataStructure( PhysicalDataStructure && other)
{
    if (this != &other)
    {
        this->valuePtr_ = std::move(other.valuePtr_); 
    }
    return;
}		// -----  end of method PhysicalDataStructure::PhysicalDataStructure  -----


PhysicalDataStructure::~PhysicalDataStructure()
{
    return;
}

PhysicalDataStructure::PhysicalDataStructureConcept::~PhysicalDataStructureConcept()
{
    return;
}


//============================= ACCESSORS ====================================

PhysicalDataStructure * PhysicalDataStructure::clone() const
{
    return new PhysicalDataStructure(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PhysicalDataStructure& PhysicalDataStructure::operator= ( const PhysicalDataStructure & other )
{
    if (this != &other)
    {
        this->valuePtr_  = other.valuePtr_->clone();
    }
    return *this;
} // assignment operator

PhysicalDataStructure& PhysicalDataStructure::operator= ( PhysicalDataStructure && other )
{
    if (this != &other)
    {
        this->valuePtr_ = std::move(other.valuePtr_);
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


}; // namespace ANANSI
