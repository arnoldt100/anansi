# =====================================================================================
#
#       Filename:  simulation_parameters_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of simulation_parameters
#                 are satisfied.
#
#
# =====================================================================================




# ===  FUNCTION  ======================================================================
#         Name:  verify_simulation_parameters_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package simulation_parameters.
# 
#
# =====================================================================================
function(verify_simulation_parameters_build_prerequisites_are_met)

    # Ensure that variable "simulation_parameters_logfilepath" is defined.
    if (NOT DEFINED simulation_parameters_logfilepath) 
        message (FATAL_ERROR "simulation_parameters_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"simulation_parameters' build prerequisities\" are satisfied.\n")
    log_message_to_file( ${simulation_parameters_logfilepath} ${my_message})

    # Again verfying that variable 'simulation_parameters_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("simulation_parameters_logfilepath" "${simulation_parameters_logfilepath}")

    # Verfying that variable 'simulation_parameters_cxx_standard' is defined.
    anansi_test_variable_is_defined("simulation_parameters_cxx_standard"  "${simulation_parameters_logfilepath}")

    # Verfying that variable 'simulation_parameters_install_bin_directory' is defined.
    anansi_test_variable_is_defined("simulation_parameters_install_bin_directory"  "${simulation_parameters_logfilepath}")

    # Verfying that variable 'simulation_parameters_install_include_directory' is defined.
    anansi_test_variable_is_defined("simulation_parameters_install_include_directory"  "${simulation_parameters_logfilepath}")

    # Verfying that variable 'simulation_parameters_install_lib_directory' is defined.
    anansi_test_variable_is_defined("simulation_parameters_install_lib_directory"  "${simulation_parameters_logfilepath}")

    set(my_message "Package \"simulation_parameters' build prerequisities\" are satisfied.\n")
    log_message_to_file( ${simulation_parameters_logfilepath} ${my_message})

endfunction()

