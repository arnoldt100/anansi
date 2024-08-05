#ifndef ANANSI_PointAtomsDecomposerResultsOwnershipImpl_INC
#define ANANSI_PointAtomsDecomposerResultsOwnershipImpl_INC
//! \file PointAtomsDecomposerResultsOwnershipImpl.hpp

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
class PointAtomsDecomposerResultsOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<PointAtomsDecomposerResultsOwnershipImpl<MyTaskImplTraits>,
                                                                   MyTaskImplTraits, 
                                                                   ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        PointAtomsDecomposerResultsOwnershipImpl() // constructor
        {
            return;
        }

        PointAtomsDecomposerResultsOwnershipImpl (const PointAtomsDecomposerResultsOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        PointAtomsDecomposerResultsOwnershipImpl (PointAtomsDecomposerResultsOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~PointAtomsDecomposerResultsOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        PointAtomsDecomposerResultsOwnershipImpl* clone() const
        {
            return new PointAtomsDecomposerResultsOwnershipImpl(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        PointAtomsDecomposerResultsOwnershipImpl& operator= ( const PointAtomsDecomposerResultsOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        PointAtomsDecomposerResultsOwnershipImpl& operator= ( PointAtomsDecomposerResultsOwnershipImpl && other ) // assignment-move operator
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

}; // ----- End of class PointAtomsDecomposerResultsOwnershipImpl  -----
}; // ----- End namespace ANANSI -----

#endif // ANANSI_PointAtomsDecomposerResultsOwnershipImpl_INC
