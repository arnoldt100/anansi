#ifndef ANANSI_PointAtoms_INC
#define ANANSI_PointAtoms_INC
//! \file PointAtoms.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! This class stores the point atoms in a spatial domain.
template <typename DataStoragePolicy_t,typename PrecisionPolicy_t>
class PointAtoms
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The default constructor.
        PointAtoms () :
                atomType_{"XXX"},
                atomSymbol_{"XXX"},
                atomGroupType_{"XXX"},
                atomIndex_{-1}
        {
            return;
        }

        //! The copy constructor.
        PointAtoms (const PointAtoms & other)
        {
            if (this != &other)
            {
            }
            return;
        }

        //! The move constructor.
        PointAtoms (PointAtoms && other)  // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }    // -----  end of method PointAtoms::PointAtoms  -----

        ~PointAtoms ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        //! The clone method.
        PointAtoms * clone () const
        {
            return new PointAtoms(*this);
        }


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! The copy assignment operator.
        PointAtoms& operator= ( const PointAtoms &other ) // assignment operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

        //! The move assignment operator.
        PointAtoms& operator= ( PointAtoms && other ) // assignment-move operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string atomType_;
        std::string atomSymbol_;
        std::string atomGroupType_;
        typename PrecisionPolicy_t::ParticleCounter_t atomIndex_;
        typename PrecisionPolicy_t::ParticleCounter_t atomGroupIndex_;
        typename PrecisionPolicy_t::ParticlePositions_t atomXCoordinate_;
        typename PrecisionPolicy_t::ParticlePositions_t atomYCoordinate_;
        typename PrecisionPolicy_t::ParticlePositions_t atomZCoordinate_;
        typename PrecisionPolicy_t::ParticleVelocities_t atomXVelocity_;
        typename PrecisionPolicy_t::ParticleVelocities_t atomYVelocity_;
        typename PrecisionPolicy_t::ParticleVelocities_t atomZVelocity_;

}; // -----  End of class PointAtoms  -----


}; // End of namespace ANANSI

#endif // ANANSI_PointAtoms_INC
