
#ifndef  ANANSI_MDPerformSimulationVisitor_INC
#define  ANANSI_MDPerformSimulationVisitor_INC


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
//        Class:  MDPerformSimulationVisitor
//  Description:  
//  =====================================================================================
class MDPerformSimulationVisitor : public MPL::BaseVisitor,
                                   public MPL::Visitor<AnansiMolecularDynamics>
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  MDPerformSimulationVisitor
        //      Method:  MDPerformSimulationVisitor :: MDPerformSimulationVisitor
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        MDPerformSimulationVisitor ();   // constructor

        MDPerformSimulationVisitor (const MDPerformSimulationVisitor & other);   // copy constructor

        MDPerformSimulationVisitor (MDPerformSimulationVisitor && other);   // copy-move constructor

        virtual ~MDPerformSimulationVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================
        void visit(AnansiMolecularDynamics& a_sim) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDPerformSimulationVisitor& operator= ( const MDPerformSimulationVisitor &other ); // assignment operator

        MDPerformSimulationVisitor& operator= ( MDPerformSimulationVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MDPerformSimulationVisitor  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_MDPerformSimulationVisitor_INC  ----- */
