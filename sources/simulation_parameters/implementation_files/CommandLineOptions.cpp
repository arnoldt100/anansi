//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandLineOptions.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommandLineOptions::CommandLineOptions() : 
    _key(""),
    _description(""),
    _value(""),
    _isRequired(false)
{
    return;
}

CommandLineOptions::CommandLineOptions (std::string const key,
                                        std::string const description,
                                        std::string const value,
                                        bool const is_required) :
    _key(key),
    _description(description),
    _value(value),
    _isRequired(is_required)
{
    return;
}

CommandLineOptions::CommandLineOptions( CommandLineOptions const & other) :
    _key(""),
    _description(""),
    _value(""),
    _isRequired(false)
{
    this->_key = other._key;
    this->_description = other._description;
    this->_value = other._value;
    this->_isRequired = other._isRequired;
    return;
}		/* -----  end of method CommandLineOptions::CommandLineOptions  ----- */

CommandLineOptions::CommandLineOptions( CommandLineOptions && other)
{
    this->_key = std::move(other._key);
    this->_description = std::move(other._description);
    this->_value = std::move(other._value);
    this->_isRequired = std::move(other._isRequired);
    return;
}		/* -----  end of method CommandLineOptions::CommandLineOptions  ----- */


CommandLineOptions::~CommandLineOptions()
{
	// TODO Auto-generated destructor stub
    return;
}

//============================= ACCESSORS ====================================


std::string CommandLineOptions::getDescription (  ) const
{
    return this->_description;
}		// -----  end of method CommandLineOptions::get__description  ----- 

std::string CommandLineOptions::getKey () const
{
    return this->_key;
}		// -----  end of method CommandLineOptions::getKey  ----- 


std::string CommandLineOptions::getOptionValue () const
{
    return this->_value;
}		// -----  end of method CommandLineOptions::getOptionValue  ----- 


bool CommandLineOptions::isRequired () const
{
    return this->_isRequired;
}		// -----  end of method CommandLineOptions::isRequired  ----- 

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommandLineOptions& CommandLineOptions::operator= ( const CommandLineOptions &other )
{
    if (this != &other)
    {
        this->_key = other._key;
        this->_description = other._description;
        this->_value = other._value;
        this->_isRequired = other._isRequired;
    }
    return *this;
} // assignment operator

CommandLineOptions& CommandLineOptions::operator= ( CommandLineOptions && other )
{
    if (this != &other)
    {
        this->_key = std::move(other._key);
        this->_description = std::move(other._description);
        this->_value = std::move(other._value);
        this->_isRequired = std::move(other._isRequired);
    }
    return *this;
} // assignment-move operator

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


} /* namespace ANANSI */
