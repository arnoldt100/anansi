/*
 * =====================================================================================
 *        Class:  MolecularDynamics
 *  Description:  
 * =====================================================================================
 */

// System includes
#include <iostream>
#include <memory>

// Local includes
#include "AnansiMDState.h"
#include "SimulationState.h"
#include "RegistryAnansiMDStatus.h"

#ifndef  MolecularDynamics_INC
#define  MolecularDynamics_INC

namespace ANANSI
{

class MolecularDynamics
{

    public:
        /* ====================  LIFECYCLE     ======================================= */
        MolecularDynamics();

        virtual ~MolecularDynamics()=0;

        MolecularDynamics(MolecularDynamics const & other) = delete;

        MolecularDynamics(MolecularDynamics && other) = delete;

        /* ====================  ACCESSORS     ======================================= */

        void stud_function(std::string const & message) const;

        bool isISEStatusOkay() const;

        bool isISEGlobalStatusOkay() const;

        bool isIICStatusOkay() const;

        COMMUNICATOR::RegistryAnansiMDStatus status() const;

        COMMUNICATOR::RegistryAnansiMDStatus globalStatus() const;
        
        bool isHelpOnCommandLine() const;

        /* ====================  MUTATORS      ======================================= */

        void disableCommunication();

        // This group of functions initializes the simulation environment.
        void initializeSimulationEnvironment();

        void initializeMpiEnvironment();

        void enableCommunication();


        // This group of functions processes the command line and sets the
        // simulation parameters.
        void processCommandLine(); 

        void saveCommandLineOptionsValues();

        // This group of functions initializes the initial conditions of the 
        // simulation.
        void initializeInitialConditions();

        void inputSimulationControlFile();

        void readInitialConfiguration();

        // This group of functions performs the MD simulation.
        void performSimulation();

        // This group of functions terminates the simulation environment.
        void terminateSimulationEnvironment();

        // These group of functions change the state of the MD object.
        // TO DO: This method will be depracted. 
        void changeMDStateToPCL();
        // TO DO: This method will be depracted. 
        void changeMDStateToIIC();
        // TO DO: This method will be depracted. 
        void changeMDStateToPS();
        // TO DO: This method will be depracted. 
        void changeMDStateToTSE();
        // TO DO: This method will be depracted. 
        void changeMDState(int const id);
        
        // These group of functions change the state of the MD object.
        void changeSimulationState( SimulationState const & sim_state)
        {
            this->changeSimulationState_(sim_state);
            return;
        }

        // This group of functions changes the status of the MD object.
        
        void setStatus(const COMMUNICATOR::RegistryAnansiMDStatus aStatus);
        void setGlobalISEStatus();

        /* ====================  OPERATORS     ======================================= */

        MolecularDynamics&                                                 
        operator=(MolecularDynamics const & other) = delete;

        MolecularDynamics&                                                 
        operator=(MolecularDynamics && other) = delete; 

    protected:
        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

    private:
        /* ====================  ACCESSORS     ======================================= */
        virtual COMMUNICATOR::RegistryAnansiMDStatus _status() const;

        virtual bool _isHelpOnCommandLine() const=0;

        virtual bool _isISEStatusOkay() const=0;

        virtual bool _isISEGlobalStatusOkay() const=0;

        virtual bool _isIICStatusOkay() const=0;

        /* ====================  MUTATORS      ======================================= */

        virtual void _disableCommunication()=0;

        // This group of functions initializes the simulation environment.
        virtual void _initializeSimulationEnvironment()=0;

        virtual void _initializeMpiEnvironment()=0;

        virtual void _enableCommunication()=0;

        // This group of functions processes the command line and sets the
        // simulation parameters.
        virtual void _processCommandLine()=0; 

        virtual void _saveCommandLineOptionParameters()=0;

        // This group of functions initializes the initial conditions of the 
        // simulation.
        virtual void _initializeInitialConditions()=0;

        virtual void _inputSimulationControlFile()=0;

        virtual void _readInitialConfiguration()=0;

        // This group of functions performs the MD simulation.
        virtual void _performSimulation()=0;

        // This group of functions terminates the simulation environment.
        virtual void _terminateSimulationEnvironment()=0;

        // This group of functions changes the state of the MD object.
        virtual void _setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState)=0;

        virtual void _changeMDStateToPCL()=0;

        virtual void _changeMDStateToIIC()=0;
        
        virtual void _changeMDStateToPS()=0;

        virtual void _changeMDStateToTSE()=0;

        virtual void _changeMDState(int const id)=0;

        virtual void changeSimulationState_( SimulationState const & sim_state)=0;

        // Set the status of the MD object.
        virtual void _setStatus(const COMMUNICATOR::RegistryAnansiMDStatus aStatus)=0;
        virtual void _setGlobalISEStatus()=0;

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class MolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef MolecularDynamics_INC  ----- */

