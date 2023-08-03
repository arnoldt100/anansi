
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFileNodeKeys.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileNodeKeys::ControlFileNodeKeys() :
    nodeKeys_()
{
    this->nodeKeys_.push_back("title");
    this->nodeKeys_.push_back("units");
    this->nodeKeys_.push_back("processor-topology.lattice-type");
    this->nodeKeys_.push_back("processor-topology.mpi-spatial-decomposition");
    this->nodeKeys_.push_back("processor-topology.compute-units-per-spatial-domain");
    this->nodeKeys_.push_back("initial-configuration");
    this->nodeKeys_.push_back("molecular-topology");
    this->nodeKeys_.push_back("Hamiltonian");
    this->nodeKeys_.push_back("time-step.value");
    this->nodeKeys_.push_back("time-step.units");
    this->nodeKeys_.push_back("time-step.number-time-steps");
    this->nodeKeys_.push_back("integration-methodology");


    return;
}

ControlFileNodeKeys::ControlFileNodeKeys( ControlFileNodeKeys const & other) :
    nodeKeys_(other.nodeKeys_)
{
    if (this != &other)
    {
        
    }
    return;
}

ControlFileNodeKeys::ControlFileNodeKeys( ControlFileNodeKeys && other) :
    nodeKeys_(std::move(other.nodeKeys_))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method ControlFileNodeKeys::ControlFileNodeKeys  -----


ControlFileNodeKeys::~ControlFileNodeKeys()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void ControlFileNodeKeys::add(const std::string keys)
{

}
//============================= OPERATORS ====================================

ControlFileNodeKeys& ControlFileNodeKeys::operator= ( const ControlFileNodeKeys &other )
{
    if (this != &other)
    {
        this->nodeKeys_ = other.nodeKeys_;
    }
    return *this;
} // assignment operator

ControlFileNodeKeys& ControlFileNodeKeys::operator= ( ControlFileNodeKeys && other )
{
    if (this != &other)
    {
        this->nodeKeys_ = std::move(other.nodeKeys_);
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
