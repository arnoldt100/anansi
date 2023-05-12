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
       
        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes_ = RECEIVER::ReceiverOwnershipType<Q,MyOwnershipImplTraits_>;

        // Place here the class data members required for doing the task.

    public:
        using receiver_result_t = MyOwnershipImplTraits_::Resulttype;
        using receiver_copy_t = MyOwnershipImplTraits_::Copytype;
        using receiver_share_t = MyOwnershipImplTraits_::Sharetype;
        using receiver_transfer_t = MyOwnershipImplTraits_::Transfertype;

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

        ControlFileMacroReceiver::receiver_copy_t receiverGetCopyOfResults_() const;


        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types &... arg);

        template<typename... Types>
        void disableReceiver_(Types &... args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        ControlFileMacroReceiver::receiver_share_t receiverShareOwnershipOfResults_();
    
        ControlFileMacroReceiver::receiver_transfer_t receiverTransferOwnershipOfResults_();

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
    return;
}

template<typename... Types>
void ControlFileMacroReceiver::receiverUndoAction_(Types & ... args) const
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileMacroReceiver_INC  ----- 
