/*
 * =====================================================================================
 *
 *       Filename:  MolecularDynamicsFactory.h
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

#include "MolecularDynamics.h"

namespace ANANSI
{
    /*
     * =====================================================================================
     *        Class:  MolecularDynamicsFactory
     *  Description:  
     * =====================================================================================
     */
    class MolecularDynamicsFactory
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */
            MolecularDynamicsFactory(); /* constructor      */

            MolecularDynamicsFactory( const MolecularDynamicsFactory &other )=delete;  /* copy constructor */

            virtual ~MolecularDynamicsFactory()=0; /* destructor */

            /* ====================  ACCESSORS     ======================================= */
            MolecularDynamics* create()
            {
                return this->_create();
            }

            std::shared_ptr<MolecularDynamics> create_shared_ptr();

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            MolecularDynamicsFactory& 
                operator=( const MolecularDynamicsFactory &other )=delete; /* assignment operator */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  ACCESSORS     ======================================= */
            virtual MolecularDynamics* _create()=0; 

            virtual std::shared_ptr<MolecularDynamics> _create_shared_ptr()=0;

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class MolecularDynamicsFactory  ----- */
}; /* -----  end of namespace MEMORY_MANAGEMENT  ----- */

#endif   /* ----- #ifndef MolecularDynamicsFactory_INC  ----- */
