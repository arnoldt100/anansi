#ifndef ANANSI_ParticlesConfigurationFiles_INC
#define ANANSI_ParticlesConfigurationFiles_INC
//! \file ParticlesConfigurationFiles.h
//!
//! \brief Brief description
//!
//! \details Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandFileName.h"
#include "NullPickleType.h"
namespace ANANSI
{

//!  An abstraction for the particle configuration files.
//!
//! The class ControlInputFile is a host class that is an abstraction
//! for the set of control input files in Anansi. The keys values 
//! are implemented via the MasterKeyPolicy.
//!
//! \tparam MasterKeyPolicy The policy class for the keys values of the input file.
//! \tparam ReaderPolicy The policy class for reading the file.
//! \tparam WriterPolicy The policy class for writing the file.
//! \tparam PicklerPolicy The policy class for pickling the file.
template<typename MasterKeyPolicy,
         typename ReaderPolicy,
         typename WriterPolicy,
         typename PicklerPolicy>
class ParticlesConfigurationFiles
{
    public:

        using PICKLEDTYPE = NullPickleType;

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        ParticlesConfigurationFiles ( ) :
            masterKeys_{},
            filename_{},
            ptree_{}
        {
            return;
        }

        //! The copy constructor.
        ParticlesConfigurationFiles (const ParticlesConfigurationFiles & other) :
            masterKeys_{other.masterKeys_},
            filename_{other.filename_},
            ptree_{other.ptree_}
        {
            if (this != &other)
            {
                
            }
            return;
        }

        //! The move constructor.
        ParticlesConfigurationFiles (ParticlesConfigurationFiles && other) :
            masterKeys_{std::move(other.masterKeys_)},
            filename_{std::move(other.filename_)},
            ptree_{std::move(other.ptree_)}
        {
            if (this != &other)
            {
            }
            return;
        } // -----  end of method ParticlesConfigurationFiles::ParticlesConfigurationFiles  -----


        ~ParticlesConfigurationFiles ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        ParticlesConfigurationFiles * clone () const
        {
            return new ParticlesConfigurationFiles(*this);
        }

        PICKLEDTYPE pickleFile() const
        {
            const PicklerPolicy pickler;
            PICKLEDTYPE a_map =  pickler.template pickle<MasterKeyPolicy>(ptree_);
            return a_map;
        }

        //! Returns the node value in ptree_ for the corresponding key.
        //!
        //! \param[in] global_key The key of the node.
        //! \return A std::string is returned, and it is the value of the
        //! node for the boost property tree "ptree_".
        std::string getValue(const std::string & global_key) const
        {
            const auto key = this->masterKeys_.node_key(global_key);
            std::string ret_value = this->ptree_. template get<std::string>(key);
            return ret_value;
        }

        std::string getDefaultNullValue() const
        {
            return this->masterKeys_.defaultNullValue();
        }


        void writeFile(const std::string & filename) const
        {
            const WriterPolicy file_writer;
            file_writer.write(this->ptree_,filename);
            return;
        }

        // ====================  MUTATORS      =======================================
        void setFileName(const CommandFileName & filename)
        {
            this->filename_ = filename;
            return;
        }

        void readFile()
        {
        	std::cout << "Reading Particle Configuration file " << this->filename_() << std::endl;
            const ReaderPolicy file_reader;
            std::string file_name = this->filename_();
            this->ptree_ = file_reader.read(file_name);
            return;
        }

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        ParticlesConfigurationFiles& operator= ( const ParticlesConfigurationFiles &other )
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

        //! The move assignment operator.
        ParticlesConfigurationFiles& operator= ( ParticlesConfigurationFiles && other )
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment-move operator
        
        // ====================  STATIC        =======================================
        //
        static void set_file_name(ParticlesConfigurationFiles & object, const CommandFileName & filename)
        {
            object.setFileName(filename);
        }

        static void read_file(ParticlesConfigurationFiles & object)
        {
            object.readFile();
        }

        void unpickeFile(const PICKLEDTYPE & pickled_obj )
        {
            const PicklerPolicy pickler;
            this->ptree_ = pickler. template unPickle<MasterKeyPolicy>(pickled_obj);
            return;
        }

        static std::string get_value(const ParticlesConfigurationFiles & object, const std::string & global_key)
        {
            return object.getValue(global_key);
        }

        static std::string get_default_null_value(const ParticlesConfigurationFiles & object)
        {
        	std::string ret_value = object.getDefaultNullValue();
            return "";
        }

        static void write_file(const ParticlesConfigurationFiles & object, const std::string & filename)
        {
            object.writeFile(filename);
        }

        static PICKLEDTYPE pickle_file(const ParticlesConfigurationFiles & object)
        {
            return object.pickleFile();
        }

        static void unpickle_file(ParticlesConfigurationFiles & object,const PICKLEDTYPE & pickled_file)
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
        
        //! The internal representation of the file.
        typename MasterKeyPolicy::InternalRepresentationTrait ptree_;

}; // -----  End of class ParticlesConfigurationFiles  -----


}; // End of namespace ANANSI

#endif // ANANSI_ParticlesConfigurationFiles_INC
