#ifndef  StandardFileParserFactory_INC
#define  StandardFileParserFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

#include "BuilderFile.h"
//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Communicator.h"


namespace ANANSI
{

     // =====================================================================================
     //        Class:  StandardFileFactory
     //  Description:  
     //  =====================================================================================
    class StandardFileFactory
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  StandardFileFactory
            //      Method:  StandardFileFactory :: StandardFileFactory
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            StandardFileFactory ();   // constructor

            StandardFileFactory (const StandardFileFactory & other);   // copy constructor

            StandardFileFactory (StandardFileFactory && other);   // copy-move constructor

            ~StandardFileFactory ();  // destructor

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

            StandardFileFactory& operator= ( const StandardFileFactory &other ); // assignment operator

            StandardFileFactory& operator= ( StandardFileFactory && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class StandardFileFactory  -----


}; // namespace ANANSI

#endif   // ----- #ifndef StandardFileParserFactory_INC  ----- 
