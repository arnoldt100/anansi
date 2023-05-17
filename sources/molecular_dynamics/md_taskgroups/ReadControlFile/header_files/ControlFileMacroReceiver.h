#ifndef  ANANSI_ControlFileMacroReceiver_INC
#define  ANANSI_ControlFileMacroReceiver_INC

//! @file ControlFileMacroReceiver.h
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverResultTraits.hpp"
#include "ReceiverInterface.hpp"
#include "TaskLabel.hpp"
#include "ControlFileMacroOwnershipImpl.hpp"
#include "ControlFileXMLReceiver.h"
#include "ControlFileXMLMPICommReceiver.h"
#include "CopyOwnershipPolicy.hpp"
#include "OwnershipTypes.hpp"

namespace ANANSI
{

class ControlFileMacroReceiver :  public RECEIVER::ReceiverInterface<ControlFileMacroReceiver>
{
    private:
        static constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'d','u','m','m','y', '_','l','a','b','e','l'};

        using my_result_type_ = int;
        using my_copy_type_ = int;
        using my_share_type_ = int;
        using my_transfer_type_ = int;
        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        using MyOwnershipImpl_ = ControlFileMacroOwnershipImpl<MyOwnershipImplTraits_>;
        using MyOwnershipPolicy_ = ANANSI::CopyOwnershipPolicy<MyOwnershipImpl_>;
       
        // Place here the class data members required for doing the task.

    public:

        // ====================  TYPEDEFS     =======================================

        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = my_result_type_;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<ControlFileMacroReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<ControlFileMacroReceiver>::TASK_LABEL_TYPE(ControlFileMacroReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        ControlFileMacroReceiver ();   // constructor

        ControlFileMacroReceiver (const ControlFileMacroReceiver & other);   // copy constructor

        ControlFileMacroReceiver (ControlFileMacroReceiver && other);   // copy-move constructor

        ~ControlFileMacroReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileMacroReceiver& operator= ( const ControlFileMacroReceiver &other ); // assignment operator

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

    std::cout << "Stub: ControlFileMacroReceiver::receiverDoAction_" << "\n";
    return;
}

template<typename... Types>
void ControlFileMacroReceiver::receiverUndoAction_(Types & ... args) const
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileMacroReceiver_INC  ----- 