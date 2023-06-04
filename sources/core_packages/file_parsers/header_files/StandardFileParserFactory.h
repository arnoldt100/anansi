#ifndef  StandardFileParserFactory_INC
#define  StandardFileParserFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BuilderFileParser.h"
#include "Communicator.h"


namespace ANANSI
{

     // =====================================================================================
     //        Class:  StandardFileParserFactory
     //  Description:  
     //  =====================================================================================
    class StandardFileParserFactory
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  StandardFileParserFactory
            //      Method:  StandardFileParserFactory :: StandardFileParserFactory
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            StandardFileParserFactory ();   // constructor

            StandardFileParserFactory (const StandardFileParserFactory & other);   // copy constructor

            StandardFileParserFactory (StandardFileParserFactory && other);   // copy-move constructor

            ~StandardFileParserFactory ();  // destructor

            // ====================  ACCESSORS     =======================================

            template <typename BuilderFileParser>
            std::shared_ptr<typename BuilderFileParser::Filetype_t> 
            create( std::shared_ptr<BuilderFileParser> builder,
                    const std::string file_name)
            {
            	std::shared_ptr<FileParser> a_parser;
                return a_parser;
            }


            // ====================  MUTATORS      =======================================
            

            // ====================  OPERATORS     =======================================

            StandardFileParserFactory& operator= ( const StandardFileParserFactory &other ); // assignment operator

            StandardFileParserFactory& operator= ( StandardFileParserFactory && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class StandardFileParserFactory  -----


}; // namespace ANANSI

#endif   // ----- #ifndef StandardFileParserFactory_INC  ----- 
