#ifndef ANANSI_ErrorOwnershipPolicy_INC
#define ANANSI_ErrorOwnershipPolicy_INC

//! @file ErrorOwnershipPolicy.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <utility>
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

template <typename T>
class ErrorOwnershipPolicy : public std::exception
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorOwnershipPolicy () : // constructor
            errorMessage_()
        {
            return;
        }

        ErrorOwnershipPolicy ( std::string const & error_message) : // constructor
            errorMessage_(error_message)
        {
            return;
        }

        ErrorOwnershipPolicy (const ErrorOwnershipPolicy & other) :  // copy constructor
            errorMessage_(other.errorMessage_)
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ErrorOwnershipPolicy (ErrorOwnershipPolicy && other) :  // copy-move constructor
            errorMessage_(std::move(other.errorMessage_))
        {
            if (this != &other)
            {
                
            }
            return;
        }

        ~ErrorOwnershipPolicy ()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        const char* what() const noexcept
        {
            return this->errorMessage_.c_str();
        }


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorOwnershipPolicy& operator= ( const ErrorOwnershipPolicy &other ) // assignment operator
        {
            if (this != &other)
            {
                this->errorMessage_ = other.errorMessage_;
            }
            return *this;
        } // assignment operator

        ErrorOwnershipPolicy& operator= ( ErrorOwnershipPolicy && other ) // assignment-move operator
        {
            if (this != &other)
            {
                this->errorMessage_(std::move(other.errorMessage_));
            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;

}; // -----  end of class ErrorOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_ErrorOwnershipPolicy_INC
