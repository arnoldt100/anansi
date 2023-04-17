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

namespace ANANSI
{

class ControlFileXMLMPICommReceiver :  public RECEIVER::ReceiverInterface<ControlFileXMLMPICommReceiver>
{
    public:
        using receiver_result_t = boost::property_tree::ptree;

        // ====================  STATIC       =======================================

        static constexpr char tmpstr[RECEIVER::TaskLabelTraits::MAX_NM_CHARS] = 
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

        std::unique_ptr<receiver_result_t> receiverGetCopyOfResults() const;

        // ====================  MUTATORS      =======================================
        template<typename T>
        void enableReceiver(T & arg);

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

        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void disableReceiver_(Types... args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable boost::property_tree::ptree results_;

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
void ControlFileXMLMPICommReceiver::disableReceiver_(Types... args)
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileXMLMPICommReceiver_INC  ----- 
