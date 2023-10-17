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
#include "KeyPathSeparator.h"

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
    public:
        using PathSeparatorTrait = KeyPathSeparator;
        using InternalRepresentationTrait = boost::property_tree::ptree;
        static std::string DefaultNullValue;

        // ====================  LIFECYCLE     =======================================

        MasterControlInputFileNodeKeys ();   // constructor

        MasterControlInputFileNodeKeys (const MasterControlInputFileNodeKeys & other);   // copy constructor

        MasterControlInputFileNodeKeys (MasterControlInputFileNodeKeys && other);   // copy-move constructor

        ~MasterControlInputFileNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================
        //! \brief Returns iterators to the begin and end of the master list of 
        //! control file node keys. 
        //!
        //! The first  and second member elements are respectively 
        //! constant iterators to the beginning and the end of the list.
        //!
        //! \return std::pair<std::vector<std::string>::const_iterator, std::vector<std::string>::const_iterator>. 
        std::pair<std::vector<std::string>::const_iterator,
                  std::vector<std::string>::const_iterator> allKeysIterator() const;

        bool find(const std::string key) const;

        bool isCommentTag(const std::string key) const;

        // ====================  MUTATORS      =======================================

        //! Adds a key to the master list of keys.
        void addKeys(const std::vector<std::string> & key);

        void addCommentTag(const std::string key);

        // ====================  OPERATORS     =======================================

        MasterControlInputFileNodeKeys& operator= ( const MasterControlInputFileNodeKeys &other ); // assignment operator

        MasterControlInputFileNodeKeys& operator= ( MasterControlInputFileNodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::vector<std::string> nodeKeys_;
        std::vector<std::string> commentNodeKeys_;

}; // -----  end of class MasterControlInputFileNodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_MasterControlInputFileNodeKeys_INC
