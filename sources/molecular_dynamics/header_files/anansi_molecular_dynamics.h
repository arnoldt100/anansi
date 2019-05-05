/*
 * =====================================================================================
 *        Class:  AnansiMolecularDynamics
 *  Description:  
 * =====================================================================================
 */

#ifndef  anansi_molecular_dynamics_INC
#define  anansi_molecular_dynamics_INC

namespace ANANSI {

    class AnansiMolecularDynamics
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            AnansiMolecularDynamics ();  /* constructor */

            ~AnansiMolecularDynamics (); /* destructor */

            AnansiMolecularDynamics(AnansiMolecularDynamics const & other) = delete; // Avoid implicit of copying the
                                                                                     // AnansiMolecularDynamics class.

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            AnansiMolecularDynamics&                                                 
            operator=(AnansiMolecularDynamics const & other) = delete; // Avoid implicit copy assignment of
                                                                       // AnansiMolecularDynamics class.

            /* ====================  STATIC        ======================================= */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

            /* ====================  STATIC        ======================================= */

    }; /* -----  end of class AnansiMolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef anansi_molecular_dynamics_INC  ----- */
