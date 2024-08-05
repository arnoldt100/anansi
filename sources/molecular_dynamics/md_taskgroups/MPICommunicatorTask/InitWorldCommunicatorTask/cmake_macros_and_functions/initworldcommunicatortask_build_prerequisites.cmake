# =====================================================================================
#
#       Filename:  initworldcommunicatortask_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of initworldcommunicatortask
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_initworldcommunicatortask_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package initworldcommunicatortask.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_initworldcommunicatortask_build_prerequisites_are_met)

    # Ensure that variable "initworldcommunicatortask_logfilepath" is defined.
    if (NOT DEFINED initworldcommunicatortask_logfilepath) 
        message (FATAL_ERROR "initworldcommunicatortask_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"initworldcommunicatortask' build prerequisites\" are satisfied.")
    log_message_to_file( ${initworldcommunicatortask_logfilepath} "---")
    log_message_to_file( ${initworldcommunicatortask_logfilepath} ${my_message})

    # Again verfying that variable 'initworldcommunicatortask_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("initworldcommunicatortask_logfilepath" "${initworldcommunicatortask_logfilepath}")

    # Verfying that variable 'initworldcommunicatortask_cxx_standard' is defined.
    anansi_test_variable_is_defined("initworldcommunicatortask_cxx_standard"  "${initworldcommunicatortask_logfilepath}")

    # Verfying that variable 'initworldcommunicatortask_install_bin_directory' is defined.
    anansi_test_variable_is_defined("initworldcommunicatortask_install_bin_directory"  "${initworldcommunicatortask_logfilepath}")

    # Verfying that variable 'initworldcommunicatortask_install_include_directory' is defined.
    anansi_test_variable_is_defined("initworldcommunicatortask_install_include_directory"  "${initworldcommunicatortask_logfilepath}")

    # Verfying that variable 'initworldcommunicatortask_install_lib_directory' is defined.
    anansi_test_variable_is_defined("initworldcommunicatortask_install_lib_directory"  "${initworldcommunicatortask_logfilepath}")

    set(my_message "Package \"initworldcommunicatortask' build prerequisities\" are satisfied.")
    log_message_to_file( ${initworldcommunicatortask_logfilepath} ${my_message})
    log_message_to_file( ${initworldcommunicatortask_logfilepath} "---\n")
endfunction(verify_initworldcommunicatortask_build_prerequisites_are_met)

