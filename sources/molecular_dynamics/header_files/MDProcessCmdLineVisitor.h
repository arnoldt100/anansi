#ifndef  ANANSI_MDProcessCmdLineVisitor_INC
#define  ANANSI_MDProcessCmdLineVisitor_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "BaseVisitor.h"
#include "Visitor.hpp"
#include "AnansiMolecularDynamics.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  MDProcessCmdLineVisitor
//  Description:  
//  =====================================================================================
class MDProcessCmdLineVisitor : public MPL::BaseVisitor,
                                public MPL::Visitor<ANANSI::AnansiMolecularDynamics>
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  MDProcessCmdLineVisitor
        //      Method:  MDProcessCmdLineVisitor :: MDProcessCmdLineVisitor
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        MDProcessCmdLineVisitor ();   // constructor

        MDProcessCmdLineVisitor (const MDProcessCmdLineVisitor & other);   // copy constructor

        MDProcessCmdLineVisitor (MDProcessCmdLineVisitor && other);   // copy-move constructor

        virtual ~MDProcessCmdLineVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================
        void visit(AnansiMolecularDynamics& a_sim) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDProcessCmdLineVisitor& operator= ( const MDProcessCmdLineVisitor &other ); // assignment operator

        MDProcessCmdLineVisitor& operator= ( MDProcessCmdLineVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MDProcessCmdLineVisitor  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_MDProcessCmdLineVisitor_INC  ----- */
