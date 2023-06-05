#ifndef  ANANSI_NullMPIEnvironment_INC
#define  ANANSI_NullMPIEnvironment_INC

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
//        Class:  NullMPIEnvironment
//  Description:  
//  =====================================================================================
class NullMPIEnvironment : public MPIEnvironmentState
{
    public:
        // ====================  LIFECYCLE     =======================================

        NullMPIEnvironment ();   // constructor

        NullMPIEnvironment (const NullMPIEnvironment & other);   // copy constructor

        NullMPIEnvironment (NullMPIEnvironment && other);   // copy-move constructor

        ~NullMPIEnvironment ();  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        NullMPIEnvironment& operator= ( const NullMPIEnvironment &other ); // assignment operator

        NullMPIEnvironment& operator= ( NullMPIEnvironment && other ); // assignment-move operator

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
        constexpr static std::string_view stateid_{"NullMPIEnvironment"};

}; // -----  end of class NullMPIEnvironment  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_NullMPIEnvironment_INC  ----- */
