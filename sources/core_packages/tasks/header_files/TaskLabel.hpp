#ifndef  ANANSI_TaskLabel_INC
#define  ANANSI_TaskLabel_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <algorithm>
#include <iostream>
#include <cstring>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TaskLabelTraits.hpp"

namespace ANANSI
{


class TaskLabel
{
    public:
        // ====================  LIFECYCLE     =======================================
        constexpr TaskLabel ();

        constexpr TaskLabel ( const char (&str)[TaskLabelTraits::MAX_NM_CHARS]);

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        // ====================  RELATIONSHIP OPERATORS ==============================
        constexpr bool operator<(TaskLabel const &rhs) const;
        
        constexpr bool operator<=(TaskLabel const &rhs) const;

        constexpr bool operator>=(TaskLabel const &rhs) const;

        constexpr bool operator>(TaskLabel const &rhs) const;

        constexpr bool operator==(TaskLabel const &rhs) const
        {
            bool retvalue{false};
            const std::string_view str_rhs(rhs.value_);
            const std::string_view str_lhs(this->value_);
            if ( str_lhs == str_rhs)
            {
                retvalue = true;
            }
            return retvalue;
        }

        constexpr bool operator!=(TaskLabel const &rhs) const;

        // ====================  STATIC        =======================================

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        char value_[TaskLabelTraits::MAX_NM_CHARS];

}; // -----  end of class TaskLabel  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_TaskLabel_INC  ----- 
