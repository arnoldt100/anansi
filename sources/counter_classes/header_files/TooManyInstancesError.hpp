#ifndef  TooManyInstancesError_INC
#define  TooManyInstancesError_INC


//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>
#include <typeinfo>
#include <string>
#include <algorithm>
#include <type_traits>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace COUNTERCLASS
{
    /*
     * =====================================================================================
     *        Class:  TooManyInstancesError
     *  Description:  
     * =====================================================================================
     */
    template <typename T, int MAX_INSTANCES>
    class TooManyInstancesError : std::exception
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            
            TooManyInstancesError ()
            {
                return;
            }

            ~TooManyInstancesError()
            {
                return;
            }

            TooManyInstancesError (TooManyInstancesError const & other)
            {
                if (&other != this)
                {
                    std::exception::operator=(other);
                }
                return;
            }

            TooManyInstancesError (TooManyInstancesError && other)
            {
                if (&other != this)
                {
                    std::exception::operator=(std::move(other));
                }
                return;
            }

            /* ====================  ACCESSORS     ======================================= */

            const char* 
            what() const noexcept override 
            {
                const auto message = std::string("Too many instances of class: ") + std::string( typeid(T).name()) ;
                const auto len = message.size();
                auto message_ptr = new char[len+1];
                std::copy(message.begin(), message.end(), message_ptr);
                return message_ptr;
            }

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

            TooManyInstancesError& 
            operator=(TooManyInstancesError const & other)
            {
                if (&other != this)
                {
                    std::exception::operator=(other);
                    return *this;
                }
                return *this;
            }

            TooManyInstancesError& 
            operator=(TooManyInstancesError && other)
            {
                if (&other != this)
                {
                    std::exception::operator=(std::move(other));
                    return *this;
                }
                return *this;
            }

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class TooManyInstancesError  ----- */


}; /* namespace COUNTERCLASS */

#endif   /* ----- #ifndef TooManyInstancesError_INC  ----- */
