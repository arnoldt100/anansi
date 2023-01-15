#ifndef __filepreprocessordefine__
#define __filepreprocessordefine__
//! @file ReceiverUtilities.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskLabel.hpp" 

namespace RECEIVER
{

// =====================================================================================
//        Class:  ReceiverUtilities
//  Description:  
//  =====================================================================================
class ReceiverUtilities
{
    public:
        // ====================  LIFECYCLE     =======================================
        template<typename ConcreteProductTypeList,
                 ANANSI::TaskLabel MY_LABEL>
        static constexpr auto foo()
        {
            int ret_val = 1;
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

#endif // __filepreprocessordefine__
