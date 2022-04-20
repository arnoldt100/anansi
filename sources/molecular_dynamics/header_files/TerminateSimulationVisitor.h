#ifndef  ANANSI_TerminateSimulationVisitor_INC
#define  ANANSI_TerminateSimulationVisitor_INC


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
//        Class:  TerminateSimulationVisitor
//  Description:  
//  =====================================================================================
class TerminateSimulationVisitor : public MPL::BaseVisitor,
                                   public MPL::Visitor<AnansiMolecularDynamics>
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  TerminateSimulationVisitor
        //      Method:  TerminateSimulationVisitor :: TerminateSimulationVisitor
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        TerminateSimulationVisitor ();   // constructor

        TerminateSimulationVisitor (const TerminateSimulationVisitor & other);   // copy constructor

        TerminateSimulationVisitor (TerminateSimulationVisitor && other);   // copy-move constructor

        virtual ~TerminateSimulationVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================
        void visit(AnansiMolecularDynamics& a_sim) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        TerminateSimulationVisitor& operator= ( const TerminateSimulationVisitor &other ); // assignment operator

        TerminateSimulationVisitor& operator= ( TerminateSimulationVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class TerminateSimulationVisitor  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_TerminateSimulationVisitor_INC  ----- */
