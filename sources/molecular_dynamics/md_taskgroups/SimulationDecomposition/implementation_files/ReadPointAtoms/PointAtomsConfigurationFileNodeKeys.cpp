
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PointAtomsConfigurationFileNodeKeys.h"
#include "PointAtomsInternalNodeKeys.h"
#include "check_string_for_separator_char.h"
#include "ErrorKeyPathSeparator.h"
#include "create_path_key_propertytree.hpp"
#include "VariableKeyFormatPolicy.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

PointAtomsConfigurationFileNodeKeys::PointAtomsConfigurationFileNodeKeys() : 
    internalToExternalKeyMapping_{},
    externalNodeKeys_{},
    commentNodeKeys_{}
{
    // The boost::property_tree::ptree uses an xml
    // comment. 
    const std::vector<std::string> xml_comment_key{std::string("<xmlcomment>")};
    this->addCommentTag_(xml_comment_key[0]);

    // Adding node key for region name
    const std::string internalRegionNameKey{PointAtomsInternalNodeKeys::Region_Name};
    std::vector<std::string> externalRegionNameKey{std::string("data"),
                                                   std::string("Region_Name")};
    this->addNodeKey_(internalRegionNameKey,externalRegionNameKey);

    // Adding node key for the type of coordinate system.
    const std::string internalCoordinateSystemTypeKey{PointAtomsInternalNodeKeys::Coordinate_System};
    std::vector<std::string> externalCoordinateSystemTypeKey{std::string("data"),
                                                             std::string("Coordinate_System")};
    this->addNodeKey_(internalCoordinateSystemTypeKey,externalCoordinateSystemTypeKey);

    // Adding node key for the number of point atoms.
    const std::string internalNumberOfPointAtomsKey{PointAtomsInternalNodeKeys::Number_Atoms_In_File};
    std::vector<std::string> externalNumberAtomsInFile{std::string("data"),
                                                       std::string("Coordinates_Velocities_etc"),
                                                       std::string("Number_of_Atoms")};
    this->addNodeKey_(internalNumberOfPointAtomsKey,externalNumberAtomsInFile);

    // Adding node key for the atom type of the i'th atom.
    std::vector<std::string> atomType{std::string("data"),
                                      std::string("Coordinates_Velocities_etc"),
                                      std::string("<1>"),
                                      std::string("Atom") };
    return;
}

PointAtomsConfigurationFileNodeKeys::PointAtomsConfigurationFileNodeKeys( PointAtomsConfigurationFileNodeKeys const & other) :
    internalToExternalKeyMapping_(other.internalToExternalKeyMapping_),
    externalNodeKeys_(other.externalNodeKeys_),
    commentNodeKeys_(other.commentNodeKeys_)
{
    if (this != &other)
    {
    }
    return;
}

PointAtomsConfigurationFileNodeKeys::PointAtomsConfigurationFileNodeKeys( PointAtomsConfigurationFileNodeKeys && other) :
    internalToExternalKeyMapping_(std::move(other.internalToExternalKeyMapping_)),
    externalNodeKeys_(std::move(other.externalNodeKeys_)),
    commentNodeKeys_(std::move(other.commentNodeKeys_))
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method PointAtomsConfigurationFileNodeKeys::PointAtomsConfigurationFileNodeKeys  -----


PointAtomsConfigurationFileNodeKeys::~PointAtomsConfigurationFileNodeKeys()
{
    return;
}

//============================= ACCESSORS ====================================

PointAtomsConfigurationFileNodeKeys * PointAtomsConfigurationFileNodeKeys::clone() const
{
    return new PointAtomsConfigurationFileNodeKeys(*this);
}

std::pair<PointAtomsConfigurationFileNodeKeys::VCI_t_,
          PointAtomsConfigurationFileNodeKeys::VCI_t_> PointAtomsConfigurationFileNodeKeys::allKeysIterator() const
{
    return std::pair<std::vector<std::string>::const_iterator,std::vector<std::string>::const_iterator>(this->externalNodeKeys_.begin(),this->externalNodeKeys_.end());
}

bool PointAtomsConfigurationFileNodeKeys::isKeyPresent(const std::string key) const
{
    bool key_found = true;
    auto it = std::find (this->externalNodeKeys_.begin(), this->externalNodeKeys_.end(), key);
    if ( it == this->externalNodeKeys_.end() )
    {
        key_found = false;
    }
    return key_found;
}

bool PointAtomsConfigurationFileNodeKeys::isCommentKey(const std::string key) const
{
    bool key_is_comment = true;
    auto it = std::find (this->commentNodeKeys_.begin(), this->commentNodeKeys_.end(), key);
    if ( it == this->commentNodeKeys_.end() )
    {
        key_is_comment = false;
    }
    return key_is_comment;
}

std::string PointAtomsConfigurationFileNodeKeys::defaultNullValue() const
{
    return PointAtomsConfigurationFileNodeKeys::DefaultNullValue_;
}

std::string PointAtomsConfigurationFileNodeKeys::node_key( const std::string & global_key) const
{
    VariableKeyFormatPolicy my_key_format_policy{};

    return this->internalToExternalKeyMapping_.at(global_key);
}

std::array<char,2> PointAtomsConfigurationFileNodeKeys::separatorChar() const
{
    return KeyPathSeparatorPeriod::separator_char;
}
//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

PointAtomsConfigurationFileNodeKeys& PointAtomsConfigurationFileNodeKeys::operator= ( const PointAtomsConfigurationFileNodeKeys &other )
{
    if (this != &other)
    {
        this->internalToExternalKeyMapping_ = other.internalToExternalKeyMapping_;
        this->externalNodeKeys_ = other.externalNodeKeys_;
        this->commentNodeKeys_ = other.commentNodeKeys_;
    }
    return *this;
} // assignment operator

PointAtomsConfigurationFileNodeKeys& PointAtomsConfigurationFileNodeKeys::operator= ( PointAtomsConfigurationFileNodeKeys && other )
{
    if (this != &other)
    {
        this->internalToExternalKeyMapping_ = std::move(other.internalToExternalKeyMapping_);
        this->externalNodeKeys_ = std::move(other.externalNodeKeys_);
        this->commentNodeKeys_ = std::move(other.commentNodeKeys_);
    }
    return *this;
} // assignment-move operator

//============================= STATIC    ===================================

std::pair<PointAtomsConfigurationFileNodeKeys::VCI_t_,PointAtomsConfigurationFileNodeKeys::VCI_t_> 
PointAtomsConfigurationFileNodeKeys::all_keys_iterator( PointAtomsConfigurationFileNodeKeys const & object)
{
    return object.allKeysIterator();
}
bool PointAtomsConfigurationFileNodeKeys::does_key_exist(const PointAtomsConfigurationFileNodeKeys & object, const std::string key)
{
    return object.isKeyPresent(key);
}

bool PointAtomsConfigurationFileNodeKeys::is_comment_key(const PointAtomsConfigurationFileNodeKeys & object, const std::string key)
{
    return object.isCommentKey(key);
}

std::array<char,2> PointAtomsConfigurationFileNodeKeys::separator_char(const PointAtomsConfigurationFileNodeKeys & object)
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

std::string PointAtomsConfigurationFileNodeKeys::DefaultNullValue_ = std::string("default-null-value");

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================
void PointAtomsConfigurationFileNodeKeys::addCommentTag_(const std::string & keys)
{
    this->commentNodeKeys_.push_back(keys.c_str());
}

void PointAtomsConfigurationFileNodeKeys::addNodeKey_(const std::string & internal_key, const std::vector<std::string> & external_keys)
{
    // Check each key and make sure no individual external key contains the path separator character.
    // If an external key contains the path separator, then throw
    // an error and abort the program.
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
}


//============================= OPERATORS ====================================


} // namespace ANANSI
