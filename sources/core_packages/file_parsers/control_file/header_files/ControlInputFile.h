#ifndef ANANSI_ControlInputFile_INC
#define ANANSI_ControlInputFile_INC
//! \file ControlInputFile.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

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
        ControlInputFile* clone() const;

        // ====================  MUTATORS      =======================================
        void setFileName(const CommandFileName & filename);

        void readFile();

        // ====================  OPERATORS     =======================================

        ControlInputFile& operator= ( const ControlInputFile &other ); // assignment operator

        ControlInputFile& operator= ( ControlInputFile && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        CommandFileName filename_;

}; // -----  end of class ControlInputFile  -----

void set_file_name_alt(ANANSI::ControlInputFile & object,ANANSI::CommandFileName filename);

void read_file(ANANSI::ControlInputFile & object);

}; // namespace ANANSI


#endif // ANANSI_ControlInputFile_INC
