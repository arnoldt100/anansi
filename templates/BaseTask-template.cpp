//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <utility>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "__header_filename__"

namespace __NAMESPACE__ 
{

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

__classname__::__classname__() :
    AnansiTask{}
{
    return;
}

__classname__::__classname__( __classname__ const & other) :
    AnansiTask{other}
{
    if (this != &other)
    {
        
    }
    return;
}

__classname__::__classname__( __classname__ && other) :
    AnansiTask{std::move(other)}
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method __classname__::__classname__  -----


__classname__::~__classname__()
{
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
        AnansiTask::operator=(other);
    }
    return *this;
} // assignment operator

__classname__& __classname__::operator= ( __classname__ && other )
{
    if (this != &other)
    {
        AnansiTask::operator=(std::move(other));
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


}; // ----- End of namespace __NAMESPACE__ -----
