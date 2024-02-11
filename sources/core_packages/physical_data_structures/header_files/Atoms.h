#ifndef ANANSI_Atoms_INC
#define ANANSI_Atoms_INC
//! \file Atoms.h

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

//! \brief This class wraps other objects that implements the Atoms concepts 
//!        interface.
//! 
//! \details This class is a type erasure for it wraps an object
//!          which then loses its type identity. The wrapped object
//!          must implement the concepts interface or bad program behavior
//!          will occur.
class Atoms
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! \brief The default constructor,
        Atoms();   // constructor

        //! \brief iUse this constructor to initialize the object. 
        template<typename T>
        Atoms(T && value) :
            valuePtr_( new AtomsModel<T>(std::forward<T>(value)) )
        {
            return;
        }

        //! \brief The copy constructor.
        Atoms(const Atoms & other);   // copy constructor

        //!  The  move constructor.
        Atoms(Atoms && other);   // copy-move constructor

        //! The destructor.
        ~Atoms();  // destructor

        // ====================  ACCESSORS     =======================================

        //! \brief The class cloning method.
        Atoms* clone() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! \brief The copy assignment operator.
        Atoms& operator=( const Atoms &other ); // assignment operator

        //! \brief The move assignment operator.
        Atoms& operator=( Atoms && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        //! \brief The concept.
        //!
        //! \details The concept class responsibility is to provide an interface,
        //!          and should have no member data attributes.
        class AtomsConcept
        {
            public: 
                // ====================  LIFECYCLE     =======================================
                AtomsConcept() = default;
                AtomsConcept(const AtomsConcept & other) = default;
                AtomsConcept(AtomsConcept && other) = default;
                virtual ~AtomsConcept()=0;

                // ====================  OPERATORS     =======================================
                AtomsConcept& operator=(const AtomsConcept & other)=default;
                AtomsConcept& operator=(AtomsConcept && other)=default;

                // ====================  ACCESSORS     =======================================
                virtual std::unique_ptr<AtomsConcept> clone() const=0;

                // ====================  MUTATORS      =======================================

        };

        //!  \brief The model.
        //!
        //! \details The model bridges the wrapped object and 
        //!          the concept interface. It stores the wrapped object
        //!          that inmplements ( or models ) the concepts interface,        
        template <typename T>
        class AtomsModel : public AtomsConcept
        {
            public:
                // ====================  LIFECYCLE     =======================================
                AtomsModel() :
                    AtomsConcept(),
                    object_()
                {
                    return;
                };

                AtomsModel(const AtomsModel & other) :
                    AtomsConcept(other),
                    object_(other.object_)
                {
                    if (this != &other)
                    {
                    }
                };

                AtomsModel(AtomsModel && other) :
                    AtomsConcept(std::move(other)),
                    object_(std::move(other.object_))
                {
                    if (this != &other)
                    {
                    }
                };

                explicit AtomsModel(const T & in_value) : 
                    object_(in_value)
                {
                    return;
                };

                // ====================  OPERATORS     =======================================
                AtomsModel& operator=(const AtomsModel & other) 
                {
                    if (this != &other)
                    {
                        AtomsConcept::operator=(other);
                        this->object_ = other.value;
                    }
                    return *this;
                }

                AtomsModel& operator=( AtomsModel && other) 
                {
                    if (this != &other)
                    {
                        AtomsConcept::operator=(std::move(other));
                        this->object_ = std::move(other.value);
                    }
                    return *this;
                }

                // ====================  ACCESSORS     =======================================
                std::unique_ptr<AtomsConcept> clone() const override
                {
                    return std::make_unique<AtomsModel>(*this);
                }

                // ====================  MUTATORS      =======================================

                T object_;
        };
        
        
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        // The actual object that is wrapped.
        std::unique_ptr<AtomsConcept> valuePtr_;

}; // -----  End of class Atoms  -----

}; // -----  End of namespace Anansi  -----

#endif // ANANSI_Atoms_INC
