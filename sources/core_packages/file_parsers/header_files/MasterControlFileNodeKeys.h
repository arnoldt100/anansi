#ifndef ANANSI_MasterControlFileNodeKeys_INC
#define ANANSI_MasterControlFileNodeKeys_INC

//! \file MasterControlFileNodeKeys.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{
//!  Contains the all control file node keys.
//!
//! All available keys of the control file are stored in this class. To add
//! a new key, see the default constructor. If the control file
//! uses a key that is not is in MasterControlFileNodeKeys, this
//! class, the program will throw an exception and terminate.
class MasterControlFileNodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        MasterControlFileNodeKeys ();   // constructor

        MasterControlFileNodeKeys (const MasterControlFileNodeKeys & other);   // copy constructor

        MasterControlFileNodeKeys (MasterControlFileNodeKeys && other);   // copy-move constructor

        ~MasterControlFileNodeKeys ();  // destructor

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

        // ====================  MUTATORS      =======================================
        void add(const std::string key);

        // ====================  OPERATORS     =======================================

        MasterControlFileNodeKeys& operator= ( const MasterControlFileNodeKeys &other ); // assignment operator

        MasterControlFileNodeKeys& operator= ( MasterControlFileNodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::vector<std::string> nodeKeys_;

}; // -----  end of class MasterControlFileNodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_MasterControlFileNodeKeys_INC
