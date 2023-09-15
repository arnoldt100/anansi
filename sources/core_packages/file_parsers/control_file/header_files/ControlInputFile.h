#ifndef ANANSI_ControlInputFile_INC
#define ANANSI_ControlInputFile_INC
//! \file ControlInputFile.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

class ControlInputFile
{
    public:
        // ====================  LIFECYCLE     =======================================

        ControlInputFile ();   // constructor

        ControlInputFile (const ControlInputFile & other);   // copy constructor

        ControlInputFile (ControlInputFile && other);   // copy-move constructor

        ~ControlInputFile ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ControlInputFile& operator= ( const ControlInputFile &other ); // assignment operator

        ControlInputFile& operator= ( ControlInputFile && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ControlInputFile  -----


}; // namespace ANANSI

#endif // ANANSI_ControlInputFile_INC
