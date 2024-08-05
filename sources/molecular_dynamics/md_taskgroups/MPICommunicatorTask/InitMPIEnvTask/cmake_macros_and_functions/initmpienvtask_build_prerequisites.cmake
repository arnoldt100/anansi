# =====================================================================================
#
#       Filename:  initmpienvtask_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of initmpienvtask
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_initmpienvtask_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package initmpienvtask.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_initmpienvtask_build_prerequisites_are_met)

    # Ensure that variable "initmpienvtask_logfilepath" is defined.
    if (NOT DEFINED initmpienvtask_logfilepath) 
        message (FATAL_ERROR "initmpienvtask_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"initmpienvtask' build prerequisites\" are satisfied.")
    log_message_to_file( ${initmpienvtask_logfilepath} "---")
    log_message_to_file( ${initmpienvtask_logfilepath} ${my_message})

    # Again verfying that variable 'initmpienvtask_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("initmpienvtask_logfilepath" "${initmpienvtask_logfilepath}")

    # Verfying that variable 'initmpienvtask_cxx_standard' is defined.
    anansi_test_variable_is_defined("initmpienvtask_cxx_standard"  "${initmpienvtask_logfilepath}")

    # Verfying that variable 'initmpienvtask_install_bin_directory' is defined.
    anansi_test_variable_is_defined("initmpienvtask_install_bin_directory"  "${initmpienvtask_logfilepath}")

    # Verfying that variable 'initmpienvtask_install_include_directory' is defined.
    anansi_test_variable_is_defined("initmpienvtask_install_include_directory"  "${initmpienvtask_logfilepath}")

    # Verfying that variable 'initmpienvtask_install_lib_directory' is defined.
    anansi_test_variable_is_defined("initmpienvtask_install_lib_directory"  "${initmpienvtask_logfilepath}")

    set(my_message "Package \"initmpienvtask' build prerequisities\" are satisfied.")
    log_message_to_file( ${initmpienvtask_logfilepath} ${my_message})
    log_message_to_file( ${initmpienvtask_logfilepath} "---\n")
endfunction(verify_initmpienvtask_build_prerequisites_are_met)
