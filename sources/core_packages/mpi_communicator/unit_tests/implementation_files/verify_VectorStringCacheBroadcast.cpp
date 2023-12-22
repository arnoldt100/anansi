//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "verify_VectorStringCacheBroadcast.h"
#include "BroadcastVectorStringCache.h"


std::tuple<bool,std::string> verify_VectorStringCacheBroadcast (STRING_UTILITIES::VectorStringCache const & my_cache)
{
    bool my_status=false;
    std::string my_message;
    std::size_t broadcast_rank = 0;

    
    
    STRING_UTILITIES::VectorStringCache my_vectorstringcache =
        ANANSI::MPI_Broadcast<STRING_UTILITIES::VectorStringCache>::Broadcast(my_cache,
                                                                              MPI_COMM_WORLD,
                                                                              broadcast_rank);
    if (my_vectorstringcache == my_cache)
    {
        my_status = true;
        my_message += "Objects are the same.";
    }
    else
    {
        my_status = false;
        my_message += "Objects are different but objects should be the same.";
    }

    return std::tie(my_status,my_message);
}   // -----  end of function verify_VectorStringCacheBroadcast  -----



