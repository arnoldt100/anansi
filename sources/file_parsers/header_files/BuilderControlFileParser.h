#ifndef  BuilderControlFileParser_INC
#define  BuilderControlFileParser_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BuilderFileParser.h"
#include "ControlFileParser.h"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  BuilderControlFileParser
     //  Description:  
     //  =====================================================================================
    class BuilderControlFileParser : public BuilderFileParser
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  BuilderControlFileParser
            //      Method:  BuilderControlFileParser :: BuilderControlFileParser
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            BuilderControlFileParser ();   // constructor

            BuilderControlFileParser (const BuilderControlFileParser & other);   // copy constructor

            BuilderControlFileParser (BuilderControlFileParser && other);   // copy-move constructor

            ~BuilderControlFileParser ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            BuilderControlFileParser& operator= ( const BuilderControlFileParser &other ); // assignment operator

            BuilderControlFileParser& operator= ( BuilderControlFileParser && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  MUTATORS      =======================================
            void _addFileName() override;

            void _addCommunicator() override;

            std::shared_ptr<FileParser> _getParser() override;

            void _resetBuilder();

            // ====================  DATA MEMBERS  =======================================
            std::shared_ptr<ControlFileParser> _myParser;

    }; // -----  end of class BuilderControlFileParser  -----


}; // namespace ANANSI

#endif   // ----- #ifndef BuilderControlFileParser_INC  ----- 
