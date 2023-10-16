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
#include "KeyPathSeparator.h"
#include "ErrorKeyPathSeparator.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

std::string MasterControlInputFileNodeKeys::DefaultNullValue = std::string("default-null-value");

//============================= LIFECYCLE ====================================

MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys() :
    nodeKeys_(),
    commentNodeKeys_()
{
        // The node key value boost::property_tree::ptree uses for an xml
        // comment. 
        const std::vector<std::string> xml_comment_key{std::string("<xmlcomment>")};
        this->addCommentTag(xml_comment_key[0]);

        // The title key store the title of the simulation.
        std::vector<std::string> title_key{std::string("title")};
        this->addKeys(title_key);

        // These are the tags for the control file. To and new tag
        // one simply appends the text tag string to nodekeys_.
        std::vector<std::string> units_key{std::string("Units")};
        this->addKeys(units_key);

        // These are the keys for the processor topology lattice type.
        std::vector<std::string> proc_topology_lt_key{std::string("processor-topology"),
                                                      std::string("lattice-type")};
        this->addKeys(proc_topology_lt_key);

        // These are the keys for the processor topology spatial decomposition.
        std::vector<std::string> proc_topology_mpi_decomp_key{std::string("processor-topology"),
                                                              std::string("mpi-spatial-decomposition")};
        this->addKeys(proc_topology_mpi_decomp_key);

        // These are the keys for the number of compute units per spatial domain.
        std::vector<std::string> proc_topology_cu_key{std::string("processor-topology"),
                                                      std::string("compute-units-per-spatial-domain")};
        this->addKeys(proc_topology_cu_key);

        // These are the keys for the initial configurtation filename.
        std::vector<std::string> ic_key{std::string("initial-configuration"),
                                        std::string("filename")};
        this->addKeys(ic_key);

        // The keys for the molecular topology file name.
        std::vector<std::string> mt_filename_key{std::string("molecular-topology"),
                                                 std::string("filename")};
        this->addKeys(mt_filename_key);

        // The keys for the molecular interaction file name.
        std::vector<std::string> Hamiltonian_filename_key{std::string("Hamiltonian"),
                                                     std::string("filename")};
        this->addKeys(Hamiltonian_filename_key);

        // The keys for the numerical value of the timestep
        std::vector<std::string> time_step_value_key{std::string("time-step"),
                                                     std::string("value")};
        this->addKeys(time_step_value_key);

        // The keys for the units of the time step.
        std::vector<std::string> time_step_units_key{std::string("time-step"),
                                                     std::string("units")};
        this->addKeys(time_step_units_key);

        // The keys for the number of time steps. 
        std::vector<std::string> time_step_nsteps_key{std::string("time-step"),
                                                     std::string("number-time-steps")};
        this->addKeys(time_step_nsteps_key);

        // The keys for the integration methodology.
        std::vector<std::string> im_method_key {std::string("integration-methodology"),
                                        std::string("ensemble")}; 
        this->addKeys(im_method_key);
  return;
}

MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys( MasterControlInputFileNodeKeys const & other) :
    nodeKeys_(other.nodeKeys_),
    commentNodeKeys_(other.commentNodeKeys_)
{
    if (this != &other)
    {
    }
    return;
}

MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys( MasterControlInputFileNodeKeys && other) :
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
std::pair<std::vector<std::string>::const_iterator,
          std::vector<std::string>::const_iterator> MasterControlInputFileNodeKeys::allKeysIterator() const
{
    return std::pair<std::vector<std::string>::const_iterator,std::vector<std::string>::const_iterator>(this->nodeKeys_.begin(),this->nodeKeys_.end());
}

bool MasterControlInputFileNodeKeys::find(const std::string key) const
{
    bool key_found = true;
    auto it = std::find (this->nodeKeys_.begin(), this->nodeKeys_.end(), key);
    if ( it == this->nodeKeys_.end() )
    {
        key_found = false;
    }
    return key_found;
}

bool MasterControlInputFileNodeKeys::isCommentTag(const std::string key) const
{
    bool key_is_comment = true;
    auto it = std::find (this->commentNodeKeys_.begin(), this->commentNodeKeys_.end(), key);
    if ( it == this->commentNodeKeys_.end() )
    {
        key_is_comment = false;
    }
    return key_is_comment;
}

//============================= MUTATORS =====================================
void MasterControlInputFileNodeKeys::addKeys(const std::vector<std::string> & keys)
{
    // Check each key and make sure no invidual key contains the path separator character.
    // If a key contains the path separator, then throw an error and abort the program.
    for (const auto & pathkey : keys)
    {
        if ( check_string_for_separator_char<KeyPathSeparator>(pathkey) )
        {
            throw ErrorKeyPathSeparator(KeyPathSeparator::separator_char,pathkey);
        }
    }

    // Form the final path key from key.
    create_path_key<PathKey<boost::property_tree::ptree>>(keys);
    return;
}

void MasterControlInputFileNodeKeys::addCommentTag(const std::string keys)
{
    this->commentNodeKeys_.push_back(keys.c_str());
}

//============================= OPERATORS ====================================

MasterControlInputFileNodeKeys& MasterControlInputFileNodeKeys::operator= ( const MasterControlInputFileNodeKeys &other )
{
    if (this != &other)
    {
        this->nodeKeys_ = other.nodeKeys_;
    }
    return *this;
} // assignment operator

MasterControlInputFileNodeKeys& MasterControlInputFileNodeKeys::operator= ( MasterControlInputFileNodeKeys && other )
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
