#ifndef ANANSI_PrecisionPolicy_INC
#define ANANSI_PrecisionPolicy_INC
//! \file PrecisionPolicy.h
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
#include "LowPrecision.h"
#include "MediumPrecision.h"
#include "HighPrecision.h"

namespace ANANSI
{

class PrecisionPolicy
{
    public:
        // ====================  LIFECYCLE     =======================================

#if ANANSI_COMPUTE_PRECISION == ANANSI_LOW_COMPUTE_PRECISION
        using Type = LowPrecision;
#elif ANANSI_COMPUTE_PRECISION == ANANSI_MEDIUM_COMPUTE_PRECISION
        using Type = MediumPrecision;
#elif ANANSI_COMPUTE_PRECISION == ANANSI_HIGH_COMPUTE_PRECISION
        using Type = HighPrecision;
#else 
    using Type = MediumPrecision;
#endif

        using PositionPrecision = Type::ParticlePositions_t;
        using VelocityPrecision = Type::ParticleVelocities_t;
        using ForcePrecision = Type::ParticleForces_t;

        //! The default constructor.
        PrecisionPolicy ();   // constructor

        //! The copy constructor.
        PrecisionPolicy (const PrecisionPolicy & other);   // copy constructor

        //! The move constructor.
        PrecisionPolicy (PrecisionPolicy && other);   // copy-move constructor

        ~PrecisionPolicy ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        PrecisionPolicy * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        PrecisionPolicy& operator= ( const PrecisionPolicy &other ); // assignment operator

        //! The move assignment operator.
        PrecisionPolicy& operator= ( PrecisionPolicy && other ); // assignment-move operator

        //! Converts the string reprentation of the particles position to a floating point type.

        static auto convertStringToPosition(const std::string & a_string)
        {
            return Type::convertStringToPosition(a_string);
        }

        static auto convertStringToVelocity(const std::string & a_string)
        {
            return Type::convertStringToVelocity(a_string);
        }

        static auto convertStringToForce(const std::string & a_string)
        {
            return Type::convertStringToForce(a_string);
        }

     protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class PrecisionPolicy  -----


}; // End of namespace ANANSI

#endif // ANANSI_PrecisionPolicy_INC
