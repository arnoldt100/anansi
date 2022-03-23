#ifndef ANANSI_SimulationState_INC
#define ANANSI_SimulationState_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <unordered_map>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Forward declarations -------------//
//--------------------------------------------------------//
class Simulation;

namespace ANANSI
{

// =====================================================================================
//        Class:  SimulationState
//  Description:  
//  =====================================================================================
class SimulationState
{
    public:

        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  SimulationState
        //      Method:  SimulationState :: SimulationState
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        SimulationState ();   // constructor

        SimulationState (const SimulationState & other);   // copy constructor

        SimulationState (SimulationState && other);   // copy-move constructor

        virtual ~SimulationState ()=0;  // destructor

        // ====================  ACCESSORS     =======================================
        virtual void who_am_i() const;

        //--------------------------------------------------------------------------------------
        //       Class:  SimulationState
        //      Method:  AnansiMDState :: initializeSimulationEnvironment
        // Description:  This function makes a request to the simulation object
        // to initialize the simulation environment.
        //
        //  Parameters:
        //        a_simulation : The object the request is made to.
        //
        //--------------------------------------------------------------------------------------
        void initializeSimulationEnvironment(Simulation * const a_simulation ) const;

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        SimulationState& operator= ( const SimulationState &other ); // assignment operator

        SimulationState& operator= ( SimulationState && other ); // assignment-move operator

    protected:
        // ====================  Type Aliases  =======================================
        
        using state_misbehavior_info = std::unordered_map<std::string, std::string>;

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

        // ====================  ACCESSORS     =======================================
        virtual std::string misbehviorErrorMessage_(state_misbehavior_info const & error_info) const;


    private:
        // ====================  METHODS       =======================================

        // ====================  ACCESSORS     =======================================

        virtual void processCommandLine_(Simulation* const a_simulation) const=0;

        virtual void initializeSimulationEnvironment_(Simulation* const a_simulation) const=0;




        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class SimulationState  -----


}; // namespace ANANSI

#endif // ANANSI_SimulationState_INC
