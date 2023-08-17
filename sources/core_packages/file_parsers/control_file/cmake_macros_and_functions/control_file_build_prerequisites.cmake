# =====================================================================================
#
#       Filename:  control_file_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the package control_file
#                  are satisfied.
#
# =====================================================================================

function(verify_control_file_build_prerequisites_are_met)

    # Ensure that variable "control_file_logfilepath" is defined.
    if (NOT DEFINED control_file_logfilepath) 
        message (FATAL_ERROR "control_file_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"control_file\" build prerequisities are satisfied.")
    log_message_to_file(${control_file_logfilepath} "---")
    log_message_to_file(${control_file_logfilepath} ${my_message})

    # Again verfying that variable 'control_file_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("control_file_logfilepath" "${control_file_logfilepath}")
    
    # Verfying that variable 'control_file_cmake_c_compiler' is defined.
    anansi_test_variable_is_defined("control_file_cmake_c_compiler"  "${control_file_logfilepath}")

    # Verfying that variable 'control_file_cmake_cxx_compiler' is defined.
    anansi_test_variable_is_defined("control_file_cmake_cxx_compiler"  "${control_file_logfilepath}")

    # Verfying that variable 'control_file_cxx_standard' is defined.
    anansi_test_variable_is_defined("control_file_cxx_standard"  "${control_file_logfilepath}")

    # Verfying that variable 'control_file_install_bin_directory' is defined.
    anansi_test_variable_is_defined("control_file_install_bin_directory"  "${control_file_logfilepath}")

    # Verfying that variable 'control_file_install_include_directory' is defined.
    anansi_test_variable_is_defined("control_file_install_include_directory"  "${control_file_logfilepath}")

    # Verfying that variable 'control_file_install_lib_directory' is defined.
    anansi_test_variable_is_defined("control_file_install_lib_directory"  "${control_file_logfilepath}")

    set(my_message "Package \"control_file\" build prerequisities are satisfied.")
    log_message_to_file(${control_file_logfilepath} ${my_message})
    log_message_to_file(${control_file_logfilepath} "---\n")

endfunction()
