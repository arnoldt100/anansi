
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

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFile::ControlFile() :
    BaseInputFile<ControlFile>(),
    fileName_(),
    nodeKeys_(),
    pt_()
{
    auto keys = this->nodeKeys_.allKeysIterator();
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
    nodeKeys_(other.nodeKeys_),
    pt_(other.pt_)
{
    return;
} // -----  end of method ControlFile::ControlFile  -----

ControlFile::ControlFile( ControlFile && other) :
    BaseInputFile<ControlFile>(std::move(other)),
    fileName_(std::move(other.fileName_)),
    nodeKeys_(std::move(other.nodeKeys_)),
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
        this->nodeKeys_ = other.nodeKeys_;
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
        this->nodeKeys_ = std::move(other.nodeKeys_);
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
    auto keys = this->nodeKeys_.allKeysIterator();
    for(; keys.first != keys.second; keys.first++)
    {
        std::cout << "Node key: " << (keys.first)->c_str() << std::endl;

        // 
        auto v1 = this->pt_.get<std::string>(keys.first->c_str());
        auto v2 = pt.get<std::string>(keys.first->c_str());

        std::cout << "v1: " << v1 << std::endl;
        std::cout << "v2: " << v2 << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }
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
