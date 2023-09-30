#ifndef ANANSI_ControlInputFile_INC
#define ANANSI_ControlInputFile_INC
//! \file ControlInputFile.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandFileName.h"


//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandFileName.h"

namespace ANANSI
{

//!  An abstraction for the control input file.
//!
//! The class ControlInputFile is a host class that is an abstraction
//! for the set of control input files in Anansi. The keys values 
//! are implemeneted via the MasterKeyPolicy.
//!
//! \tparam  MasterKeyPolicy The policy class for the keys values of the input file.
template<typename MasterKeyPolicy>
class ControlInputFile
{
    public:

        using PICKLEDTYPE = std::map<std::string,std::string>;

        // ====================  LIFECYCLE     =======================================

        ControlInputFile () :   // constructor
            masterKeys_(),
            filename_()
        {
            return;
        }


        ControlInputFile (const ControlInputFile & other) :   // copy constructor
            masterKeys_(other.masterKeys_),
            filename_(other.filename_)
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ControlInputFile (ControlInputFile && other) :  // copy-move constructor
            masterKeys_(std::move(other.masterKeys_)),
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

        //! Clones the class.
        ControlInputFile* clone() const
        {
            return new ControlInputFile(*this);
        }

        PICKLEDTYPE pickleFile() const
        {
            PICKLEDTYPE a_map;
            return a_map;
        }

        // ====================  MUTATORS      =======================================

        //! Sets the file name of file to be  read or wriiten to.
        //!
        //! \param command_file_name[in] The file name.
        void setFileName(const CommandFileName & file_name)
        {
            this->filename_ = file_name;
        }

        //! Reads the file designated by this->filename_.
        void readFile()
        {
           return;
        }

        void unpickeFile(const PICKLEDTYPE & pickled_obj )
        {
            return;
        }

        // ====================  OPERATORS     =======================================

        ControlInputFile& operator= ( const ControlInputFile &other ) // assignment operator
        {
            if (this != &other)
            {
                this->masterKeys_ = other.masterKeys_;
                this->filename_ = other.filename_;
            }
            return *this;
        } // assignment operator

        ControlInputFile& operator= ( ControlInputFile && other ) // assignment-move operator
        {
            if (this != &other)
            {
                this->masterKeys_ = std::move(other.masterKeys_);
                this->filename_ = std::move(other.filename_);
            }
            return *this;
        } // assignment-move operator

        // ====================  STATIC        =======================================

        static void set_file_name(ControlInputFile<MasterKeyPolicy> & object,ANANSI::CommandFileName filename)
        {
            object.setFileName(filename);
        }

        static void read_file(ControlInputFile<MasterKeyPolicy> & object)
        {
            object.readFile();
        }

        static PICKLEDTYPE pickle_file(const ControlInputFile<MasterKeyPolicy> & object)
        {
            return object.pickleFile();
        }

        static void unpickle_file(ControlInputFile<MasterKeyPolicy> & object,const PICKLEDTYPE & pickled_file)
        {
            object.unpickeFile(pickled_file);
            return;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        //! The keys of the control input file. 
        MasterKeyPolicy masterKeys_;

        //! The file name that is to be read or written to.
        CommandFileName filename_;

}; // -----  end of class ControlInputFile  -----

}; // namespace ANANSI


#endif // ANANSI_ControlInputFile_INC
