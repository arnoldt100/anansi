#ifndef ANANSI_ControlInputFile_INC
#define ANANSI_ControlInputFile_INC
//! \file ControlInputFile.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

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
//! \tparam ReaderPolicy The policy class for reading the file.
//! \tparam WriterPolicy The policy class for writing the file.
//! \tparam PicklerPolicy The policy class for pickling the file.
template<typename MasterKeyPolicy,
         typename ReaderPolicy,
         typename WriterPolicy,
         typename PicklerPolicy>
class ControlInputFile
{
    public:

        using PICKLEDTYPE = std::map<std::string,std::string>;

        // ====================  LIFECYCLE     =======================================

        ControlInputFile () :   // constructor
            masterKeys_(),
            filename_(),
            ptree_()
        {
            return;
        }


        ControlInputFile (const ControlInputFile & other) :   // copy constructor
            masterKeys_(other.masterKeys_),
            filename_(other.filename_),
            ptree_(other.ptree_)
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ControlInputFile (ControlInputFile && other) :  // copy-move constructor
            masterKeys_(std::move(other.masterKeys_)),
            filename_(std::move(other.filename_)),
            ptree_(std::move(other.ptree_))
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
            const PicklerPolicy pickler;
            PICKLEDTYPE a_map =  pickler.template pickle<MasterKeyPolicy>(ptree_);
            return a_map;
        }

        //! Returns the node value in ptree_ for the corresponding key.
        //!
        //! \param[in] key The key of the node.
        //! \return A std::string is returned, and it is the value of the
        //! node for the boost property tree "ptree_".
        std::string getValue(const std::string & global_key) const
        {
            const auto key = this->masterKeys_.node_key(global_key);
            std::string ret_value = this->ptree_. template get<std::string>(key);
            return ret_value;
        }

        //! Returns the default node value in ptree_.
        std::string getDefaultNullValue() const
        {
            return this->masterKeys_.defaultNullValue();
        }

        // ====================  MUTATORS      =======================================

        //! Sets the file name of file to be  read or written to.
        //!
        //! \param command_file_name[in] The file name.
        void setFileName(const CommandFileName & file_name)
        {
            this->filename_ = file_name;
        }

        //! Reads the file designated by this->filename_.
        void readFile()
        {
            const ReaderPolicy file_reader;
            std::string file_name = this->filename_();
            this->ptree_ = file_reader.read(file_name);
            return;
        }

        void unpickeFile(const PICKLEDTYPE & pickled_obj )
        {
            const PicklerPolicy pickler;
            this->ptree_ = pickler. template unPickle<MasterKeyPolicy>(pickled_obj);
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

        static void set_file_name(ControlInputFile<MasterKeyPolicy,ReaderPolicy,WriterPolicy,PicklerPolicy> & object,ANANSI::CommandFileName filename)
        {
            object.setFileName(filename);
        }

        static void read_file(ControlInputFile<MasterKeyPolicy,ReaderPolicy,WriterPolicy,PicklerPolicy> & object)
        {
            object.readFile();
        }

        static PICKLEDTYPE pickle_file(const ControlInputFile<MasterKeyPolicy,ReaderPolicy,WriterPolicy,PicklerPolicy> & object)
        {
            return object.pickleFile();
        }

        static void unpickle_file(ControlInputFile<MasterKeyPolicy,ReaderPolicy,WriterPolicy,PicklerPolicy> & object,const PICKLEDTYPE & pickled_file)
        {
            object.unpickeFile(pickled_file);
            return;
        }

        static std::string get_value(const ControlInputFile<MasterKeyPolicy,ReaderPolicy,WriterPolicy,PicklerPolicy> & object, const std::string & global_key)
        {
        	std::string ret_value = object.getValue(global_key);
        	return ret_value;
        }

        static std::string get_default_null_value(const ControlInputFile<MasterKeyPolicy,ReaderPolicy,WriterPolicy,PicklerPolicy> & object)
        {
        	std::string ret_value = object.getDefaultNullValue();
        	return ret_value;
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

        //! The internal representation of the file.
        typename MasterKeyPolicy::InternalRepresentationTrait ptree_;

}; // -----  end of class ControlInputFile  -----

}; // namespace ANANSI


#endif // ANANSI_ControlInputFile_INC
