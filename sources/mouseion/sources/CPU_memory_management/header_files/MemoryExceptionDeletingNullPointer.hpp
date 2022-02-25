/*
 * =====================================================================================
 *
 *       Filename:  MemoryExceptionDeletingNullPointer.hpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */
#ifndef  MemoryExceptionDeletingNullPointer_INC
#define  MemoryExceptionDeletingNullPointer_INC

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
 *        Class: MemoryExceptionDeletingNullPointer 
 *  Description: An exception for freeing a nullptr.
 * =====================================================================================
 */
template<typename T>
class MemoryExceptionDeletingNullPointer : public std::exception
{

    public:
        /* ====================  LIFECYCLE     ======================================= */
        MemoryExceptionDeletingNullPointer(std::string const aString) : _aString(aString)
        {
            return;
        }
        
        MemoryExceptionDeletingNullPointer( MemoryExceptionDeletingNullPointer<T> const & other) : _aString(other._aString)
        {
            if (this != &other)
            {

            }
            return;
        }

        ~MemoryExceptionDeletingNullPointer()
        {
            return;
        }

        //===== DATA MEMBERS ===

        //===== ACCESSORS ======
        const char * what() const noexcept override
        {
            return (this->_aString).c_str();
        }

        //===== MUTATORS =======

        //===== OPERATORS ======
        MemoryExceptionDeletingNullPointer<T>& 
        operator=(MemoryExceptionDeletingNullPointer<T> const & other)=delete;

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */
        std::string _aString;
};

} /* namespace MEMORY_MANAGEMENT */
#endif   /* ----- #ifndef MemoryExceptionDeletingNullPointer_INC  ----- */

