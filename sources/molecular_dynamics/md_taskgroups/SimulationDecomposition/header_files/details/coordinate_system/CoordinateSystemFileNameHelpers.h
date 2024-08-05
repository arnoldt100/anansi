#ifndef ANANSI_CoordinateSystemFileNameHelpers_INC
#define ANANSI_CoordinateSystemFileNameHelpers_INC

//! \file CoordinateSystemFileNameHelpers.h

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
    class SimulationDecompositionParameters;

    namespace SDPConstructorHelpers
    {
        //! Returns the file name that contains the coordinate system file name.
        //!
        //! \details This parameter must be explicitly specified. If the parameter 'a_string'
        //!          equals "flag_default_null_value" an exception will be thrown. Generally, a_string
        //!          equals "flag_default_null_value" if the corresponding input file doesn't
        //!          have the entry for the simulation coordinate system file name.
        //!
        //! \param[in] a_string The string to be parsed for file name of the coorddinate system  file.
        //! \param[in] flag_default_null_value The flag to potentially use the default value.
        //!
        //! \throws MOUSEION::GenericErrorClass<SimulationDecompositionParameters> This
        //!         exception is thrown if the parsing of 'a_string' for the
        //!         coordinate system file names fails.
        std::string parse_coordinate_system_file_names(const std::string initial_configuration_filenames,
                                                       const std::string flag_default_null_value);

        //! \details Returns the default coodinate system file name.
        std::string default_coordinate_system_file_names();

        //! \details The characters that are banned from being used in the file names of the
        //! initial configuration file names.
        constexpr std::string_view coordinate_system_filename_banned_chars = ";,";
    };

}; // namespace ANANSI

#endif // ANANSI_CoordinateSystemFileNameHelpers_INC
