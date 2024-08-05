#ifndef ANANSI_InitWorldCommunicatorTaskOwnershipImpl_INC
#define ANANSI_InitWorldCommunicatorTaskOwnershipImpl_INC
//! @file InitWorldCommunicatorTaskOwnershipImpl.hpp
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverResultTraits.hpp"
#include "ErrorOwnershipPolicy.hpp"
#include "BaseOwnershipImplementation.h"
#include "MPICommunicatorFactory.h"

namespace ANANSI
{

template<typename ReceiverOwnershipImplTraits>
class InitWorldCommunicatorTaskOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<InitWorldCommunicatorTaskOwnershipImpl<ReceiverOwnershipImplTraits>,
                            ReceiverOwnershipImplTraits, 
                            ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        InitWorldCommunicatorTaskOwnershipImpl ()   // constructor
        {
            return;
        }

        InitWorldCommunicatorTaskOwnershipImpl (const InitWorldCommunicatorTaskOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        InitWorldCommunicatorTaskOwnershipImpl (InitWorldCommunicatorTaskOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~InitWorldCommunicatorTaskOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        InitWorldCommunicatorTaskOwnershipImpl& operator= ( const InitWorldCommunicatorTaskOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        InitWorldCommunicatorTaskOwnershipImpl& operator= ( InitWorldCommunicatorTaskOwnershipImpl && other ) // assignment-move operator
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
            std::unique_ptr<COMMUNICATOR::CommunicatorFactory> a_communicator_factory = std::make_unique<MPICommunicatorFactory>(); 
            auto tmp_communicator = a_communicator_factory->cloneCommunicator(result);
            return tmp_communicator;
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

}; // -----  end of class InitWorldCommunicatorTaskOwnershipImpl  -----


}; // namespace ANANSI

#endif // ANANSI_InitWorldCommunicatorTaskOwnershipImpl_INC
