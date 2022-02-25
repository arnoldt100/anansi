/*
 * =====================================================================================
 *
 *       Filename:  test_row_major_layout.cpp
 *
 *    Description:  
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 *
 * =====================================================================================
 */

#include "test_row_major_layout.h"

std::string get_test_row_major_layout_logfile_name()
{
    return std::string("test_row_major_layout.logfile.txt");
}

void test_row_major_layout()
{
    const std::size_t min_matrix_row_size=1;
    const std::size_t max_matrix_row_size=10;
    const std::size_t min_matrix_column_size=1;
    const std::size_t max_matrix_column_size=10;

    const MEMORY_MANAGEMENT::CantorPairing my_pairing_object;

    std::function<std::size_t(std::size_t,std::size_t)> pairing_function = [&my_pairing_object](std::size_t row_index, std::size_t column_index)
    {
        return my_pairing_object.calculatePairValue(row_index,column_index);
    }; 


    for (auto row_size=min_matrix_row_size; row_size <= max_matrix_row_size; ++row_size)
    {
        for (auto column_size=min_matrix_column_size; column_size <= max_matrix_column_size; ++column_size)
        {
            FixtureArray2d const my_2d_array(row_size,
                                             column_size, 
                                             ArrayLayoutType::row_major,
                                             pairing_function);

            std::tuple<bool,std::string> results = verify_valid_2d_row_major_layout(row_size,
                                                                                    column_size,
                                                                                    my_2d_array.array2d_ptr,
                                                                                    pairing_function);

            if ( ! std::get<0>(results) )
            {
                BOOST_ERROR( std::get<1>(results) );
            }
        }
    }
    return;
}


std::tuple<bool,std::string>
verify_valid_2d_row_major_layout (const std::size_t row_size,
                                  const std::size_t column_size,
                                  std::size_t const * const * const & in_ptr,
                                  const std::function<std::size_t(std::size_t,std::size_t)> & pairing_function )
{
    Array2dPrintSpecs my_print_specs(ArrayLayoutType::row_major,
                                     "Row Major Matrix Errors",
                                     row_size,
                                     column_size);

    std::ofstream logFileOstream;
    logFileOstream.open("test_row_major_layout.logfile.txt",std::ios::app);

    my_print_specs.printHeaders(logFileOstream);

    bool valid_layout = true; 
    const std::string no_error_message("Valid 2d row major layout.");
    std::string error_message;

    std::size_t const * const initial_address_ptr = &(in_ptr[0][0]);
    std::size_t disp = 0;
    for (auto ip=0; ip < row_size; ++ip)
    {
        for (auto jp=0; jp < column_size; ++jp)
        {
            const std::size_t value_pma = *(initial_address_ptr+disp);
            const std::size_t value_poa = pairing_function(ip,jp); 
            const std::size_t delta = value_pma - value_poa;

            if ( delta != 0  )
            {
                valid_layout = false;
                my_print_specs.printErroneousElement(logFileOstream,ip,jp,disp,value_pma,value_poa);
                error_message += "Error in row major layout.";
            }

            ++disp;
        }
    }

    if (valid_layout)
    {
        logFileOstream << no_error_message << std::endl;
    }

    std::string message = (valid_layout ? no_error_message : error_message );

    std::tuple<bool,std::string> results(valid_layout,message);
    logFileOstream << std::endl;
    logFileOstream << std::endl;
    logFileOstream.close();

    return results;
} // -----  end of method verify_valid_2d_row_major_layout  ----- 
