#ifndef  ANANSI_ConsoleLogger_INC
#define  ANANSI_ConsoleLogger_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "boost/log/trivial.hpp"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

        namespace logging = boost::log;
        namespace sinks = boost::log::sinks;
        namespace src = boost::log::sources;
        namespace expr = boost::log::expressions;
        namespace attrs = boost::log::attributes;
        namespace keywords = boost::log::keywords;

namespace ANANSI
{

// =====================================================================================
//        Class:  ConsoleLogger
//  Description:  
//  =====================================================================================
class ConsoleLogger
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
        // void logMessage_(const std::string message) const override;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ConsoleLogger  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_ConsoleLogger_INC  ----- */
