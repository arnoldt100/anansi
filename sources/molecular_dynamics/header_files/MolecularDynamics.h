/*
 * =====================================================================================
 *        Class:  MolecularDynamics
 *  Description:  
 * =====================================================================================
 */

// System includes

// Local incudes


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
        void doSimulation() final;

        void initializeSimulation( int const argc, char const *const *const argv ) final;

        /* ====================  OPERATORS     ======================================= */

        MolecularDynamics&                                                 
            operator=(MolecularDynamics const & other) = delete; // Avoid implicit copy assignment of
        // MolecularDynamics class.
    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */
        virtual void _doInitialization( int const argc, char const *const *const argv )=0;
        virtual void _doSimulation()=0;

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class MolecularDynamics  ----- */

}; /* -----  end of namespace ANANSI  ----- */

#endif   /* ----- #ifndef MolecularDynamics_INC  ----- */

