# =====================================================================================
#
#       Filename:  invoker_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the package invoker
#                  are satisfied.
#
# =====================================================================================

function(verify_invoker_build_prerequisites_are_met)

    # Ensure that variable "invoker_logfilepath" is defined.
    if (NOT DEFINED invoker_logfilepath) 
        message (FATAL_ERROR "invoker_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"invoker\" build prerequisities are satisfied.")
    log_message_to_file(${invoker_logfilepath} "---")
    log_message_to_file(${invoker_logfilepath} ${my_message})

    # Again verfying that variable 'invoker_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("invoker_logfilepath" "${invoker_logfilepath}")

    # Verfying that variable 'invoker_cxx_standard' is defined.
    anansi_test_variable_is_defined("invoker_cxx_standard"  "${invoker_logfilepath}")

    # Verfying that variable 'invoker_install_bin_directory' is defined.
    anansi_test_variable_is_defined("invoker_install_bin_directory"  "${invoker_logfilepath}")

    # Verfying that variable 'invoker_install_include_directory' is defined.
    anansi_test_variable_is_defined("invoker_install_include_directory"  "${invoker_logfilepath}")

    # Verfying that variable 'invoker_install_lib_directory' is defined.
    anansi_test_variable_is_defined("invoker_install_lib_directory"  "${invoker_logfilepath}")

    set(my_message "Package \"invoker\" build prerequisities are satisfied.")
    log_message_to_file(${invoker_logfilepath} ${my_message})
    log_message_to_file(${invoker_logfilepath} "---\n")

endfunction()

