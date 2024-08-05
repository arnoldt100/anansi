#ifndef ANANSI_ErrorInvalidMPIEnvironmentChange_INC
#define ANANSI_ErrorInvalidMPIEnvironmentChange_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string_view>
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
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

        ErrorInvalidMPIEnvironmentChange(std::string_view const original_state, std::string_view const action );

        ErrorInvalidMPIEnvironmentChange (const ErrorInvalidMPIEnvironmentChange & other);   // copy constructor

        ErrorInvalidMPIEnvironmentChange (ErrorInvalidMPIEnvironmentChange && other);   // copy-move constructor

        ~ErrorInvalidMPIEnvironmentChange ();  // destructor

        // ====================  ACCESSORS     =======================================
        const char* what() const noexcept;

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
        std::string_view originalState_;
        std::string_view action_;

}; // -----  end of class ErrorInvalidMPIEnvironmentChange  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_ErrorInvalidMPIEnvironmentChange_INC  ----- */
