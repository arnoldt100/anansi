#ifndef  CommandLineOptions_INC
#define  CommandLineOptions_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include <CommandLineOptionsParameter.h>

namespace ANANSI
{
    // =====================================================================================
    //        Class:  CommandLineOptions
    //  Description: Encapsulates the information of a command line option
    //               The option has the general form of  
    //               --<key_long_form> <value_1> <value_2> ... <value_N>
    //               or 
    //               --<key> 
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
            // Description:  A constructor.             //               
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
            //      Method:  CommandLineOptions :: getKeyShort
            // Description:  Returns the short key of the option.
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            std::string getKeyShort() const;

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: getKeyLong
            // Description:  Returns the long key of the option.
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            std::string getKeyLong() const;

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: getOptionValue
            // Description: Returns the Options value as a string. If the option has more than
            //              one value separated by spaces, then the entiirity is retirned as a
            //              string. 
            // 
            //  Parameters: None
            //
            //      Return: std::string
            //--------------------------------------------------------------------------------------
            std::string getOptionValue() const;

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
            std::string _keyShort;
            std::string _keyLong;
            std::string _description;
            std::string _value;
            bool _isRequired;

    }; // -----  end of class CommandLineOptions  -----


}; // namespace ANANSI

#endif   // ----- #ifndef CommandLineOptions_INC  -----
