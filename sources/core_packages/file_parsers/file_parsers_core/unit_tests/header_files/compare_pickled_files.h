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

//! \brief Compares pickled_file to correct_pickle_file.
//!
//! \detail Compares pickled_file to correct_pickle_file. If the pickle_file
//! is the same as correct_pickle_file then 'true' is returned, otherwise 'false; is returned.
bool compare_pickled_files (const std::map<std::string,std::string> & correct_pickle_file,
                            const std::map<std::string,std::string> & pickled_file);


}; // namespace ANANSI

#endif // ANANSI_compare_pickled_files_INC
