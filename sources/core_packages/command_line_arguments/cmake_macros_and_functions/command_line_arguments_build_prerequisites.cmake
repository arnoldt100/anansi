#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_command_line_arguments_build_prerequisites_are_set)

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # command_line_arguments_install_lib_directory       -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED command_line_arguments_install_lib_directory)
        set(log_message "command_line_arguments_install_lib_directory=${command_line_arguments_install_lib_directory}\n")
        file(APPEND ${anansi_log_file} "${log_message}")
    else()
        message( FATAL_ERROR "The variable command_line_arguments_install_lib_directory is not defined. This \
        variable defines the directory to install the library command_line_arguments." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # command_line_arguments_install_include_directory   -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED command_line_arguments_install_include_directory)
        set(log_message "command_line_arguments_install_include_directory=${command_line_arguments_install_include_directory}\n")
        file(APPEND ${anansi_log_file} "${log_message}")
    else()
        message( FATAL_ERROR "The variable command_line_arguments_install_include_directory is not defined. This \
        variable defines the directory to install the header files for command_line_arguments." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # command_line_arguments_install_bin_directory       -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED command_line_arguments_install_bin_directory)
        set(log_message "command_line_arguments_install_bin_directory=${command_line_arguments_install_bin_directory}\n")
        file(APPEND ${anansi_log_file} "${log_message}")
    else()
        message( FATAL_ERROR "The variable command_line_arguments_install_bin_directory is not defined. This \
        variable defines the directory to install the header files for command_line_arguments." )
    endif()


endfunction()
