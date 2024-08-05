#ifndef ANANSI_MPIBarrierException_INC
#define ANANSI_MPIBarrierException_INC
//! \file MPIBarrierException.h
//!
//! \brief Brief description
//!
//! Detailed description

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

namespace ANANSI
{

class MPIBarrierException : public std::exception
{
    public:
        // ====================  LIFECYCLE     =======================================

        MPIBarrierException ();  // destructor

        ~MPIBarrierException ();  // destructor

        // ====================  ACCESSORS     =======================================
        char const * what() const noexcept override;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================


    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MPIBarrierException  -----


}; // namespace ANANSI

#endif // ANANSI_MPIBarrierException_INC
