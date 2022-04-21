#ifndef ANANSI_ProcessCmdLine_INC
#define ANANSI_ProcessCmdLine_INC

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
     //        Class:  ProcessCmdLine
     //  Description:  
     //  =====================================================================================
    class ProcessCmdLine : public SimulationState
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  ProcessCmdLine
            //      Method:  ProcessCmdLine :: ProcessCmdLine
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            ProcessCmdLine ();   // constructor

            ProcessCmdLine (ProcessCmdLine const & other);   // copy constructor

            ProcessCmdLine (ProcessCmdLine && other);   // copy-move constructor

            virtual ~ProcessCmdLine ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            ProcessCmdLine& operator= ( ProcessCmdLine const & other ); // assignment operator

            ProcessCmdLine& operator= ( ProcessCmdLine && other ); // assignment-move operator

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

    }; // -----  end of class ProcessCmdLine  -----


}; // namespace ANANSI

#endif // ANANSI_ProcessCmdLine_INC
