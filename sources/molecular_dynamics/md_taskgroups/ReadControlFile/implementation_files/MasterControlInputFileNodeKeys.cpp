
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <algorithm>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterControlInputFileNodeKeys.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MasterControlInputFileNodeKeys::MasterControlInputFileNodeKeys() :
    nodeKeys_(),
    commentNodeKeys_()
{
  // The node key value boost::property_tree::ptree uses for an xml
  // comment. 
  this->addKey(std::string("<xmlcomment>"));
  this->addCommentTag(std::string("<xmlcomment>"));

  // These are the tags for the control file. To and n new tag
  // one simply appends the text tag string to nodekeys_.
  this->addKey(std::string("title"));
  this->addKey(std::string("units"));
  this->addKey(std::string("processor-topology.lattice-type"));
  this->addKey(std::string("processor-topology.mpi-spatial-decomposition"));
  this->addKey(std::string("processor-topology.compute-units-per-spatial-domain"));
  this->addKey(std::string("initial-configuration.filename"));
  this->addKey(std::string("molecular-topology.filename"));
  this->addKey(std::string("Hamiltonian.filename"));
  this->addKey(std::string("time-step.value"));
  this->addKey(std::string("time-step.units"));
  this->addKey(std::string("time-step.number-time-steps"));
  this->addKey(std::string("integration-methodology.ensemble"));
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
    return std::pair(this->nodeKeys_.begin(),this->nodeKeys_.end());
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
void MasterControlInputFileNodeKeys::addKey(const std::string keys)
{
    this->nodeKeys_.push_back(keys.c_str());
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
