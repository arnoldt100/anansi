
#ifndef  Pointer2d_INC
#define  Pointer2d_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "Array1d.hpp"

namespace MEMORY_MANAGEMENT
{

    /*
     * =====================================================================================
     *        Class:  Pointer2d
     *  Description:  
     * =====================================================================================
     */
    template <typename T> class Pointer2d
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            Pointer2d() /* constructor */
            {
                return;
            }

            Pointer2d(Pointer2d const & other) /* copy constructor */
            {
                return;
            }

            Pointer2d(Pointer2d && other) /* copy-move constructor */
            {
                return;
            }

            virtual ~Pointer2d () /* destructor */
            {
                return;
            }

            /* ====================  ACCESSORS     ======================================= */

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            Pointer2d& operator=(Pointer2d const & other) /* assignment operator */
            {
                if (this != &other)
                {

                }
                return *this;
            }

            Pointer2d & operator=( Pointer2d && other ) /* assignment-move operator */
            {
                if (this != &other)
                {

                }
                return *this;
            } 

            /* ====================  SATATIC       ======================================= */
            static void destroyPointer2d(std::size_t const & argc, T** & in_ptr)
            {
                const Array1d<T> array_factory_1d;
                for (std::size_t ip=0; ip < argc; ++ip)
                {
                    array_factory_1d.destroyArray(in_ptr[ip]);
                }
                delete [] in_ptr;
            }

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class Pointer2d  ----- */





}; /* namespace MEMORY_MANAGEMENT */

#endif   /* ----- #ifndef Pointer2d_INC  ----- */
