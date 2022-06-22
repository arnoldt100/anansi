#ifndef  ANANSI_ConsoleLogger_INC
#define  ANANSI_ConsoleLogger_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

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
//        Class:  ConsoleLogger
//  Description:  
//  =====================================================================================
class ConsoleLogger : public ANANSI::Logger
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  ConsoleLogger
        //      Method:  ConsoleLogger :: ConsoleLogger
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        ConsoleLogger();   // constructor

        ConsoleLogger(const ConsoleLogger & other);   // copy constructor

        ConsoleLogger(ConsoleLogger && other);   // copy-move constructor

        ~ConsoleLogger();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ConsoleLogger& operator=( const ConsoleLogger &other ); // assignment operator

        ConsoleLogger& operator=( ConsoleLogger && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ConsoleLogger  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_ConsoleLogger_INC  ----- */
