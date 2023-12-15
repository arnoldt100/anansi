
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>
#include <vector>
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "FixtureBroadcastVectorStringCache.h"


//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

FixtureBroadcastVectorStringCache::FixtureBroadcastVectorStringCache() :
    experimentalVecStringCache1{}
{
    return;
}

FixtureBroadcastVectorStringCache::FixtureBroadcastVectorStringCache( FixtureBroadcastVectorStringCache const & other) :
    experimentalVecStringCache1{other.experimentalVecStringCache1}
{
    if (this != &other)
    {
        
    }
    return;
}

FixtureBroadcastVectorStringCache::FixtureBroadcastVectorStringCache( FixtureBroadcastVectorStringCache && other)  :
    experimentalVecStringCache1{std::move(other.experimentalVecStringCache1)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method FixtureBroadcastVectorStringCache::FixtureBroadcastVectorStringCache  -----


FixtureBroadcastVectorStringCache::~FixtureBroadcastVectorStringCache()
{
    return;
}

//============================= ACCESSORS ====================================

FixtureBroadcastVectorStringCache * FixtureBroadcastVectorStringCache::clone() const
{
    return new FixtureBroadcastVectorStringCache(*this);
}

//============================= MUTATORS =====================================
void FixtureBroadcastVectorStringCache::setup()
{
    std::vector<std::string> my_test_string_1{std::string("ABCDEFG"),
                                              std::string("12345678"),
                                              std::string("abcdefghi")};

    this->experimentalVecStringCache1 = STRING_UTILITIES::VectorStringCache(my_test_string_1);

    return;
}

void FixtureBroadcastVectorStringCache::teardown()
{
    return;
}

//============================= OPERATORS ====================================

FixtureBroadcastVectorStringCache& FixtureBroadcastVectorStringCache::operator= ( const FixtureBroadcastVectorStringCache &other )
{
    if (this != &other)
    {
        this->experimentalVecStringCache1 = other.experimentalVecStringCache1;
    }
    return *this;
} // assignment operator

FixtureBroadcastVectorStringCache& FixtureBroadcastVectorStringCache::operator= ( FixtureBroadcastVectorStringCache && other )
{
    if (this != &other)
    {
        this->experimentalVecStringCache1 = std::move(other.experimentalVecStringCache1);
    }
    return *this;
} // assignment-move operator

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PROTECTED ////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PRIVATE //////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
    
//============================= LIFECYCLE ====================================

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

