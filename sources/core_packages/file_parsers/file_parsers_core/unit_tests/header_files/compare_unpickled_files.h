#ifndef ANANSI_compare_unpickled_files_INC
#define ANANSI_compare_unpickled_files_INC

//! \file compare_unpickled_files.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <tuple>
#include <map>
#include <string>


//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


namespace ANANSI
{

//! \brief Compares unpickled files.
std::tuple<bool,std::string> compare_unpickled_files (const std::map<std::string,std::string> & map_A,
                                                      const boost::property_tree::ptree & ptree_B);


}; // namespace ANANSI

#endif // ANANSI_compare_unpickled_files_INC
