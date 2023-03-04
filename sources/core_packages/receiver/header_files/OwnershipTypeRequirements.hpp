#ifndef RECEIVER_OwnershipTypeRequirements_INC
#define RECEIVER_OwnershipTypeRequirements_INC

//! @file OwnershipTypeRequirements.hpp

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

namespace RECEIVER {

//! @concept OwnershipTypeRequirements 
//! Defines the requiremnents for an OwnershipImpl class.
template <typename T>
concept OwnershipTypeRequirements = !std::is_same< typename T::Copytype, typename T::Sharedtype>::value &&
                                    !std::is_same< typename T::Transfertype, typename T::Sharedtype>::value &&
requires
{
    typename T::Copytype;
    typename T::Sharedtype;
    typename T::Transfertype;
};

}; 
#endif
