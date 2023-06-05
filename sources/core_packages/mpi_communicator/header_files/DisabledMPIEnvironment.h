#ifndef  ANANSI_DisabledMPIEnvironment_INC
#define  ANANSI_DisabledMPIEnvironment_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string_view>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIEnvironmentState.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  DisabledMPIEnvironment
//  Description:  
//  =====================================================================================
class DisabledMPIEnvironment : public MPIEnvironmentState
{
    public:
        // ====================  LIFECYCLE     =======================================

        DisabledMPIEnvironment ();   // constructor

        DisabledMPIEnvironment (const DisabledMPIEnvironment & other);   // copy constructor

        DisabledMPIEnvironment (DisabledMPIEnvironment && other);   // copy-move constructor

        ~DisabledMPIEnvironment ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        DisabledMPIEnvironment& operator= ( const DisabledMPIEnvironment &other ); // assignment operator

        DisabledMPIEnvironment& operator= ( DisabledMPIEnvironment && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  ACCESSORS     =======================================
        std::string currentState_() const override;

        // ====================  MUTATORS      =======================================
         
        void enable_(MPIEnvironment* const mpi_environment) override;
        void disable_(MPIEnvironment* const mpi_environment) override;

        // ====================  DATA MEMBERS  =======================================
        constexpr static std::string_view stateid_{"DisabledMPIEnvironment"};

}; // -----  end of class DisabledMPIEnvironment  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_DisabledMPIEnvironment_INC  ----- */
