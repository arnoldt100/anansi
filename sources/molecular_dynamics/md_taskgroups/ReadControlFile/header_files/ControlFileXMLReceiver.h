#ifndef  ANANSI_ControlFileXML_INC
#define  ANANSI_ControlFileXML_INC

//! @file ControlFileXMLReceiver.h
//!
//! 

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
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

//! Ressposible for reading the control file.
class ControlFileXMLReceiver :  public RECEIVER::ReceiverInterface<ControlFileXMLReceiver>
{
    public:
        using receiver_result_t = boost::property_tree::ptree;

        static constexpr char tmpstr[TaskLabelTraits::MAX_NM_CHARS] = 
            {'r','e','a','d','_','c','o','n','t','r','o','l','_','f','i','l','e'};

        static constexpr 
        RECEIVER::ReceiverInterface<ControlFileXMLReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<ControlFileXMLReceiver>::TASK_LABEL_TYPE(ControlFileXMLReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        ControlFileXMLReceiver ();   // constructor

        ControlFileXMLReceiver (const ControlFileXMLReceiver & other);   // copy constructor

        ControlFileXMLReceiver (ControlFileXMLReceiver && other);   // copy-move constructor

        ~ControlFileXMLReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================
       

        constexpr RECEIVER::ReceiverInterface<ControlFileXMLReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel() const
        {
            return  ControlFileXMLReceiver::TASKLABEL;
        }

        template<typename... Types>
        void receiverDoAction(Types... args) const;

        template<typename... Types>
        void receiverUndoAction(Types... args) const;

        std::unique_ptr<receiver_result_t> receiverGetCopyOfResults() const;

        // ====================  MUTATORS      =======================================
        template<typename T>
        void enableReceiver(T & arg);

        template<typename... Types>
        void disableReceiver(Types... args);

        template<typename T>
        void receiverModifyMyself(T & arg);

        // ====================  OPERATORS     =======================================

        ControlFileXMLReceiver& operator= ( const ControlFileXMLReceiver &other ); // assignment operator

        ControlFileXMLReceiver& operator= ( ControlFileXMLReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable boost::property_tree::ptree results_;
        std::string controlFileName_;
        int commID_;

}; // -----  end of class ControlFileXMLReceiver  -----

template<typename... Types>
void ControlFileXMLReceiver::disableReceiver(Types... args)
{
    return;
}

template<typename... Types>
void ControlFileXMLReceiver::receiverDoAction(Types... args) const
{
    if (commID_ == 0)
    {
        std::cout << "Stub for ControlFileXMLReceiver::receiverDoAction" << std::endl;
    }
    return;
}

template<typename... Types>
void ControlFileXMLReceiver::receiverUndoAction(Types... args) const
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileXML_INC  ----- 
