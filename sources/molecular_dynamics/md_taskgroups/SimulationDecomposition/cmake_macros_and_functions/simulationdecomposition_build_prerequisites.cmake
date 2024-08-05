# =====================================================================================
#
#       Filename:  simulationdecomposition_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building target simulationdecomposition
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_simulationdecomposition_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package simulationdecomposition.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_simulationdecomposition_build_prerequisites_are_met)

    # Ensure that variable "simulationdecomposition_logfilepath" is defined.
    if (NOT DEFINED simulationdecomposition_logfilepath) 
        message (FATAL_ERROR "simulationdecomposition_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"simulationdecomposition' build prerequisites\" are satisfied.")
    log_message_to_file( ${simulationdecomposition_logfilepath} "---")
    log_message_to_file( ${simulationdecomposition_logfilepath} ${my_message})

    # Again verfying that variable 'simulationdecomposition_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("simulationdecomposition_logfilepath" "${simulationdecomposition_logfilepath}")

    # Verfying that variable 'simulationdecomposition_cxx_standard' is defined.
    anansi_test_variable_is_defined("simulationdecomposition_cxx_standard"  "${simulationdecomposition_logfilepath}")

    # Verfying that variable 'simulationdecomposition_install_bin_directory' is defined.
    anansi_test_variable_is_defined("simulationdecomposition_install_bin_directory"  "${simulationdecomposition_logfilepath}")

    # Verfying that variable 'simulationdecomposition_install_include_directory' is defined.
    anansi_test_variable_is_defined("simulationdecomposition_install_include_directory"  "${simulationdecomposition_logfilepath}")

    # Verfying that variable 'simulationdecomposition_install_lib_directory' is defined.
    anansi_test_variable_is_defined("simulationdecomposition_install_lib_directory"  "${simulationdecomposition_logfilepath}")

    set(my_message "Package \"simulationdecomposition' build prerequisities\" are satisfied.")
    log_message_to_file( ${simulationdecomposition_logfilepath} ${my_message})
    log_message_to_file( ${simulationdecomposition_logfilepath} "---\n")
endfunction(verify_simulationdecomposition_build_prerequisites_are_met)

