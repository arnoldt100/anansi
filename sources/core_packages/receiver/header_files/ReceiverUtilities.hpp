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
class F
{
    public:
        constexpr static ANANSI::TaskLabel value = L::TASKLABEL; 
};

template<ANANSI::TaskLabel T>
class G
{
    public :
        constexpr static ANANSI::TaskLabel value = T;
};


class ReceiverUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================

        template<typename ConcreteProductTypeList,
                 ANANSI::TaskLabel MY_LABEL>
        static auto foo()
        {
            using LIST_SIZE_t = MPL::mpl_size<ConcreteProductTypeList>;
            using INTEGER_SEQUENCE_t = MPL::mpl_iota<LIST_SIZE_t>;
            using Q = MPL::mpl_repeat_c<G<MY_LABEL>,LIST_SIZE_t::value> ;


            using TL_SEQUENCE_t = MPL::mpl_apply<F,ConcreteProductTypeList>;
            TL_SEQUENCE_t tmp_sequence_label;
            std::cout << "label value: " << tmp_sequence_label.value.value_ << std::endl;
            
            using zero_element_t = MPL::mpl_at_c<TL_SEQUENCE_t,0>;
            zero_element_t tmp_label;

            int ret_val = LIST_SIZE_t::value;
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
