/*
 * =====================================================================================
 *
 *       Filename:  FixtureArray2d.cpp
 *
 *    Description:  The class is a fixture for the boost unit tests. This fixture
 *                  genreates matrices for given sizes and assigns their elements
 *                  values values based on the Cantor pairing function.
 *
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#include "FixtureArray2d.h"

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

/*
 *--------------------------------------------------------------------------------------
 *       Class:  FixtureArray2d
 *      Method:  FixtureArray2d
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
FixtureArray2d::FixtureArray2d(std::size_t const row_size,
                               std::size_t const column_size,
                               ArrayLayoutType const layout,
                               const std::function<std::size_t(std::size_t,std::size_t)> & pairing_function ) :
arrayLayoutType(layout),
rowSize(row_size),
columnSize(column_size),
array2d_ptr(nullptr)
{

    MEMORY_MANAGEMENT::Array2d<std::size_t> my_array_factory;

    switch (  this->arrayLayoutType ) 
    {
        case ArrayLayoutType::column_major :	

            this->array2d_ptr = my_array_factory.createColumnMajorPointerArray(row_size,column_size);

            for (std::size_t jp=0; jp < this->columnSize; ++jp)
            {
                for(std::size_t ip=0; ip < this->rowSize; ++ip)
                {
                     this->array2d_ptr[jp][ip] = pairing_function(ip,jp);
                }
            }

            break;

        case ArrayLayoutType::row_major :	
            this->array2d_ptr = my_array_factory.createRowMajorPointerArray(row_size,column_size);

            for(std::size_t ip=0; ip < this->rowSize; ++ip)
            {
                for (std::size_t jp=0; jp < this->columnSize; ++jp)
                {
                     this->array2d_ptr[ip][jp] = pairing_function(ip,jp);
                }
            }

            break;

    } // -----  end switch  ----- 
    return;
}  /* -----  end of method FixtureArray2d::FixtureArray2d  (constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  FixtureArray2d
 *      Method:  ~FixtureArray2d
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
FixtureArray2d::~FixtureArray2d()
{
    MEMORY_MANAGEMENT::Array2d<std::size_t> my_array_factory;

    switch (  this->arrayLayoutType ) 
    {
        case ArrayLayoutType::column_major :	
            my_array_factory.destroyColumnMajorArray(this->rowSize,
                                                     this->columnSize,
                                                     this->array2d_ptr);
            break;

        case ArrayLayoutType::row_major :	
            my_array_factory.destroyRowMajorArray(this->rowSize,
                                                  this->columnSize,
                                                  this->array2d_ptr);
            break;

    } // -----  end switch  ----- 

    return;
}  /* -----  end of method FixtureArray2d::~FixtureArray2d  (destructor)  ----- */

//============================= ACCESSORS ====================================

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




