#ifndef  ClassInstanceLimiter_INC
#define  ClassInstanceLimiter_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <atomic>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "TooManyInstancesError.hpp"

namespace COUNTERCLASSES
{

template<typename T, int MAX_INSTANCES>
class ClassInstanceLimiter
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        ClassInstanceLimiter() /* constructor */
        {
            const auto tmp_nm_of_instances = this->numberOfInstances + 1;
            if ( tmp_nm_of_instances > MAX_INSTANCES)
            {
                throw COUNTERCLASS::TooManyInstancesError<T,MAX_INSTANCES>();
            }
            else
            {
            	++(this->numberOfInstances);
            }
            return;
        }

        ClassInstanceLimiter(const ClassInstanceLimiter &other)=delete; /* copy constructor */

        ~ClassInstanceLimiter ()
        {
            return;
        };

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        ClassInstanceLimiter& 
        operator=(const ClassInstanceLimiter &other)=delete; /* assignment operator */

        /* ====================  DATA MEMBERS  ======================================= */
        static inline std::atomic<int> numberOfInstances=0;

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class ClassInstanceLimiter  ----- */



}; /* namespace COUNTERCLASSES */

#endif   /* ----- #ifndef ClassInstanceLimiter_INC  ----- */
