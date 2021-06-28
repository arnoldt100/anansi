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

        bool isIICStatusOkay() const;

        ANANSI::RegistryAnansiMDStatus status() const;
        
        bool isHelpOnCommandLine() const;

        /* ====================  MUTATORS      ======================================= */

        void disableCommunication();

        // This group of functions initializes the simulation environment.
        void initializeSimulationEnvironment( int const & argc, char const *const *const & argv );

        void saveCommandLineArguments (int const & argc, char const *const *const & argv);

        void initializeMpiEnvironment(int const & argc, char const *const *const & argv);

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
        void changeMDStateToISE();
        void changeMDStateToPCL();
        void changeMDStateToIIC();
        void changeMDStateToPS();
        void changeMDStateToTSE();

        // This group of functions changes the state of the MD object.
        void setStatus(const RegistryAnansiMDStatus aStatus);

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
        virtual ANANSI::RegistryAnansiMDStatus _status() const;

        virtual bool _isHelpOnCommandLine() const=0;

        virtual bool _isIICStatusOkay() const=0;

        /* ====================  MUTATORS      ======================================= */

        virtual void _disableCommunication()=0;

        // This group of functions initializes the simulation environment.
        virtual void _initializeSimulationEnvironment( int const & argc, char const *const *const & argv )=0;

        virtual void _saveCommandLineArguments( int const & argc, char const *const *const & argv)=0;

        virtual void _initializeMpiEnvironment( int const & argc, char const *const *const & argv )=0;

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

        virtual void _changeMDStateToISE()=0;

        virtual void _changeMDStateToPCL()=0;

        virtual void _changeMDStateToIIC()=0;
        
        virtual void _changeMDStateToPS()=0;

        virtual void _changeMDStateToTSE()=0;

        // Set the status of the MD object.
        virtual void _setStatus(const RegistryAnansiMDStatus aStatus)=0;

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class MolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef MolecularDynamics_INC  ----- */

