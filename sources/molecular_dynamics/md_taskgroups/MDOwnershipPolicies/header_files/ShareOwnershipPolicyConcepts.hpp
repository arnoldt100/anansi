#ifndef ANANSI_ShareOwnershipPolicyConcepts_INC
#define ANANSI_ShareOwnershipPolicyConcepts_INC

//! @file __filename__
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

template< typename T, typename V, typename W>
concept ShareOwnershipPolicyConcepts = std::is_same<T,V>::value ||
                                       std::is_same<T,W>::value;


}; // namespace ANANSI

#endif // ANANSI_ShareOwnershipPolicyConcepts_INC
