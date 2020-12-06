
#ifndef  MPIEnvironment_INC
#define  MPIEnvironment_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include "mpi.h"

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COMMUNICATOR
{

class MPIEnvironment
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
        MPIEnvironment(); /* constructor */

        MPIEnvironment( const MPIEnvironment &other ); /* copy constructor */

        ~MPIEnvironment(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        MPIEnvironment& 
        operator=( const MPIEnvironment &other ); /* assignment operator */

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
