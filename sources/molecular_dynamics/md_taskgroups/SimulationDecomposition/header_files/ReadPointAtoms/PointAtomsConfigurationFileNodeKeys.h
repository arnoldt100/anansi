#ifndef ANANSI_PointAtomsConfigurationFileNodeKeys_INC
#define ANANSI_PointAtomsConfigurationFileNodeKeys_INC
//! \file PointAtomsConfigurationFileNodeKeys.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "boost/property_tree/ptree.hpp"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "KeyPathSeparatorPeriod.h"

namespace ANANSI
{

class PointAtomsConfigurationFileNodeKeys
{
    private:
        using VCI_t_ = std::vector<std::string>::const_iterator;

    public:
        using PathSeparatorTrait = KeyPathSeparatorPeriod;
        using InternalRepresentationTrait = boost::property_tree::ptree;
        static std::string DefaultNullValue;

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        PointAtomsConfigurationFileNodeKeys ();   // constructor

        //! The copy constructor.
        PointAtomsConfigurationFileNodeKeys (const PointAtomsConfigurationFileNodeKeys & other);   // copy constructor

        //! The move constructor.
        PointAtomsConfigurationFileNodeKeys (PointAtomsConfigurationFileNodeKeys && other);   // copy-move constructor

        ~PointAtomsConfigurationFileNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        PointAtomsConfigurationFileNodeKeys * clone () const;
        
        //! \brief Returns iterators to the begin and end of the master list of 
        //! control file node keys. 
        //!
        //! The first  and second member elements are respectively 
        //! constant iterators to the beginning and the end of the list.
        //!
        //! \return std::pair<std::vector<std::string>::const_iterator, std::vector<std::string>::const_iterator>. 
        std::pair<PointAtomsConfigurationFileNodeKeys::VCI_t_,
                  PointAtomsConfigurationFileNodeKeys::VCI_t_> allKeysIterator() const;

        bool isKeyPresent(const std::string key) const;

        bool isCommentKey(const std::string key) const;

        std::array<char,2> separatorChar() const;

        std::string defaultNullValue() const;

        std::string node_key( const std::string & global_key) const;

        // ====================  MUTATORS      =======================================


        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        PointAtomsConfigurationFileNodeKeys& operator= ( const PointAtomsConfigurationFileNodeKeys &other ); // assignment operator

        //! The move assignment operator.
        PointAtomsConfigurationFileNodeKeys& operator= ( PointAtomsConfigurationFileNodeKeys && other ); // assignment-move operator

        // ====================  STATIC        =======================================
        static bool does_key_exist(const PointAtomsConfigurationFileNodeKeys & object, const std::string key);

        static bool is_comment_key(const PointAtomsConfigurationFileNodeKeys & object, const std::string key);

        static std::pair<VCI_t_,VCI_t_> all_keys_iterator( PointAtomsConfigurationFileNodeKeys const & object);

        static std::array<char,2> separator_char(const PointAtomsConfigurationFileNodeKeys & object);

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        static std::string DefaultNullValue_;

        // ====================  MUTATORS      =======================================

        void addCommentTag_(const std::string & key);

        //! Adds a key to the master list of keys.
        void addNodeKey_(const std::string & global_key,const std::vector<std::string> & key_values);

        // ====================  DATA MEMBERS  =======================================
        std::map<std::string,std::string> internalToExternalKeyMapping_;
        std::vector<std::string> externalNodeKeys_;
        std::vector<std::string> commentNodeKeys_;

}; // -----  End of class PointAtomsConfigurationFileNodeKeys  -----


}; // End of namespace ANANSI

#endif // ANANSI_PointAtomsConfigurationFileNodeKeys_INC
