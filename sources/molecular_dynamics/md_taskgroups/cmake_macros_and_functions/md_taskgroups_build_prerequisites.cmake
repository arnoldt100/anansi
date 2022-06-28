# =====================================================================================
#
#       Filename:  md_taskgroups_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of md_taskgroups
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_md_taskgroups_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package md_taskgroups.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_md_taskgroups_build_prerequisites_are_met)

    # Ensure that variable "md_taskgroups_logfilepath" is defined.
    if (NOT DEFINED md_taskgroups_logfilepath) 
        message (FATAL_ERROR "md_taskgroups_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"md_taskgroups' build prerequisities\" are satisfied.")
    log_message_to_file( ${md_taskgroups_logfilepath} "---")
    log_message_to_file( ${md_taskgroups_logfilepath} ${my_message})

    # Again verfying that variable 'md_taskgroups_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("md_taskgroups_logfilepath" "${md_taskgroups_logfilepath}")

    # Verfying that variable 'md_taskgroups_cxx_standard' is defined.
    anansi_test_variable_is_defined("md_taskgroups_cxx_standard"  "${md_taskgroups_logfilepath}")

    # Verfying that variable 'md_taskgroups_install_bin_directory' is defined.
    anansi_test_variable_is_defined("md_taskgroups_install_bin_directory"  "${md_taskgroups_logfilepath}")

    # Verfying that variable 'md_taskgroups_install_include_directory' is defined.
    anansi_test_variable_is_defined("md_taskgroups_install_include_directory"  "${md_taskgroups_logfilepath}")

    # Verfying that variable 'md_taskgroups_install_lib_directory' is defined.
    anansi_test_variable_is_defined("md_taskgroups_install_lib_directory"  "${md_taskgroups_logfilepath}")

    set(my_message "Package \"md_taskgroups' build prerequisities\" are satisfied.")
    log_message_to_file( ${md_taskgroups_logfilepath} ${my_message})
    log_message_to_file( ${md_taskgroups_logfilepath} "---\n")
endfunction(verify_md_taskgroups_build_prerequisites_are_met)
