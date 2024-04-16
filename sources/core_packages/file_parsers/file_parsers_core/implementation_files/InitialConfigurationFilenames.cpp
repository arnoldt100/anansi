
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "InitialConfigurationFilenames.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

InitialConfigurationFilenames::InitialConfigurationFilenames() : 
    fileNames_{}
{
    return;
}

InitialConfigurationFilenames::InitialConfigurationFilenames(std::vector<std::string> const & file_names): 
    fileNames_{file_names}
{
    return;
}

InitialConfigurationFilenames::InitialConfigurationFilenames( InitialConfigurationFilenames const & other) :
    fileNames_{other.fileNames_}
{
    if (this != &other)
    {
        
    }
    return;
}

InitialConfigurationFilenames::InitialConfigurationFilenames( InitialConfigurationFilenames && other) :
    fileNames_{std::move(other.fileNames_)}
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method InitialConfigurationFilenames::InitialConfigurationFilenames  -----


InitialConfigurationFilenames::~InitialConfigurationFilenames()
{
    return;
}

//============================= ACCESSORS ====================================

InitialConfigurationFilenames * InitialConfigurationFilenames::clone() const
{
    return new InitialConfigurationFilenames(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

InitialConfigurationFilenames& InitialConfigurationFilenames::operator= ( const InitialConfigurationFilenames &other )
{
    if (this != &other)
    {
        this->fileNames_ = other.fileNames_;
    }
    return *this;
} // assignment operator

InitialConfigurationFilenames& InitialConfigurationFilenames::operator= ( InitialConfigurationFilenames && other )
{
    if (this != &other)
    {
        this->fileNames_ = std::move(other.fileNames_);
    }
    return *this;
} // assignment-move operator

std::vector<std::string> InitialConfigurationFilenames::operator()() const
{
    return this->fileNames_;
}

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
