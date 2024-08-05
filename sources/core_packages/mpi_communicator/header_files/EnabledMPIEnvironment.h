#ifndef  ANANSI_EnabledMPIEnvironment_INC
#define  ANANSI_EnabledMPIEnvironment_INC

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
//        Class:  EnabledMPIEnvironment
//  Description:  
//  =====================================================================================
class EnabledMPIEnvironment : public MPIEnvironmentState
{
    public:
        // ====================  LIFECYCLE     =======================================

        EnabledMPIEnvironment ();   // constructor

        EnabledMPIEnvironment (const EnabledMPIEnvironment & other);   // copy constructor

        EnabledMPIEnvironment (EnabledMPIEnvironment && other);   // copy-move constructor

        ~EnabledMPIEnvironment ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        EnabledMPIEnvironment& operator= ( const EnabledMPIEnvironment &other ); // assignment operator

        EnabledMPIEnvironment& operator= ( EnabledMPIEnvironment && other ); // assignment-move operator

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
        constexpr static std::string_view stateid_{"EnabledMPIEnvironment"};

}; // -----  end of class EnabledMPIEnvironment  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_EnabledMPIEnvironment_INC  ----- */
