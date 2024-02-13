#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! \file __header_filename__
//!
//! \brief Brief description
//!
//! \details  Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "GenericMDTask.hpp"
#include "MacroCommand.hpp"
#include "ReceiverInterface.hpp"
#include "TaskLabel.hpp"
#include "OwnershipTypes.hpp"
#include "AnansiTaskParameters.h"
#include "DummyConcreteTaskOwnershipImpl.hpp"
#include "__OwnershipPolicy__.hpp"

namespace __NAMESPACE__
{

class __classname__ :  public RECEIVER::ReceiverInterface<__classname__>
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

        //! The ownership policy traits  for the result.
        using MyOwnershipImpl_ = DummyConcreteTaskOwnershipImpl<MyOwnershipImplTraits_>;

        //! The ownership policy for the result.
        using MyOwnershipPolicy_ = ANANSI::__OwnershipPolicy__<MyOwnershipImpl_>;
        
        // Place here the class data members required for doing the task.

    public:

        // ====================  TYPEDEFS     =======================================
        using MyParentTask = MacroCommand<>;

        // Place here the concrete commponent receivers required for receiver to 
        // do its work.
        using MyComponentReceiverTypelist = 
            MPL::mpl_typelist<>;

        template<RECEIVER::OwnershipTypes Q>
        using MyOwnershipTypes = 
        typename RECEIVER::ReceiverResultOwnershipType<Q,MyOwnershipImpl_>;

        using receiver_result_t = my_result_type_;

        // ====================  STATIC       =======================================

        static constexpr 
        RECEIVER::ReceiverInterface<__classname__>::TASK_LABEL_TYPE TASKLABEL =
            RECEIVER::ReceiverInterface<__classname__>::TASK_LABEL_TYPE(__classname__::tmpstr);

        // ====================  LIFECYCLE     =======================================

        __classname__ ();   // constructor

        __classname__ (const __classname__ & other) = delete;   // copy constructor

        __classname__ (__classname__ && other);   // copy-move constructor

        ~__classname__ ();  // destructor

        // ====================  ACCESSORS     =======================================


        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        __classname__& operator= ( const __classname__ &other ) = delete; // assignment operator

        __classname__& operator= ( __classname__ && other ); // assignment-move operator

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
        void receiverUndoAction_(Types &... args) const;

        constexpr RECEIVER::ReceiverInterface<__classname__>::TASK_LABEL_TYPE receiverGetTaskLabel_() const
        {
            return  __classname__::TASKLABEL;
        }

        receiver_copy_t_ receiverGetCopyOfResults_() const;

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
        std::map<ANANSI::TaskLabel, std::shared_ptr<ANANSI::AnansiTask>> compenentTasks_;
        MyOwnershipPolicy_ ownershipPolicy_;

}; // -----  end of class __classname__  -----

template<typename... Types>
void __classname__::enableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void __classname__::disableReceiver_(Types &... args)
{
    return;
}

template<typename... Types>
void __classname__::receiverDoAction_(Types & ... args) const
{
    std::cout >> "Stud for __classname__::receiverDoAction_" << std::endl;
    return;
}

template<typename... Types>
void __classname__::receiverUndoAction_(Types & ... args) const
{
    std::cout >> "Stud for __classname__::receiverUndoAction_" << std::endl;
    return;
}

}; // ----- End of namespace __NAMESPACE__ -----

#endif // __filepreprocessordefine__
