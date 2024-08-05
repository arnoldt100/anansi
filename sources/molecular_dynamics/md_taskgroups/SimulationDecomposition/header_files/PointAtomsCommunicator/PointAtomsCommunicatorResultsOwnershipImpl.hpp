#ifndef ANANSI_PointAtomsCommunicatorResultsOwnershipImpl_INC
#define ANANSI_PointAtomsCommunicatorResultsOwnershipImpl_INC
//! \file PointAtomsCommunicatorResultsOwnershipImpl.hpp

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

template<typename MyTaskImplTraits>
class PointAtomsCommunicatorResultsOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<PointAtomsCommunicatorResultsOwnershipImpl<MyTaskImplTraits>,
                                                                       MyTaskImplTraits, 
                                                                       ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        PointAtomsCommunicatorResultsOwnershipImpl() // constructor
        {
            return;
        }

        PointAtomsCommunicatorResultsOwnershipImpl (const PointAtomsCommunicatorResultsOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        PointAtomsCommunicatorResultsOwnershipImpl (PointAtomsCommunicatorResultsOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~PointAtomsCommunicatorResultsOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        PointAtomsCommunicatorResultsOwnershipImpl* clone() const
        {
            return new PointAtomsCommunicatorResultsOwnershipImpl(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        PointAtomsCommunicatorResultsOwnershipImpl& operator= ( const PointAtomsCommunicatorResultsOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        PointAtomsCommunicatorResultsOwnershipImpl& operator= ( PointAtomsCommunicatorResultsOwnershipImpl && other ) // assignment-move operator
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

}; // ----- End of class PointAtomsCommunicatorResultsOwnershipImpl  -----
}; // ----- End namespace ANANSI -----

#endif // ANANSI_PointAtomsCommunicatorResultsOwnershipImpl_INC
