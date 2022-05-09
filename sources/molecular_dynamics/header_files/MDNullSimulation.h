#ifndef ANANSI_MDNullSimulation_INC
#define ANANSI_MDNullSimulation_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "NullSimulation.h"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  MDNullSimulation
     //  Description:  
     //  =====================================================================================
    class MDNullSimulation : public NullSimulation
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  MDNullSimulation
            //      Method:  MDNullSimulation :: MDNullSimulation
            // Description:  
            // 
            //  Parameters: 
            //
             //      Return:
            //--------------------------------------------------------------------------------------
            MDNullSimulation ();   // constructor

            MDNullSimulation (MDNullSimulation const & other);   // copy constructor

            MDNullSimulation (MDNullSimulation && other);   // copy-move constructor

            ~MDNullSimulation ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            MDNullSimulation& operator= ( MDNullSimulation const & other ); // assignment operator

            MDNullSimulation& operator= ( MDNullSimulation && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================
            
            // ====================  ACCESSORS     =======================================
            void Execute_(Simulation * const a_simulation) const final;

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class MDNullSimulation  -----


}; // namespace ANANSI

#endif // ANANSI_MDNullSimulation_INC
