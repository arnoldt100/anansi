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
//! \tparam PathKeyPolicy_t The policy for generating the path key. 
template< typename PathKeyPolicy_t >
void create_path_key ( const std::vector<std::string> & keys );

}; // namespace ANANSI

#endif // ANANSI_create_path_key_INC
