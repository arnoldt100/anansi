#ifndef  RECEIVER_TaskLabelTraits_INC
#define  RECEIVER_TaskLabelTraits_INC

//!@ file TaskLabelTraits.hpp
//!
//! This file s.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstddef>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace RECEIVER

{


    
//! This class stores additional information for the TaskLabel class.
class TaskLabelTraits
{
    public:
        // ====================  LIFECYCLE     =======================================

        //! The size of the char[] array in class TaskLabel.
        //! 
        //! The class TaskLabel has a class data attribute that is of
        //! length char[TaskLabelTraits::MAX_NM_CHARS]. Note this includes
        //! the null character '\0'.
        constexpr static std::size_t MAX_NM_CHARS = 100;

        // ====================  LIFECYCLE     =======================================

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskLabelTraits  -----


}; // namespace RECEIVER

#endif // RECEIVER_TaskLabelTraits_INC
