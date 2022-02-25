/*
 * =====================================================================================
 *
 *       Filename:  ArrayLayoutType.h
 *
 *    Description: This is a scoped enum for the array layout type.
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */


#ifndef ArrayLayoutType_INC
#define ArrayLayoutType_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


    /*
     * =====================================================================================
     *        Scoped Enum:  ArrayLayoutType
     *  Description:  
     * =====================================================================================
     */
    enum class ArrayLayoutType : int
    {
        row_major,
        column_major
    }; /* -----  end of scoped enum ArrayLayoutType  ----- */


#endif /* ArrayLayoutType_INC */
