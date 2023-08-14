
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
#include "MasterControlFileNodeKeys.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

MasterControlFileNodeKeys::MasterControlFileNodeKeys() :
    nodeKeys_(),
    commentNodeKeys_()
{
  // The node key value boost::property_tree::ptree uses for an xml
  // comment. 
  this->addTag(std::string("<xmlcomment>"));
  this->addCommentTag(std::string("<xmlcomment>"));

  // These are the tags for the control file. To and n new tag
  // one simply appends the text tag string to nodekeys_.
  this->addTag(std::string("title"));
  this->addTag(std::string("units"));
  this->addTag(std::string("processor-topology.lattice-type"));
  this->addTag(std::string("processor-topology.mpi-spatial-decomposition"));
  this->addTag(std::string("processor-topology.compute-units-per-spatial-domain"));
  this->addTag(std::string("initial-configuration.filename"));
  this->addTag(std::string("molecular-topology.filename"));
  this->addTag(std::string("Hamiltonian.filename"));
  this->addTag(std::string("time-step.value"));
  this->addTag(std::string("time-step.units"));
  this->addTag(std::string("time-step.number-time-steps"));
  this->addTag(std::string("integration-methodology.ensemble"));
  return;
}

MasterControlFileNodeKeys::MasterControlFileNodeKeys( MasterControlFileNodeKeys const & other) :
    nodeKeys_(other.nodeKeys_),
    commentNodeKeys_(other.commentNodeKeys_)
{
    if (this != &other)
    {
        
    }
    return;
}

MasterControlFileNodeKeys::MasterControlFileNodeKeys( MasterControlFileNodeKeys && other) :
    nodeKeys_(std::move(other.nodeKeys_)),
    commentNodeKeys_(std::move(other.commentNodeKeys_))

{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method MasterControlFileNodeKeys::MasterControlFileNodeKeys  -----


MasterControlFileNodeKeys::~MasterControlFileNodeKeys()
{
    return;
}

//============================= ACCESSORS ====================================
std::pair<std::vector<std::string>::const_iterator,
          std::vector<std::string>::const_iterator> MasterControlFileNodeKeys::allKeysIterator() const
{
    return std::pair(this->nodeKeys_.begin(),this->nodeKeys_.end());
}

bool MasterControlFileNodeKeys::find(const std::string key) const
{
    bool key_found = true;
    auto it = std::find (this->nodeKeys_.begin(), this->nodeKeys_.end(), key);
    if ( it == this->nodeKeys_.end() )
    {
        key_found = false;
    }
    return key_found;
}

bool MasterControlFileNodeKeys::isCommentTag(const std::string key) const
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
void MasterControlFileNodeKeys::addTag(const std::string keys)
{
    this->nodeKeys_.push_back(keys.c_str());
}

void MasterControlFileNodeKeys::addCommentTag(const std::string keys)
{
    this->commentNodeKeys_.push_back(keys.c_str());
}

//============================= OPERATORS ====================================

MasterControlFileNodeKeys& MasterControlFileNodeKeys::operator= ( const MasterControlFileNodeKeys &other )
{
    if (this != &other)
    {
        this->nodeKeys_ = other.nodeKeys_;
    }
    return *this;
} // assignment operator

MasterControlFileNodeKeys& MasterControlFileNodeKeys::operator= ( MasterControlFileNodeKeys && other )
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
