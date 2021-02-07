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
    this->_isRequiredOptionValues = command_line_parameter.isRequiredOptionValues;
    return;
}

CommandLineOptions::CommandLineOptions( CommandLineOptions const & other) :
    _isRequired(false),
    _isRequiredOptionValues(false)
{
    this->_optionValues = other._optionValues;
    this->_isRequired = other._isRequired;
    this->_isRequiredOptionValues = other._isRequiredOptionValues;
    return;
}		/* -----  end of method CommandLineOptions::CommandLineOptions  ----- */

CommandLineOptions::CommandLineOptions ( CommandLineOptions && other) :
    _isRequired(false)
{
    this->_optionValues = std::move(other._optionValues);
    this->_isRequired = std::move(other._isRequired);
    this->_isRequiredOptionValues = std::move(other._isRequiredOptionValues);
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
    const auto my_option_requires_values = this->isRequiredOptionValues();

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
            const auto n1 = bool_to_int(*it);
            if ( it == x.begin() ) 
            {
                num += n1;
            }
            else
            {
                num <<= 1; 
                num += n1;
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
        // in this order:
        //      [<status of requiring an option>,
        //       <staus of requiring option_parameters>,
        //       <status of requiring a default value>]
        v1.push_back(my_option_required);
        
        v1.push_back(my_option_requires_values);

        bool has_default_value;
        if (my_default_value.empty())
        {
            has_default_value = false;
        }
        else
        {
            has_default_value = true;
        }
        v1.push_back(has_default_value);
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
    bool is_option_required;
    bool is_option_required_values;
    bool has_default_value;

    // c1 :
    //      is option required : false
    //      option requires values : false
    //      has default value  : false
    is_option_required=false;
    is_option_required_values=false;
    has_default_value=false;
    const std::vector<bool> c1 = {is_option_required,is_option_required_values,has_default_value};
    const unsigned int nr_nrv_ndv = compute_number(c1);

    // c2 :
    //      is option required : false
    //      option requires values : false
    //      has default value  : true
    //      This case is contradictory and will throw an error.
    //      It is soley here for completeness.
    is_option_required=false;
    is_option_required_values=false;
    has_default_value=true;
    const std::vector<bool> c2 = {is_option_required,is_option_required_values,has_default_value};
    const unsigned int nr_nrv_dv = compute_number(c2);

    // c3 :
    //      is option required : false
    //      option requires values : true
    //      has default value  : false
    is_option_required=false;
    is_option_required_values=true;
    has_default_value=false;
    const std::vector<bool> c3 = {is_option_required,is_option_required_values,has_default_value};
    const unsigned int nr_rv_ndv = compute_number(c3);

    // c4 :
    //      is option required : false
    //      option requires values : true
    //      has default value  : true
    is_option_required=false;
    is_option_required_values=true;
    has_default_value=true;
    const std::vector<bool> c4 = {is_option_required,is_option_required_values,has_default_value};
    const unsigned int nr_rv_dv = compute_number(c4);

    // c5 :
    //      is option required : true
    //      option requires values : false
    //      has default value  : false
    //      This case is contradictory and will throw an error.
    //      It is soley here for completeness.
    is_option_required=true;
    is_option_required_values=false;
    has_default_value=false;
    const std::vector<bool> c5 ={is_option_required,is_option_required_values,has_default_value};
    const unsigned int r_nrv_ndv = compute_number(c5);

    // c6 :
    //      is option required : true
    //      option requires values : false
    //      has default value  : true
    //      This case is contradictory and will throw an error.
    //      It is soley here for completeness.
    is_option_required=true;
    is_option_required_values=false;
    has_default_value=true;
    const std::vector<bool> c6 ={is_option_required,is_option_required_values,has_default_value};
    const unsigned int r_nrv_dv = compute_number(c6);

    // c7 :
    //      is option required : true
    //      option requires values : true
    //      has default value  : false
    is_option_required=true;
    is_option_required_values=true;
    has_default_value=false;
    const std::vector<bool> c7 ={is_option_required,is_option_required_values,has_default_value};
    const unsigned int r_rv_ndv = compute_number(c7);

    // c8 :
    //      is option required : true
    //      option requires values : true
    //      has default value  : true
    //      This case is contradictory and will throw an error.
    //      It is soley here for completeness.
    is_option_required=true;
    is_option_required_values=true;
    has_default_value=true;
    const std::vector<bool> c8 ={is_option_required,is_option_required_values,has_default_value};
    const unsigned int r_rv_dv = compute_number(c8);


    if ( func_id == nr_nrv_ndv ) // case of compute number c1
    {
        description.add_options()(option_name.c_str(), 
                                  my_option_description.c_str());
    }
    else if ( func_id == nr_nrv_dv) // case of compute number c2
    {
        description.add_options()(option_name.c_str(),
                                  po::value<std::string>()->default_value(my_default_value.c_str()),
                                  my_option_description.c_str());
    } 
    else if ( func_id == nr_rv_ndv ) // case of compute number c3
    {
        description.add_options()(option_name.c_str(),
                                  po::value<std::string>()->required(),
                                  my_option_description.c_str());
    } 
    else if ( func_id == nr_rv_dv ) // case of compute number c4
    {
        description.add_options()(option_name.c_str(),
                                  po::value<std::string>()->default_value(my_default_value.c_str()),
                                  my_option_description.c_str());
    }
    else if ( func_id == r_nrv_ndv ) // case of compute number c5.
    {
         // :TODO:02/06/2021 07:35:34 PM:: Throw error for contrdictory arguments. 
    }
    else if ( func_id == r_nrv_dv) // case of compute number c6.
    {
         // :TODO:02/06/2021 07:35:40 PM:: Throw error for contrdictory arguments. 
    }
    else if ( func_id == r_rv_ndv ) // case of compute number c7.
    {
        description.add_options()(option_name.c_str(),
                                  po::value<std::string>()->required(),
                                  my_option_description.c_str());

    }
    else if ( func_id == r_rv_dv ) // case of compute number c8.
    {
         // :TODO:02/06/2021 07:35:45 PM:: Throw error for contradictory arguments. 
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

bool CommandLineOptions::isRequiredOptionValues () const
{
    return this->_isRequiredOptionValues;
}		// -----  end of method CommandLineOptions::isRequiredOptionValues  ----- 

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

CommandLineOptions& CommandLineOptions::operator= ( const CommandLineOptions &other )
{
    if (this != &other)
    {
        this->_optionValues = other._optionValues;
        this->_isRequired = other._isRequired;
        this->_isRequiredOptionValues = other._isRequiredOptionValues;
    }
    return *this;
} // assignment operator

CommandLineOptions& CommandLineOptions::operator= ( CommandLineOptions && other )
{
    if (this != &other)
    {
        this->_optionValues = std::move(other._optionValues);
        this->_isRequired = std::move(other._isRequired);
        this->_isRequiredOptionValues = std::move(other._isRequiredOptionValues);
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
