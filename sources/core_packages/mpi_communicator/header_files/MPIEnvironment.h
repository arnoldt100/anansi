#ifndef  MPIEnvironment_INC
#define  MPIEnvironment_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>
#include <memory>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//


//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "MPIEnvironmentState.h"
#include "ClassInstanceLimiter.hpp"
#include "ReceiverInterface.hpp"
#include "CommandLineArguments.h"

namespace ANANSI
{

constexpr auto MAX_MPIENVIRONMENT_INSTANCES = 1;

class MPIEnvironment final : public RECEIVER::ReceiverInterface<MPIEnvironment>, private COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        MPIEnvironment(); /* constructor */

        MPIEnvironment(const MPIEnvironment &other)=delete; /* copy constructor */

        MPIEnvironment (MPIEnvironment && other)= delete;

        ~MPIEnvironment(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */
        template <typename... Types>
        void enableReceiver( COMMANDLINE::CommandLineArguments & cmd_line_args)
        {
            std::cout << "Enabling the receiver MPIEnvironment." << std::endl;
            this->cmdLineArgs_ = cmd_line_args;
            return;
        }

        void disableReceiver();

        void receiverDoAction();

        void receiverUndoAction();

        void enableEnvironment(int const & argc, char const * const * const & argv);

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

        int argc_ptr_;
        char** argv_ptr_;
        COMMANDLINE::CommandLineArguments cmdLineArgs_;
        std::shared_ptr<ANANSI::MPIEnvironmentState> mpistate_;

}; /* -----  end of class MPIEnvironment  ----- */



}; /* namespace ANANSI */

#endif   /* ----- #ifndef MPIEnvironment_INC  ----- */
