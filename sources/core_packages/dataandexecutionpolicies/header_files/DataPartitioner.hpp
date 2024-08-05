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
          typename id_t,
          typename nm_t>
It_type RoundRobinDataPartitioner ( const It_type & my_list,
                                    id_t my_rank,
                                    nm_t my_size,
                                    id_t initial_index=0)
{
    It_type my_stuff;
    std::ptrdiff_t divisor{static_cast<std::ptrdiff_t>(my_size)};
    std::ptrdiff_t offset{static_cast<std::ptrdiff_t>(initial_index)};
    std::ptrdiff_t rank{static_cast<std::ptrdiff_t>(my_rank)};
    std::ptrdiff_t counter{0};
    for ( auto my_it = my_list.begin(); my_it != my_list.end(); ++my_it)
    {
        std::ptrdiff_t index = counter%divisor - offset;
        if (index == rank)
        {
            my_stuff.push_back(*my_it);
        }
        counter += 1;
    }
    return my_stuff;
}


}; // namespace ANANSI

#endif // ANANSI_DataPartitioner_INC
