/*
 * =====================================================================================
 *
 *       Filename:  Pointer.hpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#ifndef  Pointer_INC
#define  Pointer_INC

// System includes.
#include <new>
#include <iostream>

namespace MEMORY_MANAGEMENT
{

    /*
     * =====================================================================================
     *        Class:  Pointer<T>
     *  Description:  
     * =====================================================================================
     */
    template<typename T>
        class Pointer
        {
            public:
                /* ====================  LIFECYCLE     ======================================= */

                Pointer (); /* constructor */

                ~Pointer(); /*  destructor */

                /* ====================  ACCESSORS     ======================================= */
                
                /*
                 *--------------------------------------------------------------------------------------
                 * Method:  Pointer<T>::createPointer
                 * Description: Allocates a pointer of type T.
                 *              If the allocation fails an exception of type std::bad_alloc is thrown.
                 * Return type: A pointer T*
                 *--------------------------------------------------------------------------------------
                 */
                T* createPointer();

                /* ====================  MUTATORS      ======================================= */

                /* ====================  OPERATORS     ======================================= */


            protected:
                /* ====================  METHODS       ======================================= */

                /* ====================  DATA MEMBERS  ======================================= */

            private:
                /* ====================  METHODS       ======================================= */

                /* ====================  DATA MEMBERS  ======================================= */

        }; // -----  end of class Pointer  -----




    //////////////////////////////////////////////////////////////////////////////
    /////////////////////////////// PUBLIC ///////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////

    //============================= LIFECYCLE ====================================
    template<typename T>
    Pointer<T>::Pointer()
    {
        return;
    }

    template<typename T>
    Pointer<T>::~Pointer()
    {
        return;
    }

    //============================= ACCESSORS ====================================
    
    /*
     *--------------------------------------------------------------------------------------
     * Method:  Pointer<T>::createPointer
     * Description: Allocates a pointer of type T.
     *              If the allocation fails an exception of type std::bad_alloc is thrown.
     * Return type: A pointer T*
     *--------------------------------------------------------------------------------------
     */
    template < typename T >
    T* Pointer<T>::createPointer()
    {
        T* aPointer_ptr = nullptr;
        try
        {
            aPointer_ptr = new T;
            if ( aPointer_ptr == nullptr )
            {
                throw std::bad_alloc();
            }
        }
        catch ( const std::bad_alloc &ExceptObj )
        {
            std::cout << "Pointer allocation failed: " << ExceptObj.what() << std::endl;
        }
        return aPointer_ptr;
    } /* -----  end of method Pointer<T>::createPointer  ----- */

    //============================= MUTATORS =====================================

    //============================= OPERATORS ====================================


    //////////////////////////////////////////////////////////////////////////////
    /////////////////////////////// PROTECTED ////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////

    //============================= LIFECYCLE ====================================

    //============================= ACCESSORS ====================================

    //============================= MUTATORS =====================================

    //============================= OPERATORS ====================================

    //////////////////////////////////////////////////////////////////////////////
    /////////////////////////////// PRIVATE //////////////////////////////////////
    //////////////////////////////////////////////////////////////////////////////

    //============================= LIFECYCLE ====================================

    //============================= ACCESSORS ====================================

    //============================= MUTATORS =====================================

    //============================= OPERATORS ====================================



}; /* -----  end of namespace MEMORY_MANAGEMENT  ----- */



#endif   /* ----- #ifndef Pointer_INC  ----- */
