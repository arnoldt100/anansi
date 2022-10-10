#ifndef ANANSI_MPIEnvReceiver_INC
#define ANANSI_MPIEnvReceiver_INC
//! @file MPIEnvReceiver
//!
//! Brief description
//!
//! Detailed description

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

class MPIEnvReceiver final
{
    public:
        // ====================  LIFECYCLE     =======================================

        MPIEnvReceiver ();   // constructor

        MPIEnvReceiver (const MPIEnvReceiver & other);   // copy constructor

        MPIEnvReceiver (MPIEnvReceiver && other);   // copy-move constructor

        ~MPIEnvReceiver ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MPIEnvReceiver& operator= ( const MPIEnvReceiver &other ); // assignment operator

        MPIEnvReceiver& operator= ( MPIEnvReceiver && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MPIEnvReceiver  -----


}; // namespace ANANSI

#endif // ANANSI_MPIEnvReceiver_INC
