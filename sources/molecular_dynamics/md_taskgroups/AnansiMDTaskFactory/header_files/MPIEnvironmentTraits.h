#ifndef ANANSI_MPIEnvironmentTraits_INC
#define ANANSI_MPIEnvironmentTraits_INC
//! @file MPIEnvironmentTraits.h
//!
//! Brief description
//!
//! Detailed description

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

class MPIEnvironmentTraits final
{
    public:
        // ====================  LIFECYCLE     =======================================

        MPIEnvironmentTraits ();   // constructor

        MPIEnvironmentTraits (const MPIEnvironmentTraits & other);   // copy constructor

        MPIEnvironmentTraits (MPIEnvironmentTraits && other);   // copy-move constructor

        ~MPIEnvironmentTraits ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MPIEnvironmentTraits& operator= ( const MPIEnvironmentTraits &other ); // assignment operator

        MPIEnvironmentTraits& operator= ( MPIEnvironmentTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MPIEnvironmentTraits  -----


}; // namespace ANANSI

#endif // ANANSI_MPIEnvironmentTraits_INC
