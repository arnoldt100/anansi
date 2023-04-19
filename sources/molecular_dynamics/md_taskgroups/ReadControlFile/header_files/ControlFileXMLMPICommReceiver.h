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
#include "ReceiverInterface.hpp"
#include "TaskLabel.hpp"
#include "OwnershipImpl1.hpp"

// ---------------------------------------------------
// Uncomment the ownership policies as required for 
// class member ConcreteTaskReceiver::ownershipPolicy_.
// For this class we select CopyOwnershipPolicy.hpp.
// ---------------------------------------------------
// #include "NullOwnershipPolicy.hpp"
// #include "TransferOwnershipPolicy.hpp"
// #include "ShareCopyOwnershipPolicy.hpp"
// #include "TransferCopyOwnershipPolicy.hpp""
// #include "ShareOwnershipPolicy.hpp"
#include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

class ControlFileXMLMPICommReceiver :  public RECEIVER::ReceiverInterface<ControlFileXMLMPICommReceiver>
{
    public:
        // using receiver_result_t = boost::property_tree::ptree;
        using receiver_result_t = int;

    private:
        template<typename T>
        using OwnershipPolicy = OwnershipImpl1<T>;

        ANANSI::CopyOwnershipPolicy<receiver_result_t,OwnershipPolicy> ownershipPolicy_;

        mutable  OwnershipPolicy<receiver_result_t>::Copytype results_;
    public:

        // ====================  STATIC       =======================================

        static constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'c','o','m','m','u', 'n','i','c','a','t','e','_','c','o','n','t','r','o','l','_','f','i','l','e'};

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

        OwnershipPolicy<receiver_result_t>::Copytype receiverGetCopyOfResults_() const;

        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types... args);

        template<typename... Types>
        void disableReceiver_(Types... args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        OwnershipPolicy<receiver_result_t>::Sharedtype receiverShareOwnershipOfResults_();

        OwnershipPolicy<receiver_result_t>::Transfertype receiverTransferOwnershipOfResults_();

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

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
void ControlFileXMLMPICommReceiver::enableReceiver_(Types... args)
{
    return;
}

template<typename... Types>
void ControlFileXMLMPICommReceiver::disableReceiver_(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileXMLMPICommReceiver_INC  ----- 
