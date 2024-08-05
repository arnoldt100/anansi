#ifndef ANANSI_MacroReadPointAtomsResultsOwnershipImpl_INC
#define ANANSI_MacroReadPointAtomsResultsOwnershipImpl_INC
//! \file MacroReadPointAtomsResultsOwnershipImpl.hpp

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
class MacroReadPointAtomsResultsOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<MacroReadPointAtomsResultsOwnershipImpl<MyTaskImplTraits>,
                                                                   MyTaskImplTraits, 
                                                                   ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        MacroReadPointAtomsResultsOwnershipImpl() // constructor
        {
            return;
        }

        MacroReadPointAtomsResultsOwnershipImpl (const MacroReadPointAtomsResultsOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        MacroReadPointAtomsResultsOwnershipImpl (MacroReadPointAtomsResultsOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~MacroReadPointAtomsResultsOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        MacroReadPointAtomsResultsOwnershipImpl* clone() const
        {
            return new MacroReadPointAtomsResultsOwnershipImpl(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MacroReadPointAtomsResultsOwnershipImpl& operator= ( const MacroReadPointAtomsResultsOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        MacroReadPointAtomsResultsOwnershipImpl& operator= ( MacroReadPointAtomsResultsOwnershipImpl && other ) // assignment-move operator
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

}; // ----- End of class MacroReadPointAtomsResultsOwnershipImpl  -----
}; // ----- End namespace ANANSI -----

#endif // ANANSI_MacroReadPointAtomsResultsOwnershipImpl_INC
