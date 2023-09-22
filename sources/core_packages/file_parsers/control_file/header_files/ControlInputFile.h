#ifndef ANANSI_ControlInputFile_INC
#define ANANSI_ControlInputFile_INC
//! \file ControlInputFile.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/algorithm/string.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFilePickle.h"
#include "ControlFileTraits.h"
#include "MasterControlFileNodeKeys.h"
#include "ControlFileName.h"
#include "BaseInputFile.h"
#include "add_values_to_property_tree.h"
#include "pickle_ControlFile_property_tree.h"
#include "unpickle_to_property_tree.h"
#include "verify_controlfile_keys_are_valid.h"


//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterControlFileNodeKeys.h"
#include "CommandFileName.h"

namespace ANANSI
{

class ControlInputFile
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlInputFile ();   // constructor

        ControlInputFile (const ControlInputFile & other);   // copy constructor

        ControlInputFile (ControlInputFile && other);   // copy-move constructor

        ~ControlInputFile ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlInputFile& operator= ( const ControlInputFile &other ); // assignment operator

        ControlInputFile& operator= ( ControlInputFile && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        CommandFileName fileName_;
        MasterControlFileNodeKeys masterNodeKeys_;
        boost::property_tree::ptree pt_;
        constexpr static char defaultValue_[] = {"default-null-value"};

}; // -----  end of class ControlInputFile  -----


}; // namespace ANANSI

#endif // ANANSI_ControlInputFile_INC
