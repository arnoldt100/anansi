#ifndef ANANSI_DataPartitioner_INC
#define ANANSI_DataPartitioner_INC

//! \file DataPartitioner.h

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <cstddef>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "PrecisionPolicy.h"

namespace ANANSI
{

template <typename It_type,
          typename id_type>
It_type RoundRobinDataPartitioner ( typename It_type::iterator first,
                                    typename It_type::iterator last,
                                    id_type my_id)
{
    It_type my_stuff;
    for (auto & my_it = first; my_it != last; ++my_it)
    {

    }
    return my_stuff;
}


}; // namespace ANANSI

#endif // ANANSI_DataPartitioner_INC
