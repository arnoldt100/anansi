#ifndef ANANSI_TransferCopyOwnershipPolicyConcepts_INC
#define ANANSI_TransferCopyOwnershipPolicyConcepts_INC

//! @file TransferCopyOwnershipPolicyConcepts.hpp
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

template< typename T, typename V,typename W>
concept TransferCopyOwnershipPolicyTransferable = std::is_same<T,V>::value ||
                                                  std::is_same<T,W>::value;

}; // namespace ANANSI

#endif // ANANSI_TransferCopyOwnershipPolicyConcepts_INC

