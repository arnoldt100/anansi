#ifndef  ANANSI_MDTerminateSimulationVisitor_INC
#define  ANANSI_MDTerminateSimulationVisitor_INC


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
//        Class:  MDTerminateSimulationVisitor
//  Description:  
//  =====================================================================================
class MDTerminateSimulationVisitor : public MPL::BaseVisitor,
                                     public MPL::Visitor<AnansiMolecularDynamics>
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  MDTerminateSimulationVisitor
        //      Method:  MDTerminateSimulationVisitor :: MDTerminateSimulationVisitor
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        MDTerminateSimulationVisitor ();   // constructor

        MDTerminateSimulationVisitor (const MDTerminateSimulationVisitor & other);   // copy constructor

        MDTerminateSimulationVisitor (MDTerminateSimulationVisitor && other);   // copy-move constructor

        virtual ~MDTerminateSimulationVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================
        void visit(AnansiMolecularDynamics& a_sim) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDTerminateSimulationVisitor& operator= ( const MDTerminateSimulationVisitor &other ); // assignment operator

        MDTerminateSimulationVisitor& operator= ( MDTerminateSimulationVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MDTerminateSimulationVisitor  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_MDTerminateSimulationVisitor_INC  ----- */
