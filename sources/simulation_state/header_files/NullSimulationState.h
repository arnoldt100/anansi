#ifndef ANANSI_NullSimulationState_INC
#define ANANSI_NullSimulationState_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationState.h"

//--------------------------------------------------------//
//--------------------- Forward declarations -------------//
//--------------------------------------------------------//


namespace ANANSI
{

// =====================================================================================
//        Class:  NullSimulationState
//  Description:  
//  =====================================================================================
class NullSimulationState : public SimulationState
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  NullSimulationState
        //      Method:  NullSimulationState :: NullSimulationState
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        NullSimulationState ();   // constructor

        NullSimulationState (NullSimulationState const & other);   // copy constructor

        NullSimulationState (NullSimulationState && other);   // copy-move constructor

        virtual ~NullSimulationState ();  // destructor

        // ====================  ACCESSORS     =======================================
        virtual void who_am_i() const override;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        NullSimulationState& operator= ( NullSimulationState const & other ); // assignment operator

        NullSimulationState& operator= ( NullSimulationState && other ); // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================
        void processCommandLine_(Simulation * const aSimulation) const override;
        
        void execute_(Simulation * const a_simulation) const override;

        void execute_() const override;

        virtual void Execute_(Simulation * const a_simulation) const ;

        virtual void Execute_() const;

        // ====================  MUTATORS      =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class NullSimulationState  -----


}; // namespace ANANSI

#endif // ANANSI_NullSimulationState_INC
