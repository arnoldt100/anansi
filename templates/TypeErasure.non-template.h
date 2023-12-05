#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! \file __header_filename__
//!
//! \brief Brief description
//!
//! Detailed description

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

class __classname__
{
    public:
        // ====================  LIFECYCLE     =======================================

        __classname__();   // constructor

        template<typename T>
        __classname__(T && value) :
            valuePtr_( new __classname__Model<T>(std::forward<T>(value)) )
        {
            return;
        }

        __classname__(const __classname__ & other);   // copy constructor

        __classname__(__classname__ && other);   // copy-move constructor

        ~__classname__();  // destructor

        // ====================  ACCESSORS     =======================================
        __classname__* clone() const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        __classname__& operator=( const __classname__ &other ); // assignment operator

        __classname__& operator=( __classname__ && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        // The concept
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

        // The model.
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
        std::unique_ptr<__classname__Concept> valuePtr_;

}; // -----  end of class __classname__  -----


}; // namespace __NAMESPACE__

#endif // __filepreprocessordefine__
