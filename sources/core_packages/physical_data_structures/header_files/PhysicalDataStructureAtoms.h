//! \file PhysicalDataStructureAtoms.h
#ifndef ANANSI_PhysicalDataStructureAtoms_INC
#define ANANSI_PhysicalDataStructureAtoms_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! \brief This class wraps other objects that implements the Concepts 
//!        interface for physical data structures.
//! 
//! \details This class is a type erasure for it wraps an object
//!          which then loses its type identity. The wrapped object
//!          must implement the concepts interface or bad program behavior
//!          will occur. The types of data structures are lists for particles.
//!          The particles could be point atoms, ellipsoidal
//!          atoms, etc. 
//! \tparam DataStoragePolicy Specifies the data storage policy.
//! \tparam DataPrecisionPolicy Specifies the data precision policy.
template <typename DataStoragePolicy,
          typename DataPrecisionPolicy>
class PhysicalDataStructureAtoms
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! \brief The default constructor,
        PhysicalDataStructureAtoms() :
            valuePtr_(nullptr)
        {
            return;
        }

        template<typename T>
        PhysicalDataStructureAtoms(T && value) :
            valuePtr_( new PhysicalDataStructureAtomsModel<T>(std::forward<T>(value)) )
        {
            return;
        }

        //! \brief The copy constructor.
        PhysicalDataStructureAtoms(const PhysicalDataStructureAtoms & other)   // copy constructor
        {
            if (this != &other)
            {
                this->valuePtr_ = other.valuePtr_->clone();
            }
            return;
        }

        //! \brief The move constructor.
        PhysicalDataStructureAtoms(PhysicalDataStructureAtoms && other)   // copy-move constructor
        {
            if (this != &other)
            {
                this->valuePtr_ = std::move(other.valuePtr_); 
            }
            return;
        }   // -----  end of method PhysicalDataStructureAtoms::PhysicalDataStructureAtoms  -----

        //! The destructor.
        ~PhysicalDataStructureAtoms()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        PhysicalDataStructureAtoms* clone () const
        {
            return new PhysicalDataStructureAtoms(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! \brief The copy assignment operator.
        PhysicalDataStructureAtoms& operator=( const PhysicalDataStructureAtoms &other ) // assignment operator
        {
            if (this != &other)
            {
                this->valuePtr_  = other.valuePtr_->clone();
            }
            return *this;
        } // assignment operator

        //! \brief The move assignment operator.
        PhysicalDataStructureAtoms& operator=( PhysicalDataStructureAtoms && other ) // assignment-move operator
        {
            if (this != &other)
            {
                this->valuePtr_ = std::move(other.valuePtr_);
            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        //! \brief The concept.
        //!
        //! \details The concept class responsibility is to provide an interface,
        //!          and should have no member data attributes.
        class PhysicalDataStructureAtomsConcept
        {
            public: 
                // ====================  LIFECYCLE     =======================================
                PhysicalDataStructureAtomsConcept() = default;
                PhysicalDataStructureAtomsConcept(const PhysicalDataStructureAtomsConcept & other) = default;
                PhysicalDataStructureAtomsConcept(PhysicalDataStructureAtomsConcept && other) = default;
                virtual ~PhysicalDataStructureAtomsConcept()=0;

                // ====================  OPERATORS     =======================================
                PhysicalDataStructureAtomsConcept& operator=(const PhysicalDataStructureAtomsConcept & other)=default;
                PhysicalDataStructureAtomsConcept& operator=(PhysicalDataStructureAtomsConcept && other)=default;

                // ====================  ACCESSORS     =======================================
                virtual std::unique_ptr<PhysicalDataStructureAtomsConcept> clone() const=0;

                //! The number of particles.
                virtual typename DataPrecisionPolicy::ParticleCounter_t numberOfParticles() const=0;

                // ====================  MUTATORS      =======================================

        };

        //! \brief The model.
        //!
        //! \details The model bridges the wrapped object and 
        //!          the concept interface. It stores the wrapped object
        //!          that implements ( or models ) the concepts interface,
        template <typename T>
        class PhysicalDataStructureAtomsModel : public PhysicalDataStructureAtomsConcept
        {
            public:
                // ====================  LIFECYCLE     =======================================
                PhysicalDataStructureAtomsModel() :
                    PhysicalDataStructureAtomsConcept(),
                    object_()
                {
                    return;
                };

                PhysicalDataStructureAtomsModel(const PhysicalDataStructureAtomsModel & other) :
                    PhysicalDataStructureAtomsConcept(other),
                    object_(other.object_)
                {
                    if (this != &other)
                    {
                    }
                };

                PhysicalDataStructureAtomsModel(PhysicalDataStructureAtomsModel && other) :
                    PhysicalDataStructureAtomsConcept(std::move(other)),
                    object_(std::move(other.object_))
                {
                    if (this != &other)
                    {
                    }
                };

                explicit PhysicalDataStructureAtomsModel(const T & in_value) : 
                    object_(in_value)
                {
                    return;
                };

                // ====================  OPERATORS     =======================================
                PhysicalDataStructureAtomsModel& operator=(const PhysicalDataStructureAtomsModel & other) 
                {
                    if (this != &other)
                    {
                        PhysicalDataStructureAtomsConcept::operator=(other);
                        this->object_ = other.value;
                    }
                    return *this;
                }

                PhysicalDataStructureAtomsModel& operator=( PhysicalDataStructureAtomsModel && other) 
                {
                    if (this != &other)
                    {
                        PhysicalDataStructureAtomsConcept::operator=(std::move(other));
                        this->object_ = std::move(other.value);
                    }
                    return *this;
                }

                // ====================  ACCESSORS     =======================================
                std::unique_ptr<PhysicalDataStructureAtomsConcept> clone() const override
                {
                    return std::make_unique<PhysicalDataStructureAtomsModel>(*this);
                }

                typename DataPrecisionPolicy::ParticleCounter_t numberOfParticles() const override
                {
                    return static_cast<typename DataPrecisionPolicy::ParticleCounter_t>(1000);
                }

                // ====================  MUTATORS      =======================================

                T object_;
        };
        
        
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        // The actual object that is wrapped.
        std::unique_ptr<PhysicalDataStructureAtomsConcept> valuePtr_;

}; // -----  end of class PhysicalDataStructureAtoms  -----

template<typename DataStoragePolicy,
         typename DataPrecisionPolicy>
PhysicalDataStructureAtoms<DataStoragePolicy,DataPrecisionPolicy>::PhysicalDataStructureAtomsConcept::~PhysicalDataStructureAtomsConcept()
{
    return;
}


}; // namespace ANANSI

#endif // ANANSI_PhysicalDataStructureAtoms_INC
