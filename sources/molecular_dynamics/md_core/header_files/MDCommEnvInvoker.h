#ifndef ANANSI_MDCommEnvInvoker_INC
#define ANANSI_MDCommEnvInvoker_INC
//! @file MDCommEnvInvoker.h
//!
//! The command (or task) invoker for the communication environment.
//!
//! The only tasks invoked are 
//! * enable - enabling in communication environment
//! * disable - disabling the communication environment

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

class MDCommEnvInvoker
{
    public:
        // ====================  LIFECYCLE     =======================================

        MDCommEnvInvoker ();   // constructor

        MDCommEnvInvoker (const MDCommEnvInvoker & other)=delete;   // copy constructor

        MDCommEnvInvoker (MDCommEnvInvoker && other);   // copy-move constructor

        ~MDCommEnvInvoker ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDCommEnvInvoker& operator= ( const MDCommEnvInvoker &other )=delete; // assignment operator

        MDCommEnvInvoker& operator= ( MDCommEnvInvoker && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MDCommEnvInvoker  -----


}; // namespace ANANSI

#endif // ANANSI_MDCommEnvInvoker_INC
