# =====================================================================================
#
#       Filename:  writetexttoconsoletask_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of writetexttoconsoletask
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_writetexttoconsoletask_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package writetexttoconsoletask.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_writetexttoconsoletask_build_prerequisites_are_met)

    # Ensure that variable "writetexttoconsoletask_logfilepath" is defined.
    if (NOT DEFINED writetexttoconsoletask_logfilepath) 
        message (FATAL_ERROR "writetexttoconsoletask_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"writetexttoconsoletask' build prerequisites\" are satisfied.")
    log_message_to_file( ${writetexttoconsoletask_logfilepath} "---")
    log_message_to_file( ${writetexttoconsoletask_logfilepath} ${my_message})

    # Again verfying that variable 'writetexttoconsoletask_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("writetexttoconsoletask_logfilepath" "${writetexttoconsoletask_logfilepath}")

    # Verfying that variable 'writetexttoconsoletask_cxx_standard' is defined.
    anansi_test_variable_is_defined("writetexttoconsoletask_cxx_standard"  "${writetexttoconsoletask_logfilepath}")

    # Verfying that variable 'writetexttoconsoletask_install_bin_directory' is defined.
    anansi_test_variable_is_defined("writetexttoconsoletask_install_bin_directory"  "${writetexttoconsoletask_logfilepath}")

    # Verfying that variable 'writetexttoconsoletask_install_include_directory' is defined.
    anansi_test_variable_is_defined("writetexttoconsoletask_install_include_directory"  "${writetexttoconsoletask_logfilepath}")

    # Verfying that variable 'writetexttoconsoletask_install_lib_directory' is defined.
    anansi_test_variable_is_defined("writetexttoconsoletask_install_lib_directory"  "${writetexttoconsoletask_logfilepath}")

    set(my_message "Package \"writetexttoconsoletask' build prerequisities\" are satisfied.")
    log_message_to_file( ${writetexttoconsoletask_logfilepath} ${my_message})
    log_message_to_file( ${writetexttoconsoletask_logfilepath} "---\n")
endfunction(verify_writetexttoconsoletask_build_prerequisites_are_met)

