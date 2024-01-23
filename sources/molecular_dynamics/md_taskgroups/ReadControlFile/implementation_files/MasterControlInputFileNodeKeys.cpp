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
#include "check_string_for_separator_char.h"
#include "create_path_key_propertytree.hpp"
#include "ErrorKeyPathSeparator.h"
#include "SimulationDecompositionParameters.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

std::string MasterControlInputFileNodeKeys::DefaultNullValue = std::string("default-null-value");

//============================= LIFECYCLE ====================================

MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys() :
    nodeKeys2_(),
    nodeKeys_(),
    commentNodeKeys_()
{
        // The node key value boost::property_tree::ptree uses for an xml
        // comment. 
        const std::vector<std::string> xml_comment_key{std::string("<xmlcomment>")};
        this->addCommentTag_(xml_comment_key[0]);

        std::string title_key{"Simulation_Title"};
        std::vector<std::string> title_mc_tags{std::string("title")};
        this->addNodeKey2_(title_key,title_mc_tags);
        this->addNodeKey_(title_mc_tags);

        std::string Simulation_Units{"Simulation_Units"};
        std::vector<std::string> units_mc_tags{std::string("units")};
        this->addNodeKey2_(Simulation_Units,units_mc_tags);
        this->addNodeKey_(units_mc_tags);

        // These are the keys for the processor topology lattice type.
        std::string Simulation_Procssor_Lattice_Topology{"Simulation_Processor_Lattice_Topology"};
        std::vector<std::string> proc_topology_lt_tags{std::string("processor-topology"),
                                                      std::string("lattice-type")};
        this->addNodeKey2_(Simulation_Procssor_Lattice_Topology,proc_topology_lt_tags);
        this->addNodeKey_(proc_topology_lt_tags);

        std::vector<std::string> workload_decomposition_key{std::string("workload-decomposition")};
        this->addNodeKey_(workload_decomposition_key);

        // These are the keys for the processor topology spatial decomposition.
        std::vector<std::string> proc_topology_mpi_decomp_key{std::string("processor-topology"),
                                                              std::string("mpi-spatial-decomposition")};
        this->addNodeKey_(proc_topology_mpi_decomp_key);

        // These are the keys for the number of compute units per spatial domain.
        std::vector<std::string> proc_topology_cu_key{std::string("processor-topology"),
                                                      std::string("compute-units-per-spatial-domain")};
        this->addNodeKey_(proc_topology_cu_key);

        // These are the keys for the initial configuration filename.
        std::vector<std::string> ic_key{std::string("initial-configuration"),
                                        std::string("filename")};
        this->addNodeKey_(ic_key);

        // These are the keys for the coordinate system.
        std::vector<std::string> cs_key{std::string("coordinate-system")};
        this->addNodeKey_(cs_key);

        // The keys for the molecular topology file name.
        std::vector<std::string> mt_filename_key{std::string("molecular-topology"),
                                                 std::string("filename")};
        this->addNodeKey_(mt_filename_key);

        // The keys for the molecular interaction file name.
        std::vector<std::string> Hamiltonian_filename_key{std::string("hamiltonian"),
                                                     std::string("filename")};
        this->addNodeKey_(Hamiltonian_filename_key);

        // The keys for the numerical value of the timestep
        std::vector<std::string> time_step_value_key{std::string("time-step"),
                                                     std::string("value")};
        this->addNodeKey_(time_step_value_key);

        // The keys for the units of the time step.
        std::vector<std::string> time_step_units_key{std::string("time-step"),
                                                     std::string("units")};
        this->addNodeKey_(time_step_units_key);

        // The keys for the number of time steps. 
        std::vector<std::string> time_step_nsteps_key{std::string("time-step"),
                                                     std::string("number-time-steps")};
        this->addNodeKey_(time_step_nsteps_key);

        // The keys for the integration methodology.
        std::vector<std::string> im_method_key {std::string("integration-methodology"),
                                        std::string("ensemble")}; 
        this->addNodeKey_(im_method_key);
  return;
}

MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys( MasterControlInputFileNodeKeys const & other) :
    nodeKeys2_(other.nodeKeys2_),
    nodeKeys_(other.nodeKeys_),
    commentNodeKeys_(other.commentNodeKeys_)
{
    if (this != &other)
    {
    }
    return;
}

MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys( MasterControlInputFileNodeKeys && other) :
    nodeKeys2_(std::move(other.nodeKeys2_)),
    nodeKeys_(std::move(other.nodeKeys_)),
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
    return std::pair<std::vector<std::string>::const_iterator,std::vector<std::string>::const_iterator>(this->nodeKeys_.begin(),this->nodeKeys_.end());
}

bool MasterControlInputFileNodeKeys::isKeyPresent(const std::string key) const
{
    bool key_found = true;
    auto it = std::find (this->nodeKeys_.begin(), this->nodeKeys_.end(), key);
    if ( it == this->nodeKeys_.end() )
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


std::string MasterControlInputFileNodeKeys::workload_decomposition_type_node_key() const
{
    return std::string("workload-decomposition"); 
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
        this->nodeKeys2_ = other.nodeKeys2_;
        this->nodeKeys_ = other.nodeKeys_;
        this->commentNodeKeys_ = other.commentNodeKeys_;
    }
    return *this;
} // assignment operator

MasterControlInputFileNodeKeys& MasterControlInputFileNodeKeys::operator= ( MasterControlInputFileNodeKeys && other )
{
    if (this != &other)
    {
        this->nodeKeys2_ = std::move(other.nodeKeys2_);
        this->nodeKeys_ = std::move(other.nodeKeys_);
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

void MasterControlInputFileNodeKeys::addNodeKey_(const std::vector<std::string> & keys)
{
    // Check each key and make sure no invidual key contains the path separator character.
    // If a key contains the path separator, then throw an error and abort the program.
    for (const auto & tmpstr : keys)
    {
        if ( check_string_for_separator_char<PathSeparatorTrait>(tmpstr) )
        {
            throw ErrorKeyPathSeparator(PathSeparatorTrait::separator_char,tmpstr);
        }
    }

    // Form the final path key from key and add key to nodeKeys_.
    const auto path_key = create_path_key<PathKey<InternalRepresentationTrait>,PathSeparatorTrait>(keys);
    this->nodeKeys_.push_back(path_key);
    return;
}

void MasterControlInputFileNodeKeys::addNodeKey2_(const std::string & key, const std::vector<std::string> & keys)
{
    // Check each key and make sure no invidual key contains the path separator character.
    // If a key contains the path separator, then throw an error and abort the program.
    for (const auto & tmpstr : keys)
    {
        if ( check_string_for_separator_char<PathSeparatorTrait>(tmpstr) )
        {
            throw ErrorKeyPathSeparator(PathSeparatorTrait::separator_char,tmpstr);
        }
    }

    // Form the final path key from key and add key to nodeKeys_.
    const auto path_key = create_path_key<PathKey<InternalRepresentationTrait>,PathSeparatorTrait>(keys);
    this->nodeKeys2_[key] = path_key;
    return;
}

//============================= OPERATORS ====================================


} // namespace ANANSI
