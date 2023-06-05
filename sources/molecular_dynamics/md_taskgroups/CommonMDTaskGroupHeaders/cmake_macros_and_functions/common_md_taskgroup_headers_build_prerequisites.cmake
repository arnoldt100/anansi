# =====================================================================================
#
#       Filename: common_md_taskgroup_headers_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building target common_md_taskgroup_headers
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_common_md_taskgroup_headers_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package common_md_taskgroup_headers.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_common_md_taskgroup_headers_build_prerequisites_are_met)

    # Ensure that variable "common_md_taskgroup_headers_logfilepath" is defined.
    if (NOT DEFINED common_md_taskgroup_headers_logfilepath) 
        message (FATAL_ERROR "common_md_taskgroup_headers_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"common_md_taskgroup_headers' build prerequisites\" are satisfied.")
    log_message_to_file( ${common_md_taskgroup_headers_logfilepath} "---")
    log_message_to_file( ${common_md_taskgroup_headers_logfilepath} ${my_message})

    # Again verfying that variable 'common_md_taskgroup_headers_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("common_md_taskgroup_headers_logfilepath" "${common_md_taskgroup_headers_logfilepath}")

    # Verfying that variable 'common_md_taskgroup_headers_cxx_standard' is defined.
    anansi_test_variable_is_defined("common_md_taskgroup_headers_cxx_standard"  "${common_md_taskgroup_headers_logfilepath}")

    # Verfying that variable 'common_md_taskgroup_headers_install_bin_directory' is defined.
    anansi_test_variable_is_defined("common_md_taskgroup_headers_install_bin_directory"  "${common_md_taskgroup_headers_logfilepath}")

    # Verfying that variable 'common_md_taskgroup_headers_install_include_directory' is defined.
    anansi_test_variable_is_defined("common_md_taskgroup_headers_install_include_directory"  "${common_md_taskgroup_headers_logfilepath}")

    # Verfying that variable 'common_md_taskgroup_headers_install_lib_directory' is defined.
    anansi_test_variable_is_defined("common_md_taskgroup_headers_install_lib_directory"  "${common_md_taskgroup_headers_logfilepath}")

    set(my_message "Package \"common_md_taskgroup_headers' build prerequisities\" are satisfied.")
    log_message_to_file( ${common_md_taskgroup_headers_logfilepath} ${my_message})
    log_message_to_file( ${common_md_taskgroup_headers_logfilepath} "---\n")
endfunction(verify_common_md_taskgroup_headers_build_prerequisites_are_met)
