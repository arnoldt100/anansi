/*
 * SimulationParametersFactory.cpp
 *
 *         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
 *   Organization:  ORNL-National Center of Computational Sciences
 */

#include "SimulationParametersFactory.h"

namespace ANANSI {

//////////////////////////////////////////////////////////////////////////////
/////////////////////////////// PUBLIC ///////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//============================= LIFECYCLE ====================================

SimulationParametersFactory::SimulationParametersFactory() 
{
	return;
}

SimulationParametersFactory::SimulationParametersFactory( const SimulationParametersFactory &other )
{
    return;
}

SimulationParametersFactory::~SimulationParametersFactory() 
{
	return;
}

//============================= ACCESSORS ====================================

//============================= MUTATORS =====================================

//============================= OPERATORS ====================================

SimulationParametersFactory& SimulationParametersFactory::operator=( const SimulationParametersFactory &other )
{
    if (this != &other)
    {

    }
    return *this;
}

//============================= STATIC    ====================================

SimulationParameters SimulationParametersFactory::create(COMMANDLINE::CommandLineArguments const & aCommandLine )
{
    SimulationParameters aSimulationParameters(aCommandLine);
    return aSimulationParameters;
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


} /* namespace ANANSI */
