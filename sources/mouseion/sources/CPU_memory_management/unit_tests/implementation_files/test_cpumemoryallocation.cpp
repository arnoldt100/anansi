/*
 * =====================================================================================
 *
 *       Filename:  test_cpumemoryallocation.cpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#include "test_cpumemoryallocation.h"

#include "test_column_major_layout.h"
#include "test_row_major_layout.h"

BOOST_AUTO_TEST_SUITE( Test_Suite_CPU_Memory_Allocation )

BOOST_AUTO_TEST_CASE( column_major_layout )
{
    test_column_major_layout();
} 

BOOST_AUTO_TEST_CASE( row_major_layout )
{
    test_row_major_layout();
}

BOOST_AUTO_TEST_SUITE_END()

int main(int argc, char* argv[], char* envp[])
{
  return utf::unit_test_main(init_unit_test, argc, argv);
}
