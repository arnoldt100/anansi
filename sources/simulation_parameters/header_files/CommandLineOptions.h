#ifndef  CommandLineOptions_INC
#define  CommandLineOptions_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <utility>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "boost/program_options.hpp"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include <CommandLineOptionsParameter.h>

const std::vector<std::string> option_keys = 
{"short_name","long_name","description","default_value"}; 

namespace ANANSI
{
    // =====================================================================================
    //        Class:  CommandLineOptions
    //  Description: Encapsulates the information of a command line option
    //               The option has the general form of  
    //               --<key_long_form> <value_1> <value_2> ... <value_N>
    //               or 
    //               --<key_long_form> 
    //               or 
    //               -<key_short_form> <value_1> <value_2> ... <value_N>
    //               or 
    //               -<key_short_form> 
    // 
    // =====================================================================================
    class CommandLineOptions
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: CommandLineOptions
            // Description:  The default constructor.
            //
            //  Parameters: None
            //
            //
            //--------------------------------------------------------------------------------------
            CommandLineOptions ();   // constructor


            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: CommandLineOptions
            // Description:  A constructor.
            //
            //  Parameters: The monadic argument for initializing this class.
            //
            //
            //--------------------------------------------------------------------------------------
            CommandLineOptions ( const CommandLineOptionsParameter & command_line_parameter);   // constructor

            CommandLineOptions (const CommandLineOptions & other);   // copy constructor

            CommandLineOptions (CommandLineOptions && other);   // copy-move constructor

            virtual ~CommandLineOptions ();  // destructor

            // ====================  ACCESSORS     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: addBoostOption
            // Description:  Adds this option to description.
            // 
            //  Parameters: (boost::program_options::options_description) description - The Boost
            //              options_description which will get added this command line option.
            //
            //      Return: void
            //--------------------------------------------------------------------------------------
            void addBoostOption( boost::program_options::options_description & description ) const;


            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: getOptionsValue
            // Description:  
            // 
            //  Parameters: options_map - Stores the options values.
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            void getOptionsValue(std::map<std::string, std::string> & options_map) const;

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: getDescrtiption
            // Description: Returns the description of the option.  
            // 
            //  Parameters: None
            //
            //      Return: std::string
            //--------------------------------------------------------------------------------------
            std::string getDescription() const;

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: getShortName
            // Description:  Returns the short key of the option.
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            std::string getShortName() const;

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: getLongName
            // Description:  Returns the long key of the option.
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            std::string getLongName() const;

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: getDefaultValue
            // Description: Returns the Options default value as a string. If the option has more than
            //              one value separated by spaces, then the entirity is returned as a
            //              string. 
            // 
            //  Parameters: None
            //
            //      Return: std::string
            //--------------------------------------------------------------------------------------
            std::string getDefaultValue() const;

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: isRequired
            // Description: Returns true if the option is mandatory, otherwise returns false. 
            // 
            //  Parameters: None
            //
            //      Return: boolean
            //--------------------------------------------------------------------------------------
            bool isRequired() const;

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: isRequiredOptionValues
            // Description: Returns true if the option requires values.
            //
            //  Parameters: None
            //
            //      Return: boolean
            //--------------------------------------------------------------------------------------
            bool isRequiredOptionValues() const;

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            CommandLineOptions& operator= ( const CommandLineOptions &other ); // assignment operator

            CommandLineOptions& operator= ( CommandLineOptions && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================
            
            // ====================  DATA MEMBERS  =======================================
            std::map<std::string,std::string> _optionValues;
            bool _isRequired;
            bool _isRequiredOptionValues;

    }; // -----  end of class CommandLineOptions  -----


}; // namespace ANANSI

#endif   // ----- #ifndef CommandLineOptions_INC  -----
