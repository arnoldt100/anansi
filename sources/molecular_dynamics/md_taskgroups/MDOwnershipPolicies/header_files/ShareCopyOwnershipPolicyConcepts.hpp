#ifndef ANANSI_ShareCopyOwnershipPolicyConcepts_INC
#define ANANSI_ShareCopyOwnershipPolicyConcepts_INC

//! @file ShareCopyOwnershipPolicyConcepts.hpp
//!
//! Brief description
//!
//! Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <type_traits>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{

template< typename T, typename V>
concept ShareCopyOwnershipPolicyShareable = std::is_same<T,V>::value;


}; // namespace ANANSI

#endif // ANANSI_ShareCopyOwnershipPolicyConcepts_INC

