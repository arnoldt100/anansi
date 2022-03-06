#ifndef ANANSI_MDPerformSimulation_INC
#define ANANSI_MDPerformSimulation_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PerformSimulation.h"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  MDPerformSimulation
     //  Description:  
     //  =====================================================================================
    class MDPerformSimulation : public PerformSimulation
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  MDPerformSimulation
            //      Method:  MDPerformSimulation :: MDPerformSimulation
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            MDPerformSimulation ();   // constructor

            MDPerformSimulation (const MDPerformSimulation & other);   // copy constructor

            MDPerformSimulation (MDPerformSimulation && other);   // copy-move constructor

            ~MDPerformSimulation ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            MDPerformSimulation& operator= ( const MDPerformSimulation &other ); // assignment operator

            MDPerformSimulation& operator= ( MDPerformSimulation && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class MDPerformSimulation  -----


}; // namespace ANANSI

#endif // ANANSI_MDPerformSimulation_INC
