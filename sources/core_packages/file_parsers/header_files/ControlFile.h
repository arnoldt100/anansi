#ifndef  ControlFile_INC
#define  ControlFile_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BaseInputFile.h"

namespace ANANSI
{

class ControlFile :public ANANSI::BaseInputFile<ControlFile>
{
    public:
        // ====================  LIFECYCLE     =======================================

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  ControlFile
         *      Method:  ControlFile :: ControlFile
         * Description:  Constructor
         *
         * Arguments: 
         *
         *--------------------------------------------------------------------------------------
         */
        ControlFile();   // constructor

        ControlFile (const ControlFile & other);   // copy constructor

        ControlFile (ControlFile && other);   // copy-move constructor

        ~ControlFile ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlFile& operator=( const ControlFile &other ); // assignment operator

        ControlFile& operator=( ControlFile && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  MUTATORS      =======================================

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlFile  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ControlFile_INC  ----- 
