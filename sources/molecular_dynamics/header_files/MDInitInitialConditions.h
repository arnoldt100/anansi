#ifndef ANANSI_MDInitInitialConditions_INC
#define ANANSI_MDInitInitialConditions_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "InitInitialConditions.h"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  MDInitInitialConditions
     //  Description:  
     //  =====================================================================================
    class MDInitInitialConditions : InitInitialConditions
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  MDInitInitialConditions
            //      Method:  MDInitInitialConditions :: MDInitInitialConditions
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            MDInitInitialConditions ();   // constructor

            MDInitInitialConditions (const MDInitInitialConditions & other);   // copy constructor

            MDInitInitialConditions (MDInitInitialConditions && other);   // copy-move constructor

            ~MDInitInitialConditions ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            MDInitInitialConditions& operator= ( const MDInitInitialConditions &other ); // assignment operator

            MDInitInitialConditions& operator= ( MDInitInitialConditions && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class MDInitInitialConditions  -----


}; // namespace ANANSI

#endif // ANANSI_MDInitInitialConditions_INC
