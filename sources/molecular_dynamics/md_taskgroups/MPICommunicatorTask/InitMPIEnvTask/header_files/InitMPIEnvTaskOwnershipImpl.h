#ifndef ANANSI_InitMPIEnvTaskOwnershipImpl_INC
#define ANANSI_InitMPIEnvTaskOwnershipImpl_INC
//! @file InitMPIEnvTaskOwnershipImpl.h
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

template<typename ReceiverOwnershipImplTraits>
class InitMPIEnvTaskOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<InitMPIEnvTaskOwnershipImpl<ReceiverOwnershipImplTraits>,
                            ReceiverOwnershipImplTraits, 
                            ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        InitMPIEnvTaskOwnershipImpl ()   // constructor
        {
            return;
        }

        InitMPIEnvTaskOwnershipImpl (const InitMPIEnvTaskOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        InitMPIEnvTaskOwnershipImpl (InitMPIEnvTaskOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~InitMPIEnvTaskOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        InitMPIEnvTaskOwnershipImpl& operator= ( const InitMPIEnvTaskOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        InitMPIEnvTaskOwnershipImpl& operator= ( InitMPIEnvTaskOwnershipImpl && other ) // assignment-move operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

    private:

        using receiver_copy_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::COPYTYPE,
                                                                         ReceiverOwnershipImplTraits>::TYPE;

        using receiver_share_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::SHARETYPE,
                                                                         ReceiverOwnershipImplTraits>::TYPE;

        using receiver_transfer_t_ = 
             typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::TRANSFERTYPE,
                                                                          ReceiverOwnershipImplTraits>::TYPE;

    protected:

        // ====================  ACCESSORS     =======================================

        template<typename T>
        receiver_copy_t_ getCopyOfResults_(const T & result) const
        {
            return result;
        }

        // ====================  MUTATORS      =======================================

        template<typename T>
        receiver_transfer_t_ transferResults_(T & result) const
        {
            return std::move(result);
        }

        template<typename T>
        receiver_share_t_ shareResults_(T & result) const
        {
            return result;
        }

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class InitMPIEnvTaskOwnershipImpl  -----


}; // namespace ANANSI

#endif // ANANSI_InitMPIEnvTaskOwnershipImpl_INC
