 # =====================================================================================
 #
 #       Filename:  command_line_arguments_build_prerequisites.cmake
 #
 #    Description:  This function verifies the build prerequisites for package 
 #                  command_line_arguments are met.
 #
 # =====================================================================================

#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_command_line_arguments_build_prerequisites_are_set)


    # Ensure that variable "command_line_arguments_logfilepath" is defined.
    if (NOT DEFINED command_line_arguments_logfilepath) 
        message (FATAL_ERROR "command_line_arguments_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"command_line_arguments' build prerequisities\" are satisfied.")
    log_message_to_file( ${command_line_arguments_logfilepath} "---")
    log_message_to_file( ${command_line_arguments_logfilepath} ${my_message})

    # Again verfying that variable 'command_line_arguments_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("command_line_arguments_logfilepath" "${command_line_arguments_logfilepath}")

    # Verify variable command_line_arguments_install_lib_directory is defined,
    anansi_test_variable_is_defined("command_line_arguments_install_lib_directory" "${command_line_arguments_logfilepath}")

    # Verify variable command_line_arguments_install_include_directory defined.
    anansi_test_variable_is_defined("command_line_arguments_install_include_directory" "${command_line_arguments_logfilepath}")

    # Verify variable command_line_arguments_install_bin_directory defined.
    anansi_test_variable_is_defined("command_line_arguments_install_bin_directory" "${command_line_arguments_logfilepath}")

    # Verify variable command_line_arguments_cxx_standard defined.
    anansi_test_variable_is_defined("command_line_arguments_cxx_standard" "${command_line_arguments_logfilepath}")

    set(my_message "Package \"command_line_arguments' build prerequisities\" are satisfied.")
    log_message_to_file( ${command_line_arguments_logfilepath} ${my_message})
    log_message_to_file( ${command_line_arguments_logfilepath} "---\n")

endfunction()
