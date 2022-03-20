/*
 * =====================================================================================
 *
 *       Filename:  SimulationFactory.h
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  MolecularDynamicsFactory_INC
#define  MolecularDynamicsFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory> 

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Simulation.h"

namespace ANANSI
{
    /*
     * =====================================================================================
     *        Class:  SimulationFactory
     *  Description:  
     * =====================================================================================
     */
    class SimulationFactory
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */
            SimulationFactory(); /* constructor      */

            SimulationFactory( const SimulationFactory &other )=delete;  /* copy constructor */

            virtual ~SimulationFactory()=0; /* destructor */

            /* ====================  ACCESSORS     ======================================= */

            std::shared_ptr<Simulation> create_shared_ptr();

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            SimulationFactory& 
                operator=( const SimulationFactory &other )=delete; /* assignment operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  ACCESSORS     ======================================= */
            virtual std::shared_ptr<Simulation> create_shared_ptr_()=0;

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class SimulationFactory  ----- */
}; /* -----  end of namespace MEMORY_MANAGEMENT  ----- */

#endif   /* ----- #ifndef MolecularDynamicsFactory_INC  ----- */
