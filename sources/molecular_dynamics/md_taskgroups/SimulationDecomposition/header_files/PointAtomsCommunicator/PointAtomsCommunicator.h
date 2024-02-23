#ifndef ANANSI_PointAtomsCommunicator_INC
#define ANANSI_PointAtomsCommunicator_INC
//! \file PointAtomsCommunicator.h
//!
//! \brief Brief description
//!
//! \details  Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>
#include <iostream>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommonMDTaskGroupHeaders.h"
#include "AtomsCommunicator.h"
#include "PointAtomsCommunicatorResultsTraits.h"
#include "PointAtomsCommunicatorResultsOwnershipImpl.hpp"
#include "CopyOwnershipPolicy.hpp"
#include "Communicator.h"

namespace ANANSI
{

class PointAtomsCommunicator :  public RECEIVER::ReceiverInterface<PointAtomsCommunicator>
{
    private:
        static constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'c','o','m','m','u','n','i','c','a','t','e','_','p','o','i','n','t','_','a','t','o','m','s'};

        //! \! todo Implement a traits class for the results. 
        using my_result_type_ = PointAtomsCommunicatorResultsTraits::result_t;
        using my_copy_type_ = PointAtomsCommunicatorResultsTraits::copy_result_t;
        using my_share_type_ = PointAtomsCommunicatorResultsTraits::share_result_t;
        using my_transfer_type_ = PointAtomsCommunicatorResultsTraits::transfer_result_t;

        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        //! \todo Implement a policy class for the ownership implementation
        using MyOwnershipImpl_ = PointAtomsCommunicatorResultsOwnershipImpl<MyOwnershipImplTraits_>;

        //! The ownership policy for the result.
        using MyOwnershipPolicy_ = ANANSI::CopyOwnershipPolicy<MyOwnershipImpl_>;
        
        // \todo Place here the class data members required for doing the task.

    public:

        // ====================  TYPEDEFS     =======================================

        using MyParentTask = AtomsCommunicator;

        //! \todo Fill in typelist with Generic tasks to
        //!       accomplish the macro command. Leave typleist empty
        //!       if this is not a macro command.
        using MyComponentReceiverTypelist = MPL::mpl_typelist<>;

        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = 
        typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = my_result_type_;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<PointAtomsCommunicator>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<PointAtomsCommunicator>::TASK_LABEL_TYPE(PointAtomsCommunicator::tmpstr);

        // ====================  LIFECYCLE     =======================================

        PointAtomsCommunicator ();   // constructor

        PointAtomsCommunicator (const PointAtomsCommunicator & other) = delete;   // copy constructor

        PointAtomsCommunicator (PointAtomsCommunicator && other);   // copy-move constructor

        ~PointAtomsCommunicator ();  // destructor

        // ====================  ACCESSORS     =======================================


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        PointAtomsCommunicator& operator= ( const PointAtomsCommunicator &other ) = delete; // assignment operator

        PointAtomsCommunicator& operator= ( PointAtomsCommunicator && other ); // assignment-move operator

    private:

        using receiver_copy_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::COPYTYPE,
                                                                         MyOwnershipImplTraits_>::TYPE;

        using receiver_share_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::SHARETYPE,
                                                                         MyOwnershipImplTraits_>::TYPE;

        using receiver_transfer_t_ = 
            typename RECEIVER::ReceiverResultOwnershipType_TraitsVersion<RECEIVER::OwnershipTypes::TRANSFERTYPE,
                                                                         MyOwnershipImplTraits_>::TYPE;


    protected:
        // ====================  ACCESSORS     =======================================
        template<typename... Types>
        void receiverDoAction_(Types &... args) const;

        template<typename... Types>
        void receiverUndoAction_(Types &... args) const;

        constexpr RECEIVER::ReceiverInterface<PointAtomsCommunicator>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  PointAtomsCommunicator::TASKLABEL;
        }

        receiver_copy_t_ receiverGetCopyOfResults_() const;

        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types &... arg);

        template<typename... Types>
        void disableReceiver_(Types &... args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        receiver_share_t_ receiverShareOwnershipOfResults_();
    
        receiver_transfer_t_ receiverTransferOwnershipOfResults_();

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;
        std::unique_ptr<COMMUNICATOR::Communicator> communicator_;
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class PointAtomsCommunicator  -----

template<typename... Types>
void PointAtomsCommunicator::enableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void PointAtomsCommunicator::disableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void PointAtomsCommunicator::receiverDoAction_(Types & ... args) const
{
    std::cout << "Stud for PointAtomsCommunicator::receiverDoAction_" << std::endl;
    return;
}

template<typename... Types>
void PointAtomsCommunicator::receiverUndoAction_(Types & ... args) const
{
    std::cout << "Stud for PointAtomsCommunicator::receiverUndoAction_" << std::endl;
    return;
}

}; // ----- End of namespace ANANSI -----

#endif // ANANSI_PointAtomsCommunicator_INC
