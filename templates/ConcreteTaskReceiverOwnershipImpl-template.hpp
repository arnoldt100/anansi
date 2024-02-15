#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! \file __classname__OwnershipImpl.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

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
class __classname__OwnershipImpl : public RECEIVER::BaseOwnershipImplementation<__classname__OwnershipImpl<MyTaskImplTraits>,
                                                                                MyTaskImplTraits, 
                                                                                ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        __classname__OwnershipImpl() // constructor
        {
            return;
        }

        __classname__OwnershipImpl (const __classname__OwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        __classname__OwnershipImpl (__classname__OwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~__classname__OwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        __classname__OwnershipImpl* clone() const
        {
            return new __classname__OwnershipImpl(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        __classname__OwnershipImpl& operator= ( const __classname__OwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        __classname__OwnershipImpl& operator= ( __classname__OwnershipImpl && other ) // assignment-move operator
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
            return result.clone();
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
           return result.clone();
        }


        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class __classname__OwnershipImpl  -----
}; // namespace __NAMSESPACE__

#endif // __filepreprocessordefine__
