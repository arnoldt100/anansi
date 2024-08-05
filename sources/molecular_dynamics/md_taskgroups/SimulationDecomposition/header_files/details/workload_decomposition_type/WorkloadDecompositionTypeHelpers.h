#ifndef ANANSI_SDPConstructorHelpers_INC
#define ANANSI_SDPConstructorHelpers_INC

//! \file WorkloadDecompositionTypeHelpers.h
//!
//! \details  This file contains helper functions for initializing
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

namespace ANANSI
{
namespace SDPConstructorHelpers
{

//! \brief Returns the work load decompostion type.
//!
//! \details This parameter must be explicitly specified. If the parameter 'a_string'
//!           equals "flag_default_null_value" an exception will be thrown. Generally, a_string
//!           equals "flag_default_null_value" if the corresponding input file doesn't
//!           have the entry for the simulation workload decomposition type.
//!
//! \param[in] a_string The string to be parsed for the workload decomposition type.
//! \param[in] flag_default_null_value The flag to potentially use the default value.
//!
//! \throws MOUSEION::GenericErrorClass<SimulationDecompositionParameters> This
//!         exception is thrown if the parsing of 'a_string' for the
//!         workload decomposition type fails.
std::string workload_decomposition_type(const std::string a_string,
                                        const std::string flag_default_null_value);

//! \brief Returns the default value for the workload decomposition type.
std::string default_workload_decomposition_type();

}; // end of namespace SDPConstructorHelpers
}; // end of namespace ANANSI

#endif // ANANSI_SDPConstructorHelpers_INC
