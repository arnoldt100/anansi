#ifndef ANANSI_HighPrecision_INC
#define ANANSI_HighPrecision_INC
//! \file HighPrecision.h
//!
//! \brief Brief description
//!
//! \details Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstddef>
#include <string>


//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class HighPrecision
{
    public:

        //! This is the counter type for the number particles.
        using ParticleCounter_t = std::size_t;

        //! The precision for the positions of the particles.
        using ParticlePositions_t = long double;

        //! The precision for the velocities of the particles;
        using ParticleVelocities_t = long double;

        //! The precision for the forces of the particles.
        using ParticleForces_t = long double;

        //! Zero in High precision
        static constexpr auto ZERO = static_cast<long double>(0.00);

        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        HighPrecision ();   // constructor

        //! The copy constructor.
        HighPrecision (const HighPrecision & other);   // copy constructor

        //! The move constructor.
        HighPrecision (HighPrecision && other);   // copy-move constructor

        ~HighPrecision ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        HighPrecision * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        HighPrecision& operator= ( const HighPrecision &other ); // assignment operator

        //! The move assignment operator.
        HighPrecision& operator= ( HighPrecision && other ); // assignment-move operator

        static auto convertStringToPosition(const std::string & a_string)
        {
            return std::stold(a_string);
        }

        static auto convertStringToVelocity(const std::string & a_string)
        {
            return std::stold(a_string);
        }

        static auto convertStringToForce(const std::string & a_string)
        {
            return std::stold(a_string);
        }
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class HighPrecision  -----


}; // End of namespace ANANSI

#endif // ANANSI_HighPrecision_INC
