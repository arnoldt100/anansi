#ifndef ANANSI_TransferOwnershipPolicyConcepts_INC
#define ANANSI_TransferOwnershipPolicyConcepts_INC

//! @file TransferOwnershipPolicyConcepts.hpp
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
concept TransferOwnershipPolicyTransferable = std::is_same<T,V>::value;

template< typename T, typename V,typename W>
concept TransferOwnershipPolicyCopyable = std::is_same<T,V>::value ||
                                          std::is_same<T,W>::value;

}; // namespace ANANSI

#endif // ANANSI_TransferOwnershipPolicyConcepts_INC

