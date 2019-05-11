#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_key_environmental_are_set)
    if (DEFINED $ENV{ANANSI_INSTALL_PREFIX})
        message("ANANSI_INSTALL_PREFIX=$ENV{ANANSI_INSTALL_PREFIX}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_INSTALL_PREFIX is not defined. This \
        variable defines the root location to install anansi." )
    endif()

    if (DEFINED $ENV{ANANSI_INSTALL_BIN_DIRECTORY})
        message("ANANSI_INSTALL_BIN_DIRECTORY=$ENV{ANANSI_INSTALL_BIN_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_INSTALL_BIN_DIRECTORY is not defined. This \
        variable defines the location to install anansi binaries." )
    endif()

    if ( DEFINED $ENV{ANANSI_INSTALL_INCLUDE_DIRECTORY} )
        message("ANANSI_INSTALL_INCLUDE_DIRECTORY=$ENV{ANANSI_INSTALL_INCLUDE_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_INSTALL_INCLUDE_DIRECTORY is not defined. This \
        variable defines the location to install anansi header files." )
    endif()

    if ( DEFINED $ENV{ANANSI_INSTALL_LIB_DIRECTORY} )
        message("ANANSI_INSTALL_LIB_DIRECTORY=$ENV{ANANSI_INSTALL_LIB_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_INSTALL_LIB_DIRECTORY is not defined. This \
        variable defines the location to install anansi libraries." )
    endif()

endfunction()
