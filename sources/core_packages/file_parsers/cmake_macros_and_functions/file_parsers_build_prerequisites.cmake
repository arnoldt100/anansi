# =====================================================================================
#
#       Filename:  file_parsers_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the package file_parsers
#                  are satisfied.
#
# =====================================================================================

function(verify_file_parsers_build_prerequisites_are_met)

    # Ensure that variable "file_parsers_logfilepath" is defined.
    if (NOT DEFINED file_parsers_logfilepath) 
        message (FATAL_ERROR "file_parsers_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"file_parsers\" build prerequisities are satisfied.")
    log_message_to_file(${file_parsers_logfilepath} "---")
    log_message_to_file(${file_parsers_logfilepath} ${my_message})

    # Again verfying that variable 'file_parsers_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("file_parsers_logfilepath" "${file_parsers_logfilepath}")
    
    # Verfying that variable 'file_parsers_cmake_c_compiler' is defined.
    anansi_test_variable_is_defined("file_parsers_cmake_c_compiler"  "${file_parsers_logfilepath}")

    # Verfying that variable 'file_parsers_cmake_cxx_compiler' is defined.
    anansi_test_variable_is_defined("file_parsers_cmake_cxx_compiler"  "${file_parsers_logfilepath}")

    # Verfying that variable 'file_parsers_cxx_standard' is defined.
    anansi_test_variable_is_defined("file_parsers_cxx_standard"  "${file_parsers_logfilepath}")

    # Verfying that variable 'file_parsers_install_bin_directory' is defined.
    anansi_test_variable_is_defined("file_parsers_install_bin_directory"  "${file_parsers_logfilepath}")

    # Verfying that variable 'file_parsers_install_include_directory' is defined.
    anansi_test_variable_is_defined("file_parsers_install_include_directory"  "${file_parsers_logfilepath}")

    # Verfying that variable 'file_parsers_install_lib_directory' is defined.
    anansi_test_variable_is_defined("file_parsers_install_lib_directory"  "${file_parsers_logfilepath}")

    set(my_message "Package \"file_parsers\" build prerequisities are satisfied.")
    log_message_to_file(${file_parsers_logfilepath} ${my_message})
    log_message_to_file(${file_parsers_logfilepath} "---\n")

endfunction()
