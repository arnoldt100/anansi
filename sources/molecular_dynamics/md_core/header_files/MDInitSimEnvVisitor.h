#ifndef  ANANSI_MDInitSimEnvVisitor_INC
#define  ANANSI_MDInitSimEnvVisitor_INC


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
//        Class:  MDInitSimEnvVisitor
//  Description:  
//  =====================================================================================
class MDInitSimEnvVisitor : public MPL::BaseVisitor, 
                            public MPL::Visitor<ANANSI::AnansiMolecularDynamics>
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  MDInitSimEnvVisitor
        //      Method:  MDInitSimEnvVisitor :: MDInitSimEnvVisitor
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        MDInitSimEnvVisitor ();   // constructor

        MDInitSimEnvVisitor (const MDInitSimEnvVisitor & other);   // copy constructor

        MDInitSimEnvVisitor (MDInitSimEnvVisitor && other);   // copy-move constructor

        virtual ~MDInitSimEnvVisitor ();  // destructor

        // ====================  ACCESSORS     =======================================

        void visit(AnansiMolecularDynamics& a_sim) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        MDInitSimEnvVisitor& operator= ( const MDInitSimEnvVisitor &other ); // assignment operator

        MDInitSimEnvVisitor& operator= ( MDInitSimEnvVisitor && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MDInitSimEnvVisitor  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_MDInitSimEnvVisitor_INC  ----- 
