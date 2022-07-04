# =====================================================================================
#
#       Filename:  md_core_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of md_core
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_md_core_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package md_core.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_md_core_build_prerequisites_are_met)

    # Ensure that variable "md_core_logfilepath" is defined.
    if (NOT DEFINED md_core_logfilepath) 
        message (FATAL_ERROR "md_core_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"md_core' build prerequisites\" are satisfied.")
    log_message_to_file( ${md_core_logfilepath} "---")
    log_message_to_file( ${md_core_logfilepath} ${my_message})

    # Again verfying that variable 'md_core_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("md_core_logfilepath" "${md_core_logfilepath}")

    # Verfying that variable 'md_core_cxx_standard' is defined.
    anansi_test_variable_is_defined("md_core_cxx_standard"  "${md_core_logfilepath}")

    # Verfying that variable 'md_core_install_bin_directory' is defined.
    anansi_test_variable_is_defined("md_core_install_bin_directory"  "${md_core_logfilepath}")

    # Verfying that variable 'md_core_install_include_directory' is defined.
    anansi_test_variable_is_defined("md_core_install_include_directory"  "${md_core_logfilepath}")

    # Verfying that variable 'md_core_install_lib_directory' is defined.
    anansi_test_variable_is_defined("md_core_install_lib_directory"  "${md_core_logfilepath}")

    set(my_message "Package \"md_core' build prerequisities\" are satisfied.")
    log_message_to_file( ${md_core_logfilepath} ${my_message})
    log_message_to_file( ${md_core_logfilepath} "---\n")
endfunction(verify_md_core_build_prerequisites_are_met)
