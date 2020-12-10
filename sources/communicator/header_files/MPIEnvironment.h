
#ifndef  MPIEnvironment_INC
#define  MPIEnvironment_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIInitializedException.h"
#include "MPIFinalizedException.h"
#include "CounterClass.h"

namespace COMMUNICATOR
{

constexpr auto max_mpi_environment = 1;

class MPIEnvironment : COUNTERCLASSES::ClassCounter<MPIEnvironment,max_mpi_environment>
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        /*
         *--------------------------------------------------------------------------------------
         *       Class:  MPIEnvironment
         *      Method:  MPIEnvironment :: MPIEnvironment
         * Description:  Constructor
         *
         * Arguments: 
         *
         *--------------------------------------------------------------------------------------
         */
        MPIEnvironment(int argc, char** argv); /* constructor */

        MPIEnvironment( const MPIEnvironment &other )=delete; /* copy constructor */

        ~MPIEnvironment(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        MPIEnvironment& 
        operator=( const MPIEnvironment &other )=delete; /* assignment operator */

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
