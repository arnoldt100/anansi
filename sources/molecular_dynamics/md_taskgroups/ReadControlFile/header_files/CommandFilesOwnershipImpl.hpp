#ifndef ANANSI_CommandFilesOwnershipImpl_INC
#define ANANSI_CommandFilesOwnershipImpl_INC
//! \file CommandFilesOwnershipImpl.h

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
class CommandFilesOwnershipImpl : public RECEIVER::BaseOwnershipImplementation<CommandFilesOwnershipImpl<MyTaskImplTraits>,
                                                                               MyTaskImplTraits, 
                                                                               ErrorOwnershipPolicy>
{
    public:

        // ====================  LIFECYCLE     =======================================

        CommandFilesOwnershipImpl() // constructor
        {
            return;
        }

        CommandFilesOwnershipImpl (const CommandFilesOwnershipImpl & other)   // copy constructor
        {
            if (this != &other)
            {

            }
            return;
        }

        CommandFilesOwnershipImpl (CommandFilesOwnershipImpl && other)   // copy-move constructor
        {
            if (this != &other)
            {
            }
            return;
        }

        ~CommandFilesOwnershipImpl()  // destructor
        {
            return;
        }

        // ====================  ACCESSORS     =======================================
        CommandFilesOwnershipImpl* clone() const
        {
            return new CommandFilesOwnershipImpl(*this);
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CommandFilesOwnershipImpl& operator= ( const CommandFilesOwnershipImpl &other ) // assignment operator
        {   
            if (this != &other)
            {
            }
            return *this;
        }

        CommandFilesOwnershipImpl& operator= ( CommandFilesOwnershipImpl && other ) // assignment-move operator
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

}; // -----  end of class CommandFilesOwnershipImpl  -----

}; // namespace ANANSI

#endif // ANANSI_CommandFilesOwnershipImpl_INC
