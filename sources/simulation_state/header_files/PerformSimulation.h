#ifndef ANANSI_PerformSimulation_INC
#define ANANSI_PerformSimulation_INC

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
     //        Class:  PerformSimulation
     //  Description:  
     //  =====================================================================================
    class PerformSimulation : public SimulationState
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  PerformSimulation
            //      Method:  PerformSimulation :: PerformSimulation
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            PerformSimulation ();   // constructor

            PerformSimulation (PerformSimulation const & other);   // copy constructor

            PerformSimulation (PerformSimulation && other);   // copy-move constructor

            virtual ~PerformSimulation ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            PerformSimulation& operator= ( PerformSimulation const & other ); // assignment operator

            PerformSimulation& operator= ( PerformSimulation && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

            // ====================  ACCESSORS     =======================================
            void execute_(Simulation * const a_simulation) const override;

            virtual void Execute_(Simulation * const a_simulation) const ;

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class PerformSimulation  -----


}; // namespace ANANSI

#endif // ANANSI_PerformSimulation_INC
