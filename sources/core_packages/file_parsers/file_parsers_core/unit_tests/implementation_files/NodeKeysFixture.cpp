
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <tuple>

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
    this->keys.clear();
    this->values.clear();
    this->keyValues.clear();

    auto p = [this](auto key_values)
    { 
        this->keys.push_back(std::get<0>(key_values));
        this->values.push_back(std::get<1>(key_values));
    };

    std::tuple<std::string,std::string> key_values = {"title","Argon Dimer Simulation"};
    p(key_values);
    // this->keys.push_back(std::get<0>(key_values));
    // this->values.push_back(std::get<1>(key_values));

    key_values = {"units","real"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    key_values = {"processor-topology.lattice-type","Rectangular"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    key_values = {"processor-topology.mpi-spatial-decomposition","1 1 2"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    key_values = {"processor-topology.compute-units-per-spatial-domain","1"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    key_values = {"initial-configuration.filename","ar2.initialconfiguration"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    key_values = {"molecular-topology.filename","ar2.topology"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    key_values = {"hamiltonian.filename","ar2.hamiltonian"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    key_values = {"time-step.value","1.0"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    key_values = {"time-step.units","femtosecond"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    key_values = {"time-step.number-time-steps","100000"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    key_values = {"integration-methodology.ensemble","NVE"};
    this->keys.push_back(std::get<0>(key_values));
    this->values.push_back(std::get<1>(key_values));

    return;
}

NodeKeysFixture::NodeKeysFixture( NodeKeysFixture const & other)
{
    if (this != &other)
    {
        this->keys = other.keys;
        this->values = other.values;
        this->keyValues = other.keyValues;
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
        this->keyValues = std::move(other.keyValues);
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
        this->keyValues = other.keyValues;
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
        this->keyValues = std::move(other.keyValues);
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
