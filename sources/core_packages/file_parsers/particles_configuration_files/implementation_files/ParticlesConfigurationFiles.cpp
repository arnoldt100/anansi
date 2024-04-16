
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "ParticlesConfigurationFiles.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

ParticlesConfigurationFiles::ParticlesConfigurationFiles()
{
    return;
}

ParticlesConfigurationFiles::ParticlesConfigurationFiles( ParticlesConfigurationFiles const & other)
{
    if (this != &other)
    {
        
    }
    return;
}

ParticlesConfigurationFiles::ParticlesConfigurationFiles( ParticlesConfigurationFiles && other)
{
    if (this != &other)
    {
    }
    return;
}		// -----  end of method ParticlesConfigurationFiles::ParticlesConfigurationFiles  -----


ParticlesConfigurationFiles::~ParticlesConfigurationFiles()
{
    return;
}

//============================= ACCESSORS ====================================

ParticlesConfigurationFiles * ParticlesConfigurationFiles::clone() const
{
    return new ParticlesConfigurationFiles(*this);
}

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

ParticlesConfigurationFiles& ParticlesConfigurationFiles::operator= ( const ParticlesConfigurationFiles &other )
{
    if (this != &other)
    {
    }
    return *this;
} // assignment operator

ParticlesConfigurationFiles& ParticlesConfigurationFiles::operator= ( ParticlesConfigurationFiles && other )
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
