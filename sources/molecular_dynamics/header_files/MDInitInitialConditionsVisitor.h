#ifndef  ANANSI_MDInitInitialConditionsVisitor_INC
#define  ANANSI_MDInitInitialConditionsVisitor_INC


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
//        Class:  MDInitInitialConditionsVisitor
//  Description:
//  =====================================================================================
class MDInitInitialConditionsVisitor : public MPL::BaseVisitor,
                                       public MPL::Visitor<ANANSI::AnansiMolecularDynamics>
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  MDInitInitialConditionsVisitor
        //      Method:  MDInitInitialConditionsVisitor :: MDInitInitialConditionsVisitor
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        MDInitInitialConditionsVisitor ();   // constructor

        MDInitInitialConditionsVisitor (const MDInitInitialConditionsVisitor & other);   // copy constructor

        MDInitInitialConditionsVisitor (MDInitInitialConditionsVisitor && other);   // copy-move constructor

        virtual ~MDInitInitialConditionsVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================
        void visit(AnansiMolecularDynamics& a_sim) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDInitInitialConditionsVisitor& operator= ( const MDInitInitialConditionsVisitor &other ); // assignment operator

        MDInitInitialConditionsVisitor& operator= ( MDInitInitialConditionsVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  ACCESSORS     =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MDInitInitialConditionsVisitor  -----


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_MDInitInitialConditionsVisitor_INC  ----- */
