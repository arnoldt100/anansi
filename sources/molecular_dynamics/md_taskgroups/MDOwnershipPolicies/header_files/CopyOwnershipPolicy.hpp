#ifndef ANANSI_CopyOwnershipPolicy_INC
#define ANANSI_CopyOwnershipPolicy_INC
//! @file CopyOwnershipPolicy.hpp
//!
//! Brief description
//!
//! Detailed description

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

//! This class provides methods for implementing copy actions receiver results.
template <typename T>
class CopyOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<CopyOwnershipPolicy, T>
{
    private:
        using unique_type = typename RECEIVER::ReceiverResultOwnershipPolicy<CopyOwnershipPolicy, T>::unique_type;
        using shared_type = typename RECEIVER::ReceiverResultOwnershipPolicy<CopyOwnershipPolicy, T>::shared_type;

    public:
        // ====================  LIFECYCLE     =======================================

        CopyOwnershipPolicy ()   // constructor
        {
            return;
        }

        CopyOwnershipPolicy (const CopyOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }

        CopyOwnershipPolicy (CopyOwnershipPolicy && other)   // copy-move constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }		// -----  end of method CopyOwnershipPolicy::CopyOwnershipPolicy  -----

        ~CopyOwnershipPolicy ()
        {
            return;
        };  // destructor

        // ====================  ACCESSORS     =======================================

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the unique_ptr is copied to an object of
        //! unique_type and returned to the invoker.
        unique_type getCopyOwnershipOfObject(unique_type & my_obj) const
        {
            T* tmp_obj = new T(*my_obj);
            unique_type unique_obj(tmp_obj);
            return unique_obj; 
        }

        //! Returns a unique_ptr of the receiver results.
        //!
        //! The underlying object of the shared_ptr is copied to an object of
        //! unique_type and returned to the invoker.
        unique_type getCopyOwnershipOfObject(shared_type & my_obj) const
        {
            T* tmp_obj = new T(*my_obj);
            unique_type unique_obj(tmp_obj);
            return unique_obj; 
        }

        // ====================  MUTATORS      =======================================

        //! The copy ownership policy does not allow an object to taken over.
        //!
        //! An error is thrown if invoked.
        unique_type takeOwnershipOfObject(unique_type & my_obj)
        {
            const std::string my_err_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(my_err_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! The copy ownership does not allow an object to taken over.
        //!
        //! An error is thrown if invoked.
        unique_type takeOwnershipOfObject(shared_type & my_obj)
        {
            const std::string my_err_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(my_err_message);
            unique_type unique_obj;
            return unique_obj; 
        }

        //! The copy ownership does not allow an object to shared.
        //!
        //! An error is thrown if invoked.
        shared_type shareOwnershipOfObject(unique_type & my_obj) 
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(my_err_message);
            shared_type shared_obj;
            return shared_obj; 
        }

        //! The copy ownership does not allow an object to shared.
        //!
        //! An error is thrown if invoked.
        shared_type shareOwnershipOfObject(shared_type & my_obj)
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(shared_error_message_);
            shared_type shared_obj;
            return shared_obj; 
        }

        // ====================  OPERATORS     =======================================

        CopyOwnershipPolicy& operator= ( const CopyOwnershipPolicy &other ) // assignment operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator


        CopyOwnershipPolicy& operator= ( CopyOwnershipPolicy && other ) // assignment-move operator
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
            std::string_view("The CopyOwnershipPolicy does not permit the receiver result to be shared.");

        static constexpr std::string_view take_error_message_ = 
            std::string_view("The CopyOwnershipPolicy does not permit the receiver result to be taken over.");

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class CopyOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_CopyOwnershipPolicy_INC
