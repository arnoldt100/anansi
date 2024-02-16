//! \file PhysicalDataStructure.h
#ifndef ANANSI_PhysicalDataStructure_INC
#define ANANSI_PhysicalDataStructure_INC

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
//!          will occur. The types of data structures are lists like
//!          a list of atoms. The atoms could be point atoms, ellipsoidal
//!          atoms, etc. Quantities such as position, velocities, charge, etc.
//!          are properties of atoms and for this class not defined as physical
//!          dats structures.
class PhysicalDataStructure
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! \brief The default constructor,
        PhysicalDataStructure();

        template<typename T>
        PhysicalDataStructure(T && value) :
            valuePtr_( new PhysicalDataStructureModel<T>(std::forward<T>(value)) )
        {
            return;
        }

        //! \brief The copy constructor.
        PhysicalDataStructure(const PhysicalDataStructure & other);   // copy constructor

        //! \brief The move constructor.
        PhysicalDataStructure(PhysicalDataStructure && other);   // copy-move constructor

        //! The destructor.
        ~PhysicalDataStructure();  // destructor

        // ====================  ACCESSORS     =======================================

        //! \brief The class cloning method.
        PhysicalDataStructure* clone() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! \brief The copy assignment operator.
        PhysicalDataStructure& operator=( const PhysicalDataStructure &other ); // assignment operator

        //! \brief The move assignment operator.
        PhysicalDataStructure& operator=( PhysicalDataStructure && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        //! \brief The concept.
        //!
        //! \details The concept class responsibility is to provide an interface,
        //!          and should have no member data attributes.
        class PhysicalDataStructureConcept
        {
            public: 
                // ====================  LIFECYCLE     =======================================
                PhysicalDataStructureConcept() = default;
                PhysicalDataStructureConcept(const PhysicalDataStructureConcept & other) = default;
                PhysicalDataStructureConcept(PhysicalDataStructureConcept && other) = default;
                virtual ~PhysicalDataStructureConcept()=0;

                // ====================  OPERATORS     =======================================
                PhysicalDataStructureConcept& operator=(const PhysicalDataStructureConcept & other)=default;
                PhysicalDataStructureConcept& operator=(PhysicalDataStructureConcept && other)=default;

                // ====================  ACCESSORS     =======================================
                virtual std::unique_ptr<PhysicalDataStructureConcept> clone() const=0;

                // ====================  MUTATORS      =======================================

        };

        //! \brief The model.
        //!
        //! \details The model bridges the wrapped object and 
        //!          the concept interface. It stores the wrapped object
        //!          that inmplements ( or models ) the concepts interface,        
        template <typename T>
        class PhysicalDataStructureModel : public PhysicalDataStructureConcept
        {
            public:
                // ====================  LIFECYCLE     =======================================
                PhysicalDataStructureModel() :
                    PhysicalDataStructureConcept(),
                    object_()
                {
                    return;
                };

                PhysicalDataStructureModel(const PhysicalDataStructureModel & other) :
                    PhysicalDataStructureConcept(other),
                    object_(other.object_)
                {
                    if (this != &other)
                    {
                    }
                };

                PhysicalDataStructureModel(PhysicalDataStructureModel && other) :
                    PhysicalDataStructureConcept(std::move(other)),
                    object_(std::move(other.object_))
                {
                    if (this != &other)
                    {
                    }
                };

                explicit PhysicalDataStructureModel(const T & in_value) : 
                    object_(in_value)
                {
                    return;
                };

                // ====================  OPERATORS     =======================================
                PhysicalDataStructureModel& operator=(const PhysicalDataStructureModel & other) 
                {
                    if (this != &other)
                    {
                        PhysicalDataStructureConcept::operator=(other);
                        this->object_ = other.value;
                    }
                    return *this;
                }

                PhysicalDataStructureModel& operator=( PhysicalDataStructureModel && other) 
                {
                    if (this != &other)
                    {
                        PhysicalDataStructureConcept::operator=(std::move(other));
                        this->object_ = std::move(other.value);
                    }
                    return *this;
                }

                // ====================  ACCESSORS     =======================================
                std::unique_ptr<PhysicalDataStructureConcept> clone() const override
                {
                    return std::make_unique<PhysicalDataStructureModel>(*this);
                }

                // ====================  MUTATORS      =======================================

                T object_;
        };
        
        
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        // The actual object that is wrapped.
        std::unique_ptr<PhysicalDataStructureConcept> valuePtr_;

}; // -----  end of class PhysicalDataStructure  -----


}; // namespace ANANSI

#endif // ANANSI_PhysicalDataStructure_INC
