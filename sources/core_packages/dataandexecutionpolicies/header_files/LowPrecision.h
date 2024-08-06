#ifndef ANANSI_LowPrecision_INC
#define ANANSI_LowPrecision_INC
//! \file LowPrecision.h
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

class LowPrecision
{
    public:
        //! This is the counter type for the number particles.
        using ParticleCounter_t = std::size_t;

        //! The precision for the positions of the particles.
        using ParticlePositions_t = float;

        //! The precision for the velocities of the particles;
        using ParticleVelocities_t = float;

        //! The precision for the forces of the particles.
        using ParticleForces_t = float;

        //! Zero in low precision
        static constexpr auto ZERO = static_cast<float>(0.00);


        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        LowPrecision ();   // constructor

        //! The copy constructor.
        LowPrecision (const LowPrecision & other);   // copy constructor

        //! The move constructor.
        LowPrecision (LowPrecision && other);   // copy-move constructor

        ~LowPrecision ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        LowPrecision * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        LowPrecision& operator= ( const LowPrecision &other ); // assignment operator

        //! The move assignment operator.
        LowPrecision& operator= ( LowPrecision && other ); // assignment-move operator

        static auto convertStringToPosition(const std::string & a_string)
        {
            return std::stof(a_string);
        }

        static auto convertStringToVelocity(const std::string & a_string)
        {
            return std::stof(a_string);
        }

        static auto convertStringToForce(const std::string & a_string)
        {
            return std::stof(a_string);
        }
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class LowPrecision  -----


}; // End of namespace ANANSI

#endif // ANANSI_LowPrecision_INC
