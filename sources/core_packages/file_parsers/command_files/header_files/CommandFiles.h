#ifndef ANANSI_CommandFiles_INC
#define ANANSI_CommandFiles_INC
//! \file CommandFiles.h

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

class CommandFiles
{
    public:
        // ====================  LIFECYCLE     =======================================

        CommandFiles ();   // constructor

        CommandFiles (const CommandFiles & other);   // copy constructor

        CommandFiles (CommandFiles && other);   // copy-move constructor

        ~CommandFiles ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        CommandFiles& operator= ( const CommandFiles &other ); // assignment operator

        CommandFiles& operator= ( CommandFiles && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class CommandFiles  -----


}; // namespace ANANSI

#endif // ANANSI_CommandFiles_INC
