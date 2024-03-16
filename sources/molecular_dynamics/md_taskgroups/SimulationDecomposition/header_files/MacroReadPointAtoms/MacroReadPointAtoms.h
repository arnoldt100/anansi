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
#include <vector>

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

        bool ifEnabled_ () const;

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
        bool enabledStatus_;
        mutable receiver_result_t results_;
        std::map<ANANSI::TaskLabel, std::shared_ptr<ANANSI::AnansiTask>> componentTasks_;
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class MacroReadPointAtoms  -----

template<typename... Types>
void MacroReadPointAtoms::enableReceiver_(Types &... args)
{
	std::cout << "Stud for MacroReadPointAtoms::enableReceiver_" << std::endl;
    this->enabledStatus_ = true;
    return;
}

template<typename... Types>
void MacroReadPointAtoms::disableReceiver_(Types &... args)
{
	std::cout << "Stud for MacroReadPointAtoms::disableReceiver_" << std::endl;
    this->enabledStatus_ = false;
    return;
}

template<typename... Types>
void MacroReadPointAtoms::receiverDoAction_(Types & ... args) const
{
    std::cout << "Stud for MacroReadPointAtoms::receiverDoAction_" << std::endl;
    // (1) The first step is to read the initial configuration via the
    //     ReadPointAtoms task. Only the master process reads the initial
    //     configuration.
    // (2) Get the results ReadPointAtoms and copy to PointAtomsDecomposer in
    //     which the atoms are spatially decomposed.
    // (3) Get the results from PointAtomsDecomposer and communicate, via
    //     PointAtomsCommunicator, the atoms to the correct spatial domains.
    // (4) Copy the results from PointAtomsCommunicator back the
    //     MacroReadPointAtoms.
    try {
        // (1) Get the task label for ReadPointAtoms.
        auto task_1_label = ReadPointAtoms::TASKLABEL;
        std::vector<std::string> flags;
        this->componentTasks_.at(task_1_label)->doAction(flags);

        // (2) Get the results of the ReadPointAtoms and copy to PointAtomsDecomposer and
        //     execute PointAtomsDecomposer.
        auto task_2_label = PointAtomsDecomposer::TASKLABEL;
        this->componentTasks_.at(task_2_label)->doAction(flags);

        // (3) Get the results from PointAtomsDecomposer and copy to PointAtomsCommunicator
        //     and execute PointAtomsCommunicator.
        auto task_3_label = PointAtomsCommunicator::TASKLABEL;
        this->componentTasks_.at(task_3_label)->doAction(flags);

        // (4) Get the results from PointAtomsCommunicator and copy results to this MacroReadPointAtoms.

    }
    catch (const std::exception&) {
        
    }

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
