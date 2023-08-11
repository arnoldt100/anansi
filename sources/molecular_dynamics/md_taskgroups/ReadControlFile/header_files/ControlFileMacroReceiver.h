#ifndef  ANANSI_ControlFileMacroReceiver_INC
#define  ANANSI_ControlFileMacroReceiver_INC

//! \file ControlFileMacroReceiver.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <boost/test/unit_test_parameters.hpp>
#include <map>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommonMDTaskGroupHeaders.h"

#include "GenericMDTaskUtilities.hpp"
#include "ControlFileMacroOwnershipImpl.hpp"
#include "ControlFileXMLReceiver.h"
#include "ControlFileXMLMPICommReceiver.h"
#include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

//! Assembles the ControlFileXMLReceiver and ControlFileXMLMPICommReceiver commands.
//!
//! These assembled commands will have the result of all MPI tasks in the
//! communicator group of ControlFileXMLMPICommReceiver to contain the information
//! contained in control file.
class ControlFileMacroReceiver :  public RECEIVER::ReceiverInterface<ControlFileMacroReceiver>
{
    private:
        //! The command label for the task associated with this receiver.
        static constexpr char commandlabel_[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'d','o','_','m','a','c','r','o','_','i','n','p','u','t','_','c','o','n','t','r','o','l','_','f','i','l','e'};

        //! The ownership types for the result. 
        //!
        //! Currently we use a dummy int result.
        using my_result_type_ = int;
        using my_copy_type_ = int;
        using my_share_type_ = int;
        using my_transfer_type_ = int;
        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        //! The ownership policy traits  for the result.
        using MyOwnershipImpl_ = ControlFileMacroOwnershipImpl<MyOwnershipImplTraits_>;
        
        //! The ownership policy for the result.
        using MyOwnershipPolicy_ = ANANSI::CopyOwnershipPolicy<MyOwnershipImpl_>;
       
    public:

        // ====================  TYPEDEFS     =======================================

        using MyParentTask = MacroCommand<ControlFileXMLReceiver,ControlFileXMLMPICommReceiver>;

        // Place here the concrete commponent receivers required for receiver to 
        // do its work.
        using MyComponentReceiverTypelist = 
            MPL::mpl_typelist<GenericMDTask<ControlFileXMLReceiver>,
                              GenericMDTask<ControlFileXMLMPICommReceiver>>;


        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = 
        typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = my_result_type_;

        // ====================  STATIC       =======================================

        static constexpr
        RECEIVER::ReceiverInterface<ControlFileMacroReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<ControlFileMacroReceiver>::TASK_LABEL_TYPE(ControlFileMacroReceiver::commandlabel_);

        // ====================  LIFECYCLE     =======================================

        ControlFileMacroReceiver ();   // constructor

        ControlFileMacroReceiver (const ControlFileMacroReceiver & other) = delete ;   // copy constructor

        ControlFileMacroReceiver (ControlFileMacroReceiver && other);   // copy-move constructor

        ~ControlFileMacroReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileMacroReceiver& operator= ( const ControlFileMacroReceiver &other ) = delete; // assignment operator

        ControlFileMacroReceiver& operator= ( ControlFileMacroReceiver && other ); // assignment-move operator

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

        constexpr RECEIVER::ReceiverInterface<ControlFileMacroReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  ControlFileMacroReceiver::TASKLABEL;
        }

        ControlFileMacroReceiver::receiver_copy_t_ receiverGetCopyOfResults_() const;


        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types &... arg);

        template<typename... Types>
        void disableReceiver_(Types &... args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        ControlFileMacroReceiver::receiver_share_t_ receiverShareOwnershipOfResults_();
    
        ControlFileMacroReceiver::receiver_transfer_t_ receiverTransferOwnershipOfResults_();

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;
        std::map<ANANSI::TaskLabel, std::shared_ptr<ANANSI::AnansiTask>> componentTasks_;
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class ControlFileMacroReceiver  -----

template<typename... Types>
void ControlFileMacroReceiver::enableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void ControlFileMacroReceiver::disableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void ControlFileMacroReceiver::receiverDoAction_(Types & ... args) const
{
    // (1) The first step is to execute the task of reading the control file via ControlFileXMLReceiver.
    //     Only the master process reads the control file. As the number of processes increases, one doesn't 
    //     want all processes reading the same file.
    // (2) Get the results of the ControlFileXMLReceiver and copy to ControlFileXMLMPICommReceiver 
    // (3) ControlFileXMLMPICommReceiver communicates control file to other processes.
    // (4) Get the results of the ControlFileXMLMPICommReceiver and copy to ControlFileXMLReceiver

    try {
        // (1) The first step is to execute the task of reading the control file via ControlFileXMLReceiver. 
        auto task_label_1 = ControlFileXMLReceiver::TASKLABEL;
        std::vector<std::string> flags;
        this->componentTasks_.at(task_label_1)->doAction(flags);

        // (2) Get the results of the ControlFileXMLReceiver and copy to ControlFileXMLMPICommReceiver 
        GenericMDTaskUtilities<ControlFileXMLReceiver>::convertToConcreteGenericmdtask(this->componentTasks_.at(task_label_1));

        // (3) ControlFileXMLMPICommReceiver to communicate control file to other processies.
    
        // (4) Get the results of the ControlFileXMLMPICommReceiver and copy to ControlFileXMLReceiver

        auto task_label_2 = ControlFileXMLMPICommReceiver::TASKLABEL;
        this->componentTasks_.at(task_label_2)->doAction(flags);
    } 
    catch ( const RECEIVER::ReceiverError & my_error)
    {
        std::cout << my_error.what() << std::endl;
        // Send signal to abort program.
    }
    catch (const std::exception& my_error) 
    {
        std::cout << my_error.what() << std::endl;
        // Send signal to abort program.
    }
    return;
}

template<typename... Types>
void ControlFileMacroReceiver::receiverUndoAction_(Types & ... args) const
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileMacroReceiver_INC  ----- 
