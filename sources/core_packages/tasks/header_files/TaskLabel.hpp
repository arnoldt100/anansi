#ifndef  RECEIVER_TaskLabel_INC
#define  RECEIVER_TaskLabel_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>

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
        constexpr TaskLabel () :
            value_()
        {
            return;
        }

        constexpr TaskLabel ( const char (&str)[TaskLabelTraits::MAX_NM_CHARS]) :
            value_{}
        {
            using tmp_t = std::remove_const<decltype(TaskLabelTraits::MAX_NM_CHARS)>::type;

            if (str[0] != '\0')
            {
                for (tmp_t ip = 0; ip < TaskLabelTraits::MAX_NM_CHARS; ++ip)
                {
                    this->value_[ip] = str[ip];
                }
            }
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================
        std::string operator()() const
        {
            return std::string{this->value_};
        }

        // ====================  RELATIONSHIP OPERATORS ==============================
        constexpr bool operator<(TaskLabel const &rhs) const
        {
            bool retvalue = {false};
            const std::string_view str_rhs(rhs.value_);
            const std::string_view str_lhs(this->value_);
            if ( str_lhs < str_rhs )
            {
                retvalue = true;
            }
            return retvalue;
        }

        
        constexpr bool operator<=(TaskLabel const &rhs) const
        {
            bool retvalue = {false};
            const std::string_view str_rhs(rhs.value_);
            const std::string_view str_lhs(this->value_);
            if ( str_lhs <= str_rhs )
            {
                retvalue = true;
            }
            return retvalue;
        }

        constexpr bool operator>=(TaskLabel const &rhs) const
        {
            bool retvalue = {false};
            const std::string_view str_rhs(rhs.value_);
            const std::string_view str_lhs(this->value_);
            if ( str_lhs >= str_rhs )
            {
                retvalue = true;
            }
            return retvalue;
        }

        constexpr bool operator>(TaskLabel const &rhs) const
        {
            return (rhs < *this);
        }

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

        constexpr bool operator!=(TaskLabel const &rhs) const
        { 
            bool retvalue{true};
            if ( *this == rhs)
            {
                retvalue = false;
            }
            return retvalue;
        }
        // ====================  STATIC        =======================================
        char value_[TaskLabelTraits::MAX_NM_CHARS];

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TaskLabel  -----


}; // namespace ANANSI

#endif   // ----- #ifndef RECEIVER_TaskLabel_INC  ----- 
