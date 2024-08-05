#ifndef ANANSI_ShareOwnershipPolicyConcepts_INC
#define ANANSI_ShareOwnershipPolicyConcepts_INC

//! @file ShareOwnershipPolicyConcepts.hpp
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
concept ShareOwnershipPolicyTransferable = std::is_same<T,V>::value;

}; // namespace ANANSI

#endif // ANANSI_ShareOwnershipPolicyConcepts_INC
