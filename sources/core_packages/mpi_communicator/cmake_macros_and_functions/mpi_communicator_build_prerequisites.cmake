# =====================================================================================
#
#       Filename:  mpi_communicator_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the  package mpi_communicator
#                  are satisfied.
#
# =====================================================================================

function(verify_mpi_communicator_build_prerequisites_are_met)

    # Ensure that variable "mpi_communicator_logfilepath" is defined.
    if (NOT DEFINED mpi_communicator_logfilepath) 
        message (FATAL_ERROR "mpi_communicator_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"mpi_communicator\" build prerequisities are satisfied.")
    log_message_to_file(${mpi_communicator_logfilepath} "---")
    log_message_to_file(${mpi_communicator_logfilepath} ${my_message})

    # Again verfying that variable 'mpi_communicator_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("mpi_communicator_logfilepath" "${mpi_communicator_logfilepath}")

    # Verfying that variable 'mpi_communicator_cxx_standard' is defined.
    anansi_test_variable_is_defined("mpi_communicator_cxx_standard"  "${mpi_communicator_logfilepath}")

    # Verfying that variable 'mpi_communicator_install_bin_directory' is defined.
    anansi_test_variable_is_defined("mpi_communicator_install_bin_directory"  "${mpi_communicator_logfilepath}")

    # Verfying that variable 'mpi_communicator_install_include_directory' is defined.
    anansi_test_variable_is_defined("mpi_communicator_install_include_directory"  "${mpi_communicator_logfilepath}")

    # Verfying that variable 'mpi_communicator_install_lib_directory' is defined.
    anansi_test_variable_is_defined("mpi_communicator_install_lib_directory"  "${mpi_communicator_logfilepath}")

    set(my_message "Package \"mpi_communicator\" build prerequisities are satisfied.")
    log_message_to_file(${mpi_communicator_logfilepath} ${my_message})
    log_message_to_file(${mpi_communicator_logfilepath} "---\n")

endfunction()
