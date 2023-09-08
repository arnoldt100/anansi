
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
#include "ControlFile.hpp"
#include "add_values_to_property_tree.h"
#include "pickle_ControlFile_property_tree.h"
#include "unpickle_to_property_tree.h"
#include "verify_controlfile_keys_are_valid.h"
#include <boost/algorithm/string.hpp>

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

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

ControlFileTraits::PICKLETYPE ControlFile::pickle_() const
{
    ControlFileTraits::PICKLETYPE pobj;

    // Pickle the file name to std::map.
    pobj[std::string("filename")] = this->fileName_();

    pickle_ControlFile_property_tree();

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

//! \brief Unpickles "pickle_obj" and reforms the ControlFile's property tree,
//!        and other data members.
//!
//! Iterate through the keys of this->masterNodeKeys. Check if a matching is
//! found in the pickle_obj, and if a matching key is found the add key-value pair to
//! boost::property_tree "this->pt_". If the key is not found then add the key
//! value pair with "default-null-value" as the key's value.
void ControlFile::unpickle_(const ControlFileTraits::PICKLETYPE & pickle_obj) 
{
    // Unpickle the filename.
    this->fileName_ = ControlFileName(pickle_obj.at("filename")); 

    this->pt_.clear();

    this->writeToDisk_(std::string("debug.controlFile.before"));

    this->pt_ = unpickle_to_property_tree(this->masterNodeKeys_,
                                          pickle_obj,
                                          this->defaultValue_);

    this->writeToDisk_(std::string("debug.controlFile.after"));

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
