#ifndef ANANSI_ControlFileMacroOwnershipImpl_INC
#define ANANSI_ControlFileMacroOwnershipImpl_INC
//! @file ControlFileMacroOwnershipImpl.h
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
class ControlFileMacroOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<ControlFileMacroOwnershipImpl<MyTaskImplTraits>,
                                                                                   MyTaskImplTraits, 
                                                                                   ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        ControlFileMacroOwnershipImpl ()   // constructor
        {
            return;
        }

        ControlFileMacroOwnershipImpl (const ControlFileMacroOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        ControlFileMacroOwnershipImpl (ControlFileMacroOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~ControlFileMacroOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileMacroOwnershipImpl& operator= ( const ControlFileMacroOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        ControlFileMacroOwnershipImpl& operator= ( ControlFileMacroOwnershipImpl && other ) // assignment-move operator
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

}; // -----  end of class ControlFileMacroOwnershipImpl  -----


}; // namespace ANANSI

#endif // ANANSI_ControlFileMacroOwnershipImpl_INC

