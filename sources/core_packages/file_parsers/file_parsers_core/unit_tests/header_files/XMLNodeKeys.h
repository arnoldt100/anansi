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

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "KeyPathSeparator.h"

namespace ANANSI
{

class XMLNodeKeys
{
    public:
        // ====================  ALIASES       =======================================

        using PathSeparatorTrait = KeyPathSeparator;

        // ====================  LIFECYCLE     =======================================

        XMLNodeKeys ();   // constructor

        XMLNodeKeys (const XMLNodeKeys & other);   // copy constructor

        XMLNodeKeys (XMLNodeKeys && other);   // copy-move constructor

        ~XMLNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================
        XMLNodeKeys * clone () const;

        bool isKeyPresent(const std::string key) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        XMLNodeKeys& operator= ( const XMLNodeKeys &other ); // assignment operator

        XMLNodeKeys& operator= ( XMLNodeKeys && other ); // assignment-move operator

        // ====================  STATIC        =======================================
        static bool find(const XMLNodeKeys & object, const std::string key);

        static std::string DefaultNullValue;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ALIASES       =======================================

        using InternalRepresentationTrait_ = boost::property_tree::ptree;

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
