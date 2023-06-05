#ifndef  ANANSI_ControlFile_INC
#define ANANSI_ControlFile_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFileName.h"
#include "BaseInputFile.h"

namespace ANANSI
{

class ControlFile :public ANANSI::BaseInputFile<ControlFile>
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlFile();   // constructor

        ControlFile (const ControlFile & other);   // copy constructor

        ControlFile (ControlFile && other);   // copy-move constructor

        ~ControlFile ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        void setFileName_(const std::string my_file_name);

        // ====================  OPERATORS     =======================================

        ControlFile& operator=( const ControlFile &other ); // assignment operator

        ControlFile& operator=( ControlFile && other ); // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  MUTATORS      =======================================

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        ControlFileName fileName_;

}; // -----  end of class ControlFile  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFile_INC  ----- 
