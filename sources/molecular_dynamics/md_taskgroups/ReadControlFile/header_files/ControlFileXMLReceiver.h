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

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ReceiverResultTraits.hpp"
#include "ReceiverInterface.hpp"
#include "ControlFile.h"
#include "ControlFileXMLOwnershipImpl.hpp"
#include "TaskLabel.hpp"
#include "ControlFileName.h"
#include "MasterProcess.h"
#include "OwnershipTypes.hpp"

// ---------------------------------------------------
// Uncomment the ownership policies as required for 
// class member ConcreteTaskReceiver::ownershipPolicy_.
// For this class we select ShareCopyOwnershipPolicy.hpp.
// ---------------------------------------------------
// #include "NullOwnershipPolicy.hpp"
// #include "TransferOwnershipPolicy.hpp"
// #include "ShareCopyOwnershipPolicy.hpp"
#include "ShareCopyOwnershipPolicy.hpp"
// #include "TransferCopyOwnershipPolicy.hpp""
// #include "ShareOwnershipPolicy.hpp"
// #include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

//! Resposible for reading the control file.
class ControlFileXMLReceiver :  public RECEIVER::ReceiverInterface<ControlFileXMLReceiver>
{
    private:

        static constexpr char tmpstr[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'r','e','a','d','_','x','m','l','_','c','o','n','t','r','o','l','_','f','i','l','e'};

        using my_result_type_ = int;
        using my_copy_type_ = int;
        using my_share_type_ = int;
        using my_transfer_type_ = int;
        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        using MyOwnershipImpl_ = ControlFileXMLOwnershipImpl<MyOwnershipImplTraits_>;

        using MyOwnershipPolicy_ = ANANSI::ShareCopyOwnershipPolicy<MyOwnershipImpl_>;

        ControlFileName controlFileName_;
        MasterProcess masterProcess_;

    public:

        using MyParentTask = ControlFile;

        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = MyOwnershipImplTraits_::Resulttype;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<ControlFileXMLReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<ControlFileXMLReceiver>::TASK_LABEL_TYPE(ControlFileXMLReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        ControlFileXMLReceiver ();   // constructor

        ControlFileXMLReceiver (const ControlFileXMLReceiver & other) = delete;   // copy constructor

        ControlFileXMLReceiver (ControlFileXMLReceiver && other);   // copy-move constructor

        ~ControlFileXMLReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================
       
        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileXMLReceiver& operator= ( const ControlFileXMLReceiver &other ) = delete; // assignment operator

        ControlFileXMLReceiver& operator= ( ControlFileXMLReceiver && other ); // assignment-move operator

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
        void receiverDoAction_(Types & ... args) const;
        
        template<typename... Types>
        void receiverUndoAction_(Types & ... args) const;

        constexpr RECEIVER::ReceiverInterface<ControlFileXMLReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  ControlFileXMLReceiver::TASKLABEL;
        }

        ControlFileXMLReceiver::receiver_copy_t_ receiverGetCopyOfResults_() const;

        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types &... args);

        template<typename... Types>
        void disableReceiver_(Types &... args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        ControlFileXMLReceiver::receiver_share_t_ receiverShareOwnershipOfResults_();
    
        ControlFileXMLReceiver::receiver_transfer_t_ receiverTransferOwnershipOfResults_();

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ACCESSORS     =======================================

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        mutable receiver_result_t results_;
        MyOwnershipPolicy_ ownershipPolicy_;
        
}; // -----  end of class ControlFileXMLReceiver  -----
template<typename... Types>
void ControlFileXMLReceiver::enableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void ControlFileXMLReceiver::disableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void ControlFileXMLReceiver::receiverDoAction_(Types &... args) const
{
    if (this->masterProcess_.operator()())
    {
        std::cout << "Stub for ControlFileXMLReceiver::receiverDoAction_" << std::endl;
    }
    return;
}

template<typename... Types>
void ControlFileXMLReceiver::receiverUndoAction_(Types &...  args) const
{
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileXMLReceiver_INC  ----- 
