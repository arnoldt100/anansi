#ifndef ANANSI_GenericTaskUtilities_INC
#define ANANSI_GenericTaskUtilities_INC

//! @file GenericTaskUtilities.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "OwnershipTypes.hpp"
#include "TaskLabel.hpp" 
#include "AnansiTask.h"
#include "AnansiTaskUtilities.hpp"
#include "MPLAliases.hpp"

namespace ANANSI
{

// =====================================================================================
//        Class:  GenericTaskUtilities
//  Description:  
//  =====================================================================================

namespace {
//! A utility class for aiding in searching the tasks typelist.
//!
//! This class sole function is to store the TaskLabel for a task type.
//!
//! @tparam L The TaskLabel type.
template<typename L>
class TaskLabelContainer_
{
    public:
        //! Stores the TaskLabel of type L.
        //! 
        //! The type L must have a static member TASKLABEL.
        constexpr static ANANSI::TaskLabel value = L::TASKLABEL; 
}; 

//! The primary template for searching
//!
//! This class is only invoked by classes "IndexOfLabel" and "IndexOfLabel_".
template <typename TList,
          ANANSI::TaskLabel label,
          typename LabelIndex>
class IndexOfLabel_
{
    using T_front=MPL::mpl_front<TList>;
    using T_rest=MPL::mpl_rest<TList>;
    using next_label_index = MPL::mpl_int<LabelIndex::value + 1>;

    public :
       enum {value = T_front::value == label ? LabelIndex::value : IndexOfLabel_<T_rest,
                                                                                label,
                                                                                next_label_index>::value };
};

//! The specialization for an empty typelist.
//!
//! If the typelist is empty
template <ANANSI::TaskLabel label,
          typename LabelIndex>
class IndexOfLabel_<MPL::mpl_typelist<>, label, LabelIndex>
{
    public :
       enum {value = -1};
};

// The primary template case. 
//
//! This class is initially called by the program.
template <typename TList, 
          ANANSI::TaskLabel Key>
class IndexOfLabel
{
    // For this initial iteration set label_index to MPL::mpl_int<0>
    using label_index = MPL::mpl_int<0>; 

    public :
        enum { value = IndexOfLabel_<TList,Key,label_index>::value};
};


class GenericTaskUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================


        template<typename ConcreteProductTypeList,
                 ANANSI::TaskLabel KEY>
        constexpr static auto getLocationInTypeList()
        {
            using TL_SEQUENCE_t = MPL::mpl_transform<TaskLabelContainer_,ConcreteProductTypeList>;
            auto constexpr index = IndexOfLabel<TL_SEQUENCE_t,KEY>::value;
            return index;
        }

        // ====================  LIFECYCLE     =======================================

        GenericTaskUtilities ();   // constructor

        GenericTaskUtilities (const GenericTaskUtilities & other);   // copy constructor

        GenericTaskUtilities (GenericTaskUtilities && other);   // copy-move constructor

        ~GenericTaskUtilities ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        GenericTaskUtilities& operator= ( const GenericTaskUtilities &other ); // assignment operator

        GenericTaskUtilities& operator= ( GenericTaskUtilities && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class GenericTaskUtilities  -----


//! Gets the concrete task type for the concrete task that has label MY_LABEL.
//!
//! @tparam ConcreteProductTypeList A typelist of concrete tasks.
//! MY_LABEL The label we seek  to match in the concrete tasks.
template <typename ConcreteTasksTypeList,
          typename LABEL_t,
          LABEL_t COMMAND_LABEL>
class
ConcreteTypeForCorrespondingLabel 
{
    private:
        static const int concreteindex_ =
            ANANSI::GenericTaskUtilities::getLocationInTypeList<ConcreteTasksTypeList,COMMAND_LABEL>();
    public:
        using TYPE = MPL::mpl_at_c<ConcreteTasksTypeList,concreteindex_>;
};

template < typename LABEL_t,
           LABEL_t COMMAND_LABEL,
           typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipConcreteType
{
    public:
        using TYPE = 
            typename ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::TYPE;
};

template <RECEIVER::OwnershipTypes T,
         typename LABEL_t,
         LABEL_t COMMAND_LABEL,
         typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipTypes; 

template <typename LABEL_t,LABEL_t COMMAND_LABEL,typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipTypes<RECEIVER::OwnershipTypes::COPYTYPE,LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList> 
{
    private:
        using concrete_task_type_ = 
            typename GenericTaskInvokerOwnershipConcreteType<LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList>::TYPE;

    public:
        using TYPE = 
            typename concrete_task_type_:: template MyOwnershipTypes<RECEIVER::OwnershipTypes::COPYTYPE>::TYPE;
};

template <typename LABEL_t,LABEL_t COMMAND_LABEL,typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipTypes<RECEIVER::OwnershipTypes::SHARETYPE,LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList> 
{
    private:
        using concrete_task_type_ = 
            typename GenericTaskInvokerOwnershipConcreteType<LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList>::TYPE;

    public:
        using TYPE = 
            typename concrete_task_type_:: template MyOwnershipTypes<RECEIVER::OwnershipTypes::SHARETYPE>::TYPE;
};

template <typename LABEL_t,LABEL_t COMMAND_LABEL,typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipTypes<RECEIVER::OwnershipTypes::TRANSFERTYPE,LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList> 
{
    private:
        using concrete_task_type_ = 
            typename GenericTaskInvokerOwnershipConcreteType<LABEL_t,COMMAND_LABEL,ConcreteTasksTypeList>::TYPE;

    public:
        using TYPE = 
            typename concrete_task_type_:: template MyOwnershipTypes<RECEIVER::OwnershipTypes::TRANSFERTYPE>::TYPE;
};


}; // end of Anonymous namespace


//! Verifies the a concrete task has label COMMAND_LABEL.
template <typename ConcreteTasksTypeList, ANANSI::TaskLabel COMMAND_LABEL>
void
verifyConcreteProductInTypeList()
{

    // We compute the range of concrete products in ConcreteTasksTypeList.
    constexpr auto nm_products =
        static_cast<MPL::mpl_size_type>(MPL::mpl_size<ConcreteTasksTypeList>::value);

    // This is the lcation of the corresponding concrete product in typelist
    // ConcreteTasksTypeList that has tasklabel COMMAND_LABEL.
    constexpr int concrete_index =
        ANANSI::GenericTaskUtilities::getLocationInTypeList<ConcreteTasksTypeList,
        COMMAND_LABEL>();

    // If the corresponding concrete product is not found then abort.
    if constexpr ( not ((0 <= concrete_index ) and (concrete_index < nm_products)) )
    {
        // :TODO:11/15/2022 10:00:29 AM:: Abort program
        // for a nonrecoverable error has occurred.
    }
} // end of verifyConcreteProductInTypeList

//! Gets the concrete oswnership type for the result of concrete task that has label MY_LABEL.
//!
//! @tparam ConcreteProductTypeList A typelist of concrete tasks.
//! MY_LABEL The label we seek  to match in the concrete tasks.
template <typename ConcreteTasksTypeList,
          typename LABEL_t,
          LABEL_t COMMAND_LABEL,
          RECEIVER::OwnershipTypes Q>
class
ConcreteOwnershipTypeForCorrespondingLabel
{
    private:
        static constexpr int concreteindex_ =
            ANANSI::GenericTaskUtilities::getLocationInTypeList<ConcreteTasksTypeList,COMMAND_LABEL>();

        using concrete_type_ = MPL::mpl_at_c<ConcreteTasksTypeList,concreteindex_>;
    
    public:
        using TYPE = typename concrete_type_:: template MyOwnershipTypes<Q>::TYPE;
};

//! Modifies the receiver of the concrete type located at concrete_index.
template <typename ConcreteTasksTypeList,
          typename LABEL_t, 
          LABEL_t COMMAND_LABEL,
          typename... ReceiverArgsTypes>
void
modifyTaskReceiver(std::shared_ptr<ANANSI::AnansiTask> &task,
                   ReceiverArgsTypes &...receiver_args)
{
    using concrete_task_type = 
        typename  ConcreteTypeForCorrespondingLabel<ConcreteTasksTypeList,LABEL_t,COMMAND_LABEL>::TYPE;

    std::shared_ptr<concrete_task_type> concrete_task =
        AnansiTaskUtilities<ANANSI::AnansiTask,concrete_task_type>::asConcreteTask(task);
    concrete_task->modifyReceiver(receiver_args...);

    return;
};

}; // namespace ANANSI

#endif // ANANSI_GenericTaskUtilities_INC
