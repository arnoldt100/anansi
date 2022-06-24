# =====================================================================================
#
#       Filename:  core_packages_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of core_packages
#                 are satisfied.
#
#
# =====================================================================================




# ===  FUNCTION  ======================================================================
#         Name:  verify_core_packages_build_prerequisites_are_set
#  Description:  Verifies that key variables that control the building and installation
#                of the various subpackages of core_packages.
# 
#   Parameters: target : The target of 
#
# =====================================================================================
function(verify_core_packages_build_prerequisites_are_set )

    # Ensure that variable "core_packages_logfilepath" is defined.
    if (NOT DEFINED core_packages_logfilepath) 
        message (FATAL_ERROR "core_packages_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"core_packages' build prerequisities\" are satisfied.\n")
    log_message_to_file( ${core_packages_logfilepath} ${my_message})

    # Again verfying that variable 'core_packages_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("core_packages_logfilepath" "${core_packages_logfilepath}")

    # Verfying that variable 'core_packages_minimum_cmake_version' is defined.
    anansi_test_variable_is_defined("core_packages_minimum_cmake_version"  "${core_packages_logfilepath}")

    # Verfying that variable 'core_packages_cxx_standard' is defined.
    anansi_test_variable_is_defined("core_packages_cxx_standard"  "${core_packages_logfilepath}")

    # Verfying that variable 'core_packages_cmake_c_compiler' is defined.
    anansi_test_variable_is_defined("core_packages_cmake_c_compiler"  "${core_packages_logfilepath}")

    # Verfying that variable 'core_packages_cmake_cxx_compiler' is defined.
    anansi_test_variable_is_defined("core_packages_cmake_cxx_compiler"  "${core_packages_logfilepath}")

    # Verfying that variable 'core_packages_install_prefix' is defined.
    anansi_test_variable_is_defined("core_packages_install_prefix"  "${core_packages_logfilepath}")

    # Verfying that variable 'core_packages_install_bin_directory' is defined.
    anansi_test_variable_is_defined("core_packages_install_bin_directory"  "${core_packages_logfilepath}")

    # Verfying that variable 'core_packages_install_include_directory' is defined.
    anansi_test_variable_is_defined("core_packages_install_include_directory"  "${core_packages_logfilepath}")

    # Verfying that variable 'core_packages_install_lib_directory' is defined.
    anansi_test_variable_is_defined("core_packages_install_lib_directory"  "${core_packages_logfilepath}")

    set(my_message "Package \"core_packages' build prerequisities\" are satisfied.\n")
    log_message_to_file( ${core_packages_logfilepath} ${my_message})

endfunction(verify_core_packages_build_prerequisites_are_set)

