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

            virtual ~InitInitialConditions () = 0;  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            InitInitialConditions& operator= ( InitInitialConditions const & other ); // assignment operator

            InitInitialConditions& operator= ( InitInitialConditions && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

            // ====================  ACCESSORS     =======================================
            void execute_(Simulation * const a_simulation) const override;

            void execute_() const override;

            virtual void Execute_(Simulation * const a_simulation) const ;

            virtual void Execute_() const ;

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class InitInitialConditions  -----


}; // namespace ANANSI

#endif // ANANSI_InitInitialConditions_INC
