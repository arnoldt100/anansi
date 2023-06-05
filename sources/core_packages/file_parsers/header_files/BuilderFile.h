#ifndef  BuilderFileParser_INC
#define  BuilderFileParser_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

#include "BaseInputFile.h"
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

            // ====================  OPERATORS     =======================================

            BuilderFile& operator=( const BuilderFile &other ); // assignment operator

            BuilderFile& operator=( BuilderFile && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  MUTATORS      =======================================

            // ====================  DATA MEMBERS  =======================================

    };  // -----  end of class BuilderFile  -----


}; // namespace ANANSI

#endif   // ----- #ifndef BuilderFileParser_INC  ----- 
