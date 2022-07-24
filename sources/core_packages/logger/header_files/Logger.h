#ifndef  ANANSI_Logger_INC
#define  ANANSI_Logger_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

// =====================================================================================
//        Class:  Logger
//  Description:  
//  =====================================================================================
class Logger
{
    public:
        // ====================  LIFECYCLE     =======================================

        Logger (); // constructor

        Logger (const Logger & other); // copy constructor

        Logger (Logger && other); // copy-move constructor

        virtual ~Logger ()=0; // destructor

        // ====================  ACCESSORS     =======================================
        void logMessage(const std::string message) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        Logger& operator= ( const Logger &other ); // assignment operator

        Logger& operator= ( Logger && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        virtual void logMessage_(const std::string message) const =0;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class Logger  -----


}; // namespace ANANSI

#endif //  ANANSI_Logger_INC
