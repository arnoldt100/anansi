#ifndef  ANANSI_ControlFile_INC
#define ANANSI_ControlFile_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MasterControlFileNodeKeys.h"
#include "ControlFileName.h"
#include "BaseInputFile.h"

namespace ANANSI
{

class ControlFile : public ANANSI::BaseInputFile<ControlFile>
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
        void writeToDisk_(const std::string my_file_name);

        // ====================  MUTATORS      =======================================
        void setFileName_(const std::string my_file_name);

        void readPropertyTree_(boost::property_tree::ptree & pt);


        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  MUTATORS      =======================================
        
        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================
        ControlFileName fileName_;
        MasterControlFileNodeKeys masterNodeKeys_;
        boost::property_tree::ptree pt_;
        constexpr static char defaultValue_[] = {"default-null-value"};


}; // -----  end of class ControlFile  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFile_INC  ----- 
