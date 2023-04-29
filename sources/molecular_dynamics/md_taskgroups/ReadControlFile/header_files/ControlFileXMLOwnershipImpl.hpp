#ifndef ANANSI_ControlFileXMLOwnershipImpl_INC
#define ANANSI_ControlFileXMLOwnershipImpl_INC
//! @file ControlFileXMLOwnershipImpl.h
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
class ControlFileXMLOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<ControlFileXMLOwnershipImpl<MyTaskImplTraits>,
                                                                                 MyTaskImplTraits, 
                                                                                 ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        ControlFileXMLOwnershipImpl ()   // constructor
        {
            return;
        }

        ControlFileXMLOwnershipImpl (const ControlFileXMLOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        ControlFileXMLOwnershipImpl (ControlFileXMLOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~ControlFileXMLOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileXMLOwnershipImpl& operator= ( const ControlFileXMLOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        ControlFileXMLOwnershipImpl& operator= ( ControlFileXMLOwnershipImpl && other ) // assignment-move operator
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

}; // -----  end of class ControlFileXMLOwnershipImpl  -----


}; // namespace ANANSI

#endif // ANANSI_ControlFileXMLOwnershipImpl_INC

