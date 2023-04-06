# =====================================================================================
#
#       Filename:  receiver_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the package receiver
#                  are satisfied.
#
# =====================================================================================

function(verify_receiver_build_prerequisites_are_met)

    # Ensure that variable "receiver_logfilepath" is defined.
    if (NOT DEFINED receiver_logfilepath) 
        message (FATAL_ERROR "receiver_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"receiver\" build prerequisities are satisfied.")
    log_message_to_file(${receiver_logfilepath} "---")
    log_message_to_file(${receiver_logfilepath} ${my_message})

    # Again verfying that variable 'receiver_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("receiver_logfilepath" "${receiver_logfilepath}")

    # Verfying that variable 'receiver_cxx_standard' is defined.
    anansi_test_variable_is_defined("receiver_cxx_standard"  "${receiver_logfilepath}")

    # Verfying that variable 'receiver_install_bin_directory' is defined.
    anansi_test_variable_is_defined("receiver_install_bin_directory"  "${receiver_logfilepath}")

    # Verfying that variable 'receiver_install_include_directory' is defined.
    anansi_test_variable_is_defined("receiver_install_include_directory"  "${receiver_logfilepath}")

    # Verfying that variable 'receiver_cmake_c_compiler' is defined.
    anansi_test_variable_is_defined("receiver_cmake_c_compiler"  "${receiver_logfilepath}")

    # Verfying that variable 'receiver_cmake_cxx_compiler' is defined.
    anansi_test_variable_is_defined("receiver_cmake_cxx_compiler"  "${receiver_logfilepath}")

    # Verfying that variable 'receiver_install_lib_directory' is defined.
    anansi_test_variable_is_defined("receiver_install_lib_directory"  "${receiver_logfilepath}")

    set(my_message "Package \"receiver\" build prerequisities are satisfied.")
    log_message_to_file(${receiver_logfilepath} ${my_message})
    log_message_to_file(${receiver_logfilepath} "---\n")

endfunction()
