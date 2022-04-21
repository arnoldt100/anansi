#ifndef  ANANSI_MDNullSimulationStateVisitor_INC
#define  ANANSI_MDNullSimulationStateVisitor_INC


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
//        Class:  MDNullSimulationStateVisitor
//  Description:  
//  =====================================================================================
class MDNullSimulationStateVisitor : public MPL::BaseVisitor,
                                     public MPL::Visitor<AnansiMolecularDynamics>
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  MDNullSimulationStateVisitor
        //      Method:  MDNullSimulationStateVisitor :: MDNullSimulationStateVisitor
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        MDNullSimulationStateVisitor ();   // constructor

        MDNullSimulationStateVisitor (const MDNullSimulationStateVisitor & other);   // copy constructor

        MDNullSimulationStateVisitor (MDNullSimulationStateVisitor && other);   // copy-move constructor

        virtual ~MDNullSimulationStateVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================
        void visit(AnansiMolecularDynamics& a_sim) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDNullSimulationStateVisitor& operator= ( const MDNullSimulationStateVisitor &other ); // assignment operator

        MDNullSimulationStateVisitor& operator= ( MDNullSimulationStateVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MDNullSimulationStateVisitor  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_MDNullSimulationStateVisitor_INC  ----- */
