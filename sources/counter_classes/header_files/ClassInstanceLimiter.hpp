#ifndef  ClassInstanceLimiter_INC
#define  ClassInstanceLimiter_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <atomic>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COUNTERCLASSES
{

template<typename T ,int MAX_INSTANCES>
class ClassInstanceLimiter
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        ClassInstanceLimiter() /* constructor */
        {
            ++(this->numberOfInstances);
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
