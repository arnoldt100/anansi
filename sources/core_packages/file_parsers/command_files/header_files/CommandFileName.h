#ifndef ANANSI_CommandFileName_INC
#define ANANSI_CommandFileName_INC
//! @file CommandFileName.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

// =====================================================================================
//        Class:  CommandFileName
//  Description:  
//  =====================================================================================
class CommandFileName
{
    public:
        // ====================  LIFECYCLE     =======================================
        CommandFileName ();   // constructor

        CommandFileName (const std::string file_name);   // constructor

        ~CommandFileName ();   // destructor

        CommandFileName (const CommandFileName & other);   // copy constructor

        CommandFileName (CommandFileName && other);   // copy-move constructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        std::string operator()() const;

        CommandFileName& operator= ( const CommandFileName &other ); // assignment operator

        CommandFileName& operator= ( CommandFileName && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        std::string fileName_; 

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class CommandFileName  -----


}; // namespace ANANSI

#endif // ANANSI_CommandFileName_INC
