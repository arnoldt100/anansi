#ifndef  CounterClass_INC
#define  CounterClass_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COUNTERCLASSES
{

class ClassCounter
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        ClassCounter() /* constructor */
        {
            return;
        }

        ClassCounter(const ClassCounter &other)=delete; /* copy constructor */

        ~ClassCounter (); /* destructor */

        /* ====================  ACCESSORS     ======================================= */

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        ClassCounter& 
        operator=(const ClassCounter &other)=delete; /* assignment operator */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

}; /* -----  end of class ClassCounter  ----- */


}; /* namespace COUNTERCLASSES */

#endif   /* ----- #ifndef CounterClass_INC  ----- */
