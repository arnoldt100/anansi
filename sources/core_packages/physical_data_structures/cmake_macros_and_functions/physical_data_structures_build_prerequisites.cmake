# =====================================================================================
#
#       Filename:  physical_data_structures_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the package physical_data_structures
#                  are satisfied.
#
# =====================================================================================

function(verify_physical_data_structures_build_prerequisites_are_met)

    # Ensure that variable "physical_data_structures_logfilepath" is defined.
    if (NOT DEFINED physical_data_structures_logfilepath) 
        message (FATAL_ERROR "physical_data_structures_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"physical_data_structures\" build prerequisities are satisfied.")
    log_message_to_file(${physical_data_structures_logfilepath} "---")
    log_message_to_file(${physical_data_structures_logfilepath} ${my_message})

    # Again verfying that variable 'physical_data_structures_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("physical_data_structures_logfilepath" "${physical_data_structures_logfilepath}")

    # Verfying that variable 'physical_data_structures_cxx_standard' is defined.
    anansi_test_variable_is_defined("physical_data_structures_cxx_standard"  "${physical_data_structures_logfilepath}")

    # Verfying that variable 'physical_data_structures_install_bin_directory' is defined.
    anansi_test_variable_is_defined("physical_data_structures_install_bin_directory"  "${physical_data_structures_logfilepath}")

    # Verfying that variable 'physical_data_structures_install_include_directory' is defined.
    anansi_test_variable_is_defined("physical_data_structures_install_include_directory"  "${physical_data_structures_logfilepath}")

    # Verfying that variable 'physical_data_structures_cmake_c_compiler' is defined.
    anansi_test_variable_is_defined("physical_data_structures_cmake_c_compiler"  "${physical_data_structures_logfilepath}")

    # Verfying that variable 'physical_data_structures_cmake_cxx_compiler' is defined.
    anansi_test_variable_is_defined("physical_data_structures_cmake_cxx_compiler"  "${physical_data_structures_logfilepath}")

    # Verfying that variable 'physical_data_structures_install_lib_directory' is defined.
    anansi_test_variable_is_defined("physical_data_structures_install_lib_directory"  "${physical_data_structures_logfilepath}")

    set(my_message "Package \"physical_data_structures\" build prerequisities are satisfied.")
    log_message_to_file(${physical_data_structures_logfilepath} ${my_message})
    log_message_to_file(${physical_data_structures_logfilepath} "---\n")

endfunction()
