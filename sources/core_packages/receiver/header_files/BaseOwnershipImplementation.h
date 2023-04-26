#ifndef RECEIVER_BaseOwnershipImplementation_INC
#define RECEIVER_BaseOwnershipImplementation_INC
//! @file BaseOwnershipImplementation.h
//!
//! Brief description
//!
//! Detailed description

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
#include "ReceiverResultTraits.hpp"
namespace RECEIVER
{

// =====================================================================================
//        Class:  BaseOwnershipImplementation
//  Description:  
//  =====================================================================================
template<typename Derived,
         typename RT, 
         template <typename> typename ErrorPolicy>
class BaseOwnershipImplementation
{
    public:
    
        using Copytype = typename RT::Copytype;
        using Sharetype = typename RT::Sharetype;
        using Transfertype = typename RT::Transfertype;

    private:
        // ====================  ACCESSORS     =======================================

        //! Provides access to the CRTP derived class member methods.
        //!
        //! The goal of this stucture is to better encapsulate (i.e. hide) the
        //! concrete CRTP receivers implementation details. The receievers
        //! implement protected member functions as in ConcretReceiver::foo_. A
        //! function pointer to the address derived pointer member function is
        //! ConcretReceiver::foo_ is formed so that we can indirectly call
        //! ConcretReceiver::foo_.
        struct Accessor_ : public Derived
        {
            //! Provides access to the receiver member receiverGetCopyOfResults_.
            template <typename T>
            static Copytype copy_results(const Derived & derived, const T & result)
            {
                Copytype (Derived::*fn)(const T &) const = &Accessor_::getCopyOfResults_;
                return (derived.*fn)(result);
            }

        template <typename T>
        static Transfertype transfer_results(const Derived & derived, T & result)
        {
            Transfertype (Derived::*fn)(T &) const = &Accessor_::transferResults_;
            return (derived.*fn)(result);
        }

        template <typename T>
        static Sharetype share_results(const Derived & derived, T & result)
        {
            Transfertype (Derived::*fn)(T &) const = &Accessor_::shareResults_;
            return (derived.*fn)(result);
        }
        };

        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to a constant CRTP derived class "Derived".
        constexpr Derived const & asDerived_() const
        {
            return *static_cast<Derived const*>(this);
        }

        // ====================  MUTATORS      =======================================
        
        //! Provides access to the CRTP derived class "Derived."
        //!
        //! @return A reference to the CRTP derived class.
        constexpr Derived& asDerived_() 
        {
            return *static_cast<Derived*>(this);
        }

        // ====================  DATA MEMBERS  =======================================

    public:
        
        // ====================  STATIC        =======================================

        static Sharetype throwSharingError(const std::string & error_message)
        {
            throw ErrorPolicy<Derived>(error_message);
            Sharetype tmp_obj;
            return tmp_obj;
        }

        static Copytype throwCopyingError(const std::string & error_message)
        {
            throw ErrorPolicy<Derived>(error_message);
            Copytype tmp_obj;
            return tmp_obj;
        }
        static Transfertype throwTransferringError(const std::string & error_message)
        {
            throw ErrorPolicy<Derived>(error_message);
            Transfertype tmp_obj;
            return tmp_obj;
        }

        // ====================  LIFECYCLE     =======================================

        BaseOwnershipImplementation ()
        {
            return;
        }

        BaseOwnershipImplementation (const BaseOwnershipImplementation & other)
        {
            if (this != &other)
            {
                
            }
            return;
        }

        BaseOwnershipImplementation (BaseOwnershipImplementation && other)
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method BaseOwnershipImplementation::BaseOwnershipImplementation  -----


        virtual ~BaseOwnershipImplementation ()=0;
        
        // ====================  ACCESSORS     =======================================
        template<typename T>
        Copytype copy( T const & result) const
        {
            return Accessor_::copy_results(this->asDerived_(),result);
}

        template<typename T>
        Sharetype share( T & result)
        {
            return Accessor_::share_results(this->asDerived_(),result);
        }

        template<typename T>
        Transfertype transfer( T & result)
        {
            return Accessor_::transfer_results(this->asDerived_(),result);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        BaseOwnershipImplementation& operator= ( const BaseOwnershipImplementation &other )
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator

        BaseOwnershipImplementation& operator= ( BaseOwnershipImplementation && other )
        {
            if (this != &other)
            {
        
            }
            return *this;
        } // assignment operator
    
    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class BaseOwnershipImplementation  -----

template<typename Derived,
         typename RT, 
         template <typename> typename ErrorPolicy>
BaseOwnershipImplementation<Derived,RT,ErrorPolicy>::~BaseOwnershipImplementation()
{
    return;
}


}; // namespace RECEIVER

#endif // RECEIVER_BaseOwnershipImplementation_INC
