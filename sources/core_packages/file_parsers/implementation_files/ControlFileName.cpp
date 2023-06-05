//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ControlFileName.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ControlFileName::ControlFileName() :
    fileName_()
{
    return;
}

ControlFileName::ControlFileName(const std::string file_name) :
    fileName_(file_name)
{
    return;
}

ControlFileName::ControlFileName( ControlFileName const & other) :
    fileName_(other.fileName_)
{
    if (this != &other)
    {
    }
    return;
}

ControlFileName::ControlFileName( ControlFileName && other) :
    fileName_(std::move(other.fileName_))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method ControlFileName::ControlFileName  -----


ControlFileName::~ControlFileName()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

std::string ControlFileName::operator()() const
{
    return this->fileName_;
}

ControlFileName& ControlFileName::operator= ( const ControlFileName &other )
{
    if (this != &other)
    {
        this->fileName_ = other.fileName_;
    }
    return *this;
} // assignment operator

ControlFileName& ControlFileName::operator= ( ControlFileName && other )
{
    if (this != &other)
    {
        this->fileName_ = std::move(other.fileName_);
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
