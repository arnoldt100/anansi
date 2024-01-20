#ifndef ANANSI_GenericTaskUtilities_INC
#define ANANSI_GenericTaskUtilities_INC

//! @file GenericTaskUtilities.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "OwnershipTypes.hpp"
#include "TaskLabel.hpp" 
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

}; // Anonymous namespace

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

template <RECEIVER::OwnershipTypes T,
         typename LABEL_t,
         LABEL_t COMMAND_LABEL,
         typename ConcreteTasksTypeList>
struct GenericTaskInvokerOwnershipTypes; 

//! Gets the concrete result type for the concrete task that has label MY_LABEL.
//!
//! @tparam ConcreteProductTypeList A typelist of concrete tasks.
//! MY_LABEL The label we seek  to match in the concrete tasks.
template <typename ConcreteTasksTypeList,
          typename LABEL_t,
          LABEL_t COMMAND_LABEL>
class
ConcreteResultTypeForCorrespondingLabel
{
    private:
        static const int concreteindex_ =
            ANANSI::GenericTaskUtilities::getLocationInTypeList<ConcreteTasksTypeList,COMMAND_LABEL>();

        using concrete_type_ = MPL::mpl_at_c<ConcreteTasksTypeList,concreteindex_>;
    
    public:

        using COPYTYPE = concrete_type_::COPYTYPE; 
        using SHARETYPE = concrete_type_::SHARETYPE; 
        using TRANSFERTYPE = concrete_type_::TRANSFERTYPE; 
};

}; // namespace ANANSI

#endif // ANANSI_GenericTaskUtilities_INC
