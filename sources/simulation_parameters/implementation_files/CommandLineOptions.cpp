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

CommandLineOptions::CommandLineOptions( CommandLineOptions && other)
{
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

    }
    return *this;
} /* assignment operator */

CommandLineOptions& CommandLineOptions::operator= ( CommandLineOptions && other )
{
    if (this != &other)
    {

    }
    return *this;
} /* assignment-move operator */

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
