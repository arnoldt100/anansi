# =====================================================================================
#
#       Filename:  simulation_state_build_prerequisites.cmake
#
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the  package simulation_state
#                  are satisfied.
#
# =====================================================================================

function(verify_simulation_state_build_prerequisites_are_met)

    # Ensure that variable "simulation_state_logfilepath" is defined.
    if (NOT DEFINED simulation_state_logfilepath) 
        message (FATAL_ERROR "simulation_state_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"simulation_state\" build prerequisities are satisfied.")
    log_message_to_file(${simulation_state_logfilepath} "---")
    log_message_to_file(${simulation_state_logfilepath} ${my_message})

    # Again verfying that variable 'simulation_state_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("simulation_state_logfilepath" "${simulation_state_logfilepath}")

    # Verfying that variable 'simulation_state_cxx_standard' is defined.
    anansi_test_variable_is_defined("simulation_state_cxx_standard"  "${simulation_state_logfilepath}")

    # Verfying that variable 'simulation_state_install_bin_directory' is defined.
    anansi_test_variable_is_defined("simulation_state_install_bin_directory"  "${simulation_state_logfilepath}")

    # Verfying that variable 'simulation_state_install_include_directory' is defined.
    anansi_test_variable_is_defined("simulation_state_install_include_directory"  "${simulation_state_logfilepath}")

    # Verfying that variable 'simulation_state_install_lib_directory' is defined.
    anansi_test_variable_is_defined("simulation_state_install_lib_directory"  "${simulation_state_logfilepath}")

    set(my_message "Package \"simulation_state\" build prerequisites are satisfied.")
    log_message_to_file(${simulation_state_logfilepath} ${my_message})
    log_message_to_file(${simulation_state_logfilepath} "---\n")

endfunction()
