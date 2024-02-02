#ifndef ANANSI_SDPConstructorHelpers_INC
#define ANANSI_SDPConstructorHelpers_INC

//! \file WorkloadDecompositionTypeHelpers.h
//!
//! \detailed This file contains helper functions for initializing
//!           class SimulationDecompositionParameters data members in
//!           its constructor.

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//
#include "SimulationDecompositionParameters.h"

namespace ANANSI
{
namespace SDPConstructorHelpers
{

//! \brief Returns the work load decompostion type.
std::string workload_decomposition_type(const std::string a_string,
                                        const std::string flag_default_null_value);

}; // end of namespace WorkloadDecompositionTypeHelpers 
}; // end of namespace ANANSI

#endif // ANANSI_SDPConstructorHelpers_INC
