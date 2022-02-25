#ifndef  MOUSEION_MPLAliases_INC
#define  MOUSEION_MPLAliases_INC

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//
#include <boost/mp11.hpp>

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace MPL
{

//-----------------------------------------------------
//  Below we define aliases to boost mp11 meta        -
//  programming library.                              -
//                                                    -
//-----------------------------------------------------

//-----------------------------------------------------
// The alias to the the boost mp11 typelist.
//
//-----------------------------------------------------
template<typename ...T>
using mpl_typelist = boost::mp11::mp_list<T...>;


//-----------------------------------------------------
// The alias to the the boost mp11 transformation type
// that just returns the same type. It’s useful both as
// such, and as a type wrapper for passing types as
// values to functions.
//-----------------------------------------------------
template<typename T>
using mpl_type2type = boost::mp11::mp_identity<T>;

//-----------------------------------------------------
// The alias to boost mp11 list size
//-----------------------------------------------------
template<typename L>
using mpl_size = boost::mp11::mp_size<L>;

//-----------------------------------------------------
// The alias to boost mp11 list size 0.
//-----------------------------------------------------
using mpl_size_0 = mpl_size< mpl_typelist<>>; 

//-----------------------------------------------------
// The alias to boost mp11 list size 1.
//-----------------------------------------------------
using mpl_size_1 = mpl_size< mpl_typelist<int>>; 

//-----------------------------------------------------
// The alias to boost mp11 to pop the first list 
// element and return the remainder of the list.
//-----------------------------------------------------
template<typename L>
using mpl_rest = boost::mp11::mp_rest<L>;

//-----------------------------------------------------
// The alias to boost mp11 to pop the first list 
// element and return the size of the remainder of the 
// list.
//-----------------------------------------------------
template<typename L>
using mpl_rest_size = mpl_size< mpl_rest<L> >;

//-----------------------------------------------------
// The alias to boost mp11 to pop the first list 
// element and return the front of the  list.
//-----------------------------------------------------
template<typename L>
using mpl_front = boost::mp11::mp_front<L>;

//-----------------------------------------------------
// The alias to boost mp11 to pop the first list 
// element and return the size of the front of the
// list element..
//-----------------------------------------------------
template<typename L>
using mpl_front_size = mpl_size< mpl_front<L> >;


//-----------------------------------------------------
// The alias to boost mp11 to reverse the elements
// of the typelist.
//-----------------------------------------------------
template<typename L>
using mpl_reverse = boost::mp11::mp_reverse<L>;


}; // namespace MPL

#endif   // ----- #ifndef MOUSEION_MPLAliases_INC  ----- 
