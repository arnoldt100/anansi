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

template<typename MyTaskImplTraits>
class InitWorldCommunicatorTaskOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<InitWorldCommunicatorTaskOwnershipImpl<MyTaskImplTraits>,
                                                                                            MyTaskImplTraits, 
                                                                                            ErrorOwnershipPolicy>
{
    public:
        using Underlyingtype = typename MyTaskImplTraits::Resulttype;

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

    protected:

        // ====================  ACCESSORS     =======================================

        template<typename T>
        typename MyTaskImplTraits::Copytype getCopyOfResults_(const T & result) const
        {
            std::unique_ptr<COMMUNICATOR::CommunicatorFactory> a_communicator_factory = std::make_unique<MPICommunicatorFactory>(); 
            auto tmp_communicator = a_communicator_factory->cloneCommunicator(result);
            return tmp_communicator;
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

}; // -----  end of class InitWorldCommunicatorTaskOwnershipImpl  -----


}; // namespace ANANSI

#endif // ANANSI_InitWorldCommunicatorTaskOwnershipImpl_INC
