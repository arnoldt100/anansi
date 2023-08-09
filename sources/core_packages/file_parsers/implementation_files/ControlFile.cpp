
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <utility>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFile.h"
#include "add_values_to_property_tree.h"
#include "verify_controlfile_keys_are_valid.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFile::ControlFile() :
    BaseInputFile<ControlFile>(),
    fileName_(),
    masterNodeKeys_(),
    pt_()
{
    auto keys = this->masterNodeKeys_.allKeysIterator();
    for(; keys.first != keys.second; keys.first++)
    {
        const auto my_node_key = (keys.first)->c_str();
        this->pt_.put(my_node_key,"--default-null-value--");
    }

    return;
}

ControlFile::ControlFile( const ControlFile & other) : 
    BaseInputFile<ControlFile>(other),
    fileName_(other.fileName_),
    masterNodeKeys_(other.masterNodeKeys_),
    pt_(other.pt_)
{
    return;
} // -----  end of method ControlFile::ControlFile  -----

ControlFile::ControlFile( ControlFile && other) :
    BaseInputFile<ControlFile>(std::move(other)),
    fileName_(std::move(other.fileName_)),
    masterNodeKeys_(std::move(other.masterNodeKeys_)),
    pt_(std::move(other.pt_))

{
    return;
} // -----  end of method ControlFile::ControlFile  -----


ControlFile::~ControlFile()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ControlFile& ControlFile::operator= ( const ControlFile & other )
{
    if (this != &other)
    {
        BaseInputFile<ControlFile>::operator=(other);
        this->fileName_ = other.fileName_;
        this->masterNodeKeys_ = other.masterNodeKeys_;
        this->pt_ = other.pt_;
    }
    return *this;
} // assignment operator


ControlFile& ControlFile::operator= ( ControlFile && other )
{
    if (this != &other)
    {
        BaseInputFile<ControlFile>::operator=(std::move(other));
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
void ControlFile::setFileName_(const std::string my_file_name)
{
    this->fileName_ = ANANSI::ControlFileName(my_file_name);
    return;
}

void ControlFile::readFileInformation_(boost::property_tree::ptree & pt)
{
    // Verify all keys in pt are valid keys.
    verify_controlfile_keys_are_valid(this->masterNodeKeys_,pt);

    // Add values to masterNodeKeys_ property tree.
    add_values_to_property_tree(this->masterNodeKeys_,pt);    
    
    // auto keys = this->masterNodeKeys_.allKeysIterator();
    // for(; keys.first != keys.second; keys.first++)
    // {
    //     const auto node_key = (keys.first)->c_str();
    //     std::cout << "Node key: " << node_key << std::endl;

    //     boost::property_tree::ptree::const_assoc_iterator it = pt.find(node_key);
    //     if ( it != pt.not_found()  )
    //     {

    //     }
    //     auto v2 = this->pt_.get<std::string>(keys.first->c_str());
    //     std::cout << "v2: " << v2 << std::endl;
    //     std::cout << std::endl;
    //     std::cout << std::endl;
    //     
    // }
    return;
}

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
