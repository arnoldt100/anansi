#ifndef ANANSI_ControlFileXMLMPICommOwnershipImpl_INC
#define ANANSI_ControlFileXMLMPICommOwnershipImpl_INC
//! @file ControlFileXMLMPICommOwnershipImpl.h
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
class ControlFileXMLMPICommOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<ControlFileXMLMPICommOwnershipImpl<MyTaskImplTraits>,
                                                                                        MyTaskImplTraits, 
                                                                                        ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        ControlFileXMLMPICommOwnershipImpl ()   // constructor
        {
            return;
        }

        ControlFileXMLMPICommOwnershipImpl (const ControlFileXMLMPICommOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        ControlFileXMLMPICommOwnershipImpl (ControlFileXMLMPICommOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~ControlFileXMLMPICommOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileXMLMPICommOwnershipImpl& operator= ( const ControlFileXMLMPICommOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        ControlFileXMLMPICommOwnershipImpl& operator= ( ControlFileXMLMPICommOwnershipImpl && other ) // assignment-move operator
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

}; // -----  end of class ControlFileXMLMPICommOwnershipImpl  -----


}; // namespace ANANSI

#endif // ANANSI_ControlFileXMLMPICommOwnershipImpl_INC

