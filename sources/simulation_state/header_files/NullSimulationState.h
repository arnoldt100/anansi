#ifndef ANANSI_NullSimulationState_INC
#define ANANSI_NullSimulationState_INC

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
     //        Class:  NullSimulationState
     //  Description:  
     //  =====================================================================================
    class NullSimulationState : public SimulationState
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  NullSimulationState
            //      Method:  NullSimulationState :: NullSimulationState
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            NullSimulationState ();   // constructor

            NullSimulationState (NullSimulationState const & other);   // copy constructor

            NullSimulationState (NullSimulationState && other);   // copy-move constructor

            virtual ~NullSimulationState ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            NullSimulationState& operator= ( NullSimulationState const & other ); // assignment operator

            NullSimulationState& operator= ( NullSimulationState && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class NullSimulationState  -----


}; // namespace ANANSI

#endif // ANANSI_NullSimulationState_INC
