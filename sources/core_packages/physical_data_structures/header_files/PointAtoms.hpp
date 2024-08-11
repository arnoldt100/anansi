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
            atomType_{"ZZ"},
            atomSymbol_{"ZZ"},
            atomGroupType_{"ZZ"},
            atomIndex_{0},
            atomGroupIndex_{0},
            atomXCoordinate_{PrecisionPolicy_t::ZERO},
            atomYCoordinate_{PrecisionPolicy_t::ZERO},
            atomZCoordinate_{PrecisionPolicy_t::ZERO},
            atomXVelocity_{PrecisionPolicy_t::ZERO},
            atomYVelocity_{PrecisionPolicy_t::ZERO},
            atomZVelocity_{PrecisionPolicy_t::ZERO},
            atomXForce_{PrecisionPolicy_t::ZERO},
            atomYForce_{PrecisionPolicy_t::ZERO},
            atomZForce_{PrecisionPolicy_t::ZERO}
        {
            return;
        }

        //! The copy constructor.
        PointAtoms (const PointAtoms & other) :
            atomType_{other.atomType_},
            atomSymbol_{other.atomSymbol_},
            atomGroupType_{other.atomGroupType_},
            atomIndex_{other.atomIndex_},
            atomGroupIndex_{other.atomGroupIndex_},
            atomXCoordinate_{other.atomXCoordinate_},
            atomYCoordinate_{other.atomYCoordinate_},
            atomZCoordinate_{other.atomZCoordinate_},
            atomXVelocity_{other.atomXVelocity_},
            atomYVelocity_{other.atomYVelocity_},
            atomZVelocity_{other.atomZVelocity_},
            atomXForce_{other.atomXForce_},
            atomYForce_{other.atomYForce_},
            atomZForce_{other.atomZForce_}
        {
            if (this != &other)
            {
            }
            return;
        }

        //! The move constructor.
        PointAtoms (PointAtoms && other) :  // copy-move constructor
            atomType_{std::move(other.atomType_)},
            atomSymbol_{std::move(other.atomSymbol_)},
            atomGroupType_{std::move(other.atomGroupType_)},
            atomIndex_{std::move(other.atomIndex_)},
            atomGroupIndex_{std::move(other.atomGroupIndex_)},
            atomXCoordinate_{std::move(other.atomXCoordinate_)},
            atomYCoordinate_{std::move(other.atomYCoordinate_)},
            atomZCoordinate_{std::move(other.atomZCoordinate_)},
            atomXVelocity_{std::move(other.atomXVelocity_)},
            atomYVelocity_{std::move(other.atomYVelocity_)},
            atomZVelocity_{std::move(other.atomZVelocity_)},
            atomXForce_{std::move(other.atomXForce_)},
            atomYForce_{std::move(other.atomYForce_)},
            atomZForce_{std::move(other.atomZForce_)}
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
                this->atomType_ = other.atomType_;
                this->atomSymbol_ = other.atomSymbol_;
                this->atomGroupType_ = other.atomGroupType_;
                this->atomIndex_ = other.atomIndex_;
                this->atomGroupIndex_ = other.atomGroupIndex_;
                this->atomXCoordinate_ = other.atomXCoordinate_;
                this->atomYCoordinate_ = other.atomYCoordinate_;
                this->atomZCoordinate_ = other.atomZCoordinate_;
                this->atomXVelocity_ = other.atomXVelocity_;
                this->atomYVelocity_ = other.atomYVelocity_;
                this->atomZVelocity_ = other.atomZVelocity_;
                this->atomXForce_ = other.atomXForce_;
                this->atomYForce_ = other.atomYForce_;
                this->atomZForce_ = other.atomZForce_;
            }
            return *this;
        } // assignment operator

        //! The move assignment operator.
        PointAtoms& operator= ( PointAtoms && other ) // assignment-move operator
        {
            if (this != &other)
            {
                this->atomType_ = std::move(other.atomType_);
                this->atomSymbol_ = std::move(other.atomSymbol_);
                this->atomGroupType_ = std::move(other.atomGroupType_);
                this->atomIndex_ = std::move(other.atomIndex_);
				this->atomGroupIndex_ = std::move(other.atomGroupIndex_);
				this->atomXCoordinate_ = std::move(other.atomXCoordinate_);
				this->atomYCoordinate_ = std::move(other.atomYCoordinate_);
				this->atomZCoordinate_ = std::move(other.atomZCoordinate_);
				this->atomXVelocity_ = std::move(other.atomXVelocity_);
				this->atomYVelocity_ = std::move(other.atomYVelocity_);
				this->atomZVelocity_ = std::move(other.atomZVelocity_);
				this->atomXForce_ = std::move(other.atomXForce_);
				this->atomYForce_ = std::move(other.atomYForce_);
				this->atomZForce_ = std::move(other.atomZForce_);
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
        typename PrecisionPolicy_t::PositionPrecision_t atomXCoordinate_;
        typename PrecisionPolicy_t::PositionPrecision_t atomYCoordinate_;
        typename PrecisionPolicy_t::PositionPrecision_t atomZCoordinate_;
        typename PrecisionPolicy_t::VelocityPrecision_t atomXVelocity_;
        typename PrecisionPolicy_t::VelocityPrecision_t atomYVelocity_;
        typename PrecisionPolicy_t::VelocityPrecision_t atomZVelocity_;
        typename PrecisionPolicy_t::ForcePrecision_t atomXForce_;
        typename PrecisionPolicy_t::ForcePrecision_t atomYForce_;
        typename PrecisionPolicy_t::ForcePrecision_t atomZForce_;

}; // -----  End of class PointAtoms  -----


}; // End of namespace ANANSI

#endif // ANANSI_PointAtoms_INC
