# =====================================================================================
#
#       Filename:  readcontrolfile_build_prerequisites.cmake
#
#    Description: Contains convenience functions that help verify the
#                 prerequisites for building target readcontrolfile
#                 are satisfied.
#
#
# =====================================================================================


# ===  FUNCTION  ======================================================================
#         Name:  verify_readcontrolfile_build_prerequisites_are_met
#  Description:  Verifies that key variables that control the building and installation
#                of the package readcontrolfile.
# 
#   Parameters: 
#
#        Return:
# =====================================================================================
function(verify_readcontrolfile_build_prerequisites_are_met)

    # Ensure that variable "readcontrolfile_logfilepath" is defined.
    if (NOT DEFINED readcontrolfile_logfilepath) 
        message (FATAL_ERROR "readcontrolfile_logfilepath is not defined.")
    endif()

    set(my_message "Verifying \"readcontrolfile' build prerequisites\" are satisfied.")
    log_message_to_file( ${readcontrolfile_logfilepath} "---")
    log_message_to_file( ${readcontrolfile_logfilepath} ${my_message})

    # Again verfying that variable 'readcontrolfile_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("readcontrolfile_logfilepath" "${readcontrolfile_logfilepath}")

    # Verfying that variable 'readcontrolfile_cxx_standard' is defined.
    anansi_test_variable_is_defined("readcontrolfile_cxx_standard"  "${readcontrolfile_logfilepath}")

    # Verfying that variable 'readcontrolfile_install_bin_directory' is defined.
    anansi_test_variable_is_defined("readcontrolfile_install_bin_directory"  "${readcontrolfile_logfilepath}")

    # Verfying that variable 'readcontrolfile_install_include_directory' is defined.
    anansi_test_variable_is_defined("readcontrolfile_install_include_directory"  "${readcontrolfile_logfilepath}")

    # Verfying that variable 'readcontrolfile_install_lib_directory' is defined.
    anansi_test_variable_is_defined("readcontrolfile_install_lib_directory"  "${readcontrolfile_logfilepath}")

    set(my_message "Package \"readcontrolfile' build prerequisities\" are satisfied.")
    log_message_to_file( ${readcontrolfile_logfilepath} ${my_message})
    log_message_to_file( ${readcontrolfile_logfilepath} "---\n")
endfunction(verify_readcontrolfile_build_prerequisites_are_met)
