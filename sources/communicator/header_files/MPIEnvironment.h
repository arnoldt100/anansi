
#ifndef  MPIEnvironment_INC
#define  MPIEnvironment_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"
#include <iostream>
#include <cstdlib>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIInitException.h"
#include "MPIInitializedException.h"
#include "MPIFinalizedException.h"
#include "ClassInstanceLimiter.hpp"

namespace COMMUNICATOR
{

constexpr auto MAX_MPIENVIRONMENT_INSTANCES = 1;

class MPIEnvironment : COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        MPIEnvironment(int argc, char** argv); /* constructor */

        MPIEnvironment(const MPIEnvironment &other)=delete; /* copy constructor */

        ~MPIEnvironment(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        MPIEnvironment& 
        operator=(const MPIEnvironment &other)=delete; /* assignment operator */

        /* ====================  STATIC        ======================================= */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class MPIEnvironment  ----- */


}; /* namespace COMMUNICATOR */

#endif   /* ----- #ifndef MPIEnvironment_INC  ----- */
