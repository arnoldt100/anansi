
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "__filename__.h"

namespace __NAMESPACE__ {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

__classname__::__classname__()
{
	// TODO Auto-generated constructor stub
    return;
}

__classname__::__classname__( __classname__ const & other)
{
	// TODO Auto-generated constructor stub
    if (this != &other)
    {
        
    }
    return;
}

__classname__::__classname__( __classname__ && other)
{
	// TODO Auto-generated constructor stub
    if (this != &other)
    {
    }
    return;
}		// -----  end of method __classname__::__classname__  -----


__classname__::~__classname__()
{
	// TODO Auto-generated destructor stub
    return;
}

//============================= ACCESSORS ====================================

__classname__ * __classname__::clone() const
{
    return new __classname__(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

__classname__& __classname__::operator= ( const __classname__ &other )
{
    if (this != &other)
    {
        this = other.clone()
    }
    return *this;
} // assignment operator

__classname__& __classname__::operator= ( __classname__ && other )
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


} // namespace __NAMESPACE__
