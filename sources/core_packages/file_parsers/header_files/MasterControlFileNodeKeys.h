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

class MasterControlFileNodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        MasterControlFileNodeKeys ();   // constructor

        MasterControlFileNodeKeys (const MasterControlFileNodeKeys & other);   // copy constructor

        MasterControlFileNodeKeys (MasterControlFileNodeKeys && other);   // copy-move constructor

        ~MasterControlFileNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================
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
