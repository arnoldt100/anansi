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

// =====================================================================================
//        Class:  CopyOwnershipPolicy
//  Description:  
//  =====================================================================================
//! This class provides methods for implementing copy actions receiver results.
template <typename T>
class CopyOwnershipPolicy : public RECEIVER::ReceiverResultOwnershipPolicy<CopyOwnershipPolicy, T>
{
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
        std::unique_ptr<T> getCopyOwnershipOfObject(std::unique_ptr<T> & my_obj) const
        {
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }

        //! Returns a unique_ptr of the receiver results.
        std::unique_ptr<T> getCopyOwnershipOfObject(std::shared_ptr<T> & my_obj) const
        {
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }
        // ====================  MUTATORS      =======================================

        //! The copy ownership does not allow an object to taken over.
        //!
        //! An error is thrown if invoked.
        std::unique_ptr<T> takeOwnershipOfObject(std::unique_ptr<T> & my_obj)
        {
            const std::string my_err_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(my_err_message);
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }

        //! The copy ownership does not allow an object to taken over.
        //!
        //! An error is thrown if invoked.
        std::unique_ptr<T> takeOwnershipOfObject(std::shared_ptr<T> & my_obj)
        {
            const std::string my_err_message(take_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(my_err_message);
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }

        //! The copy ownership does not allow an object to shared.
        //!
        //! An error is thrown if invoked.
        std::unique_ptr<T> shareOwnershipOfObject(std::unique_ptr<T> & my_obj) 
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(my_err_message);
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
        }

        //! The copy ownership does not allow an object to shared.
        //!
        //! An error is thrown if invoked.
        std::unique_ptr<T> shareOwnershipOfObject(std::shared_ptr<T> & my_obj)
        {
            const std::string my_err_message(shared_error_message_);
            throw ANANSI::ErrorOwnershipPolicy<CopyOwnershipPolicy>(shared_error_message_);
            std::unique_ptr<T> owned_obj;
            return owned_obj; 
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
