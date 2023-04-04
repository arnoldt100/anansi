# =====================================================================================
#
#       Filename:  initworldcommunicator_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of initworldcommunicator
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_initworldcommunicator_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package initworldcommunicator.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_initworldcommunicator_build_prerequisites_are_met)

    # Ensure that variable "initworldcommunicator_logfilepath" is defined.
    if (NOT DEFINED initworldcommunicator_logfilepath) 
        message (FATAL_ERROR "initworldcommunicator_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"initworldcommunicator' build prerequisites\" are satisfied.")
    log_message_to_file( ${initworldcommunicator_logfilepath} "---")
    log_message_to_file( ${initworldcommunicator_logfilepath} ${my_message})

    # Again verfying that variable 'initworldcommunicator_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("initworldcommunicator_logfilepath" "${initworldcommunicator_logfilepath}")

    # Verfying that variable 'initworldcommunicator_cxx_standard' is defined.
    anansi_test_variable_is_defined("initworldcommunicator_cxx_standard"  "${initworldcommunicator_logfilepath}")

    # Verfying that variable 'initworldcommunicator_install_bin_directory' is defined.
    anansi_test_variable_is_defined("initworldcommunicator_install_bin_directory"  "${initworldcommunicator_logfilepath}")

    # Verfying that variable 'initworldcommunicator_install_include_directory' is defined.
    anansi_test_variable_is_defined("initworldcommunicator_install_include_directory"  "${initworldcommunicator_logfilepath}")

    # Verfying that variable 'initworldcommunicator_install_lib_directory' is defined.
    anansi_test_variable_is_defined("initworldcommunicator_install_lib_directory"  "${initworldcommunicator_logfilepath}")

    set(my_message "Package \"initworldcommunicator' build prerequisities\" are satisfied.")
    log_message_to_file( ${initworldcommunicator_logfilepath} ${my_message})
    log_message_to_file( ${initworldcommunicator_logfilepath} "---\n")
endfunction(verify_initworldcommunicator_build_prerequisites_are_met)

