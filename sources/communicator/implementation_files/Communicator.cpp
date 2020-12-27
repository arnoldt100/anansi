/*
 * Communicator.cpp
 *
 *  Created on: Oct 15, 2018
 *      Author: arnoldt
 */

#include "Communicator.h"
#include "Array1d.hpp"
#include "Array1dChar.hpp"
#include "convert_sequence_of_chars_to_vector_string.h"

namespace COMMUNICATOR
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

Communicator::Communicator()
{
    return;
}

Communicator::~Communicator()
{
    return;
}

Communicator::Communicator(Communicator const & other)
{
    if ( this != &other)
    {
        *this = other;
    }
}

Communicator::Communicator(Communicator&& other)
{
    *this = std::move(other);
}
//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================
Communicator& Communicator::operator=(Communicator const  & other)
{
    if (this != &other)
    {
        
    }
    return *this;
}

Communicator& Communicator::operator=(Communicator && other)
{
    if (this != &other)
    {
        
    }
    return *this;
}


//============================= OPERATORS ====================================

//============================= STATIC FUNCTIONS =============================
std::map<std::string, std::size_t>
Communicator::formGlobalMap(std::string const & tag,
                            Communicator const  & aCommunicator)
{
    MEMORY_MANAGEMENT::Array1d<char> my_char_array_factory;
    MEMORY_MANAGEMENT::Array1d<int> my_int_array_factory;

    // Get the maximum length of tag with respect to the communicator group.
    int tag_length = tag.length();
    int tag_length_maximum = aCommunicator._getMaximum(tag_length);

    // Form and c string with length tag_length + 1, and 
    // then copy the tag in a c string.
    int tag_length_maximum_adj = tag_length_maximum  + 1;

    char* tag_ptr = my_char_array_factory.createArray(tag,
                                                      tag_length_maximum_adj);

    // Gather all the tags into a char* array.
    std::size_t offset_size;
    int* start_offsets_ptr = nullptr;
    int* end_offsets_ptr = nullptr;
    char* all_tags_ptr = aCommunicator._allGather(
                             tag_ptr,
                             static_cast<std::size_t> (tag_length_maximum_adj),
                             offset_size,
                             start_offsets_ptr,
                             end_offsets_ptr);


    // Form vector string array of the hostnames.
    std::vector<std::string> aHostnameVec =
        STRING_UTILITIES::convert_sequence_of_chars_to_vector_string(offset_size,
                                                                     start_offsets_ptr,
                                                                     end_offsets_ptr,
                                                                     const_cast<char* >(all_tags_ptr) );

    // Form global map.
    std::size_t counter = 0;
    std::map<std::string,std::size_t>::iterator it;
    std::map<std::string, std::size_t> aGlobalTagMap;
    for (auto it = aHostnameVec.begin(); it != aHostnameVec.end(); ++it)
    {
        auto it2 = aGlobalTagMap.find(*it);
        if (it2 == aGlobalTagMap.end())
        {
                aGlobalTagMap[*it] = counter;
                ++counter;
        }
    }

    my_char_array_factory.destroyArray(all_tags_ptr);
    my_char_array_factory.destroyArray(tag_ptr);

    my_int_array_factory.destroyArray(start_offsets_ptr);
    my_int_array_factory.destroyArray(end_offsets_ptr);

    return aGlobalTagMap ;
}

template<>
std::vector<std::string> gatherData(
       std::string const & data_to_gather,
       Communicator const  & aCommunicator,
       const std::size_t task_id_gather_data)
{
    std::vector<std::string> gathered_data;
    gathered_data = aCommunicator.gatherString(data_to_gather,task_id_gather_data);
    return gathered_data;
};

template<>
std::vector<int> gatherData(
       int const & data_to_gather,
       Communicator const  & aCommunicator,
       const std::size_t task_id_gather_data)
{

    std::vector<int> gathered_data;
    gathered_data = aCommunicator.gatherInt(data_to_gather,
                                            task_id_gather_data);

    return gathered_data;
};

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    

} /* namespace COMMUNICATOR */
