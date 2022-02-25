/*
 * =====================================================================================
 *
 *       Filename:  AllocatingArrayDimensionToNonPositiveSize.hpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */
#ifndef  AllocatingArrayDimensionToNonPositiveSize_INC
#define  AllocatingArrayDimensionToNonPositiveSize_INC

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
 *        Class: AllocatingArrayDimensionToNonPositiveSize 
 *  Description: An exception for freeing a nullptr.
 * =====================================================================================
 */
template<typename T>
class AllocatingArrayDimensionToNonPositiveSize : public std::exception
{

    public:
        /* ====================  LIFECYCLE     ======================================= */
        AllocatingArrayDimensionToNonPositiveSize(const std::string error_message) :
            _message(error_message)
        {
            return;
        }
        
        AllocatingArrayDimensionToNonPositiveSize( AllocatingArrayDimensionToNonPositiveSize<T> const & other) :
            _message(other._message)
        {
            if (this != &other)
            {

            }
            return;
        }

        ~AllocatingArrayDimensionToNonPositiveSize()
        {
            return;
        }

        //===== DATA MEMBERS ===

        //===== ACCESSORS ======
        const char * what() const noexcept override
        {
            return (this->_message).c_str();
        }

        //===== MUTATORS =======

        //===== OPERATORS ======
        AllocatingArrayDimensionToNonPositiveSize<T>& 
        operator=(AllocatingArrayDimensionToNonPositiveSize<T> const & other)=delete;

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */
        std::string _message;

        /* ====================  DATA MEMBERS  ======================================= */

};

} /* namespace MEMORY_MANAGEMENT */
#endif   /* ----- #ifndef AllocatingArrayDimensionToNonPositiveSize_INC  ----- */

