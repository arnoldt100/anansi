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

            //--------------------------------------------------------------------------------------
            //       Class:  StandardFileParserFactory
            //      Method:  StandardFileParserFactory :: create
            // Description:  Creates a standard FileParser. The standard FileParser has a 
            //               a communicator, and logger.
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            std::shared_ptr<FileParser> create( std::shared_ptr<BuilderFileParser>& builder );

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
