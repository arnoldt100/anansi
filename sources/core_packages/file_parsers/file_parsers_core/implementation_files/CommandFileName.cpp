//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "CommandFileName.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

CommandFileName::CommandFileName() :
    fileName_()
{
    return;
}

CommandFileName::CommandFileName(const std::string file_name) :
    fileName_(file_name)
{
    return;
}

CommandFileName::CommandFileName( CommandFileName const & other) :
    fileName_(other.fileName_)
{
    if (this != &other)
    {
    }
    return;
}

CommandFileName::CommandFileName( CommandFileName && other) :
    fileName_(std::move(other.fileName_))
{
    if (this != &other)
    {
        
    }
    return;
}		// -----  end of method CommandFileName::CommandFileName  -----


CommandFileName::~CommandFileName()
{
    return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

std::string CommandFileName::operator()() const
{
    return this->fileName_;
}

CommandFileName& CommandFileName::operator= ( const CommandFileName &other )
{
    if (this != &other)
    {
        this->fileName_ = other.fileName_;
    }
    return *this;
} // assignment operator

CommandFileName& CommandFileName::operator= ( CommandFileName && other )
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
