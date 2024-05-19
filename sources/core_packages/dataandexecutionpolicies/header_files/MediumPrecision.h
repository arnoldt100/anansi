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

        //! This is the counter type for the number particles in a 
        //! PhysicalDataStructures.
        using ParticleCounter_t = std::size_t;

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

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  End of class MediumPrecision  -----


}; // End of namespace ANANSI

#endif // ANANSI_MediumPrecision_INC
