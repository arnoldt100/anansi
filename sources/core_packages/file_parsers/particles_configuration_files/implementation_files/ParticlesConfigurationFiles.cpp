
//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <iostream>

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

//! Returns the node value in ptree_ for the corresponding key.
//!
//! \param[in] global_key The key of the node.
//! \return A std::string is returned, and it is the value of the
//! node for the boost property tree "ptree_".
std::string ParticlesConfigurationFiles::getValue(const std::string & global_key) const
{
   return "Dummy_particle_value";
}

void ParticlesConfigurationFiles::writeFile(const std::string & filename) const
{
    return;
}

//============================= MUTATORS =====================================
void ParticlesConfigurationFiles::setFileName(const CommandFileName & filename)
{
    this->filename_ = filename;
    return;
}

void ParticlesConfigurationFiles::readFile()
{
	std::cout << "Reading Particle Configuration file " << this->filename_() << std::endl;
    return;
}

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
