# =====================================================================================
#
#       Filename:  command_files_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the package command_files
#                  are satisfied.
#
# =====================================================================================

function(verify_command_files_build_prerequisites_are_met)

    # Ensure that variable "command_files_logfilepath" is defined.
    if (NOT DEFINED command_files_logfilepath) 
        message (FATAL_ERROR "command_files_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"command_files\" build prerequisities are satisfied.")
    log_message_to_file(${command_files_logfilepath} "---")
    log_message_to_file(${command_files_logfilepath} ${my_message})

    # Again verfying that variable 'command_files_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("command_files_logfilepath" "${command_files_logfilepath}")
    
    # Verfying that variable 'command_files_cmake_c_compiler' is defined.
    anansi_test_variable_is_defined("command_files_cmake_c_compiler"  "${command_files_logfilepath}")

    # Verfying that variable 'command_files_cmake_cxx_compiler' is defined.
    anansi_test_variable_is_defined("command_files_cmake_cxx_compiler"  "${command_files_logfilepath}")

    # Verfying that variable 'command_files_cxx_standard' is defined.
    anansi_test_variable_is_defined("command_files_cxx_standard"  "${command_files_logfilepath}")

    # Verfying that variable 'command_files_install_bin_directory' is defined.
    anansi_test_variable_is_defined("command_files_install_bin_directory"  "${command_files_logfilepath}")

    # Verfying that variable 'command_files_install_include_directory' is defined.
    anansi_test_variable_is_defined("command_files_install_include_directory"  "${command_files_logfilepath}")

    # Verfying that variable 'command_files_install_lib_directory' is defined.
    anansi_test_variable_is_defined("command_files_install_lib_directory"  "${command_files_logfilepath}")

    set(my_message "Package \"command_files\" build prerequisities are satisfied.")
    log_message_to_file(${command_files_logfilepath} ${my_message})
    log_message_to_file(${command_files_logfilepath} "---\n")

endfunction()
