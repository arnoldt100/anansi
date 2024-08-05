# =====================================================================================
#
#       Filename:  dataandexecutionpolicies_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the package dataandexecutionpolicies
#                  are satisfied.
#
# =====================================================================================

function(verify_dataandexecutionpolicies_build_prerequisites_are_met)

    # Ensure that variable "dataandexecutionpolicies_logfilepath" is defined.
    if (NOT DEFINED dataandexecutionpolicies_logfilepath) 
        message (FATAL_ERROR "dataandexecutionpolicies_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"dataandexecutionpolicies\" build prerequisities are satisfied.")
    log_message_to_file(${dataandexecutionpolicies_logfilepath} "---")
    log_message_to_file(${dataandexecutionpolicies_logfilepath} ${my_message})

    # Again verfying that variable 'dataandexecutionpolicies_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("dataandexecutionpolicies_logfilepath" "${dataandexecutionpolicies_logfilepath}")
 
    # Verfying that variable 'dataandexecutionpolicies_cmake_c_compiler' is defined.
    anansi_test_variable_is_defined("dataandexecutionpolicies_cmake_c_compiler"  "${dataandexecutionpolicies_logfilepath}")

    # Verfying that variable 'dataandexecutionpolicies_cmake_cxx_compiler' is defined.
    anansi_test_variable_is_defined("dataandexecutionpolicies_cmake_cxx_compiler"  "${dataandexecutionpolicies_logfilepath}")

    # Verfying that variable 'dataandexecutionpolicies_cxx_standard' is defined.
    anansi_test_variable_is_defined("dataandexecutionpolicies_cxx_standard"  "${dataandexecutionpolicies_logfilepath}")

    # Verfying that variable 'dataandexecutionpolicies_install_bin_directory' is defined.
    anansi_test_variable_is_defined("dataandexecutionpolicies_install_bin_directory"  "${dataandexecutionpolicies_logfilepath}")

    # Verfying that variable 'dataandexecutionpolicies_install_include_directory' is defined.
    anansi_test_variable_is_defined("dataandexecutionpolicies_install_include_directory"  "${dataandexecutionpolicies_logfilepath}")

    # Verfying that variable 'dataandexecutionpolicies_install_lib_directory' is defined.
    anansi_test_variable_is_defined("dataandexecutionpolicies_install_lib_directory"  "${dataandexecutionpolicies_logfilepath}")

    set(my_message "Package \"dataandexecutionpolicies\" build prerequisities are satisfied.")
    log_message_to_file(${dataandexecutionpolicies_logfilepath} ${my_message})
    log_message_to_file(${dataandexecutionpolicies_logfilepath} "---\n")

endfunction()

