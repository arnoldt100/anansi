
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "NodeKeysFixture.h"
#include "XMLNodeKeys.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

NodeKeysFixture::NodeKeysFixture() :
            nodeKeys{ANANSI::XMLNodeKeys()}
{
    // Initialize the keys that are in the test XML input data file.
    keys.clear();
    keys.push_back("title");
    keys.push_back("units");
    keys.push_back("processor-topology.lattice-type");
    keys.push_back("processor-topology.mpi-spatial-decomposition");
    keys.push_back("processor-topology.compute-units-per-spatial-domain");
    keys.push_back("initial-configuration.filename");
    keys.push_back("molecular-topology.filename");
    keys.push_back("hamiltonian.filename");
    keys.push_back("time-step.value");
    keys.push_back("time-step.units");
    keys.push_back("time-step.number-time-steps");
    keys.push_back("integration-methodology.ensemble");
    return;
}

NodeKeysFixture::NodeKeysFixture( NodeKeysFixture const & other)
{
    if (this != &other)
    {
        this->keys = other.keys;
        this->nodeKeys = other.nodeKeys;
    }
    return;
}

NodeKeysFixture::NodeKeysFixture( NodeKeysFixture && other)
{
    if (this != &other)
    {
        this->keys = std::move(other.keys);
        this->nodeKeys = std::move(other.nodeKeys);
    }
    return;
}		// -----  end of method NodeKeysFixture::NodeKeysFixture  -----


NodeKeysFixture::~NodeKeysFixture()
{
    return;
}

//============================= ACCESSORS ====================================

NodeKeysFixture * NodeKeysFixture::clone() const
{
    return new NodeKeysFixture(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

NodeKeysFixture& NodeKeysFixture::operator= (const NodeKeysFixture &other )
{
    if (this != &other)
    {
        this->keys = other.keys;
        this->nodeKeys = other.nodeKeys;
    }
    return *this;
} // assignment operator

NodeKeysFixture& NodeKeysFixture::operator=( NodeKeysFixture && other )
{
    if (this != &other)
    {
        this->keys = std::move(other.keys);
        this->nodeKeys = std::move(other.nodeKeys);
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
