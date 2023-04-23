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
#include "ErrorOwnershipPolicy.hpp"
#include "BaseOwnershipImplementation.h"

namespace ANANSI
{

class InitMPIEnvTaskOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<InitMPIEnvTaskOwnershipImpl,
                                                                                 int,
                                                                                 ErrorOwnershipPolicy>
{
    public:
        using Underlyingtype = int;

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

    protected:

        // ====================  ACCESSORS     =======================================

        template<typename T>
        Underlyingtype getCopyOfResults_(const T & result) const
        {
            return result;
        }

        // ====================  MUTATORS      =======================================

        template<typename T>
        Underlyingtype transferResults_(T & result) const
        {
            return std::move(result);
        }

        template<typename T>
        Underlyingtype shareResults_(T & result) const
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
