# =====================================================================================
#
#       Filename:  molecular_dynamics_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of molecular_dynamics
#                 are satisfied.
#
#
# =====================================================================================




# ===  FUNCTION  ======================================================================
#         Name:  verify_molecular_dynamics_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package molecular_dynamics.
# 
# =====================================================================================
function(verify_molecular_dynamics_build_prerequisites_are_met)

    # Ensure that variable "molecular_dynamics_logfilepath" is defined.
    if (NOT DEFINED molecular_dynamics_logfilepath) 
        message (FATAL_ERROR "molecular_dynamics_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"molecular_dynamics' build prerequisities\" are satisfied.")
    log_message_to_file( ${molecular_dynamics_logfilepath} "---")
    log_message_to_file( ${molecular_dynamics_logfilepath} ${my_message})

    # Again verfying that variable 'molecular_dynamics_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("molecular_dynamics_logfilepath" "${molecular_dynamics_logfilepath}")

    # Verfying that variable 'molecular_dynamics_minimum_cmake_version' is defined.
    anansi_test_variable_is_defined("molecular_dynamics_minimum_cmake_version"  "${molecular_dynamics_logfilepath}")

    # Verfying that variable 'molecular_dynamics_cxx_standard' is defined.
    anansi_test_variable_is_defined("molecular_dynamics_cxx_standard"  "${molecular_dynamics_logfilepath}")

    # Verfying that variable 'molecular_dynamics_cmake_c_compiler' is defined.
    anansi_test_variable_is_defined("molecular_dynamics_cmake_c_compiler"  "${molecular_dynamics_logfilepath}")

    # Verfying that variable 'molecular_dynamics_cmake_cxx_compiler' is defined.
    anansi_test_variable_is_defined("molecular_dynamics_cmake_cxx_compiler"  "${molecular_dynamics_logfilepath}")

    # Verfying that variable 'molecular_dynamics_install_prefix' is defined.
    anansi_test_variable_is_defined("molecular_dynamics_install_prefix"  "${molecular_dynamics_logfilepath}")

    # Verfying that variable 'molecular_dynamics_install_bin_directory' is defined.
    anansi_test_variable_is_defined("molecular_dynamics_install_bin_directory"  "${molecular_dynamics_logfilepath}")

    # Verfying that variable 'molecular_dynamics_install_include_directory' is defined.
    anansi_test_variable_is_defined("molecular_dynamics_install_include_directory"  "${molecular_dynamics_logfilepath}")

    # Verfying that variable 'molecular_dynamics_install_lib_directory' is defined.
    anansi_test_variable_is_defined("molecular_dynamics_install_lib_directory"  "${molecular_dynamics_logfilepath}")

    set(my_message "Package \"molecular_dynamics' build prerequisities\" are satisfied.")
    log_message_to_file( ${molecular_dynamics_logfilepath} ${my_message})
    log_message_to_file( ${molecular_dynamics_logfilepath} "---\n")

endfunction()

