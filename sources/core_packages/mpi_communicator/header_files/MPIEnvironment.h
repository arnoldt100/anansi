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

namespace ANANSI
{

constexpr auto MAX_MPIENVIRONMENT_INSTANCES = 1;

class MPIEnvironment final : private COUNTERCLASSES::ClassInstanceLimiter<MPIEnvironment,MAX_MPIENVIRONMENT_INSTANCES>
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        MPIEnvironment(); /* constructor */

        MPIEnvironment(const MPIEnvironment &other)=delete; /* copy constructor */

        MPIEnvironment (MPIEnvironment && other)= delete;

        ~MPIEnvironment(); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */
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
        std::shared_ptr<ANANSI::MPIEnvironmentState> mpistate_;

}; /* -----  end of class MPIEnvironment  ----- */


}; /* namespace ANANSI */

#endif   /* ----- #ifndef MPIEnvironment_INC  ----- */
