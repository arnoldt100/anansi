#ifndef ANANSI_MDNullSimulationState_INC
#define ANANSI_MDNullSimulationState_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "NullSimulationState.h"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  MDNullSimulationState
     //  Description:  
     //  =====================================================================================
    class MDNullSimulationState : public NullSimulationState
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  MDNullSimulationState
            //      Method:  MDNullSimulationState :: MDNullSimulationState
            // Description:  
            // 
            //  Parameters: 
            //
             //      Return:
            //--------------------------------------------------------------------------------------
            MDNullSimulationState ();   // constructor

            MDNullSimulationState (MDNullSimulationState const & other);   // copy constructor

            MDNullSimulationState (MDNullSimulationState && other);   // copy-move constructor

            ~MDNullSimulationState ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            MDNullSimulationState& operator= ( MDNullSimulationState const & other ); // assignment operator

            MDNullSimulationState& operator= ( MDNullSimulationState && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================
            
            // ====================  ACCESSORS     =======================================
            void Execute_(Simulation * const a_simulation) const final;

            void Execute_() const final;

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class MDNullSimulationState  -----


}; // namespace ANANSI

#endif // ANANSI_MDNullSimulationState_INC
