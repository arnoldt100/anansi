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
    _keyShort(""),
    _keyLong(""),
    _description(""),
    _value(""),
    _isRequired(false)
{
    return;
}

CommandLineOptions::CommandLineOptions( const CommandLineOptionsParameter & command_line_parameter) :
    _keyShort(""),
    _keyLong(""),
    _description(""),
    _value(""),
    _isRequired(false)
{
    this->_keyShort = command_line_parameter.key_short;
    this->_keyLong = command_line_parameter.key_long;
    this->_description = command_line_parameter.description;
    this->_value = command_line_parameter.description;
    this->_isRequired = command_line_parameter.isRequired;
    return;
}

CommandLineOptions::CommandLineOptions( CommandLineOptions const & other) :
    _keyShort(""),
    _keyLong(""),
    _description(""),
    _value(""),
    _isRequired(false)
{
    this->_keyShort = other._keyShort;
    this->_keyLong = other._keyLong;
    this->_description = other._description;
    this->_value = other._value;
    this->_isRequired = other._isRequired;
    return;
}		/* -----  end of method CommandLineOptions::CommandLineOptions  ----- */

CommandLineOptions::CommandLineOptions ( CommandLineOptions && other) :
    _keyShort(""),
    _keyLong(""),
    _description(""),
    _value(""),
    _isRequired(false)
{
    this->_keyShort = std::move(other._keyShort);
    this->_keyLong = std::move(other._keyLong);
    this->_description = std::move(other._description);
    this->_value = std::move(other._value);
    this->_isRequired = std::move(other._isRequired);
    return;
}



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

std::string CommandLineOptions::getKeyLong () const
{
    return this->_keyLong;
}		// -----  end of method CommandLineOptions::getKeyLong  ----- 

std::string CommandLineOptions::getKeyShort () const
{
    return this->_keyShort;
}		// -----  end of method CommandLineOptions::getKeyShort  ----- 

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
        this->_keyShort = other._keyShort;
        this->_keyLong = other._keyLong;
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
        this->_keyShort = std::move(other._keyShort);
        this->_keyLong = std::move(other._keyLong);
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
