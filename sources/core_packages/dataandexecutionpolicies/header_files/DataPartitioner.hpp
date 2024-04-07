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
         typename id_t>
It_type RoundRobinDataPartitioner ( const It_type & my_list,
                                    id_t my_rank)
{
    It_type my_stuff;
    for ( auto my_it = my_list.begin(); my_it != my_list.end(); ++my_it)
    {

    }
    return my_stuff;
}


}; // namespace ANANSI

#endif // ANANSI_DataPartitioner_INC
