#ifndef ANANSI_SimulationState_INC
#define ANANSI_SimulationState_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <unordered_map>
#include <string>
#include <functional>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Forward declarations -------------//
//--------------------------------------------------------//
namespace ANANSI
{
    class Simulation;
};

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

        void execute (Simulation * const a_simulation ) const;

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
        virtual void execute_(Simulation* const a_simulation) const;

        virtual std::string misbehviorErrorMessage_(state_misbehavior_info const & error_info) const;

    private:
        // ====================  METHODS       =======================================

        // ====================  ACCESSORS     =======================================




        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class SimulationState  -----


}; // namespace ANANSI

#endif // ANANSI_SimulationState_INC
