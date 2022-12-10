#ifndef  ANANSI_StringLiteral_INC
#define  ANANSI_StringLiteral_INC

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
#include "StringLiteralTraits.hpp"

namespace STRINGLITERAL
{

template <std::size_t LABEL_SIZE=StringLiteralTraits::MAX_NM_CHARS> 
class StringLiteral
{
    public:
        // ====================  LIFECYCLE     =======================================

        constexpr StringLiteral () :  // constructor
            value_()
        {
            return;
        }

        constexpr StringLiteral ( const char (&str)[LABEL_SIZE], const int index ) :  // constructor
            value_{},
            index_(index)
        {
            if (str[0] != '\0')
            {
                for (int ip{0}; ip < LABEL_SIZE; ++ip)
                {
                    this->value_[ip] = str[ip];
                }
            }
            return;
        }

        // ====================  ACCESSORS     =======================================
        constexpr void printStringLiteral() const
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
        constexpr bool operator<(StringLiteral const &rhs) const
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
        
        constexpr bool operator<=(StringLiteral const &rhs) const
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

        constexpr bool operator>=(StringLiteral const &rhs) const
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

        constexpr bool operator>(StringLiteral const &rhs) const
        {
            return (rhs < *this);
        }

        constexpr bool operator==(StringLiteral const &rhs) const
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

        constexpr bool operator!=(StringLiteral const &rhs) const
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

}; // -----  end of class StringLiteral  -----


}; // namespace STRINGLITERAL

#endif   // ----- #ifndef ANANSI_StringLiteral_INC  ----- 
