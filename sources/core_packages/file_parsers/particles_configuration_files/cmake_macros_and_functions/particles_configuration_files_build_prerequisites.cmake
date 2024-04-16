# =====================================================================================
#
#       Filename:  particles_configuration_files_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the package particles_configuration_files
#                  are satisfied.
#
# =====================================================================================

function(verify_particles_configuration_files_build_prerequisites_are_met)

    # Ensure that variable "particles_configuration_files_logfilepath" is defined.
    if (NOT DEFINED particles_configuration_files_logfilepath) 
        message (FATAL_ERROR "particles_configuration_files_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"particles_configuration_files\" build prerequisities are satisfied.")
    log_message_to_file(${particles_configuration_files_logfilepath} "---")
    log_message_to_file(${particles_configuration_files_logfilepath} ${my_message})

    # Again verfying that variable 'particles_configuration_files_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("particles_configuration_files_logfilepath" "${particles_configuration_files_logfilepath}")
    
    # Verfying that variable 'particles_configuration_files_cmake_c_compiler' is defined.
    anansi_test_variable_is_defined("particles_configuration_files_cmake_c_compiler"  "${particles_configuration_files_logfilepath}")

    # Verfying that variable 'particles_configuration_files_cmake_cxx_compiler' is defined.
    anansi_test_variable_is_defined("particles_configuration_files_cmake_cxx_compiler"  "${particles_configuration_files_logfilepath}")

    # Verfying that variable 'particles_configuration_files_cxx_standard' is defined.
    anansi_test_variable_is_defined("particles_configuration_files_cxx_standard"  "${particles_configuration_files_logfilepath}")

    # Verfying that variable 'particles_configuration_files_install_bin_directory' is defined.
    anansi_test_variable_is_defined("particles_configuration_files_install_bin_directory"  "${particles_configuration_files_logfilepath}")

    # Verfying that variable 'particles_configuration_files_install_include_directory' is defined.
    anansi_test_variable_is_defined("particles_configuration_files_install_include_directory"  "${particles_configuration_files_logfilepath}")

    # Verfying that variable 'particles_configuration_files_install_lib_directory' is defined.
    anansi_test_variable_is_defined("particles_configuration_files_install_lib_directory"  "${particles_configuration_files_logfilepath}")

    set(my_message "Package \"particles_configuration_files\" build prerequisities are satisfied.")
    log_message_to_file(${particles_configuration_files_logfilepath} ${my_message})
    log_message_to_file(${particles_configuration_files_logfilepath} "---\n")

endfunction()
