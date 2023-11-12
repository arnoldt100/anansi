
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
    values.clear();

    keys.push_back("title");
    values.push_back("Argon Dimer Simulation");

    keys.push_back("units");
    values.push_back("real");

    keys.push_back("processor-topology.lattice-type");
    values.push_back("Rectangular");

    keys.push_back("processor-topology.mpi-spatial-decomposition");
    values.push_back("1 1 2");

    keys.push_back("processor-topology.compute-units-per-spatial-domain");
    values.push_back("1");

    keys.push_back("initial-configuration.filename");
    values.push_back("ar2.initialconfiguration");

    keys.push_back("molecular-topology.filename");
    values.push_back("ar2.topology");

    keys.push_back("hamiltonian.filename");
    values.push_back("ar2.hamiltonian");

    keys.push_back("time-step.value");
    values.push_back("1.0");

    keys.push_back("time-step.units");
    values.push_back("femtosecond");

    keys.push_back("time-step.number-time-steps");
    values.push_back("100000");

    keys.push_back("integration-methodology.ensemble");
    values.push_back("NVE");

    return;
}

NodeKeysFixture::NodeKeysFixture( NodeKeysFixture const & other)
{
    if (this != &other)
    {
        this->keys = other.keys;
        this->values = other.values;
        this->nodeKeys = other.nodeKeys;
    }
    return;
}

NodeKeysFixture::NodeKeysFixture( NodeKeysFixture && other)
{
    if (this != &other)
    {
        this->keys = std::move(other.keys);
        this->values = std::move(other.values);
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
        this->values = other.values;
        this->nodeKeys = other.nodeKeys;
    }
    return *this;
} // assignment operator

NodeKeysFixture& NodeKeysFixture::operator=( NodeKeysFixture && other )
{
    if (this != &other)
    {
        this->keys = std::move(other.keys);
        this->values = std::move(other.values);
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
