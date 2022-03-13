#ifndef ANANSI_SimulationState_INC
#define ANANSI_SimulationState_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

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
        void who_am_i() const
        {
            std::cout << "I'm SimulationState" << std::endl;
        }

        // ====================  MUTATORS      =======================================

        // ====================  OPERATORS     =======================================

        SimulationState& operator= ( const SimulationState &other ); // assignment operator

        SimulationState& operator= ( SimulationState && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class SimulationState  -----


}; // namespace ANANSI

#endif // ANANSI_SimulationState_INC
