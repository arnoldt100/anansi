#ifndef ANANSI_InternalNodeKeys_INC
#define ANANSI_InternalNodeKeys_INC
//! \file InternalNodeKeys.h
//!
//! \brief This is a TypeErasure class for objects that have the semantics of the InternalNodeKeysConcept.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <string>
#include <vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

//! \brief This class wraps other objects that implement the InternalNodeKeysConcept semantics.
//!
//! \details This class is a type erasure for it wraps concrete objects
//!          which then loses its type identity. The concrete objects
//!          must implement the semantics of the InternalNodeKeysConcept or
//!          bad program behavior will occur.
//!
//!          The class `InternalNodeKeysConcept` is a [type erasure](#TypeErasureInheritance) for it wraps
//!          concrete objects which then loses their type identity. The wrapped concrete objects must implement the
//!          semantics of the `InternalNodeKeysConcept` or bad program behavior will occur.
//!
//!          The wrapped concrete objects must implement the following free functions:
//!
//!             - std::string get_internal_node_key(ConcreteInternalNodeKey_Type const & concretSe_object,std::string external_key)
class InternalNodeKeys
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! \brief The default constructor,
        InternalNodeKeys();   // constructor

        //! \brief Use this constructor to initialize the object.
        template<typename T>
        InternalNodeKeys(T && value) :
            valuePtr_( new InternalNodeKeysModel<T>(std::forward<T>(value)) )
        {
            return;
        }

        //! \brief The copy constructor.
        InternalNodeKeys(const InternalNodeKeys & other);   // copy constructor

        //!  The move constructor.
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
                // virtual std::string getInternalNodeKey(const std::string & global_key) const=0;
                virtual std::string getInternalNodeKey(const std::string & global_key,
                                                       const std::vector<std::string> & key_frmt_args) const=0;

                // ====================  MUTATORS      =======================================

        };

        //!  \brief The model.
        //!
        //! \details The model bridges the wrapped object and 
        //!          the concept interface. It stores the wrapped object
        //!          that implements ( or models ) the concepts interface,
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
                        this->object_ = other.object_;
                    }
                    return *this;
                }

                InternalNodeKeysModel& operator=( InternalNodeKeysModel && other) 
                {
                    if (this != &other)
                    {
                        InternalNodeKeysConcept::operator=(std::move(other));
                        this->object_ = std::move(other.object_);
                    }
                    return *this;
                }

                // ====================  ACCESSORS     =======================================
                std::unique_ptr<InternalNodeKeysConcept> clone() const override
                {
                    return std::make_unique<InternalNodeKeysModel>(*this);
                }

                // std::string getInternalNodeKey(const std::string & global_key) const override
                // {
                //     return get_internal_node_key(this->object_,global_key);
                // }

                std::string getInternalNodeKey(const std::string & global_key, const std::vector<std::string> & key_frmt_args) const override
                {
                    return get_internal_node_key(this->object_,global_key,key_frmt_args);
                }

                // ====================  MUTATORS      =======================================

                T object_;
        };

        // friend std::string get_internal_node_key( const InternalNodeKeys & internal_node_key,std::string const & global_key)
        // {
        //     return internal_node_key.valuePtr_->getInternalNodeKey(global_key);
        // }

        friend std::string get_internal_node_key( const InternalNodeKeys & internal_node_key,std::string const & global_key,
            const std::vector<std::string> & key_frmt_args = std::vector<std::string>{} )
        {
            return internal_node_key.valuePtr_->getInternalNodeKey(global_key,key_frmt_args);
        }

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        // The actual object that is wrapped.
        std::unique_ptr<InternalNodeKeysConcept> valuePtr_;

}; // -----  end of class InternalNodeKeys  -----


}; // ----- End of namespace ANANSI -----

#endif // ANANSI_InternalNodeKeys_INC
