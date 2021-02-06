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
#include "ErrorNoLongName.h"
#include "ErrorNoOptionDescription.h"
#include "ErrorNoOptionAdded.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommandLineOptions::CommandLineOptions() : 
    _isRequired(false)
{
    for ( const auto & it : option_keys )
    {
        this->_optionValues[it] = "";
    }
    return;
}

CommandLineOptions::CommandLineOptions( const CommandLineOptionsParameter & command_line_parameter) :
    _isRequired(false)
{
    for ( const auto & it : option_keys )
    {
        this->_optionValues[it] = "";
    }

    this->_optionValues["short_name"] = command_line_parameter.short_name;
    this->_optionValues["long_name"] = command_line_parameter.long_name;
    this->_optionValues["description"] = command_line_parameter.description;
    this->_optionValues["default_value"] = command_line_parameter.default_value;
    this->_isRequired = command_line_parameter.isRequired;
    return;
}

CommandLineOptions::CommandLineOptions( CommandLineOptions const & other) :
    _isRequired(false)
{
    this->_optionValues = other._optionValues;
    this->_isRequired = other._isRequired;
    return;
}		/* -----  end of method CommandLineOptions::CommandLineOptions  ----- */

CommandLineOptions::CommandLineOptions ( CommandLineOptions && other) :
    _isRequired(false)
{
    this->_optionValues = std::move(other._optionValues);
    this->_isRequired = std::move(other._isRequired);
    return;
}



CommandLineOptions::~CommandLineOptions()
{
    return;
}

//============================= ACCESSORS ====================================


void CommandLineOptions::addBoostOption(boost::program_options::options_description & description) const
{
    namespace po = boost::program_options;
    const auto my_short_name = this->_optionValues.at("short_name");
    const auto my_long_name = this->_optionValues.at("long_name");
    const auto my_option_description = this->_optionValues.at("description"); 
    const auto my_default_value = this->_optionValues.at("default_value");
    const auto my_option_required = this->isRequired();

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
            if ( it == x.begin() ) 
            {
                num += *it;
            }
            else
            {
                num <<= 1; 
                num += *it;
            } 
        }
        return num;
    };

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // The boost option_description call needs a string that describes @
    // the option form. The form of this string is                     @
    // <long_name>,<short_name>.                                       @
    //                                                                 @
    // We requires all options to have a long and optionally a short   @
    // form.                                                           @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    if ( my_long_name.empty() )
    {
        throw ErrorNoLongName();
    }

    auto option_name = my_long_name;
    if ( ! my_short_name.empty())
    {
        option_name += ",";
        option_name += my_short_name;
    }

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // The boost option_description call needs a string that describes @
    // the option intent.                                              @
    // The option description is mandatory. Check that description is  @
    // not empty.                                                      @
    //                                                                 @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    if ( my_option_description.empty()  )
    {
        throw ErrorNoOptionDescription();
    }
    
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //                                                                 @
    // We form a unique integer, func_id, based on the option          @
    // values. This number is used to call the appropiate add_options  @
    // function form.                                                  @
    //                                                                 @
    // We form a bool vector, v_b, where                               @
    // v_b[0] = logical value of requiring the option.                 @
    // v_b[1] = logical value of is there a default value              @
    //                                                                 @
    // This bool vector will be used to form the unique number         @
    // and the order of the elements must be consistent with           @
    // the ???                                                         @
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    // This lambda generates the bool vector of the extant 
    // command line program options.
    auto generate_bool_vector = [&]() {
        std::vector<bool> v1;

        // The order of appending to form the vector must be consistent.
        v1.push_back(my_option_required);
        v1.push_back(my_default_value.empty());
        return v1;
    };

    std::vector<bool> v_b = generate_bool_vector(); 
    const unsigned int func_id = compute_number(v_b);

    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    //
    // We now compute the uniqued id for various cases
    // of default values and required options.
    // 
    //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    bool req;
    bool defval;

    // c2 :
    //      option not required
    //      no default value 
    req=false;
    defval=false;
    const std::vector<bool> c2 = {req,defval};
    const unsigned int not_required_and_no_default_value = compute_number(c2);

    // c4 :
    //      option not required
    //      option has default value 
    req=false;
    defval=true;
    const std::vector<bool> c4 = {req,defval};
    const unsigned int not_required_and_default_value = compute_number(c4);

    // c3 :
    //      option is required
    //      no default value 
    req=true;
    defval=false;
    const std::vector<bool> c3 = {req,defval};
    const unsigned int required_and_no_default_value = compute_number(c3);

    // c1 :
    //      option is required
    //      option has default value 
    req=true;
    defval=true;
    const std::vector<bool> c1 = {req,defval};
    const unsigned int required_and_default_value = compute_number(c1);

    if ( func_id == not_required_and_no_default_value )
    {
        description.add_options()(option_name.c_str(), 
                                  po::value<std::string>(),
                                  my_option_description.c_str());
    }
    else if ( func_id == not_required_and_default_value )
    {
        description.add_options()(option_name.c_str(),
                                  po::value<std::string>()->default_value(my_default_value.c_str()),
                                  my_option_description.c_str());
    } 
    else if ( func_id == required_and_no_default_value )
    {
        description.add_options()(option_name.c_str(),
                                  po::value<std::string>()->required(),
                                  my_option_description.c_str());
    } 
    else if ( func_id == required_and_default_value )
    {
        description.add_options()(option_name.c_str(),
                                  po::value<std::string>()->required()->default_value(my_default_value.c_str()),
                                  my_option_description.c_str());
    }
    else
    {
        throw ErrorNoOptionAdded();
    } 

    
    return ;
}		// -----  end of method CommandLineOptions::addBoostOption  -----

std::string CommandLineOptions::getDescription (  ) const
{
    return this->_optionValues.at("description");
}		// -----  end of method CommandLineOptions::get__description  ----- 

std::string CommandLineOptions::getLongName () const
{
    return this->_optionValues.at("long_name");
}		// -----  end of method CommandLineOptions::getLongName  ----- 

std::string CommandLineOptions::getShortName () const
{
    return this->_optionValues.at("short_name");
}		// -----  end of method CommandLineOptions::getShortName  ----- 

std::string CommandLineOptions::getDefaultValue () const
{
    return this->_optionValues.at("default_value");
}		// -----  end of method CommandLineOptions::getDefaultValue  ----- 


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
        this->_isRequired = other._isRequired;
    }
    return *this;
} // assignment operator

CommandLineOptions& CommandLineOptions::operator= ( CommandLineOptions && other )
{
    if (this != &other)
    {
        this->_optionValues = std::move(other._optionValues);
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
