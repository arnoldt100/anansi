
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "XMLKeyPathFormatSymbol.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

XMLKeyPathFormatSymbol::XMLKeyPathFormatSymbol()
{
    return;
}

XMLKeyPathFormatSymbol::XMLKeyPathFormatSymbol( XMLKeyPathFormatSymbol const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

XMLKeyPathFormatSymbol::XMLKeyPathFormatSymbol( XMLKeyPathFormatSymbol && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method XMLKeyPathFormatSymbol::XMLKeyPathFormatSymbol  -----


XMLKeyPathFormatSymbol::~XMLKeyPathFormatSymbol()
{
    return;
}

//============================= ACCESSORS ====================================

XMLKeyPathFormatSymbol * XMLKeyPathFormatSymbol::clone() const
{
    return new XMLKeyPathFormatSymbol(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

XMLKeyPathFormatSymbol& XMLKeyPathFormatSymbol::operator= ( const XMLKeyPathFormatSymbol &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

XMLKeyPathFormatSymbol& XMLKeyPathFormatSymbol::operator= ( XMLKeyPathFormatSymbol && other )
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
