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

            virtual ~PerformSimulation () = 0;  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            PerformSimulation& operator= ( PerformSimulation const & other ); // assignment operator

            PerformSimulation& operator= ( PerformSimulation && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class PerformSimulation  -----


}; // namespace ANANSI

#endif // ANANSI_PerformSimulation_INC
