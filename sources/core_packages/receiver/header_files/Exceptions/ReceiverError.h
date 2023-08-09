#ifndef RECEIVER_ReceiverError_INC
#define RECEIVER_ReceiverError_INC
//! \file ReceiverError.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <exception>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace RECEIVER
{

class ReceiverError : public std::exception
{
    public:
        // ====================  LIFECYCLE     =======================================

        ReceiverError ();   // constructor

        ReceiverError (const std::string error_message);   // constructor

        ReceiverError (const ReceiverError & other);   // copy constructor

        ReceiverError (ReceiverError && other);   // copy-move constructor

        virtual ~ReceiverError ();  // destructor

        // ====================  ACCESSORS     =======================================
        const char* what() const noexcept;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        ReceiverError& operator= ( const ReceiverError &other ); // assignment operator

        ReceiverError& operator= ( ReceiverError && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::string errorMessage_;

}; // -----  end of class ReceiverError  -----


}; // namespace RECEIVER

#endif // RECEIVER_ReceiverError_INC
