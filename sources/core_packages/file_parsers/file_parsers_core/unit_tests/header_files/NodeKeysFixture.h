#ifndef ANANSI_NodeKeysFixture_INC
#define ANANSI_NodeKeysFixture_INC
//! \file NodeKeysFixture.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>
#include <string>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "NodeKeys.h"

namespace ANANSI
{

class NodeKeysFixture
{
    public:
        // ====================  LIFECYCLE     =======================================

        NodeKeysFixture ();   // constructor

        NodeKeysFixture (const NodeKeysFixture & other);   // copy constructor

        NodeKeysFixture (NodeKeysFixture && other);   // copy-move constructor

        ~NodeKeysFixture ();  // destructor

        // ====================  ACCESSORS     =======================================
        NodeKeysFixture * clone () const;

        std::map<std::string,std::string> getMap() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        NodeKeysFixture& operator= ( const NodeKeysFixture &other ); // assignment operator

        NodeKeysFixture& operator= ( NodeKeysFixture && other ); // assignment-move operator

        // ====================  DATA MEMBERS  =======================================

        std::vector<std::string> keys;
        std::vector<std::string> values;
        std::map<std::string,std::string> keyValues;
        ANANSI::NodeKeys nodeKeys;

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class NodeKeysFixture  -----


}; // namespace ANANSI

#endif // ANANSI_NodeKeysFixture_INC