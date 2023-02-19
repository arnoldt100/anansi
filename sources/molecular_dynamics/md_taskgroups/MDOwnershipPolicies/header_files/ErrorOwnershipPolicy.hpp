#ifndef ANANSI_ErrorOwnershipPolicy_INC
#define ANANSI_ErrorOwnershipPolicy_INC

//! @file ErrorOwnershipPolicy.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
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

        ErrorOwnershipPolicy ()   // constructor
        {
            return;
        }

        ErrorOwnershipPolicy (const ErrorOwnershipPolicy & other)   // copy constructor
        {
            if (this != &other)
            {
                
            }
            return;
        }


        ErrorOwnershipPolicy (ErrorOwnershipPolicy && other)   // copy-move constructor
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
            return "Ownnership exception thown.";
        }


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorOwnershipPolicy& operator= ( const ErrorOwnershipPolicy &other ) // assignment operator
        {
            if (this != &other)
            {
            }
            return *this;
        } // assignment operator

        ErrorOwnershipPolicy& operator= ( ErrorOwnershipPolicy && other ) // assignment-move operator
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
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ErrorOwnershipPolicy  -----


}; // namespace ANANSI

#endif // ANANSI_ErrorOwnershipPolicy_INC
