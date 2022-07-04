#ifndef  ANANSI_ISEStatus_INC
#define  ANANSI_ISEStatus_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include "TaskStatus.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

     // =====================================================================================
     //        Class:  ISEStatus
     //  Description:  
     //  =====================================================================================
    class ISEStatus final :public COMMUNICATOR::TaskStatus
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  ISEStatus
            //      Method:  ISEStatus :: ISEStatus
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            ISEStatus ();   // constructor

            ISEStatus (const ISEStatus & other);   // copy constructor

            ISEStatus (ISEStatus && other);   // copy-move constructor

            ~ISEStatus (); // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            ISEStatus& operator= ( const ISEStatus &other ); // assignment operator

            ISEStatus& operator= ( ISEStatus && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class ISEStatus  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_ISEStatus_INC  ----- 
