#ifndef  AnansiMolecularDynamicsFactory_INC
#define  AnansiMolecularDynamicsFactory_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "AnansiMolecularDynamics.h"
#include "MolecularDynamicsFactory.h"

namespace ANANSI
{
    /*
     * =====================================================================================
     *        Class:  AnansiMolecularDynamicsFactory
     *  Description:  
     * =====================================================================================
     */
    class AnansiMolecularDynamicsFactory final : public MolecularDynamicsFactory 
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */
            AnansiMolecularDynamicsFactory(); /* constructor      */

            AnansiMolecularDynamicsFactory(int const argc, char const * const * const & argv ); /* constructor      */

            AnansiMolecularDynamicsFactory(const AnansiMolecularDynamicsFactory &other )=delete;

            AnansiMolecularDynamicsFactory(AnansiMolecularDynamicsFactory && other )=delete;

            ~AnansiMolecularDynamicsFactory(); /* destructor       */

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMolecularDynamicsFactory&
            operator=( const AnansiMolecularDynamicsFactory &other )=delete;

            AnansiMolecularDynamicsFactory&
            operator=( AnansiMolecularDynamicsFactory && other )=delete;

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */
            std::shared_ptr<MolecularDynamics> create_shared_ptr_() final override;

            /* ====================  DATA MEMBERS  ======================================= */
            int argc_;
            char** argv_ptr_;

    }; /* -----  end of class AnansiMolecularDynamicsFactory  ----- */
};		/* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef AnansiMolecularDynamicsFactory_INC  ----- */
