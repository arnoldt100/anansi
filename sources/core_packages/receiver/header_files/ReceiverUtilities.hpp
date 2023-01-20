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

template<typename L>
class TaskLabelContainer
{
    public:
        constexpr static ANANSI::TaskLabel value = L::TASKLABEL; 
};

// The primary template case. This class is called by the 
// program. 
template <typename TList, 
          ANANSI::TaskLabel label>
class IndexOfLabel
{
    public :
       enum {value = -1};
};

// The partial specialization for not finding the label. The typelist is empty.
// template <int LabelIndex, 
//           ANANSI::TaskLabel label>
// class IndexOfLabel<MPL::mpl_typelist<>, LabelIndex, label>
// {
//     public :
//        enum {value = -1};
// };

// The partial specialization for the 0'th iteration of the search.
// template <typename TList, 
//           ANANSI::TaskLabel label>
// class IndexOfLabel<TList, 0, label>
// {
//     using mp_front=MPL::mpl_front<TList>;
//     using mp_rest=MPL::mpl_rest<TList>;
//     using label_index = MPL::mpl_int<0>; 
//     using next_label_index = MPL::mpl_int<label_index::value + 1>;
// 
//     // private:
//     //     enum { my_index = mp_front.value == label ? label_index::value : IndexOfLabel<mp_rest,next_label_index,label>::value};
//     // public :
//     //     enum {value = my_index};
// };

// The partial specialization for the i'th iteration of the search.
// template <typename TList, 
//           int LabelIndex,
//           ANANSI::TaskLabel label>
// class IndexOfLabel<TList, LabelIndex, label>
// {
//     using mp_front=MPL::mpl_front<TList>;
//     using mp_rest=MPL::mpl_rest<TList>;
// 
//     // private:
//     //     enum { my_index = mp_front.value == label ? label_index::value : IndexOfLabel<mp_rest,next_label_index,label>::value};
// 
//     // public:
//     //     enum {value = my_index};
// 
// };

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
                 ANANSI::TaskLabel MY_LABEL>
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
