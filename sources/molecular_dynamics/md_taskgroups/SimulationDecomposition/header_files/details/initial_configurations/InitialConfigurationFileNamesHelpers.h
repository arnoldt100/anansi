#ifndef ANANSI_InitialConfigurationFileNamesHelpers_INC
#define ANANSI_InitialConfigurationFileNamesHelpers_INC
//! \file InitialConfigurationFileNamesHelpers.h
//!
//! \brief Brief description
//!
//! \details Detailed description

//--------------------------------------------------------//
//-------------------- System includes -------------------//
//--------------------------------------------------------//
#include <string>
#include <vector>

//--------------------------------------------------------//
//-------------------- External Library Files ------------//
//--------------------------------------------------------//

//--------------------------------------------------------//
//--------------------- Package includes -----------------//
//--------------------------------------------------------//

namespace ANANSI
{
    class SimulationDecompositionParameters;

    namespace SDPConstructorHelpers
    {
        //! Returns a vector of initial configuration file names.
        //!
        //! \details This parameter must be explicitly specified. If the parameter 'a_string'
        //!          equals "flag_default_null_value" an exception will be thrown. Generally, a_string
        //!          equals "flag_default_null_value" if the corresponding input file doesn't
        //!          have the entry for the simulation initial configuration file names.
        //!
        //! \param[in] a_string The string to be parsed for the lattice topology spatial dimensions.
        //! \param[in] flag_default_null_value The flag to potentially use the default value.
        //!
        //! \throws MOUSEION::GenericErrorClass<SimulationDecompositionParameters> This
        //!         exception is thrown if the parsing of 'a_string' for the
        //!         initial configuration file names fails.
        std::vector<std::string> parse_initial_configuration_file_names(std::string initial_configuration_filenames,
                                                                        const std::string flag_default_null_value);

        //! Returns the default initial configuration file names.
        std::vector<std::string> default_initial_configuration_file_names();

    }; // ----- End of namespace SDPConstructorHelpers.
}; // End of namespace ANANSI

#endif // ANANSI_InitialConfigurationFileNamesHelpers_INC
