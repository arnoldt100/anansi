#ifndef  ANANSI_ConsoleLoggerTraits_INC
#define  ANANSI_ConsoleLoggerTraits_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Logger.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  ConsoleLoggerTraits
//  Description:  
//  =====================================================================================
class ConsoleLoggerTraits : public ANANSI::Logger
{
    public:
        // ====================  LIFECYCLE     =======================================

        ConsoleLoggerTraits ();   // constructor

        ConsoleLoggerTraits (const ConsoleLoggerTraits & other);   // copy constructor

        ConsoleLoggerTraits (ConsoleLoggerTraits && other);   // copy-move constructor

        ~ConsoleLoggerTraits ();  // destructor
        
        // ====================  ALIASES       =======================================
        using type = std::shared_ptr<Logger>;

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ConsoleLoggerTraits& operator= ( const ConsoleLoggerTraits &other ); // assignment operator

        ConsoleLoggerTraits& operator= ( ConsoleLoggerTraits && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ConsoleLoggerTraits  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ConsoleLoggerTraits_INC  ----- 
