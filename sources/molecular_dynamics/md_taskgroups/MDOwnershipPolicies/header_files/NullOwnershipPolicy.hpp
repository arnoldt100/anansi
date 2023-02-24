#ifndef ANANSI_NullOwnershipPolicy_INC
#define ANANSI_NullOwnershipPolicy_INC
//! @file NullOwnershipPolicy.hpp
//!
//! Contains the declaration for class NullOwnershipPolicy.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string.h>
#include <utility>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ErrorOwnershipPolicy.hpp"
#include "ReceiverResultOwnershipPolicy.hpp"

namespace ANANSI
{

//! This class provides methods for implementing null actions receiver results.
template <typename T>
class NullOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<NullOwnershipPolicy, T>
{
    private:
        using nop_unique_type = typename RECEIVER::ReceiverResultOwnershipPolicy<NullOwnershipPolicy, T>::unique_type;
        using nop_shared_type = typename RECEIVER::ReceiverResultOwnershipPolicy<NullOwnershipPolicy, T>::shared_type;

    public:
        // ====================  LIFECYCLE     =======================================

        NullOwnershipPolicy ()   // constructor
        {
            return;
        }

        NullOwnershipPolicy (const NullOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        NullOwnershipPolicy (NullOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method NullOwnershipPolicy::NullOwnershipPolicy  -----

        ~NullOwnershipPolicy ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================
        
        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! copied.
        std::unique_ptr<T> copyOwnershipOfObject(std::unique_ptr<T> & my_obj)
        {
            const std::string my_error_message(copy_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>(my_error_message);
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! copied.
        std::unique_ptr<T> copyOwnershipOfObject(std::shared_ptr<T> & my_obj)
        {
            const std::string my_error_message(copy_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>(my_error_message);
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }


        // ====================  MUTATORS      =======================================

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        std::unique_ptr<T> takeOwnershipOfObject(std::unique_ptr<T> & my_obj)
        {
            std::string my_error_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>(my_error_message);
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! taken over.
        std::unique_ptr<T> takeOwnershipOfObject(std::shared_ptr<T> & my_obj)
        {
            std::string my_error_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>(take_error_message_);
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }

        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! shared.
        std::unique_ptr<T> shareOwnershipOfObject(std::shared_ptr<T> & my_obj)
        {
            std::string my_error_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>(my_error_message);
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }
        
        //! Throws runtime error if invoked.
        //!
        //! The NullOwnershipPolicy doesn't allow the receiver results to be
        //! shared.
        std::unique_ptr<T> shareOwnershipOfObject(std::unique_ptr<T> & my_obj)
        {
            std::string my_error_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<NullOwnershipPolicy>(my_error_message);
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }
        
        // ====================  OPERATORS     =======================================

        NullOwnershipPolicy& operator= ( const NullOwnershipPolicy &other) // assignment operator
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator


        NullOwnershipPolicy& operator= ( NullOwnershipPolicy && other ) // assignment-move operator
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
        // ====================  STATIC       =======================================
        static constexpr std::string_view shared_error_message_ = 
            std::string_view("The NullOwnershipPolicy does not permit the receiver result to be shared.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The NullOwnershipPolicy does not permit the receiver result to be taken over.");

        static constexpr std::string_view copy_error_message_ = 
            std::string_view("The NullOwnershipPolicy does not permit the receiver result to be copied.");


        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class NullOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_NullOwnershipPolicy_INC
