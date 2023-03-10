#ifndef RECEIVER_ReceiverUtilities_INC
#define RECEIVER_ReceiverUtilities_INC

//! @file ReceiverUtilities.hpp

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
#include "TaskLabel.hpp" 
#include "MPLAliases.hpp"

namespace RECEIVER
{

// =====================================================================================
//        Class:  ReceiverUtilities
//  Description:  
//  =====================================================================================

//! A utility class for aiding in searching the tasks typelist.
//!
//! This class sole function is to store the TaskLabel for a task type.
//!
//! @tparam L The TaskLabel type.
template<typename L>
class TaskLabelContainer
{
    public:
        //! Stores the TaskLabel of type L.
        //! 
        //! The type L must have a static member TASKLABEL.
        constexpr static RECEIVER::TaskLabel value = L::TASKLABEL; 
};

//! The primary template for searching
//!
//! This class is only invoked by classes "IndexOfLabel" and "IndexOfLabel_".
template <typename TList,
          RECEIVER::TaskLabel label,
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
template <RECEIVER::TaskLabel label,
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
          RECEIVER::TaskLabel Key>
class IndexOfLabel
{
    // For this initial iteration set label_index to MPL::mpl_int<0>
    using label_index = MPL::mpl_int<0>; 

    public :
        enum { value = IndexOfLabel_<TList,Key,label_index>::value};
};

class ReceiverUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! Gets the result type for the concrete task that has label MY_LABEL.
        //!
        //! @tparam ConcreteProductTypeList A typelist of concrete tasks.
        //! MY_LABEL The label we seek  to match in the concrete tasks.
        template<typename ConcreteProductTypeList,
                 RECEIVER::TaskLabel KEY>
        constexpr static auto getLocationInTypeList()
        {
            using TL_SEQUENCE_t = MPL::mpl_transform<TaskLabelContainer,ConcreteProductTypeList>;
            auto constexpr index = IndexOfLabel<TL_SEQUENCE_t,KEY>::value;
            return index;
        }

        // ====================  LIFECYCLE     =======================================

        ReceiverUtilities ();   // constructor

        ReceiverUtilities (const ReceiverUtilities & other);   // copy constructor

        ReceiverUtilities (ReceiverUtilities && other);   // copy-move constructor

        ~ReceiverUtilities ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ReceiverUtilities& operator= ( const ReceiverUtilities &other ); // assignment operator

        ReceiverUtilities& operator= ( ReceiverUtilities && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ReceiverUtilities  -----


}; // namespace RECEIVER

#endif // RECEIVER_ReceiverUtilities_INC
