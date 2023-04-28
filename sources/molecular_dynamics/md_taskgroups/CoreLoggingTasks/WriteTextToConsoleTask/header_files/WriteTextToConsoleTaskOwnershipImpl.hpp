#ifndef ANANSI_WriteTextToConsoleTaskOwnershipImpl_INC
#define ANANSI_WriteTextToConsoleTaskOwnershipImpl_INC
//! @file WriteTextToConsoleTaskOwnershipImpl.h
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverResultTraits.hpp"
#include "ErrorOwnershipPolicy.hpp"
#include "BaseOwnershipImplementation.h"

namespace ANANSI
{

template<typename MyTaskImplTraits>
class WriteTextToConsoleTaskOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<WriteTextToConsoleTaskOwnershipImpl<MyTaskImplTraits>,
                                                                                         MyTaskImplTraits, 
                                                                                         ErrorOwnershipPolicy>
{
    public:
        using Underlyingtype = int;

        // ====================  LIFECYCLE     =======================================

        WriteTextToConsoleTaskOwnershipImpl ()   // constructor
        {
            return;
        }

        WriteTextToConsoleTaskOwnershipImpl (const WriteTextToConsoleTaskOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        WriteTextToConsoleTaskOwnershipImpl (WriteTextToConsoleTaskOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~WriteTextToConsoleTaskOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        WriteTextToConsoleTaskOwnershipImpl& operator= ( const WriteTextToConsoleTaskOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        WriteTextToConsoleTaskOwnershipImpl& operator= ( WriteTextToConsoleTaskOwnershipImpl && other ) // assignment-move operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

    protected:

        // ====================  ACCESSORS     =======================================

        template<typename T>
        typename MyTaskImplTraits::Copytype  getCopyOfResults_(const T & result) const
        {
            return result;
        }

        // ====================  MUTATORS      =======================================

        template<typename T>
        typename MyTaskImplTraits::Transfertype transferResults_(T & result) const
        {
            return std::move(result);
        }

        template<typename T>
        typename MyTaskImplTraits::Sharetype shareResults_(T & result) const
        {
            return result;
        }


        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class WriteTextToConsoleTaskOwnershipImpl  -----


}; // namespace ANANSI

#endif // ANANSI_WriteTextToConsoleTaskOwnershipImpl_INC
