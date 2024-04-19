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

template<typename ReaderPolicy>
class ParticlesConfigurationFiles
{
    public:

        using PICKLEDTYPE = NullPickleType;

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        ParticlesConfigurationFiles ( ) :
            filename_{}
        {
            return;
        }

        //! The copy constructor.
        ParticlesConfigurationFiles (const ParticlesConfigurationFiles & other) :
            filename_{other.filename_}
        {
            if (this != &other)
            {
                
            }
            return;
        }

        //! The move constructor.
        ParticlesConfigurationFiles (ParticlesConfigurationFiles && other) :
            filename_{std::move(other.filename_)}
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

        //! Returns the node value in ptree_ for the corresponding key.
        //!
        //! \param[in] global_key The key of the node.
        //! \return A std::string is returned, and it is the value of the
        //! node for the boost property tree "ptree_".
        std::string getValue(const std::string & global_key) const
        {
           return "Dummy_particle_value";
        }

        void writeFile(const std::string & filename) const
        {
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

        static std::string get_value(const ParticlesConfigurationFiles & object, const std::string & global_key)
        {
            return object.getValue(global_key);
        }

        static std::string get_default_null_value(const ParticlesConfigurationFiles & object)
        {
            return "";
        }

        static void write_file(const ParticlesConfigurationFiles & object, const std::string & filename)
        {
            object.writeFile(filename);
        }

        static PICKLEDTYPE pickle_file(const ParticlesConfigurationFiles & object)
        {
            return PICKLEDTYPE{};
        }

        static void unpickle_file(ParticlesConfigurationFiles & object,const PICKLEDTYPE & pickled_file)
        {
            return;
        }

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        CommandFileName filename_;

}; // -----  End of class ParticlesConfigurationFiles  -----


}; // End of namespace ANANSI

#endif // ANANSI_ParticlesConfigurationFiles_INC
