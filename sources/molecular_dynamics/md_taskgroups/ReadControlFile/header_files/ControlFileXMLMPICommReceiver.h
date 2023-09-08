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
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPICommunicator.h"
#include "MPLAliases.hpp"
#include "ReceiverResultTraits.hpp"
#include "ReceiverInterface.hpp"
#include "ControlFile.hpp"
#include "ControlFileCommunicator.h"
#include "ControlFileXMLMPICommOwnershipImpl.hpp"
#include "TaskLabel.hpp"
#include "OwnershipTypes.hpp"

// ---------------------------------------------------
// Uncomment the ownership policies as required for 
// class member ConcreteTaskReceiver::ownershipPolicy_.
// For this class we select CopyOwnershipPolicy.hpp.
// ---------------------------------------------------
// #include "NullOwnershipPolicy.hpp"
// #include "TransferOwnershipPolicy.hpp"
#include "CopyOwnershipPolicy.hpp"
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

        using my_result_type_ = ANANSI::ControlFile<ControlFileTraits::PICKLEPOLICY>;
        using my_copy_type_ = ANANSI::ControlFile<ControlFileTraits::PICKLEPOLICY>;
        using my_share_type_ = ANANSI::ControlFile<ControlFileTraits::PICKLEPOLICY>;
        using my_transfer_type_ = ANANSI::ControlFile<ControlFileTraits::PICKLEPOLICY>;
        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        using MyOwnershipImpl_ = ControlFileXMLMPICommOwnershipImpl<MyOwnershipImplTraits_>;

        using MyOwnershipPolicy_ = ANANSI::CopyOwnershipPolicy<MyOwnershipImpl_>;

    public:
        // ====================  TYPEDEFS     =======================================

        using MyComponentReceiverTypelist = MPL::mpl_typelist<>;

        using MyParentTask = ControlFileCommunicator;

        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = my_result_type_;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<ControlFileXMLMPICommReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<ControlFileXMLMPICommReceiver>::TASK_LABEL_TYPE(ControlFileXMLMPICommReceiver::tmpstr);

        // ====================  LIFECYCLE     =======================================

        ControlFileXMLMPICommReceiver ();   // constructor

        ControlFileXMLMPICommReceiver (const ControlFileXMLMPICommReceiver & other)=delete;   // copy constructor

        ControlFileXMLMPICommReceiver (ControlFileXMLMPICommReceiver && other);   // copy-move constructor

        ~ControlFileXMLMPICommReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFileXMLMPICommReceiver& operator= ( const ControlFileXMLMPICommReceiver &other )=delete; // assignment operator

        ControlFileXMLMPICommReceiver& operator= ( ControlFileXMLMPICommReceiver && other ); // assignment-move operator
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
        void receiverUndoAction_(Types & ... args) const;

        constexpr RECEIVER::ReceiverInterface<ControlFileXMLMPICommReceiver>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  ControlFileXMLMPICommReceiver::TASKLABEL;
        }

        ControlFileXMLMPICommReceiver::receiver_copy_t_ receiverGetCopyOfResults_() const;


        // ====================  MUTATORS      =======================================

        template<typename... Types>
        void enableReceiver_(Types & ... args);

        template<typename... Types>
        void disableReceiver_(Types &... args);

        template<typename T>
        void receiverModifyMyself_(T & arg);

        ControlFileXMLMPICommReceiver::receiver_share_t_ receiverShareOwnershipOfResults_();

        ControlFileXMLMPICommReceiver::receiver_transfer_t_ receiverTransferOwnershipOfResults_();

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        mutable receiver_result_t results_;
        std::unique_ptr<COMMUNICATOR::Communicator> communicator_;

        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class ControlFileXMLMPICommReceiver  -----

template<typename... Types>
void ControlFileXMLMPICommReceiver::receiverDoAction_(Types & ... args) const
{
    std::cout << "Stub for ControlFileXMLMPICommReceiver::receiverDoAction_" << std::endl;

    // Synchronize all processes in the communicator group of
    // "this->communicator_" at this point.
    this->communicator_->synchronizationPoint();

    // Only the master process will pickle it's results, this->results_, which is the ControlFile.
    // The master process then broadcasts this pickled object to the other worker processes.
    // The worker processes uses the broadcasted pickled object to fill in their 
    // "this->results_".
    const bool i_am_master = this->communicator_->iAmMasterProcess();
    receiver_result_t::PICKLETYPE  pickled_control_file;
    if ( i_am_master )
    {
      pickled_control_file = this->results_.pickle();
    }
   
    // Broadcast the pickled_control_file to the other worker processes.
    const std::size_t rank_to_broadcast = COMMUNICATOR::MASTER_TASK_ID;
    const receiver_result_t::PICKLETYPE broadcasted_pickled_control_file =
        this->communicator_->broadcastStdMap(pickled_control_file,rank_to_broadcast);

    // Use the broadcasted_pickled_obj to fill in this->results_ for the workers.
    if ( ! i_am_master )
    {
        this->results_.unpickle(broadcasted_pickled_control_file);      
    }


    // Synchronize all processes in the communicator group of
    // "this->communicator_" at this point.
    this->communicator_->synchronizationPoint();

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
    if (this->communicator_)
    {
        this->communicator_->freeCommunicator();
    }
    return;
}

}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ControlFileXMLMPICommReceiver_INC  ----- 
