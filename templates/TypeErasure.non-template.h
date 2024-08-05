#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! \file __header_filename__
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

namespace __NAMESPACE__
{

//! \brief This class wraps other objects that implements the Concepts 
//!        interface.
//! 
//! \details This class is a type erasure for it wraps an object
//!          which then loses its type identity. The wrapped object
//!          must implement the concepts interface or bad program behavior
//!          will occur.
class __classname__
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! \brief The default constructor,
        __classname__();   // constructor

        //! \brief iUse this constructor to initialize the object. 
        template<typename T>
        __classname__(T && value) :
            valuePtr_( new __classname__Model<T>(std::forward<T>(value)) )
        {
            return;
        }

        //! \brief The copy constructor.
        __classname__(const __classname__ & other);   // copy constructor

        //!  The  move constructor.
        __classname__(__classname__ && other);   // copy-move constructor

        //! The destructor.
        ~__classname__();  // destructor

        // ====================  ACCESSORS     =======================================

        //! \brief The class cloning method.
        __classname__* clone() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        //! \brief The copy assignment operator.
        __classname__& operator=( const __classname__ &other ); // assignment operator

        //! \brief The move assignment operator.
        __classname__& operator=( __classname__ && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        //! \brief The concept.
        //!
        //! \details The concept class responsibility is to provide an interface,
        //!          and should have no member data attributes.
        class __classname__Concept
        {
            public: 
                // ====================  LIFECYCLE     =======================================
                __classname__Concept() = default;
                __classname__Concept(const __classname__Concept & other) = default;
                __classname__Concept(__classname__Concept && other) = default;
                virtual ~__classname__Concept()=0;

                // ====================  OPERATORS     =======================================
                __classname__Concept& operator=(const __classname__Concept & other)=default;
                __classname__Concept& operator=(__classname__Concept && other)=default;

                // ====================  ACCESSORS     =======================================
                virtual std::unique_ptr<__classname__Concept> clone() const=0;

                // ====================  MUTATORS      =======================================

        };

        //!  \brief The model.
        //!
        //! \details The model bridges the wrapped object and 
        //!          the concept interface. It stores the wrapped object
        //!          that inmplements ( or models ) the concepts interface,        
        template <typename T>
        class __classname__Model : public __classname__Concept
        {
            public:
                // ====================  LIFECYCLE     =======================================
                __classname__Model() :
                    __classname__Concept(),
                    object_()
                {
                    return;
                };

                __classname__Model(const __classname__Model & other) :
                    __classname__Concept(other),
                    object_(other.object_)
                {
                    if (this != &other)
                    {
                    }
                };

                __classname__Model(__classname__Model && other) :
                    __classname__Concept(std::move(other)),
                    object_(std::move(other.object_))
                {
                    if (this != &other)
                    {
                    }
                };

                explicit __classname__Model(const T & in_value) : 
                    object_(in_value)
                {
                    return;
                };

                // ====================  OPERATORS     =======================================
                __classname__Model& operator=(const __classname__Model & other) 
                {
                    if (this != &other)
                    {
                        __classname__Concept::operator=(other);
                        this->object_ = other.value;
                    }
                    return *this;
                }

                __classname__Model& operator=( __classname__Model && other) 
                {
                    if (this != &other)
                    {
                        __classname__Concept::operator=(std::move(other));
                        this->object_ = std::move(other.value);
                    }
                    return *this;
                }

                // ====================  ACCESSORS     =======================================
                std::unique_ptr<__classname__Concept> clone() const override
                {
                    return std::make_unique<__classname__Model>(*this);
                }

                // ====================  MUTATORS      =======================================

                T object_;
        };
        
        
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        // The actual object that is wrapped.
        std::unique_ptr<__classname__Concept> valuePtr_;

}; // -----  end of class __classname__  -----


}; // ----- End of namespace __NAMESPACE__ -----

#endif // __filepreprocessordefine__
