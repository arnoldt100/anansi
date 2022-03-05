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

            virtual ~ProcessCmdLine () = 0;  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            ProcessCmdLine& operator= ( ProcessCmdLine const & other ); // assignment operator

            ProcessCmdLine& operator= ( ProcessCmdLine && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class ProcessCmdLine  -----


}; // namespace ANANSI

#endif // ANANSI_ProcessCmdLine_INC
