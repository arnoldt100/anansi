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

class ParticlesConfigurationFiles
{
    public:

        using PICKLEDTYPE = NullPickleType;

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        ParticlesConfigurationFiles ();   // constructor

        //! The copy constructor.
        ParticlesConfigurationFiles (const ParticlesConfigurationFiles & other);   // copy constructor

        //! The move constructor.
        ParticlesConfigurationFiles (ParticlesConfigurationFiles && other);   // copy-move constructor

        ~ParticlesConfigurationFiles ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        ParticlesConfigurationFiles * clone () const;

        std::string getValue(const std::string & global_key) const;

        void writeFile(const std::string &  filename) const;

        // ====================  MUTATORS      =======================================
        void setFileName(const CommandFileName & filename);

        void readFile();

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        ParticlesConfigurationFiles& operator= ( const ParticlesConfigurationFiles &other ); // assignment operator

        //! The move assignment operator.
        ParticlesConfigurationFiles& operator= ( ParticlesConfigurationFiles && other ); // assignment-move operator
        
        // ====================  STATIC        =======================================
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
