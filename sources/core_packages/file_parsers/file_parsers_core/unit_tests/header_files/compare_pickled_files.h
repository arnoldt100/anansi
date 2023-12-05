#ifndef ANANSI_compare_pickled_files_INC
#define ANANSI_compare_pickled_files_INC

//! \file compare_pickled_files.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <map>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


namespace ANANSI
{

//! \brief Compares pickled_file to correct_pickle_file and returns the comparison status.
//!
//! \detail Compares pickled_file to correct_pickle_file. If the pickle_file
//! is the same as correct_pickle_file then std::tuple {true,"messge"} is returned, otherwise 
//! {false,message} is returned.
//!
//! 
std::tuple<bool,std::string> compare_pickled_files (const std::map<std::string,std::string> & correct_pickle_file,
                                                    const std::map<std::string,std::string> & pickled_file);


}; // namespace ANANSI

#endif // ANANSI_compare_pickled_files_INC
