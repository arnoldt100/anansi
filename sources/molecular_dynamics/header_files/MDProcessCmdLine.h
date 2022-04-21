#ifndef ANANSI_MDProcessCmdLine_INC
#define ANANSI_MDProcessCmdLine_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MDProcessCmdLineVisitor.h"
#include "ProcessCmdLine.h"

namespace ANANSI
{

     // =====================================================================================
     //        Class:  MDProcessCmdLine
     //  Description:  
     //  =====================================================================================
    class MDProcessCmdLine : public ProcessCmdLine
    {
        public:
            // ====================  LIFECYCLE     =======================================

            //--------------------------------------------------------------------------------------
            //       Class:  MDProcessCmdLine
            //      Method:  MDProcessCmdLine :: MDProcessCmdLine
            // Description:  
            // 
            //  Parameters: 
            //
            //      Return:
            //--------------------------------------------------------------------------------------
            MDProcessCmdLine ();   // constructor

            MDProcessCmdLine (const MDProcessCmdLine & other);   // copy constructor

            MDProcessCmdLine (MDProcessCmdLine && other);   // copy-move constructor

            ~MDProcessCmdLine ();  // destructor

            // ====================  ACCESSORS     =======================================

            // ====================  MUTATORS      =======================================

            // ====================  OPERATORS     =======================================

            MDProcessCmdLine& operator= ( const MDProcessCmdLine &other ); // assignment operator

            MDProcessCmdLine& operator= ( MDProcessCmdLine && other ); // assignment-move operator

        protected:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

            // ====================  ACCESSORS     =======================================
            void Execute_(Simulation * const a_simulation) const final;

            void Execute_() const final;

        private:
            // ====================  METHODS       =======================================

            // ====================  DATA MEMBERS  =======================================

    }; // -----  end of class MDProcessCmdLine  -----


}; // namespace ANANSI

#endif // ANANSI_MDProcessCmdLine_INC
