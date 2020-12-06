/*
 * =====================================================================================
 *
 *       Filename:  AnansiMolecularDynamicsFactory.h
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  AnansiMolecularDynamicsFactory_INC
#define  AnansiMolecularDynamicsFactory_INC

// System includes

// Local includes
#include "Pointer.hpp"
#include "MolecularDynamicsFactory.h"
#include "AnansiMolecularDynamics.h"

namespace ANANSI
{
    /*
     * =====================================================================================
     *        Class:  AnansiMolecularDynamicsFactory
     *  Description:  
     * =====================================================================================
     */
    class AnansiMolecularDynamicsFactory : public MolecularDynamicsFactory 
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */
            AnansiMolecularDynamicsFactory(); /* constructor      */
            AnansiMolecularDynamicsFactory(const AnansiMolecularDynamicsFactory &other )=delete;   /* copy constructor */
            ~AnansiMolecularDynamicsFactory(); /* destructor       */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMolecularDynamicsFactory&
            operator=( const AnansiMolecularDynamicsFactory &other )=delete; /* assignment operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */
            MolecularDynamics* _create() final override;

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class AnansiMolecularDynamicsFactory  ----- */
};		/* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef AnansiMolecularDynamicsFactory_INC  ----- */
