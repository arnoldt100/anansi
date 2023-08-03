#ifndef ANANSI_ControlFileNodeKeys_INC
#define ANANSI_ControlFileNodeKeys_INC
//! \file ControlFileNodeKeys.h
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

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

struct SSS
{
};

class ControlFileNodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFileNodeKeys ();   // constructor

        ControlFileNodeKeys (const ControlFileNodeKeys & other);   // copy constructor

        ControlFileNodeKeys (ControlFileNodeKeys && other);   // copy-move constructor

        ~ControlFileNodeKeys ();  // destructor

        // ====================  ACCESSORS     =======================================
        std::pair<std::vector<std::string>::iterator,
                  std::vector<std::string>::iterator> allKeysIterator();

        // ====================  MUTATORS      =======================================
        void add(const std::string key);

        // ====================  OPERATORS     =======================================

        ControlFileNodeKeys& operator= ( const ControlFileNodeKeys &other ); // assignment operator

        ControlFileNodeKeys& operator= ( ControlFileNodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::vector<std::string> nodeKeys_;

}; // -----  end of class ControlFileNodeKeys  -----


}; // namespace ANANSI

#endif // ANANSI_ControlFileNodeKeys_INC
