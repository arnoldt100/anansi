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

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class ParticlesConfigurationFiles
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        ParticlesConfigurationFiles ();   // constructor

        //! The copy constructor.
        ParticlesConfigurationFiles (const ParticlesConfigurationFiles & other);   // copy constructor

        //! The move constructor.
        ParticlesConfigurationFiles (ParticlesConfigurationFiles && other);   // copy-move constructor

        virtual ~ParticlesConfigurationFiles ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        ParticlesConfigurationFiles * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        ParticlesConfigurationFiles& operator= ( const ParticlesConfigurationFiles &other ); // assignment operator

        //! The move assignment operator.
        ParticlesConfigurationFiles& operator= ( ParticlesConfigurationFiles && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class ParticlesConfigurationFiles  -----


}; // End of namespace ANANSI

#endif // ANANSI_ParticlesConfigurationFiles_INC
