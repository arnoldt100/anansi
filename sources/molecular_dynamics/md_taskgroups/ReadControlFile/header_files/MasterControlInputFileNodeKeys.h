#ifndef ANANSI_MasterControlInputFileNodeKeys_INC
#define ANANSI_MasterControlInputFileNodeKeys_INC

//! \file MasterControlInputFileNodeKeys.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>
#include <utility>
#include <cstdarg>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------/
//--------------------------------------------------------//
#include "KeyPathSeparatorPeriod.h"
#include "NodeKeys.h"

namespace ANANSI
{

//!  Contains the all control file node keys.
//!
//! All available keys of the control file are stored in this class. To add
//! a new key, see the default constructor. If the control file
//! uses a key that is not is in MasterControlInputFileNodeKeys, this
//! class, the program will throw an exception and terminate.
class MasterControlInputFileNodeKeys
{
    private:

        using VCI_t_ = std::vector<std::string>::const_iterator;

    public:
        using PathSeparatorTrait = KeyPathSeparatorPeriod;
        using InternalRepresentationTrait = boost::property_tree::ptree;
        static std::string DefaultNullValue;

        // ====================  LIFECYCLE     =======================================

        MasterControlInputFileNodeKeys ();   // constructor

        MasterControlInputFileNodeKeys (const MasterControlInputFileNodeKeys & other);   // copy constructor

        MasterControlInputFileNodeKeys (MasterControlInputFileNodeKeys && other);   // copy-move constructor

        ~MasterControlInputFileNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================

        MasterControlInputFileNodeKeys * clone () const;
        
        //! \brief Returns iterators to the begin and end of the master list of 
        //! control file node keys. 
        //!
        //! The first  and second member elements are respectively 
        //! constant iterators to the beginning and the end of the list.
        //!
        //! \return std::pair<std::vector<std::string>::const_iterator, std::vector<std::string>::const_iterator>. 
        std::pair<MasterControlInputFileNodeKeys::VCI_t_,
                  MasterControlInputFileNodeKeys::VCI_t_> allKeysIterator() const;

        bool isKeyPresent(const std::string key) const;

        bool isCommentKey(const std::string key) const;

        std::array<char,2> separatorChar() const;

        std::string defaultNullValue() const;

        // ====================  MUTATORS      =======================================


        // ====================  OPERATORS     =======================================

        MasterControlInputFileNodeKeys& operator= ( const MasterControlInputFileNodeKeys &other ); // assignment operator

        MasterControlInputFileNodeKeys& operator= ( MasterControlInputFileNodeKeys && other ); // assignment-move operator

        // ====================  STATIC        =======================================

        static bool does_key_exist(const MasterControlInputFileNodeKeys & object, const std::string key);

        static bool is_comment_key(const MasterControlInputFileNodeKeys & object, const std::string key);
        
        static std::pair<VCI_t_,VCI_t_> all_keys_iterator(const MasterControlInputFileNodeKeys & object);

        static std::array<char,2> separator_char(const MasterControlInputFileNodeKeys & object);

        static std::string default_null_value(const MasterControlInputFileNodeKeys & object);

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

}; // -----  end of class MasterControlInputFileNodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_MasterControlInputFileNodeKeys_INC