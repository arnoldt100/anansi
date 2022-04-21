#ifndef ANANSI_TerminateSimulation_INC
#define ANANSI_TerminateSimulation_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationState.h"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  TerminateSimulation
     //  Description:  
     //  =====================================================================================
    class TerminateSimulation : public SimulationState
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  TerminateSimulation
            //      Method:  TerminateSimulation :: TerminateSimulation
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            TerminateSimulation ();   // constructor

            TerminateSimulation (TerminateSimulation const & other);   // copy constructor

            TerminateSimulation (TerminateSimulation && other);   // copy-move constructor

            virtual ~TerminateSimulation ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            TerminateSimulation& operator= ( TerminateSimulation const & other ); // assignment operator

            TerminateSimulation& operator= ( TerminateSimulation && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  ACCESSORS     =======================================
            void execute_(Simulation * const a_simulation) const override;

            void execute_() const override;

            virtual void Execute_(Simulation * const a_simulation) const = 0;

            virtual void Execute_() const = 0;

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class TerminateSimulation  -----


}; // namespace ANANSI

#endif // ANANSI_TerminateSimulation_INC
