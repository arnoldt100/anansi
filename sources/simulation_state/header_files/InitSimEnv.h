#ifndef ANANSI_InitSimEnv_INC
#define ANANSI_InitSimEnv_INC

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
     //        Class:  InitSimEnv
     //  Description:  
     //  =====================================================================================
    class InitSimEnv : public SimulationState
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  InitSimEnv
            //      Method:  InitSimEnv :: InitSimEnv
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            InitSimEnv ();   // constructor

            InitSimEnv (InitSimEnv const & other);   // copy constructor

            InitSimEnv (InitSimEnv && other);   // copy-move constructor

            virtual ~InitSimEnv ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            InitSimEnv& operator= ( InitSimEnv const & other ); // assignment operator

            InitSimEnv& operator= ( InitSimEnv && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  ACCESSORS     =======================================
            void execute_(Simulation * const a_simulation) const override;

            virtual void Execute_(Simulation * const a_simulation) const ;


            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class InitSimEnv  -----


}; // namespace ANANSI

#endif // ANANSI_InitSimEnv_INC
