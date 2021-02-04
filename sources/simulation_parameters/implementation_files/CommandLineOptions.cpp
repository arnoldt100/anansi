//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandLineOptions.h"
#include "ErrorNoShortName.h"
#include "ErrorNoLongName.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommandLineOptions::CommandLineOptions() : 
    _optionValues{{"short_name",""}, {"long_name",""}, {"description",""}, {"default_value",""}},
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
    this->_optionValues = other._optionValues;
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
    this->_optionValues = std::move(other._optionValues);
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


void CommandLineOptions::addBoostOption(boost::program_options::options_description & description) const
{
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // This lambda converts a bool to 0 or 1.                          @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    auto bool_to_int = [&](bool x) {
         unsigned int y =  x ? 1 : 0; 
         return y;
    }; 

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // This lambda computes a unique number for a given bool vector.   @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    auto compute_number = [&](std::vector<bool> x) {
        unsigned int num = 0;
        for (auto it = x.begin(); it != x.end(); ++it)
        {
            num = num << bool_to_int(*it); 
        }
        return num;
    };

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Form option name from the long and short optiona names.         @
    // - check if the short and long option names are                  @
    // defined.                                                        @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    if (this->_keyLong.empty())
    {
        throw ErrorNoLongName();
    }

    if (this->_keyShort.empty())
    {
        throw ErrorNoShortName();
    }
    const auto my_option_name = this->_keyLong + "," + this->_keyShort;

    
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // Form option decription.  The option description is mandatory.   @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    // :TODO:02/03/2021 10:53:48 PM:ant: Implement check that option description is not empty.
    const auto my_option_description = this->getDescription(); 
    

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // We form a unique integer based on the option values. This       @
    // number is used to call the appropiate add_options form.         @
    //                                                                 @
    // A bool vector is formed as follows:                             @
    // {}                                                                
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    const auto my_default_value = this->getOptionValue();
   
    // Get the bool value associated with if this is a required option. 
    const auto my_option_required = this->isRequired();


    std::vector<bool> my_options = {my_option_required, 
                                    my_default_value.empty()};

    // This lambda generates the bool vector of the extant 
    // command line program options.
    auto generate_bool_vector = [&]() {
        std::vector<bool> v1;

        // The order of appending to form the vector must be consistent.
        v1.push_back(my_option_required);
        v1.push_back(my_default_value.empty());
        return v1;
    };

    // c1 :
    //      option is required
    //      has default value 
    bool req=true;
    bool defval=true;
    const std::vector<bool> c1{req,defval};
    const int required_and_default_value = compute_number(c1);

    // c2 :
    //      option not required
    //      no default value 
    req=false;
    defval=false;
    const std::vector<bool> c2{req,defval};
    const int not_required_and_no_default_value = compute_number(c2);


    // Compute the number for the command line options.
    const std::vector<bool> m1 = generate_bool_vector();
    const int n1 = compute_number(m1);


    // if ( n1 == c1 )
    // {

    // }
    // else if ()
    // {

    // } 
    // else if ( )
    // {

    // } 
    // else if ( )
    // {

    // }
    // else
    // {

    // } 

    
    return ;
}		// -----  end of method CommandLineOptions::addBoostOption  -----

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
        this->_optionValues = other._optionValues;
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
        this->_optionValues = std::move(other._optionValues);
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
