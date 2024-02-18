#ifndef ANANSI_ReadPointAtomsResultsOwnershipImpl_INC
#define ANANSI_ReadPointAtomsResultsOwnershipImpl_INC
//! \file ReadPointAtomsResultsOwnershipImpl.hpp

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
class ReadPointAtomsResultsOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<ReadPointAtomsResultsOwnershipImpl<MyTaskImplTraits>,
                                                                                        MyTaskImplTraits, 
                                                                                        ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        ReadPointAtomsResultsOwnershipImpl() // constructor
        {
            return;
        }

        ReadPointAtomsResultsOwnershipImpl (const ReadPointAtomsResultsOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        ReadPointAtomsResultsOwnershipImpl (ReadPointAtomsResultsOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~ReadPointAtomsResultsOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        ReadPointAtomsResultsOwnershipImpl* clone() const
        {
            return new ReadPointAtomsResultsOwnershipImpl(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ReadPointAtomsResultsOwnershipImpl& operator= ( const ReadPointAtomsResultsOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        ReadPointAtomsResultsOwnershipImpl& operator= ( ReadPointAtomsResultsOwnershipImpl && other ) // assignment-move operator
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

}; // ----- End of class ReadPointAtomsResultsOwnershipImpl  -----
}; // ----- End namespace ANANSI -----

#endif // ANANSI_ReadPointAtomsResultsOwnershipImpl_INC
