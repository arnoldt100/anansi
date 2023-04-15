#ifndef  ANANSI_ControlFileXMLReceiver_INC
#define  ANANSI_ControlFileXMLReceiver_INC

//! @file ControlFileXMLReceiver.h
//!
//! Class ControlFileXMLReceiver is the concrete task for reading the control
//! file.
//!
//! The reading of the control file is distributed across a group of
//! processes in a communicator group. The master process in the communicator
//! group reads the file. The result will be the a ControlFile
//! object will be populated on the master process. The non-master processes
//! will have an empyty ControlFile object.
//!
//! The result of this action is ControFile object. We need a
//! ShareCopyOwnershipPolicy and a SharedType ownership for the result.

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
#include "OwnershipImpl1.hpp"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverInterface.hpp"
#include "TaskLabel.hpp"

// ---------------------------------------------------
// Uncomment the ownership policies as required for 
// class member ConcreteTaskReceiver::ownershipPolicy_.
// For this class we select ShareCopyOwnershipPolicy.hpp.
// ---------------------------------------------------
// #include "NullOwnershipPolicy.hpp"
// #include "TransferOwnershipPolicy.hpp"
#include "ShareCopyOwnershipPolicy.hpp"
// #include "TransferCopyOwnershipPolicy.hpp""
// #include "ShareOwnershipPolicy.hpp"
// #include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

//! Ressposible for reading the control file.
class ControlFileXMLReceiver :  public RECEIVER::ReceiverInterface<ControlFileXMLReceiver>
{
    public:
        using receiver_result_t = int;

    private:
        template<typename T>
        using OwnershipPolicy = OwnershipImpl1<T>;

        static constexpr char tmpstr[RECEIVER::TaskLabelTraits::MAX_NM_CHARS] = 
            {'r','e','a','d','_','c','o','n','t','r','o','l','_','f','i','l','e'};

        // ---------------------------------------------------
        // Declare the ownership policy of the receivers' result.
        // ---------------------------------------------------
        ANANSI::ShareCopyOwnershipPolicy<receiver_result_t,OwnershipPolicy> ownershipPolicy_;

        // ---------------------------------------------------
        // Declare the results. Note that this declaration also
        // sets the ownership of the result. The ownership and the 
        // ownership policy must be compatible.
        // ---------------------------------------------------
        mutable  OwnershipPolicy<receiver_result_t>::Sharedtype results_;

    public:
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

        OwnershipPolicy<receiver_result_t>::Copytype receiverGetCopyOfResults() const;

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
        
}; // -----  end of class ControlFileXMLReceiver  -----

template<typename T>
void ControlFileXMLReceiver::enableReceiver(T & arg)
{
    return;
}

template<typename... Types>
void ControlFileXMLReceiver::disableReceiver(Types... args)
{
    return;
}

template<typename... Types>
void ControlFileXMLReceiver::receiverDoAction(Types... args) const
{
    return;
}

template<typename... Types>
void ControlFileXMLReceiver::receiverUndoAction(Types... args) const
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileXMLReceiver_INC  ----- 
