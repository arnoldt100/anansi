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

// template<ANANSI::TaskLabel T>
// class G
// {
//     public :
//         constexpr static ANANSI::TaskLabel value = T;
// };



class ReceiverUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! Gets the result type for the concrete task that has label MY_LABEL.
        //!
        //! @tparam ConcreteProductTypeList A typelist of concrete tasks.
        //! MY_LABEL The label we seek  to match in the concrete tasks.
        template<typename ConcreteProductTypeList,
                 ANANSI::TaskLabel KEY>
        static auto foo()
        {

            // This typelist is the type t<C...>
            // using TL_SEQUENCE_t = MPL::mpl_apply<TaskLabelContainer,ConcreteProductTypeList>;
            // TL_SEQUENCE_t tmp_sequence_label;

            // // ---- // 
            // std::cout << "label value: " << tmp_sequence_label.value.value_ << std::endl;
           
            // using zero_element_t = MPL::mpl_at_c<TL_SEQUENCE_t,0>;
            // zero_element_t tmp_label;

            int ret_val = 10;
            return ret_val;
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
