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

using LABEL_SIZE=TaskLabelTraits::MAX_NM_CHARS;

class TaskLabel
{
    public:
        // ====================  LIFECYCLE     =======================================
        constexpr TaskLabel ():

        constexpr TaskLabel ( const char (&str)[LABEL_SIZE], const int index ) :  // constructor
            value_{},
            index_(index)
        {
            if (str[0] != '\0')
            {
                for (decltype(LABEL_SIZE) ip{0}; ip < LABEL_SIZE; ++ip)
                {
                    this->value_[ip] = str[ip];
                }
            }
            return;
        }

        // ====================  ACCESSORS     =======================================
        constexpr void printTaskLabel() const
        {
            std::cout << this->value_ << std::endl;
            return;
        }

        constexpr int getIndex() const
        {
            return this->index_;
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        // ====================  RELATIONSHIP OPERATORS ==============================
        constexpr bool operator<(TaskLabel const &rhs) const
        {
            bool retvalue = {false};
            const std::string str_rhs(rhs.value_);
            const std::string str_lhs(this->value_);
            if ( str_lhs < str_rhs )
            {
                retvalue = true;
            }
            return retvalue;
        }
        
        constexpr bool operator<=(TaskLabel const &rhs) const
        {
            bool retvalue = {false};
            const std::string str_rhs(rhs.value_);
            const std::string str_lhs(this->value_);
            if ( str_lhs <= str_rhs )
            {
                retvalue = true;
            }
            return retvalue;
        }

        constexpr bool operator>=(TaskLabel const &rhs) const
        {
            bool retvalue = {false};
            const std::string str_rhs(rhs.value_);
            const std::string str_lhs(this->value_);
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
            const std::string str_rhs(rhs.value_);
            const std::string str_lhs(this->value_);
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

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        char value_[LABEL_SIZE];
        const int index_;

}; // -----  end of class TaskLabel  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_TaskLabel_INC  ----- 
