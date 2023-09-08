#ifndef  ANANSI_ControlFile_INC
#define ANANSI_ControlFile_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFileTraits.h"
#include "MasterControlFileNodeKeys.h"
#include "ControlFileName.h"
#include "BaseInputFile.h"

namespace ANANSI
{

class ControlFile : public ANANSI::BaseInputFile<ControlFile,ControlFileTraits>
{
    public:

        // ====================  LIFECYCLE     =======================================

        ControlFile();   // constructor

        ControlFile (const ControlFile & other);   // copy constructor

        ControlFile (ControlFile && other);   // copy-move constructor

        ~ControlFile ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFile& operator=( const ControlFile &other ); // assignment operator

        ControlFile& operator=( ControlFile && other ); // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================
        void writeToDisk_(const std::string my_file_name) const;

        // ====================  MUTATORS      =======================================
        void setFileName_(const std::string my_file_name);

        void readPropertyTree_(boost::property_tree::ptree & pt);

        ControlFileTraits::PICKLETYPE pickle_() const;

        void unpickle_(const ControlFileTraits::PICKLETYPE & pickle_obj);

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  MUTATORS      =======================================
        
        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================
        ControlFileName fileName_;
        MasterControlFileNodeKeys masterNodeKeys_;
        boost::property_tree::ptree pt_;
        constexpr static char defaultValue_[] = {"default-null-value"};

    public:
}; // -----  end of class ControlFile  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFile_INC  ----- 
