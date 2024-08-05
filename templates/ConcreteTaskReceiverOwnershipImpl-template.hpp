#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! \file __header_filename__

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

namespace __NAMESPACE__
{

template<typename MyTaskImplTraits>
class __classname__ : public RECEIVER::BaseOwnershipImplementation<__classname__<MyTaskImplTraits>,
                                                                   MyTaskImplTraits, 
                                                                   ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        __classname__() // constructor
        {
            return;
        }

        __classname__ (const __classname__ & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        __classname__ (__classname__ && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~__classname__()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        __classname__* clone() const
        {
            return new __classname__(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        __classname__& operator= ( const __classname__ &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        __classname__& operator= ( __classname__ && other ) // assignment-move operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

    protected:

        // ====================  ACCESSORS     =======================================

        //! \todo Implement the copying of the results.
        template<typename T>
        typename MyTaskImplTraits::Copytype getCopyOfResults_(const T & result) const
        {
            return result.clone();
        }

        // ====================  MUTATORS      =======================================

        //! \todo Implement the transferring of the results.
        template<typename T>
        typename MyTaskImplTraits::Transfertype transferResults_(T & result) const
        {
            return std::move(result);
        }

        //! \todo Implement the sharing of the results.
        template<typename T>
        typename MyTaskImplTraits::Sharetype shareResults_(T & result) const
        {
           return result.clone();
        }


        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // ----- End of class __classname__  -----
}; // ----- End namespace __NAMESPACE__ -----

#endif // __filepreprocessordefine__
