#ifndef  ANANSI_DummyConcreteTaskReceiver_INC
#define  ANANSI_DummyConcreteTaskReceiver_INC

//! @file DummyConcreteTaskReceiver.h
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
#include "DummyConcreteTaskOwnershipImpl.hpp"
#include "__OwnershipPolicy__.hpp"
#include "OwnershipTypes.hpp"

namespace ANANSI
{

class DummyConcreteTaskReceiver :  public RECEIVER::ReceiverInterface<DummyConcreteTaskReceiver>
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

        using MyOwnershipImpl_ = DummyConcreteTaskOwnershipImpl<MyOwnershipImplTraits_>;
        using MyOwnershipPolicy_ = ANANSI::__OwnershipPolicy__<MyOwnershipImpl_>;
        
        // Place here the class data members required for doing the task.

    public:
        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = RECEIVER::ReceiverOwnershipType<Q,MyOwnershipImplTraits_>;

        using receiver_result_t = my_result_type_;

        // ====================  STATIC       =======================================

    private: 
        using receiver_copy_t_ = MyOwnershipTypes<RECEIVER::OwnershipTypes::COPYTYPE>::TYPE;
        using receiver_share_t_ = MyOwnershipTypes<RECEIVER::OwnershipTypes::SHARETYPE>::TYPE;
        using receiver_transfer_t_ = MyOwnershipTypes<RECEIVER::OwnershipTypes::TRANSFERTYPE>::TYPE;

    public: 
        static constexpr 
        RECEIVER::ReceiverInterface<DummyConcreteTaskReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<DummyConcreteTaskReceiver>::TASK_LABEL_TYPE(DummyConcreteTaskReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        DummyConcreteTaskReceiver ();   // constructor

        DummyConcreteTaskReceiver (const DummyConcreteTaskReceiver & other);   // copy constructor

        DummyConcreteTaskReceiver (DummyConcreteTaskReceiver && other);   // copy-move constructor

        ~DummyConcreteTaskReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DummyConcreteTaskReceiver& operator= ( const DummyConcreteTaskReceiver &other ); // assignment operator

        DummyConcreteTaskReceiver& operator= ( DummyConcreteTaskReceiver && other ); // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================
        template<typename... Types>
        void receiverDoAction_(Types &... args) const;

        template<typename... Types>
        void receiverUndoAction_(Types &... args) const;

        constexpr RECEIVER::ReceiverInterface<DummyConcreteTaskReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  DummyConcreteTaskReceiver::TASKLABEL;
        }

        MyOwnershipImplTraits_::Copytype receiverGetCopyOfResults_() const;


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
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class DummyConcreteTaskReceiver  -----

template<typename... Types>
void DummyConcreteTaskReceiver::enableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void DummyConcreteTaskReceiver::disableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void DummyConcreteTaskReceiver::receiverDoAction_(Types & ... args) const
{
    return;
}

template<typename... Types>
void DummyConcreteTaskReceiver::receiverUndoAction_(Types & ... args) const
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_DummyConcreteTaskReceiver_INC  ----- 
