#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_key_environmental_are_set)

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # mpi_communicator_install_lib_directory             -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED mpi_communicator_install_lib_directory)
        set(log_message "mpi_communicator_install_lib_directory=${mpi_communicator_install_lib_directory}\n")
        file(APPEND ${mouseion_log_file} "${log_message}")
    else()
        message( FATAL_ERROR "The variable mpi_communicator_install_lib_directory is not defined. This \
        variable defines the directory to install the library mpi_communicator." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # mpi_communicator_install_include_directory         -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED mpi_communicator_install_include_directory)
        set(log_message "mpi_communicator_install_include_directory=${mpi_communicator_install_include_directory}\n")
        file(APPEND ${mouseion_log_file} "${log_message}")
    else()
        message( FATAL_ERROR "The variable mpi_communicator_install_include_directory is not defined. This \
        variable defines the directory to install the header files for mpi_communicator." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # mpi_communicator_install_bin_directory             -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED mpi_communicator_install_bin_directory)
        set(log_message "mpi_communicator_install_bin_directory=${mpi_communicator_install_bin_directory}\n")
        file(APPEND ${mouseion_log_file} "${log_message}")
    else()
        message( FATAL_ERROR "The variable mpi_communicator_install_bin_directory is not defined. This \
        variable defines the directory to install the header files for mpi_communicator." )
    endif()


endfunction()
