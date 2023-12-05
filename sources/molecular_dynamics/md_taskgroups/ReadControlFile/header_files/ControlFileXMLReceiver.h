#ifndef  ANANSI_ControlFileXMLReceiver_INC
#define  ANANSI_ControlFileXMLReceiver_INC

//! \file ControlFileXMLReceiver.h
//!
//! \brief Class ControlFileXMLReceiver is the reciever for 
//! concrete task for reading the control file.
//!
//! The master process in the communicator
//! group reads the file. The result will be the a ControlInputFile
//! object will be populated on the master process. The non-master processes
//! will have an empyty ControlInputFile object.
//!
//! The result of this action is ControFile object. We need a
//! ShareCopyOwnershipPolicy and a SharedType ownership for the result.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <iostream>
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommonMDTaskGroupHeaders.h"
#include "ReceiverError.h"
#include "ControlFileNodeKeyNotFound.h"
#include "ControlInputFile.hpp"
#include "MasterControlInputFileNodeKeys.h"
#include "CommandFiles.h"
#include "ControlFileTask.h"
#include "CommandFilesOwnershipImpl.hpp"
#include "CommandFileName.h"
#include "MasterProcess.h"
#include "ReadControlFileResultsTraits.h"

// ---------------------------------------------------
// Uncomment the ownership policies as required for 
// class member ConcreteTaskReceiver::ownershipPolicy_.
// For this class we select ShareCopyOwnershipPolicy.hpp.
// ---------------------------------------------------
#include "CopyOwnershipPolicy.hpp"

namespace ANANSI
{

//! Resposible for reading the control file.
class ControlFileXMLReceiver :  public RECEIVER::ReceiverInterface<ControlFileXMLReceiver>
{
    private:

        static constexpr char tmpstr_[ANANSI::TaskLabelTraits::MAX_NM_CHARS] = 
            {'r','e','a','d','_','x','m','l','_','c','o','n','t','r','o','l','_','f','i','l','e'};

        using my_result_type_ = ReadControlFileResultsTraits::result_t;
        using my_copy_type_ = ReadControlFileResultsTraits::result_t;
        using my_share_type_ = ReadControlFileResultsTraits::result_t;
        using my_transfer_type_ =  ReadControlFileResultsTraits::result_t;
        using MyOwnershipImplTraits_ = RECEIVER::ReceiverResultTraits<my_result_type_,
                                                                      my_copy_type_,
                                                                      my_share_type_,
                                                                      my_transfer_type_>;

        using MyOwnershipImpl_ = CommandFilesOwnershipImpl<MyOwnershipImplTraits_>;

        using MyOwnershipPolicy_ = ANANSI::CopyOwnershipPolicy<MyOwnershipImpl_>;

        CommandFileName commandFileName_;
        MasterProcess masterProcess_;

    public:
        using MyComponentReceiverTypelist = MPL::mpl_typelist<>;

        using MyParentTask = ControlFileTask;

        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = MyOwnershipImplTraits_::Resulttype;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<ControlFileXMLReceiver>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<ControlFileXMLReceiver>::TASK_LABEL_TYPE(ControlFileXMLReceiver::tmpstr_);

        // ====================  LIFECYCLE     =======================================

        ControlFileXMLReceiver ();   // constructor

        ControlFileXMLReceiver (const ControlFileXMLReceiver & other) = delete;   // copy constructo

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
    std::cout << "Stub for ControlFileXMLReceiver::receiverDoAction_" << std::endl;

    if (this->masterProcess_.operator()())
    {
        try 
        {
            read_CommandFile(this->results_);
        }
        catch(const boost::property_tree::xml_parser_error & my_error)
        {
            std::string error_message = "In ConcreteTaskReceiver::receiverDoAction_ caught error 'boost::property_tree::xml_parser_error'.\n"; 
            error_message += "The boost::property_tree::xml_parser errored during reading the XML formatted control file.\n";
            error_message += "Some typical causes are the following:\n";
            error_message += "(1) Check every <tag> has a matching <\\tag>.\n" ;
            error_message += "(2) Check all comments are properly enclosed <!--  A dummy comment.   -->\n" ;
            throw RECEIVER::ReceiverError(error_message);
        }
        catch (const ControlFileNodeKeyNotFound & my_error)
        {
            std::string error_message = "In ConcreteTaskReceiver::receiverDoAction_ caught error 'ControlFileNodeKeyNotFound'.\n"; 
            error_message += std::string(my_error.what());
            throw RECEIVER::ReceiverError(error_message);

        }
        catch (const std::exception& my_error)
        {
            std::string error_message = "In ConcreteTaskReceiver::receiverDoAction_ caught error 'std::exception'.\n"; 
            error_message += std::string(my_error.what());
            throw RECEIVER::ReceiverError(error_message);
        }
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
