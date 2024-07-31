#ifndef ANANSI_MediumPrecision_INC
#define ANANSI_MediumPrecision_INC
//! \file MediumPrecision.h
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

class MediumPrecision
{
    public:

        //! This is the counter type for the number particles.
        using ParticleCounter_t = std::size_t;

        //! The precision for the positions of the particles.
        using ParticlePositions_t = double;

        //! The precision for the velocities of the particles;
        using ParticleVelocities_t = double;

        //! The precision for the forces of the particles.
        using ParticleForces_t = double;


        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        MediumPrecision ();   // constructor

        //! The copy constructor.
        MediumPrecision (const MediumPrecision & other);   // copy constructor

        //! The move constructor.
        MediumPrecision (MediumPrecision && other);   // copy-move constructor

        ~MediumPrecision ();  // destructor

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        MediumPrecision * clone () const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        MediumPrecision& operator= ( const MediumPrecision &other ); // assignment operator

        //! The move assignment operator.
        MediumPrecision& operator= ( MediumPrecision && other ); // assignment-move operator

        static auto convertStringToPosition(const std::string & a_string)
        {
            return std::stod(a_string);
        }

        static auto convertStringToVelocity(const std::string & a_string)
        {
            return std::stod(a_string);
        }

        static auto convertStringToForce(const std::string & a_string)
        {
            return std::stod(a_string);
        }
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class MediumPrecision  -----


}; // End of namespace ANANSI

#endif // ANANSI_MediumPrecision_INC
