/*
 * =====================================================================================
 *
 *       Filename:  ExceptionLengthOfCharPointerIsTooSmall.hpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  ExceptionLengthOfCharPointerIsTooSmall_INC
#define  ExceptionLengthOfCharPointerIsTooSmall_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <exception>
#include <iostream>
#include <string>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MEMORY_MANAGEMENT 
{


/*
 * =====================================================================================
 *        Class:  ExceptionLengthOfCharPointerIsTooSmall
 *  Description:  
 * =====================================================================================
 */
class ExceptionLengthOfCharPointerIsTooSmall : public std::exception
{
    public:
        /* ====================  LIFECYCLE     ======================================= */
        ExceptionLengthOfCharPointerIsTooSmall( std::string const message); /* constructor      */

        ExceptionLengthOfCharPointerIsTooSmall (const ExceptionLengthOfCharPointerIsTooSmall &other);  /* copy constructor */

        ~ExceptionLengthOfCharPointerIsTooSmall(); /* destructor       */

        /* ====================  ACCESSORS     ======================================= */
        const char * what() const noexcept override;

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */

        ExceptionLengthOfCharPointerIsTooSmall&
        operator=( const ExceptionLengthOfCharPointerIsTooSmall &other)=delete; /* assignment operator */

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */
        std::string _message;

}; /* -----  end of class ExceptionLengthOfCharPointerIsTooSmall  ----- */


} /* namespace MEMORY_MANAGEMENT */
#endif   /* ----- #ifndef ExceptionLengthOfCharPointerIsTooSmall_INC  ----- */

