# =====================================================================================
#
#       Filename:  genericmdtask_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building target genericmdtask
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_genericmdtask_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package genericmdtask.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_genericmdtask_build_prerequisites_are_met)

    # Ensure that variable "genericmdtask_logfilepath" is defined.
    if (NOT DEFINED genericmdtask_logfilepath) 
        message (FATAL_ERROR "genericmdtask_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"genericmdtask' build prerequisites\" are satisfied.")
    log_message_to_file( ${genericmdtask_logfilepath} "---")
    log_message_to_file( ${genericmdtask_logfilepath} ${my_message})

    # Again verfying that variable 'genericmdtask_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("genericmdtask_logfilepath" "${genericmdtask_logfilepath}")

    # Verfying that variable 'genericmdtask_cxx_standard' is defined.
    anansi_test_variable_is_defined("genericmdtask_cxx_standard"  "${genericmdtask_logfilepath}")

    # Verfying that variable 'genericmdtask_install_bin_directory' is defined.
    anansi_test_variable_is_defined("genericmdtask_install_bin_directory"  "${genericmdtask_logfilepath}")

    # Verfying that variable 'genericmdtask_install_include_directory' is defined.
    anansi_test_variable_is_defined("genericmdtask_install_include_directory"  "${genericmdtask_logfilepath}")

    # Verfying that variable 'genericmdtask_install_lib_directory' is defined.
    anansi_test_variable_is_defined("genericmdtask_install_lib_directory"  "${genericmdtask_logfilepath}")

    set(my_message "Package \"genericmdtask' build prerequisities\" are satisfied.")
    log_message_to_file( ${genericmdtask_logfilepath} ${my_message})
    log_message_to_file( ${genericmdtask_logfilepath} "---\n")
endfunction(verify_genericmdtask_build_prerequisites_are_met)
