/*
 * =====================================================================================
 *        Class:  MolecularDynamics
 *  Description:  
 * =====================================================================================
 */

// System includes
#include <iostream>
#include <memory>

// Local incudes
#include "AnansiMDState.h"


#ifndef  MolecularDynamics_INC
#define  MolecularDynamics_INC

namespace ANANSI
{

class MolecularDynamics
{

    public:
        /* ====================  LIFECYCLE     ======================================= */
        MolecularDynamics(); /* constructor */

        virtual ~MolecularDynamics()=0; /* destructor */ 

        MolecularDynamics(MolecularDynamics const & other) = delete; // Avoid implicit of copying the
        // MolecularDynamics class.

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */
        void doSimulation();

        void enableCommunication();

        void disableCommunication();

        void initializeSimulation( int const argc, char const *const *const & argv );

        void initializeSimulationEnvironment( int const argc, char const *const *const & argv );

        void setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState)
        {
            this->_setMDState(std::move(a_AnansiMDState));
        }

        /* ====================  OPERATORS     ======================================= */

        MolecularDynamics&                                                 
        operator=(MolecularDynamics const & other) = delete; // Avoid implicit copy assignment of
                                                             // MolecularDynamics class.
    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  MUTATORS      ======================================= */
        virtual void 
        _doSimulation()=0;

        virtual void 
        _enableCommunication()=0;

        virtual void _disableCommunication()=0;

        virtual void _initializeSimulation( int const argc, char const *const *const & argv )=0;

        virtual void _initializeSimulationEnvironment( int const argc, char const *const *const & argv )=0;

        virtual void _setMDState(std::unique_ptr<AnansiMDState> && a_AnansiMDState)=0;

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class MolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef MolecularDynamics_INC  ----- */

