#ifndef  ANANSI_MDNullSimulationVisitor_INC
#define  ANANSI_MDNullSimulationVisitor_INC


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
//        Class:  MDNullSimulationVisitor
//  Description:  
//  =====================================================================================
class MDNullSimulationVisitor : public MPL::BaseVisitor,
                                     public MPL::Visitor<ANANSI::AnansiMolecularDynamics>
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  MDNullSimulationVisitor
        //      Method:  MDNullSimulationVisitor :: MDNullSimulationVisitor
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        MDNullSimulationVisitor ();   // constructor

        MDNullSimulationVisitor (const MDNullSimulationVisitor & other);   // copy constructor

        MDNullSimulationVisitor (MDNullSimulationVisitor && other);   // copy-move constructor

        virtual ~MDNullSimulationVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================
        void visit(AnansiMolecularDynamics& a_sim) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDNullSimulationVisitor& operator= ( const MDNullSimulationVisitor &other ); // assignment operator

        MDNullSimulationVisitor& operator= ( MDNullSimulationVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MDNullSimulationVisitor  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_MDNullSimulationVisitor_INC  ----- */
