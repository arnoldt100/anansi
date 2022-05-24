#ifndef  COMMUNICATOR_MPIEnvironmentState_INC
#define  COMMUNICATOR_MPIEnvironmentState_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Forward Declarations -------------//
//--------------------------------------------------------//
namespace COMMUNICATOR
{

class MPIEnvironment; 

}

namespace COMMUNICATOR
{


// =====================================================================================
//        Class:  MPIEnvironmentState
//  Description:  
//  =====================================================================================
class MPIEnvironmentState
{
    public:
        // ====================  LIFECYCLE     =======================================

        //--------------------------------------------------------------------------------------
        //       Class:  MPIEnvironmentState
        //      Method:  MPIEnvironmentState :: MPIEnvironmentState
        // Description:  
        // 
        //  Parameters: 
        //
        //      Return:
        //--------------------------------------------------------------------------------------
        MPIEnvironmentState ();   // constructor

        MPIEnvironmentState (const MPIEnvironmentState & other);   // copy constructor

        MPIEnvironmentState (MPIEnvironmentState && other);   // copy-move constructor

        virtual ~MPIEnvironmentState ()=0;  // destructor

        // ====================  ACCESSORS     =======================================

        // ====================  MUTATORS      =======================================
        void enable(MPIEnvironment* const mpi_environment);

        void enable(MPIEnvironment* const mpi_environment,int const & argc, char const * const * const & argv );

        void disable(MPIEnvironment* const mpi_environment);

        // ====================  OPERATORS     =======================================

        MPIEnvironmentState& operator= ( const MPIEnvironmentState &other ); // assignment operator

        MPIEnvironmentState& operator= ( MPIEnvironmentState && other ); // assignment-move operator

    protected:
        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

    private:
        // ====================  MUTATORS      =======================================
        virtual void enable_(MPIEnvironment* const mpi_environment);

        virtual void enable_(MPIEnvironment* const mpi_environment, int const & argc, char const * const * const & argv);

        virtual void disable_(MPIEnvironment* const mpi_environment);

        // ====================  METHODS       =======================================

        // ====================  DATA MEMBERS  =======================================

}; // -----  end of class MPIEnvironmentState  -----


}; // namespace __NAMESPACE__

#endif   /* ----- #ifndef COMMUNICATOR_MPIEnvironmentState_INC  ----- */
