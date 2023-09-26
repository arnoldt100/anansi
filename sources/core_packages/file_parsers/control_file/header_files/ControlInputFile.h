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
#include "ControlFileName.h"
#include "BaseInputFile.h"
#include "add_values_to_property_tree.hpp"
#include "pickle_ControlFile_property_tree.h"
#include "unpickle_to_property_tree.h"
#include "verify_controlfile_keys_are_valid.h"


//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
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

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        KeyPolicyClass masterKeys_;
        CommandFileName filename_;

}; // -----  end of class ControlInputFile  -----

template< typename T>
void set_file_name_alt(T & object,ANANSI::CommandFileName filename)
{
    object.setFileName(filename);
}

template<typename T>
void read_file(T & object)
{
    object.readFile();
}

}; // namespace ANANSI


#endif // ANANSI_ControlInputFile_INC
