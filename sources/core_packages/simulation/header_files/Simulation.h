#ifndef  ANANSI_Simulation_INC
#define  ANANSI_Simulation_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "DefineVisitableMacro.h"
#include "BaseVisitable.hpp"
#include "RegistryAnansiMDStatus.h"

namespace ANANSI
{

// =====================================================================================
//        Class:  Simulation
//  Description:  
//  =====================================================================================
class Simulation : public MPL::BaseVisitable<>
{

    public:
        /* ====================  LIFECYCLE     ======================================= */
        Simulation();

        virtual ~Simulation()=0;

        Simulation(Simulation const & other) = delete;

        Simulation(Simulation && other) = delete;

        /* ====================  ACCESSORS     ======================================= */


        void stud_function(std::string const & message) const;

        bool isISEStatusOkay() const;

        bool isISEGlobalStatusOkay() const;

        bool isIICStatusOkay() const;

        COMMUNICATOR::RegistryAnansiMDStatus status() const;

        COMMUNICATOR::RegistryAnansiMDStatus globalStatus() const;
        
        bool isHelpOnCommandLine() const;

        /* ====================  MUTATORS      ======================================= */

        DEFINE_VISITABLE()

        // This function initializes the simulation environment.
        void initializeSimulationEnvironment();

        // This function processes the command line and sets the
        // simulation parameters.
        void processCommandLine(); 

        // This function initializes the initial conditions of the 
        // simulation.
        void initializeInitialConditions();

        // This function performs the simulation.
        void performSimulation();

        // This function terminates the simulation environment.
        void terminateSimulationEnvironment();

        // This group of functions changes the status of the MD object.
        void setStatus(const COMMUNICATOR::RegistryAnansiMDStatus aStatus);
        void setGlobalISEStatus();

        /* ====================  OPERATORS     ======================================= */

        Simulation&                                                 
        operator=(Simulation const & other) = delete;

        Simulation&                                                 
        operator=(Simulation && other) = delete; 

    protected:
        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

    private:
        /* ====================  ACCESSORS     ======================================= */
        virtual COMMUNICATOR::RegistryAnansiMDStatus status_() const;

        virtual bool isHelpOnCommandLine_() const=0;

        virtual bool isISEStatusOkay_() const=0;

        virtual bool isISEGlobalStatusOkay_() const=0;

        virtual bool isIICStatusOkay_() const=0;

        /* ====================  MUTATORS      ======================================= */

        // This group of functions initializes the simulation environment.
        virtual void initializeSimulationEnvironment_()=0;

        // This group of functions processes the command line and sets the
        // simulation parameters.
        virtual void processCommandLine_()=0; 

        // This group of functions initializes the initial conditions of the 
        // simulation.
        virtual void initializeInitialConditions_()=0;

        // This group of functions performs the MD simulation.
        virtual void performSimulation_()=0;

        // This group of functions terminates the simulation environment.
        virtual void terminateSimulationEnvironment_()=0;

        // Set the status of the MD object.
        virtual void setStatus_(const COMMUNICATOR::RegistryAnansiMDStatus aStatus)=0;
        virtual void setGlobalISEStatus_()=0;

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class Simulation  ----- */


}; // namespace ANANSI

#endif   /* ----- #ifndef ANANSI_Simulation_INC  ----- */
