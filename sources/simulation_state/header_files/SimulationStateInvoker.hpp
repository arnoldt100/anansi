#ifndef  ANANSI_SimulationStateInvoker_INC
#define  ANANSI_SimulationStateInvoker_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>
#include <map>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationState.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  SimulationStateInvoker
//  Description:  
//  =====================================================================================
template< typename T > 
class SimulationStateInvoker final
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  SimulationStateInvoker
        //      Method:  SimulationStateInvoker :: SimulationStateInvoker
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        SimulationStateInvoker()
        {
            return;
        }

        SimulationStateInvoker( SimulationStateInvoker && other)
        {
            return;
        }		// -----  end of method SimulationStateInvoker::SimulationStateInvoker  -----


        virtual ~SimulationStateInvoker()
        {
            return;
        }

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        void setCommand(std::string const & key, std::shared_ptr<SimulationState> simulation_state)
        {
            this->simulationStates_.insert({key,simulation_state});
            return;
        }

        void executeCommand(std::string key)
        {
            this->simulationStates_.at(key)->execute();
            return;
        }

        // ====================  OPERATORS     =======================================

        SimulationStateInvoker& operator= ( const SimulationStateInvoker &other )
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment operator

        SimulationStateInvoker& operator= ( SimulationStateInvoker && other )
        {
            if (this != &other)
            {

            }
            return *this;
        } // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================
        std::map<std::string,std::shared_ptr<ANANSI::SimulationState>> simulationStates_;

}; // -----  end of class SimulationStateInvoker  -----


}; // namespace ANANSI

#endif   // ----- #ifndef ANANSI_SimulationStateInvoker_INC  ----- 
