//! \file InternalNodeKeys.h
//!
//! \brief Brief description
//!
//! \details Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "InternalNodeKeys.h"

namespace ANANSI
{
//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

InternalNodeKeys::InternalNodeKeys()
{
   return;
};

InternalNodeKeys::InternalNodeKeys(const InternalNodeKeys & other)
{
   if (this != &other)
   {
       this->valuePtr_ = other.valuePtr_->clone();
   }
   return;
}

InternalNodeKeys::InternalNodeKeys(InternalNodeKeys && other)
{
   if (this != &other)
   {
       this->valuePtr_ = std::move(other.valuePtr_); 
   }
   return;
}

InternalNodeKeys::~InternalNodeKeys()
{
    return;
}

InternalNodeKeys::InternalNodeKeysConcept::~InternalNodeKeysConcept()
{
    return;
}

//============================= ACCESSORS ====================================

InternalNodeKeys * InternalNodeKeys::clone() const
{
    return new InternalNodeKeys(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

InternalNodeKeys& InternalNodeKeys::operator= ( const InternalNodeKeys & other )
{
    if (this != &other)
    {
        this->valuePtr_  = other.valuePtr_->clone();
    }
    return *this;
} // assignment operator

InternalNodeKeys& InternalNodeKeys::operator= ( InternalNodeKeys && other )
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

};
