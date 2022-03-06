#ifndef ANANSI_MDTerminateSimulation_INC
#define ANANSI_MDTerminateSimulation_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TerminateSimulation.h"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  MDTerminateSimulation
     //  Description:  
     //  =====================================================================================
    class MDTerminateSimulation : public TerminateSimulation
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  MDTerminateSimulation
            //      Method:  MDTerminateSimulation :: MDTerminateSimulation
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            MDTerminateSimulation ();   // constructor

            MDTerminateSimulation (const MDTerminateSimulation & other);   // copy constructor

            MDTerminateSimulation (MDTerminateSimulation && other);   // copy-move constructor

            ~MDTerminateSimulation ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            MDTerminateSimulation& operator= ( const MDTerminateSimulation &other ); // assignment operator

            MDTerminateSimulation& operator= ( MDTerminateSimulation && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class MDTerminateSimulation  -----


}; // namespace ANANSI

#endif // ANANSI_MDTerminateSimulation_INC
