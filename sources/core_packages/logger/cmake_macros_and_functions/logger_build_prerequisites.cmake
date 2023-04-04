# =====================================================================================
#
#       Filename:  logger_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building subpackages of logger
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_logger_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package logger.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_logger_build_prerequisites_are_met)

    # Ensure that variable "logger_logfilepath" is defined.
    if (NOT DEFINED logger_logfilepath) 
        message (FATAL_ERROR "logger_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"logger' build prerequisites\" are satisfied.")
    log_message_to_file( ${logger_logfilepath} "---")
    log_message_to_file( ${logger_logfilepath} ${my_message})

    # Again verfying that variable 'logger_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("logger_logfilepath" "${logger_logfilepath}")

    # Verfying that variable 'logger_cxx_standard' is defined.
    anansi_test_variable_is_defined("logger_cxx_standard"  "${logger_logfilepath}")

    # Verfying that variable 'logger_install_bin_directory' is defined.
    anansi_test_variable_is_defined("logger_install_bin_directory"  "${logger_logfilepath}")

    # Verfying that variable 'logger_install_include_directory' is defined.
    anansi_test_variable_is_defined("logger_install_include_directory"  "${logger_logfilepath}")

    # Verfying that variable 'logger_install_lib_directory' is defined.
    anansi_test_variable_is_defined("logger_install_lib_directory"  "${logger_logfilepath}")

    set(my_message "Package \"logger' build prerequisities\" are satisfied.")
    log_message_to_file( ${logger_logfilepath} ${my_message})
    log_message_to_file( ${logger_logfilepath} "---\n")
endfunction(verify_logger_build_prerequisites_are_met)
