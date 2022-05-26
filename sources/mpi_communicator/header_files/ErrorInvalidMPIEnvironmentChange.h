#ifndef  MOUSEION_ErrorInvalidMPIEnvironmentChange_INC
#define MOUSEION_ErrorInvalidMPIEnvironmentChange_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR
{

// =====================================================================================
//        Class:  ErrorInvalidMPIEnvironmentChange
//  Description:  
//  =====================================================================================
class ErrorInvalidMPIEnvironmentChange : public std::exception
{
    public:
        // ====================  LIFECYCLE     =======================================

        ErrorInvalidMPIEnvironmentChange ();   // constructor

        ErrorInvalidMPIEnvironmentChange (const ErrorInvalidMPIEnvironmentChange & other);   // copy constructor

        ErrorInvalidMPIEnvironmentChange (ErrorInvalidMPIEnvironmentChange && other);   // copy-move constructor

        ~ErrorInvalidMPIEnvironmentChange ();  // destructor

        // ====================  ACCESSORS     =======================================
        const char* what() const noexcept override;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorInvalidMPIEnvironmentChange& operator= ( const ErrorInvalidMPIEnvironmentChange &other ); // assignment operator

        ErrorInvalidMPIEnvironmentChange& operator= ( ErrorInvalidMPIEnvironmentChange && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ErrorInvalidMPIEnvironmentChange  -----


}; // namespace COMMUNICATOR

#endif   /* ----- #ifndef MOUSEION_ErrorInvalidMPIEnvironmentChange_INC  ----- */
