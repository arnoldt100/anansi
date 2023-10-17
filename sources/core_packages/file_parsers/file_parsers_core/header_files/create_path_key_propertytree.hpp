#ifndef ANANSI_create_path_key_propertytree_INC
#define ANANSI_create_path_key_propertytree_INC

//! \file create_path_key_propertytree.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "create_path_key.hpp"
#include "PathKeyPropertyTree.hpp"
#include "KeyPathSeparator.h"


namespace ANANSI
{

//! \brief Stud text for brief description
template<>
std::string create_path_key< PathKey<boost::property_tree::ptree>,
                             KeyPathSeparator> ( const std::vector<std::string> & keys );

}; // namespace ANANSI

#endif // ANANSI_create_path_key_propertytree_INC
