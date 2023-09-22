
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlInputFile.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlInputFile::ControlInputFile() :
    fileName_(),
    masterNodeKeys_(),
    pt_()
{
    auto keys = this->masterNodeKeys_.allKeysIterator();
    for(; keys.first != keys.second; keys.first++)
    {
        const auto my_node_key = (keys.first)->c_str();
        this->pt_.put(my_node_key,this->defaultValue_);
    }
    return;
}

ControlInputFile::ControlInputFile( ControlInputFile const & other) :
    fileName_(other.fileName_),
    masterNodeKeys_(other.masterNodeKeys_),
    pt_(other.pt_)

{
    if (this != &other)
    {
        
    }
    return;
}

ControlInputFile::ControlInputFile( ControlInputFile && other) : 
    fileName_(std::move(other.fileName_)),
    masterNodeKeys_(std::move(other.masterNodeKeys_)),
    pt_(std::move(other.pt_))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method ControlInputFile::ControlInputFile  -----


ControlInputFile::~ControlInputFile()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlInputFile& ControlInputFile::operator= ( const ControlInputFile &other )
{
    if (this != &other)
    {
        this->fileName_ = other.fileName_;
        this->masterNodeKeys_ = other.masterNodeKeys_;
        this->pt_ = other.pt_;
    }
    return *this;
} // assignment operator

ControlInputFile& ControlInputFile::operator= ( ControlInputFile && other )
{
    if (this != &other)
    {
        this->fileName_ = std::move(other.fileName_);
        this->masterNodeKeys_ = std::move(other.masterNodeKeys_);
        this->pt_ = std::move(other.pt_);
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


}; // namespace ANANSI
