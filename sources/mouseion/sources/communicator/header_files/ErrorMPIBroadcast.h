#ifndef  COMMUNICATOR_ErrorMPIBroadcast_INC
#define  COMMUNICATOR_ErrorMPIBroadcast_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>
#include <iostream>
#include <string>
#include <string.h>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR
{

// =====================================================================================
//        Class:  ErrorMPIBroadcast
//  Description:  
// =====================================================================================
template<typename T>
class ErrorMPIBroadcast : public std::exception
{
    public:
        // ====================  LIFECYCLE     =======================================

        // -------------------------------------------------------------------------------------
        //      Class:  ErrorMPIBroadcast
        //      Method:  ErrorMPIBroadcast :: ErrorMPIBroadcast
        // Description:  Constructor
        // 
        // Arguments: 
        // 
        // -------------------------------------------------------------------------------------
        ErrorMPIBroadcast() : 
            exception(),
            _errorMessage("")
        {
            return;
        }

        ErrorMPIBroadcast(std::string const error_message) : 
            exception(),
            _errorMessage(error_message)
        {
            return;
        }   

        ErrorMPIBroadcast(const ErrorMPIBroadcast & other)
        {
            if (this != &other)
            {
                exception::operator=(other);
                this->_errorMessage = other._errorMessage;
            }
            return;
        }

        ErrorMPIBroadcast(ErrorMPIBroadcast && other)=delete;   // copy-move constructor

        // ====================  ACCESSORS     =======================================
        char const * what() const noexcept override
        {
            char const * error_message_ptr = strdup(this->_errorMessage.c_str());
            return error_message_ptr;
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ErrorMPIBroadcast& operator=( const ErrorMPIBroadcast &other )
        {
            if (this != &other)
            {
                exception::operator=(other);
                this->_errorMessage = other._errorMessage;
            }
            return *this;

        } // assignment operator

        ErrorMPIBroadcast& operator=( ErrorMPIBroadcast && other )=delete; // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================
        std::string _errorMessage;

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class ErrorMPIBroadcast  -----


}; // namespace COMMUNICATOR

#endif   // ----- #ifndef COMMUNICATOR_ErrorMPIBroadcast_INC  -----
