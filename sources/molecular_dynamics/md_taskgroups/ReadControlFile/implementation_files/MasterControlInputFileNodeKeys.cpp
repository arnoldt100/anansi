//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <algorithm>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterControlInputFileNodeKeys.h"
#include "MasterControlInternalNodeKeys.h"
#include "check_string_for_separator_char.h"
#include "create_path_key_propertytree.hpp"
#include "ErrorKeyPathSeparator.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

std::string MasterControlInputFileNodeKeys::DefaultNullValue = std::string("default-null-value");

//============================= LIFECYCLE ====================================

//! This class contains the external keys with respect to the master control file.
//! 
//! The external keys correspond to the external node tags
//! in the master control input file. The external keys are used by the 
//! program users to set the paramaters of the program's execution.
MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys() :
    internalToExternalKeyMapping_(),
    externalNodeKeys_(),
    commentNodeKeys_()
{
    // The boost::property_tree::ptree uses an xml
    // comment. 
    const std::vector<std::string> xml_comment_key{std::string("<xmlcomment>")};
    this->addCommentTag_(xml_comment_key[0]);

    //! Adding node key for the simulation title.
    const std::string internalSimulationTitleKey{MasterControlInternalNodeKeys::Simulation_Title};
    std::vector<std::string> externalSimulationTitleKey{std::string("title")};
    this->addNodeKey_(internalSimulationTitleKey,externalSimulationTitleKey);

    std::string Simulation_Units{"Simulation_Units"};
    std::vector<std::string> units_mc_tags{std::string("units")};
    this->addNodeKey_(Simulation_Units,units_mc_tags);

    //! Adding node key for the workload decomposition.
    const std::string internalKeySimulationWorkloadDecompositionKey{MasterControlInternalNodeKeys::Simulation_Workload_Decomposition_Type};
    const std::vector<std::string> externalWorkloadDecompositionKey{std::string("workload-decomposition")};
    this->addNodeKey_(internalKeySimulationWorkloadDecompositionKey,externalWorkloadDecompositionKey);

    // These are the keys for the processor topology lattice type.
    std::string internalSimulationProcessorLatticeTopologyKey{MasterControlInternalNodeKeys::Simulation_Processor_Lattice_Topology_Type};
    std::vector<std::string> externalSimulationProcessorLatticeTopologyKey{std::string("processor-topology"),
                                                                            std::string("lattice-type")};
    this->addNodeKey_(internalSimulationProcessorLatticeTopologyKey,externalSimulationProcessorLatticeTopologyKey);

    // These are the keys for the processor lattice topology spatial dimensions.
    std::string internalSimulationProcessorLatticeTopologyDimensionsKey{MasterControlInternalNodeKeys::Simulation_Processor_Lattice_Topology_Dimensions};
    std::vector<std::string> externalSimulationProcessorLatticeTopologyDimensionsKey{std::string("processor-topology"),
                                                                                     std::string("mpi-spatial-decomposition")};
    this->addNodeKey_(internalSimulationProcessorLatticeTopologyDimensionsKey,
                      externalSimulationProcessorLatticeTopologyDimensionsKey);

    // These are the keys for the number of compute units per spatial domain.
    std::string internalSimulationNumberComputeUnitsPerSpatialDomainKey{MasterControlInternalNodeKeys::Simulation_Number_Compute_Units_Per_Spatial_Domain};
    std::vector<std::string> externalSimulationNumberComputeUnitsPerSpatialDomainKey{std::string("processor-topology"),
                                                                                     std::string("compute-units-per-spatial-domain")};
    this->addNodeKey_(internalSimulationNumberComputeUnitsPerSpatialDomainKey,
                      externalSimulationNumberComputeUnitsPerSpatialDomainKey);

    // These are the keys for the initial configuration filename.
    std::string internalSimulationInitialConfigurationKey{MasterControlInternalNodeKeys::Simulation_Initial_Configuration};
    std::vector<std::string> externalSimulationInitialConfigurationKey{std::string("initial-configuration"),
                                                                       std::string("filename")};
    this->addNodeKey_(internalSimulationInitialConfigurationKey,
                      externalSimulationInitialConfigurationKey);

    // These are the keys for the simulation coordinate system.
    std::string internalSimulationCoordinateSystemkey{MasterControlInternalNodeKeys::Simulation_Coordinate_System};
    std::vector<std::string> externalSimulationCoordinateSystemKey{std::string("coordinate-system")};
    this->addNodeKey_(internalSimulationCoordinateSystemkey,externalSimulationCoordinateSystemKey);

    // The keys for the molecular topology file name.
    std::string internalSimulationMolecularTopologyKey{MasterControlInternalNodeKeys::Simulation_Molecular_Topology};
    std::vector<std::string> externalMolecularTopologyKey{std::string("molecular-topology"),
                                                          std::string("filename")};
    this->addNodeKey_(internalSimulationMolecularTopologyKey,externalMolecularTopologyKey);

    // The keys for the molecular interaction file name.
    std::string internalSimulationHamiltonianKey{MasterControlInternalNodeKeys::Simulation_Hamiltonian};
    std::vector<std::string> externalSimulationHamiltonianKey{std::string("hamiltonian"),
                                                              std::string("filename")};
    this->addNodeKey_(internalSimulationHamiltonianKey,externalSimulationHamiltonianKey);

    // The keys for the numerical value of the timestep
    std::string internalSimulationTimestepKey{MasterControlInternalNodeKeys::Simulation_Timestep};
    std::vector<std::string> externalSimulationTimestepKey{std::string("time-step")};
    this->addNodeKey_(internalSimulationTimestepKey,externalSimulationTimestepKey);

    // The keys for the number of time steps. 
    std::string internalSimulationTotalNumberTimestepsKey{"Simulation_Total_Number_Timesteps"};
    std::vector<std::string> externalSimulationTotalNumberTimestepsKey{std::string("total-number-time-steps")};
    this->addNodeKey_(internalSimulationTotalNumberTimestepsKey,externalSimulationTimestepKey);

    // The keys for the integration methodology.
    std::string internalSimulationIntegrationMethodologyKey{MasterControlInternalNodeKeys::Simulation_Integration_Methodology};
    std::vector<std::string> externalSimulationIntegrationMethodologyKey {std::string("integration-methodology"),
                                                                          std::string("ensemble")}; 
    this->addNodeKey_(internalSimulationIntegrationMethodologyKey,externalSimulationIntegrationMethodologyKey);

    return;
}

MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys( MasterControlInputFileNodeKeys const & other) :
    internalToExternalKeyMapping_(other.internalToExternalKeyMapping_),
    externalNodeKeys_(other.externalNodeKeys_),
    commentNodeKeys_(other.commentNodeKeys_)
{
    if (this != &other)
    {
    }
    return;
}

MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys( MasterControlInputFileNodeKeys && other) :
    internalToExternalKeyMapping_(std::move(other.internalToExternalKeyMapping_)),
    externalNodeKeys_(std::move(other.externalNodeKeys_)),
    commentNodeKeys_(std::move(other.commentNodeKeys_))

{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys  -----


MasterControlInputFileNodeKeys::~MasterControlInputFileNodeKeys()
{
    return;
}

//============================= ACCESSORS ====================================

MasterControlInputFileNodeKeys * MasterControlInputFileNodeKeys::clone() const
{
    return new MasterControlInputFileNodeKeys(*this);
}

std::pair<MasterControlInputFileNodeKeys::VCI_t_,
          MasterControlInputFileNodeKeys::VCI_t_> MasterControlInputFileNodeKeys::allKeysIterator() const
{
    return std::pair<std::vector<std::string>::const_iterator,std::vector<std::string>::const_iterator>(this->externalNodeKeys_.begin(),this->externalNodeKeys_.end());
}

bool MasterControlInputFileNodeKeys::isKeyPresent(const std::string key) const
{
    bool key_found = true;
    auto it = std::find (this->externalNodeKeys_.begin(), this->externalNodeKeys_.end(), key);
    if ( it == this->externalNodeKeys_.end() )
    {
        key_found = false;
    }
    return key_found;
}

bool MasterControlInputFileNodeKeys::isCommentKey(const std::string key) const
{
    bool key_is_comment = true;
    auto it = std::find (this->commentNodeKeys_.begin(), this->commentNodeKeys_.end(), key);
    if ( it == this->commentNodeKeys_.end() )
    {
        key_is_comment = false;
    }
    return key_is_comment;
}

std::string MasterControlInputFileNodeKeys::defaultNullValue() const
{
    return MasterControlInputFileNodeKeys::DefaultNullValue_;
}


std::string MasterControlInputFileNodeKeys::node_key( const std::string & global_key) const
{
    return this->internalToExternalKeyMapping_.at(global_key);
}

//============================= MUTATORS =====================================

std::array<char,2> MasterControlInputFileNodeKeys::separatorChar() const
{
    return KeyPathSeparatorPeriod::separator_char;
}

//============================= OPERATORS ====================================

MasterControlInputFileNodeKeys& MasterControlInputFileNodeKeys::operator= ( const MasterControlInputFileNodeKeys &other )
{
    if (this != &other)
    {
        this->internalToExternalKeyMapping_ = other.internalToExternalKeyMapping_;
        this->externalNodeKeys_ = other.externalNodeKeys_;
        this->commentNodeKeys_ = other.commentNodeKeys_;
    }
    return *this;
} // assignment operator

MasterControlInputFileNodeKeys& MasterControlInputFileNodeKeys::operator= ( MasterControlInputFileNodeKeys && other )
{
    if (this != &other)
    {
        this->internalToExternalKeyMapping_ = std::move(other.internalToExternalKeyMapping_);
        this->externalNodeKeys_ = std::move(other.externalNodeKeys_);
        this->commentNodeKeys_ = std::move(other.commentNodeKeys_);
    }
    return *this;
} // assignment-move operator

// ====================  STATIC        =======================================

bool MasterControlInputFileNodeKeys::does_key_exist(const MasterControlInputFileNodeKeys & object, const std::string key)
{
    return object.isKeyPresent(key);
}

bool MasterControlInputFileNodeKeys::is_comment_key(const MasterControlInputFileNodeKeys & object, const std::string key)
{
    return object.isCommentKey(key);
}

std::pair<MasterControlInputFileNodeKeys::VCI_t_,
          MasterControlInputFileNodeKeys::VCI_t_> MasterControlInputFileNodeKeys::all_keys_iterator(const MasterControlInputFileNodeKeys & object)
{
    return object.allKeysIterator();
}

std::string MasterControlInputFileNodeKeys::default_null_value(const MasterControlInputFileNodeKeys & object)
{
    return object.defaultNullValue();
}

std::array<char,2> MasterControlInputFileNodeKeys::separator_char(const MasterControlInputFileNodeKeys & object)
{
    return object.separatorChar();
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
    
// ====================  STATIC        =======================================
std::string MasterControlInputFileNodeKeys::DefaultNullValue_ = std::string("default-null-value");

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

void MasterControlInputFileNodeKeys::addCommentTag_(const std::string & keys)
{
    this->commentNodeKeys_.push_back(keys.c_str());
}

void MasterControlInputFileNodeKeys::addNodeKey_(const std::string & internal_key, const std::vector<std::string> & external_keys)
{
    // Check each key and make sure no invidual external key contains the path separator character.
    // If an external key contains the path separator, then throw an error and abort the program.
    for (const auto & tmpstr : external_keys)
    {
        if ( check_string_for_separator_char<PathSeparatorTrait>(tmpstr) )
        {
            throw ErrorKeyPathSeparator(PathSeparatorTrait::separator_char,tmpstr);
        }
    }

    // Form the final path key from key and add key to externalNodeKeys_.
    const auto path_key = create_path_key<PathKey<InternalRepresentationTrait>,PathSeparatorTrait>(external_keys);
    this->internalToExternalKeyMapping_[internal_key] = path_key;
    this->externalNodeKeys_.push_back(path_key);
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
