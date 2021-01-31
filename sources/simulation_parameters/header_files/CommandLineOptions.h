#ifndef  CommandLineOptions_INC
#define  CommandLineOptions_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{
    // =====================================================================================
    //        Class:  CommandLineOptions
    //  Description:  
    // =====================================================================================
    class CommandLineOptions
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  CommandLineOptions
            //      Method:  CommandLineOptions :: CommandLineOptions
            // Description:  Constructor
            //
            //  Parameters: None
            //
            //
            //--------------------------------------------------------------------------------------
            CommandLineOptions ();   // constructor

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
            //      Method:  CommandLineOptions :: getKey
            // Description:  Returns the key of the option.
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            std::string getKey() const;

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
            std::string _key;
            std::string _description;
            std::string _value;
            bool _isRequired;

    }; // -----  end of class CommandLineOptions  -----


}; // namespace ANANSI

#endif   // ----- #ifndef CommandLineOptions_INC  -----
