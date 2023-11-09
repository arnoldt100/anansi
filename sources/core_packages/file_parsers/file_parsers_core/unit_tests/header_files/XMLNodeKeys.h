#ifndef ANANSI_XMLNodeKeys_INC
#define ANANSI_XMLNodeKeys_INC
//! \file XMLNodeKeys.h
//!
//! \brief Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "KeyPathSeparatorPeriod.h"

namespace ANANSI
{

class XMLNodeKeys
{
    private:
        using VCI_t_ = std::vector<std::string>::const_iterator;

    public:
        // ====================  ALIASES       =======================================

        using PathSeparatorTrait = KeyPathSeparatorPeriod;

        // ====================  LIFECYCLE     =======================================

        XMLNodeKeys ();   // constructor

        XMLNodeKeys (const XMLNodeKeys & other);   // copy constructor

        XMLNodeKeys (XMLNodeKeys && other);   // copy-move constructor

        ~XMLNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================
        XMLNodeKeys * clone () const;

        bool isKeyPresent(const std::string key) const;

        std::pair<std::vector<std::string>::const_iterator,
                  std::vector<std::string>::const_iterator> allKeysIterator() const;

        std::array<char,2> separatorChar() const;

        bool isCommentKey(const std::string key) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        XMLNodeKeys& operator= ( const XMLNodeKeys &other ); // assignment operator

        XMLNodeKeys& operator= ( XMLNodeKeys && other ); // assignment-move operator

        // ====================  STATIC        =======================================

        static bool does_key_exist(const XMLNodeKeys & object, const std::string key);

        static std::pair<VCI_t_,VCI_t_> all_keys_iterator(const XMLNodeKeys & object);

        static std::array<char,2> separator_char(const XMLNodeKeys & object);

        static bool is_comment_key(const XMLNodeKeys & object, const std::string key);

        static std::string default_null_value(const XMLNodeKeys & object);

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ALIASES       =======================================

        using InternalRepresentationTrait_ = boost::property_tree::ptree;

        // ====================  STATIC        =======================================

        static std::string DefaultNullValue_;

        // ====================  MUTATORS      =======================================
        void addCommentTag_(const std::string & key);

        //! Adds a key to the master list of keys.
        void addNodeKey_(const std::vector<std::string> & key);

        // ====================  DATA MEMBERS  =======================================
        std::vector<std::string> nodeKeys_;
        std::vector<std::string> commentNodeKeys_;

}; // -----  end of class XMLNodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_XMLNodeKeys_INC
