#ifndef  MPIEnvironment_INC
#define  MPIEnvironment_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//


//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIEnvironmentState.h"
#include "ClassInstanceLimiter.hpp"
#include "CommandLineArguments.h"

namespace ANANSI
{

constexpr auto MAX_MPIENVIRONMENT_INSTANCES = 1;

class MPIEnvironment : private COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        MPIEnvironment(); /* constructor */

        MPIEnvironment(COMMANDLINE::CommandLineArguments & cmd_line_args);

        MPIEnvironment(const MPIEnvironment &other)=delete; /* copy constructor */

        MPIEnvironment (MPIEnvironment && other)= delete;

        ~MPIEnvironment(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        std::string currentMPIEnvironmentState() const;

        /* ====================  MUTATORS      ======================================= */
        template <typename T>
        void addMember( const T & member);

        void enableEnvironment();

        void disableEnvironment();

        /* ====================  OPERATORS     ======================================= */

        MPIEnvironment&
        operator=(const MPIEnvironment &other)=delete; /* assignment operator */

        MPIEnvironment&
		operator=(MPIEnvironment &&other)=delete;

        /* ====================  FRIENDS       ======================================= */

        friend class NullMPIEnvironment;
        friend class EnabledMPIEnvironment;
        friend class DisbledMPIEnvironment;

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */
        void enable_(int const & argc, char const * const * const & argv);

        void enable_();

        void disable_();

        template<class T>
        void changeMPIState_()
        {
            this->mpistate_ = std::make_shared<T>();
        }

        /* ====================  DATA MEMBERS  ======================================= */

        COMMANDLINE::CommandLineArguments cmdLineArgs_;
        std::shared_ptr<ANANSI::MPIEnvironmentState> mpistate_;

}; /* -----  end of class MPIEnvironment  ----- */



}; /* namespace ANANSI */

#endif   /* ----- #ifndef MPIEnvironment_INC  ----- */
