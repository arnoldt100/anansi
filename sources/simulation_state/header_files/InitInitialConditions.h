#ifndef ANANSI_InitInitialConditions_INC
#define ANANSI_InitInitialConditions_INC

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
     //        Class:  InitInitialConditions
     //  Description:  
     //  =====================================================================================
    class InitInitialConditions : public SimulationState
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  InitInitialConditions
            //      Method:  InitInitialConditions :: InitInitialConditions
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            InitInitialConditions ();   // constructor

            InitInitialConditions (InitInitialConditions const & other);   // copy constructor

            InitInitialConditions (InitInitialConditions && other);   // copy-move constructor

            virtual ~InitInitialConditions ()=0;  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            InitInitialConditions& operator= ( InitInitialConditions const & other ); // assignment operator

            InitInitialConditions& operator= ( InitInitialConditions && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class InitInitialConditions  -----


}; // namespace ANANSI

#endif // ANANSI_InitInitialConditions_INC
