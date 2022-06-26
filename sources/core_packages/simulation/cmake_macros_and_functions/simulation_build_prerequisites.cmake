# =====================================================================================
#
#       Filename:  simulation_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the  package simulation
#                  are satisfied.
#
# =====================================================================================

function(verify_simulation_build_prerequisites_are_met)

    # Ensure that variable "simulation_logfilepath" is defined.
    if (NOT DEFINED simulation_logfilepath) 
        message (FATAL_ERROR "simulation_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"simulation\" build prerequisities are satisfied.")
    log_message_to_file(${simulation_logfilepath} "---")
    log_message_to_file(${simulation_logfilepath} ${my_message})

    # Again verfying that variable 'simulation_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("simulation_logfilepath" "${simulation_logfilepath}")

    # Verfying that variable 'simulation_cxx_standard' is defined.
    anansi_test_variable_is_defined("simulation_cxx_standard"  "${simulation_logfilepath}")

    # Verfying that variable 'simulation_install_bin_directory' is defined.
    anansi_test_variable_is_defined("simulation_install_bin_directory"  "${simulation_logfilepath}")

    # Verfying that variable 'simulation_install_include_directory' is defined.
    anansi_test_variable_is_defined("simulation_install_include_directory"  "${simulation_logfilepath}")

    # Verfying that variable 'simulation_install_lib_directory' is defined.
    anansi_test_variable_is_defined("simulation_install_lib_directory"  "${simulation_logfilepath}")

    set(my_message "Package \"simulation\" build prerequisities are satisfied.")
    log_message_to_file(${simulation_logfilepath} ${my_message})
    log_message_to_file(${simulation_logfilepath} "---\n")

endfunction()
