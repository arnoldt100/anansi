
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "coordinates.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

coordinates::coordinates()
{
    return;
}

coordinates::coordinates( coordinates const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

coordinates::coordinates( coordinates && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method coordinates::coordinates  -----


coordinates::~coordinates()
{
    return;
}

//============================= ACCESSORS ====================================

coordinates * coordinates::clone() const
{
    return new coordinates(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

coordinates& coordinates::operator= ( const coordinates &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

coordinates& coordinates::operator= ( coordinates && other )
{
    if (this != &other)
    {
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


} // namespace ANANSI