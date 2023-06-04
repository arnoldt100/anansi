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
#include "Communicator.h"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  BuilderFile
     //  Description:  
     //  =====================================================================================
    class BuilderFile
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  BuilderFile
            //      Method:  BuilderFile :: BuilderFile
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            BuilderFile ();   // constructor

            BuilderFile (const BuilderFile & other);   // copy constructor

            BuilderFile (BuilderFile && other);   // copy-move constructor

            virtual ~BuilderFile()=0;  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================
            void setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator);

            void setFileName(const std::string filename);

            std::shared_ptr<FileParser> getParser();
            // ====================  OPERATORS     =======================================

            BuilderFile& operator=( const BuilderFile &other ); // assignment operator

            BuilderFile& operator=( BuilderFile && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  MUTATORS      =======================================
            virtual void _setFileName(const std::string file_name);

            virtual void _setCommunicator(std::unique_ptr<COMMUNICATOR::Communicator> && a_communicator) = 0;

            virtual std::shared_ptr<FileParser> _getParser()=0;

            // ====================  DATA MEMBERS  =======================================

    };  // -----  end of class BuilderFile  -----


}; // namespace ANANSI

#endif   // ----- #ifndef BuilderFileParser_INC  ----- 
