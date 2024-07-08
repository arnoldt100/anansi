#ifndef ANANSI_InternalNodeKeys_INC
#define ANANSI_InternalNodeKeys_INC
//! \file InternalNodeKeys.h
//!
//! \brief Brief description
//!
//! \details Detailed description

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
//!        interface.
//! 
//! \details This class is a type erasure for it wraps an object
//!          which then loses its type identity. The wrapped object
//!          must implement the concepts interface or bad program behavior
//!          will occur.
class InternalNodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! \brief The default constructor,
        InternalNodeKeys();   // constructor

        //! \brief iUse this constructor to initialize the object. 
        template<typename T>
        InternalNodeKeys(T && value) :
            valuePtr_( new InternalNodeKeysModel<T>(std::forward<T>(value)) )
        {
            return;
        }

        //! \brief The copy constructor.
        InternalNodeKeys(const InternalNodeKeys & other);   // copy constructor

        //!  The  move constructor.
        InternalNodeKeys(InternalNodeKeys && other);   // copy-move constructor

        //! The destructor.
        ~InternalNodeKeys();  // destructor

        // ====================  ACCESSORS     =======================================

        //! \brief The class cloning method.
        InternalNodeKeys* clone() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! \brief The copy assignment operator.
        InternalNodeKeys& operator=( const InternalNodeKeys &other ); // assignment operator

        //! \brief The move assignment operator.
        InternalNodeKeys& operator=( InternalNodeKeys && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        //! \brief The concept.
        //!
        //! \details The concept class responsibility is to provide an interface,
        //!          and should have no member data attributes.
        class InternalNodeKeysConcept
        {
            public: 
                // ====================  LIFECYCLE     =======================================
                InternalNodeKeysConcept() = default;
                InternalNodeKeysConcept(const InternalNodeKeysConcept & other) = default;
                InternalNodeKeysConcept(InternalNodeKeysConcept && other) = default;
                virtual ~InternalNodeKeysConcept()=0;

                // ====================  OPERATORS     =======================================
                InternalNodeKeysConcept& operator=(const InternalNodeKeysConcept & other)=default;
                InternalNodeKeysConcept& operator=(InternalNodeKeysConcept && other)=default;

                // ====================  ACCESSORS     =======================================
                virtual std::unique_ptr<InternalNodeKeysConcept> clone() const=0;

                // ====================  MUTATORS      =======================================

        };

        //!  \brief The model.
        //!
        //! \details The model bridges the wrapped object and 
        //!          the concept interface. It stores the wrapped object
        //!          that inmplements ( or models ) the concepts interface,        
        template <typename T>
        class InternalNodeKeysModel : public InternalNodeKeysConcept
        {
            public:
                // ====================  LIFECYCLE     =======================================
                InternalNodeKeysModel() :
                    InternalNodeKeysConcept(),
                    object_()
                {
                    return;
                };

                InternalNodeKeysModel(const InternalNodeKeysModel & other) :
                    InternalNodeKeysConcept(other),
                    object_(other.object_)
                {
                    if (this != &other)
                    {
                    }
                };

                InternalNodeKeysModel(InternalNodeKeysModel && other) :
                    InternalNodeKeysConcept(std::move(other)),
                    object_(std::move(other.object_))
                {
                    if (this != &other)
                    {
                    }
                };

                explicit InternalNodeKeysModel(const T & in_value) : 
                    object_(in_value)
                {
                    return;
                };

                // ====================  OPERATORS     =======================================
                InternalNodeKeysModel& operator=(const InternalNodeKeysModel & other) 
                {
                    if (this != &other)
                    {
                        InternalNodeKeysConcept::operator=(other);
                        this->object_ = other.value;
                    }
                    return *this;
                }

                InternalNodeKeysModel& operator=( InternalNodeKeysModel && other) 
                {
                    if (this != &other)
                    {
                        InternalNodeKeysConcept::operator=(std::move(other));
                        this->object_ = std::move(other.value);
                    }
                    return *this;
                }

                // ====================  ACCESSORS     =======================================
                std::unique_ptr<InternalNodeKeysConcept> clone() const override
                {
                    return std::make_unique<InternalNodeKeysModel>(*this);
                }

                // ====================  MUTATORS      =======================================

                T object_;
        };
        
        
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        // The actual object that is wrapped.
        std::unique_ptr<InternalNodeKeysConcept> valuePtr_;

}; // -----  end of class InternalNodeKeys  -----


}; // ----- End of namespace ANANSI -----

#endif // ANANSI_InternalNodeKeys_INC
