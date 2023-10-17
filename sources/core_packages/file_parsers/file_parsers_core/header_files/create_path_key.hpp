#ifndef ANANSI_create_path_key_INC
#define ANANSI_create_path_key_INC

//! \file create_path_key.hpp

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <vector>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//


namespace ANANSI
{

//! \brief Creates the path key for the internal representation (key,value) pair.
//!
//! \tparam PathKeyPolicy_t The policy class for generating the path key. 
//! \tparam KeyPathSeparator_t The trait class for the key path separating character.
template< typename PathKeyPolicy_t,typename KeyPathSeparator_t >
std::string create_path_key ( const std::vector<std::string> & keys );

}; // namespace ANANSI

#endif // ANANSI_create_path_key_INC
