#ifndef  BuilderFileParser_INC
#define  BuilderFileParser_INC


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
#include "FileParser.h"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  BuilderFileParser
     //  Description:  
     //  =====================================================================================
    class BuilderFileParser
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  BuilderFileParser
            //      Method:  BuilderFileParser :: BuilderFileParser
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            BuilderFileParser ();   // constructor

            BuilderFileParser (const BuilderFileParser & other);   // copy constructor

            BuilderFileParser (BuilderFileParser && other);   // copy-move constructor

            virtual ~BuilderFileParser()=0;  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================
            void addCommunicator();

            void addFileName();

            std::shared_ptr<FileParser> getParser();
            // ====================  OPERATORS     =======================================

            BuilderFileParser& operator= ( const BuilderFileParser &other ); // assignment operator

            BuilderFileParser& operator= ( BuilderFileParser && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  MUTATORS      =======================================
            virtual void _addFileName();

            virtual void _addCommunicator();

            virtual std::shared_ptr<FileParser> _getParser()=0;

            // ====================  DATA MEMBERS  =======================================

    };  // -----  end of class BuilderFileParser  -----


}; // namespace ANANSI

#endif   // ----- #ifndef BuilderFileParser_INC  ----- 
