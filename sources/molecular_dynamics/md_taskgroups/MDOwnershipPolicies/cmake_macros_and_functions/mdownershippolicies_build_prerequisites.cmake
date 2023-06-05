# =====================================================================================
#
#       Filename:  mdownershippolicies_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of mdownershippolicies
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_mdownershippolicies_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package mdownershippolicies.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_mdownershippolicies_build_prerequisites_are_met)

    # Ensure that variable "mdownershippolicies_logfilepath" is defined.
    if (NOT DEFINED mdownershippolicies_logfilepath) 
        message (FATAL_ERROR "mdownershippolicies_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"mdownershippolicies' build prerequisites\" are satisfied.")
    log_message_to_file( ${mdownershippolicies_logfilepath} "---")
    log_message_to_file( ${mdownershippolicies_logfilepath} ${my_message})

    # Again verfying that variable 'mdownershippolicies_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("mdownershippolicies_logfilepath" "${mdownershippolicies_logfilepath}")

    # Verfying that variable 'mdownershippolicies_cxx_standard' is defined.
    anansi_test_variable_is_defined("mdownershippolicies_cxx_standard"  "${mdownershippolicies_logfilepath}")

    # Verfying that variable 'mdownershippolicies_install_bin_directory' is defined.
    anansi_test_variable_is_defined("mdownershippolicies_install_bin_directory"  "${mdownershippolicies_logfilepath}")

    # Verfying that variable 'mdownershippolicies_install_include_directory' is defined.
    anansi_test_variable_is_defined("mdownershippolicies_install_include_directory"  "${mdownershippolicies_logfilepath}")

    # Verfying that variable 'mdownershippolicies_install_lib_directory' is defined.
    anansi_test_variable_is_defined("mdownershippolicies_install_lib_directory"  "${mdownershippolicies_logfilepath}")

    set(my_message "Package \"mdownershippolicies' build prerequisities\" are satisfied.")
    log_message_to_file( ${mdownershippolicies_logfilepath} ${my_message})
    log_message_to_file( ${mdownershippolicies_logfilepath} "---\n")
endfunction(verify_mdownershippolicies_build_prerequisites_are_met)
