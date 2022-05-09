#ifndef ANANSI_NullSimulation_INC
#define ANANSI_NullSimulation_INC

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
//        Class:  NullSimulation
//  Description:  
//  =====================================================================================
class NullSimulation : public SimulationState
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  NullSimulation
        //      Method:  NullSimulation :: NullSimulation
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        NullSimulation ();   // constructor

        NullSimulation (NullSimulation const & other);   // copy constructor

        NullSimulation (NullSimulation && other);   // copy-move constructor

        virtual ~NullSimulation () = 0 ;  // destructor

        // ====================  ACCESSORS     =======================================
        virtual void who_am_i() const override;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        NullSimulation& operator= ( NullSimulation const & other ); // assignment operator

        NullSimulation& operator= ( NullSimulation && other ); // assignment-move operator

    protected:
        // ====================  ACCESSORS     =======================================
        // void processCommandLine_(Simulation * const aSimulation) const override;
        
        void execute_(Simulation * const a_simulation) const override;

        virtual void Execute_(Simulation * const a_simulation) const ;

        // ====================  MUTATORS      =======================================

        // ====================  DATA MEMBERS  =======================================

    private:

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class NullSimulation  -----


}; // namespace ANANSI

#endif // ANANSI_NullSimulation_INC
