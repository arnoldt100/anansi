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

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================
    constexpr TaskLabel::TaskLabel () :
        value_()
    {
        return;
    }

    constexpr TaskLabel::TaskLabel ( const char (&str)[TaskLabelTraits::MAX_NM_CHARS]) :  // constructor
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
//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

// ====================  RELATIONSHIP OPERATORS ==============================


    constexpr bool TaskLabel::operator<(TaskLabel const &rhs) const
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

    constexpr bool TaskLabel::operator<=(TaskLabel const &rhs) const
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

    constexpr bool TaskLabel::operator>=(TaskLabel const &rhs) const
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

    constexpr bool TaskLabel::operator>(TaskLabel const &rhs) const
    {
        return (rhs < *this);
    }

    // constexpr bool TaskLabel::operator==(TaskLabel const &rhs) const
    // {
    //     bool retvalue{false};
    //     const std::string_view str_rhs(rhs.value_);
    //     const std::string_view str_lhs(this->value_);
    //     if ( str_lhs == str_rhs)
    //     {
    //         retvalue = true;
    //     }
    //     return retvalue;
    // }

    constexpr bool TaskLabel::operator!=(TaskLabel const &rhs) const
    { 
        bool retvalue{true};
        if ( *this == rhs)
        {
            retvalue = false;
        }
        return retvalue;
    }

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================


} // namespace ANANSI
