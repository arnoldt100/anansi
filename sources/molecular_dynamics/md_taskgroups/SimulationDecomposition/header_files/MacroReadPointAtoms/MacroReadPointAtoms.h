#ifndef ANANSI_MacroReadPointAtoms_INC
#define ANANSI_MacroReadPointAtoms_INC
//! \file MacroReadPointAtoms.h
//!
//! \brief Brief description
//!
//! \details  Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommonMDTaskGroupHeaders.h"
#include "ReadPointAtoms.h"
#include "PointAtomsCommunicator.h"
#include "PointAtomsDecomposer.h"
#include "MacroReadPointAtomsResultsTraits.h"
#include "MacroReadPointAtomsResultsOwnershipImpl.hpp"
#include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

class MacroReadPointAtoms :  public RECEIVER::ReceiverInterface<MacroReadPointAtoms>
{
    private:
        static constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'m','a','c','r','o','_','r','e','a','d','_','p','o','i','n','t','_','a','t','o','m','s'};

        //! \! todo Implement a traits class for the results. 
        using my_result_type_ = MacroReadPointAtomsResultsTraits::result_t;
        using my_copy_type_ = MacroReadPointAtomsResultsTraits::copy_result_t;
        using my_share_type_ = MacroReadPointAtomsResultsTraits::share_result_t;
        using my_transfer_type_ = MacroReadPointAtomsResultsTraits::transfer_result_t;

        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        //! \todo Implement a policy class for the ownership implementation
        using MyOwnershipImpl_ = MacroReadPointAtomsResultsOwnershipImpl<MyOwnershipImplTraits_>;

        //! The ownership policy for the result.
        using MyOwnershipPolicy_ = ANANSI::CopyOwnershipPolicy<MyOwnershipImpl_>;
        
        // \todo Place here the class data members required for doing the task.

    public:

        // ====================  TYPEDEFS     =======================================

        using MyParentTask = MacroCommand< 
                                           ReadPointAtoms,PointAtomsDecomposer,PointAtomsCommunicator
                                         >;

        // Place here the concrete component receivers required for receiver to
        // do its work.
        using MyComponentReceiverTypelist = MPL::mpl_typelist<
                                                               GenericMDTask<ReadPointAtoms>,
                                                               GenericMDTask<PointAtomsCommunicator>,
                                                               GenericMDTask<PointAtomsCommunicator>
                                                              >;

        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = 
        typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = my_result_type_;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<MacroReadPointAtoms>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<MacroReadPointAtoms>::TASK_LABEL_TYPE(MacroReadPointAtoms::tmpstr);

        // ====================  LIFECYCLE     =======================================

        MacroReadPointAtoms ();   // constructor

        MacroReadPointAtoms (const MacroReadPointAtoms & other) = delete;   // copy constructor

        MacroReadPointAtoms (MacroReadPointAtoms && other);   // copy-move constructor

        ~MacroReadPointAtoms ();  // destructor

        // ====================  ACCESSORS     =======================================


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MacroReadPointAtoms& operator= ( const MacroReadPointAtoms &other ) = delete; // assignment operator

        MacroReadPointAtoms& operator= ( MacroReadPointAtoms && other ); // assignment-move operator

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

        constexpr RECEIVER::ReceiverInterface<MacroReadPointAtoms>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  MacroReadPointAtoms::TASKLABEL;
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
        std::map<ANANSI::TaskLabel, std::shared_ptr<ANANSI::AnansiTask>> componentTasks_;
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class MacroReadPointAtoms  -----

template<typename... Types>
void MacroReadPointAtoms::enableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void MacroReadPointAtoms::disableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void MacroReadPointAtoms::receiverDoAction_(Types & ... args) const
{
    std::cout << "Stud for MacroReadPointAtoms::receiverDoAction_" << std::endl;
    return;
}

template<typename... Types>
void MacroReadPointAtoms::receiverUndoAction_(Types & ... args) const
{
    std::cout << "Stud for MacroReadPointAtoms::receiverUndoAction_" << std::endl;
    return;
}

}; // ----- End of namespace ANANSI -----

#endif // ANANSI_MacroReadPointAtoms_INC
