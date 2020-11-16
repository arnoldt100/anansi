#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_key_environmental_are_set)

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # string_utilities_install_lib_directory             -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED string_utilities_install_lib_directory)
        set(log_message "string_utilities_install_lib_directory=${string_utilities_install_lib_directory}\n")
        file(APPEND ${anansi_log_file} "${log_message}")
    else()
        message( FATAL_ERROR "The variable string_utilities_install_lib_directory is not defined. This \
        variable defines the directory to install the library string_utilities." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # string_utilities_install_include_directory         -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED string_utilities_install_include_directory)
        set(log_message "string_utilities_install_include_directory=${string_utilities_install_include_directory}\n")
        file(APPEND ${anansi_log_file} "${log_message}")
    else()
        message( FATAL_ERROR "The variable string_utilities_install_include_directory is not defined. This \
        variable defines the directory to install the header files for string_utilities." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # string_utilities_install_bin_directory             -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED string_utilities_install_bin_directory)
        set(log_message "string_utilities_install_bin_directory=${string_utilities_install_bin_directory}\n")
        file(APPEND ${anansi_log_file} "${log_message}")
    else()
        message( FATAL_ERROR "The variable string_utilities_install_bin_directory is not defined. This \
        variable defines the directory to install the header files for string_utilities." )
    endif()


endfunction()
