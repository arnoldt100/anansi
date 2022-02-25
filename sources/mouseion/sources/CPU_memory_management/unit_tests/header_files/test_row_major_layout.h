// =====================================================================================
//
//       Filename:  test_row_major_layout.h
//
//    Description:  
//
//         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
//   Organization:  ORNL-National Center of Computational Sciences
//
// =====================================================================================

#ifndef  test_row_major_layout_INC
#define  test_row_major_layout_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <boost/test/unit_test.hpp>
#include <tuple>
#include <string>
#include <functional>
#include <fstream>

//--------------------------------------------------------//
//-------------------- Local includes  -------------------//
//--------------------------------------------------------//
#include "CantorPairing.h"
#include "Array2d.hpp"
#include "FixtureArray2d.h"
#include "Array2dPrintSpecs.h"

// ===  function  ======================================================================
//         name:  verify_valid_2d_row_major_layout
//
//  description:  Validates the matrix in_ptr has a row major layout. Each 
//                matrix element in_ptr[ip][jp] = pairing_function(ip,jp). The elements
//                of matrix in_ptr are accessed by pointer arithmetic, *(in_ptr + disp),
//                and each element must equal the appropiate paring_function(ip,jp) value for
//                the corrsponding row major element associated with "disp" from the 
//                [0][0] element. For the in_ptr[ip][jp] element, disp = jp*row_size + ip.
//
//
//  arguments: row_size; type std::size_t; the number of rows.
//           : column_size; type std::size_t; the number of columns.
//           : in_ptr; type std::size_t**; the column major 2d array.
//           : pairing_function; type std::function<std::size_t(std::size_t,std::size_t)>; 
//             a funtion that generates a unique value for a given pair of natural numbers
//             x and y. the pairing function is called by pairing_function(x,y) where
//             x and y are of types std::size_t. the unique number returned is of type 
//             std::size_t.
// =====================================================================================
std::tuple<bool,std::string> 
verify_valid_2d_row_major_layout( const std::size_t row_size,
                                  const std::size_t column_size,
                                  std::size_t const * const * const & in_ptr,
                                  const std::function<std::size_t(std::size_t,std::size_t)> & pairing_function);

// ===  function  ======================================================================
//         name:  test_row_major_layout
//  description:  runs tests verfying a row major layout.
// =====================================================================================
void test_row_major_layout();


// ===  FUNCTION  ======================================================================
//         Name:  get_test_row_log_file_name
//  Description:  Returns the file name to which the tests results are wriiten to.
// =====================================================================================
std::string get_test_row_major_layout_logfile_name();




#endif   // ----- #ifndef test_row_major_layout_INC  ----- 
