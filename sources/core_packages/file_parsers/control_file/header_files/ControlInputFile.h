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

//!  An abstraction for the control input file.
//!
//! \tparam  KeyPolicyClass The policy class for the keys values of the input file.
template<typename KeyPolicyClass>
class ControlInputFile
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlInputFile () :   // constructor
            filename_()
        {
            return;
        }


        ControlInputFile (const ControlInputFile & other) :   // copy constructor
            filename_(other.filename_)
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ControlInputFile (ControlInputFile && other) :  // copy-move constructor
            filename_(std::move(other.filename_))
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method ControlInputFile::ControlInputFile  -----


        ~ControlInputFile ()  // destructor
        {
            return;
        }


        // ====================  ACCESSORS     =======================================
        ControlInputFile* clone() const
        {
            return new ControlInputFile(*this);
        }

        // ====================  MUTATORS      =======================================
        void setFileName(const CommandFileName & command_file_name)
        {
            this->filename_ = command_file_name;
        }


        void readFile()
        {
           return;
        }

        // ====================  OPERATORS     =======================================

        ControlInputFile& operator= ( const ControlInputFile &other ) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        ControlInputFile& operator= ( ControlInputFile && other ) // assignment-move operator
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment-move operator

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
