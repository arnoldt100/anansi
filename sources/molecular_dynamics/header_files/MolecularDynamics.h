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

class MolecularDynamics
{

public:
    /* ====================  LIFECYCLE     ======================================= */
    MolecularDynamics (); /* constructor */

    virtual ~MolecularDynamics=0 /* destructor */ 

    MolecularDynamics(MolecularDynamics const & other) = delete; // Avoid implicit of copying the
                                                                 // MolecularDynamics class.

    /* ====================  ACCESSORS     ======================================= */

    /* ====================  MUTATORS      ======================================= */

    /* ====================  OPERATORS     ======================================= */

    MolecularDynamics&                                                 
    operator=(MolecularDynamics const & other) = delete; // Avoid implicit copy assignment of
                                                         // MolecularDynamics class.
protected:
    /* ====================  METHODS       ======================================= */

    /* ====================  DATA MEMBERS  ======================================= */

private:
    /* ====================  METHODS       ======================================= */

    /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class MolecularDynamics  ----- */

#endif   /* ----- #ifndef MolecularDynamics_INC  ----- */

