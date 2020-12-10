#ifndef  CounterClass_INC
#define  CounterClass_INC

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
class ClassCounter
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        ClassCounter() /* constructor */
        {
            ++(this->numberOfInstances);
            return;
        }

        ClassCounter(const ClassCounter &other)=delete; /* copy constructor */

        ~ClassCounter ()
        {
            return;
        };

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        ClassCounter& 
        operator=(const ClassCounter &other)=delete; /* assignment operator */

        /* ====================  DATA MEMBERS  ======================================= */
        static inline std::atomic<int> numberOfInstances=0;

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class ClassCounter  ----- */



}; /* namespace COUNTERCLASSES */

#endif   /* ----- #ifndef CounterClass_INC  ----- */
