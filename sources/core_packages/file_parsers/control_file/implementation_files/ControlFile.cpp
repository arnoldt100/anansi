
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <utility>
#include <map>

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
#include <boost/algorithm/string.hpp>

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFile::ControlFile() :
    BaseInputFile<ControlFile,ControlFileTraits>(),
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

ControlFile::ControlFile( const ControlFile & other) : 
    BaseInputFile<ControlFile,ControlFileTraits>(other),
    fileName_(other.fileName_),
    masterNodeKeys_(other.masterNodeKeys_),
    pt_(other.pt_)
{
    return;
} // -----  end of method ControlFile::ControlFile  -----

ControlFile::ControlFile( ControlFile && other) :
    BaseInputFile<ControlFile,ControlFileTraits>(std::move(other)),
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
        BaseInputFile<ControlFile,ControlFileTraits>::operator=(other);
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
        BaseInputFile<ControlFile,ControlFileTraits>::operator=(std::move(other));
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
void ControlFile::writeToDisk_(const std::string my_filename) const
{
    // Write property tree to XML file
    boost::property_tree::write_xml(my_filename, this->pt_);
    return;
}

ControlFileTraits::PICKLETYPE ControlFile::pickleToMap_() const
{
    std::cout << "Pickling file to  std::map" << std::endl;
    ControlFileTraits::PICKLETYPE pobj;

    // Pickle the file name to std::map.
    pobj[std::string("filename")] = this->fileName_();

    // Pickle the property tree to std::map.
    return pobj; 
}

//============================= MUTATORS =====================================
void ControlFile::setFileName_(const std::string my_file_name)
{
    this->fileName_ = ANANSI::ControlFileName(my_file_name);
    return;
}

void ControlFile::readPropertyTree_(boost::property_tree::ptree & pt)
{
    // Verify all keys in pt are valid keys.
    verify_controlfile_keys_are_valid(this->masterNodeKeys_,pt);

    // Fill in this->pt_ from pt. The pt values come from the control file on disk.
    add_values_to_property_tree(this->masterNodeKeys_,
                                pt,
                                std::string(this->defaultValue_),
                                this->pt_);    
   
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
