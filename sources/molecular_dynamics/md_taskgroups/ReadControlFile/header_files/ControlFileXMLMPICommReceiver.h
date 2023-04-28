#ifndef  ANANSI_ControlFileXMLMPICommReceiver_INC
#define  ANANSI_ControlFileXMLMPICommReceiver_INC

//! @file ControlFileXMLMPICommReceiver.h
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
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverResultTraits.hpp"
#include "ReceiverInterface.hpp"
#include "ControlFileXMLMPICommOwnershipImpl.hpp"
#include "TaskLabel.hpp"

// ---------------------------------------------------
// Uncomment the ownership policies as required for 
// class member ConcreteTaskReceiver::ownershipPolicy_.
// For this class we select CopyOwnershipPolicy.hpp.
// ---------------------------------------------------
// #include "NullOwnershipPolicy.hpp"
// #include "TransferOwnershipPolicy.hpp"
#include "ShareCopyOwnershipPolicy.hpp"
// #include "TransferCopyOwnershipPolicy.hpp""
// #include "ShareOwnershipPolicy.hpp"
// #include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

class ControlFileXMLMPICommReceiver :  public RECEIVER::ReceiverInterface<ControlFileXMLMPICommReceiver>
{
    private:
        static constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'c','o','m','m','u', 'n','i','c','a','t','e','_','c','o','n','t','r','o','l','_','f','i','l','e'};

        using my_result_type_ = int;
        using my_copy_type_ = int;
        using my_share_type_ = int;
        using my_transfer_type_ = int;
        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        using MyOwnershipImpl_ = ControlFileXMLMPICommOwnershipImpl<MyOwnershipImplTraits_>;

        using MyOwnershipPolicy_ = ANANSI::ShareCopyOwnershipPolicy<MyOwnershipImplTraits_::Resulttype,
                                                                    MyOwnershipImpl_>;

    public:
        using receiver_result_t = MyOwnershipImplTraits_::Resulttype;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<ControlFileXMLMPICommReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<ControlFileXMLMPICommReceiver>::TASK_LABEL_TYPE(ControlFileXMLMPICommReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        ControlFileXMLMPICommReceiver ();   // constructor

        ControlFileXMLMPICommReceiver (const ControlFileXMLMPICommReceiver & other);   // copy constructor

        ControlFileXMLMPICommReceiver (ControlFileXMLMPICommReceiver && other);   // copy-move constructor

        ~ControlFileXMLMPICommReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileXMLMPICommReceiver& operator= ( const ControlFileXMLMPICommReceiver &other ); // assignment operator

        ControlFileXMLMPICommReceiver& operator= ( ControlFileXMLMPICommReceiver && other ); // assignment-move operator

    protected:
        
        // ====================  ACCESSORS     =======================================

        template<typename... Types>
        void receiverDoAction_(Types &... args) const;

        template<typename... Types>
        void receiverUndoAction_(Types & ... args) const;

        constexpr RECEIVER::ReceiverInterface<ControlFileXMLMPICommReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  ControlFileXMLMPICommReceiver::TASKLABEL;
        }

        MyOwnershipImpl_::Copytype receiverGetCopyOfResults_() const;

        MyOwnershipImpl_::Transfertype receiverTransferOwnershipOfResults_();

        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types & ... args);

        template<typename... Types>
        void disableReceiver_(Types &... args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        MyOwnershipImplTraits_::Sharetype receiverShareOwnershipOfResults_();

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        mutable receiver_result_t results_;
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class ControlFileXMLMPICommReceiver  -----

template<typename... Types>
void ControlFileXMLMPICommReceiver::receiverDoAction_(Types & ... args) const
{
    std::cout << "Stub for ControlFileXMLMPICommReceiver::receiverDoAction_" << std::endl;
    return;
}

template<typename... Types>
void ControlFileXMLMPICommReceiver::receiverUndoAction_(Types & ... args) const
{
    return;
}

template<typename... Types>
void ControlFileXMLMPICommReceiver::enableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void ControlFileXMLMPICommReceiver::disableReceiver_(Types &... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileXMLMPICommReceiver_INC  ----- 
