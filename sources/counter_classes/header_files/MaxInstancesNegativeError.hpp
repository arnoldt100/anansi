#ifndef  MaxInstancesNegativeError_INC
#define  MaxInstancesNegativeError_INC

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
     *        Class:  MaxInstancesNegativeError
     *  Description:  
     * =====================================================================================
     */
    template <typename T, int MAX_INSTANCES>
    class MaxInstancesNegativeError : std::exception
    {
        public:
            /* ====================  LIFECYCLE     ======================================= */

            
            MaxInstancesNegativeError ()
            {
                return;
            }

            ~MaxInstancesNegativeError()
            {
                return;
            }

            MaxInstancesNegativeError (MaxInstancesNegativeError const & other)
            {
                if (&other != this)
                {
                    std::exception::operator=(other);
                }
                return;
            }

            MaxInstancesNegativeError (MaxInstancesNegativeError && other)
            {
                if (&other != this)
                {
                    std::exception::operator=(std::move(other));
                }
                return;
            }

            MaxInstancesNegativeError& 
            operator=(MaxInstancesNegativeError const & other)
            {
                if (&other != this)
                {
                    std::exception::operator=(other);
                    return *this;
                }
                return *this;
            }

            MaxInstancesNegativeError& 
            operator=(MaxInstancesNegativeError && other)
            {
                if (&other != this)
                {
                    std::exception::operator=(std::move(other));
                    return *this;
                }
                return *this;
            }
            /* ====================  ACCESSORS     ======================================= */

            const char* 
            what() const noexcept override 
            {
                const auto message = std::string("MAX_INSTANCES is set to a negative value for class: ") + std::string( typeid(T).name()) ;
                const auto len = message.size();
                auto message_ptr = new char[len+1];
                std::copy(message.begin(), message.end(), message_ptr);
                return message_ptr;
            }

            /* ====================  MUTATORS      ======================================= */

            /* ====================  OPERATORS     ======================================= */

        protected:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

        private:
            /* ====================  METHODS       ======================================= */

            /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class MaxInstancesNegativeError  ----- */


}; /* namespace COUNTERCLASS */

#endif   /* ----- #ifndef MaxInstancesNegativeError_INC  ----- */
