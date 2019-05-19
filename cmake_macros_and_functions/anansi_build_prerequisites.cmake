#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_key_environmental_are_set)

    #-----------------------------------------------------
    # Verify environmental variable ANANSI_TOP_LEVEL is  -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED ENV{ANANSI_TOP_LEVEL})
        message("ANANSI_TOP_LEVEL=$ENV{ANANSI_TOP_LEVEL}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_TOP_LEVEL is not defined. This \
        variable defines the top level directory of the anansi package." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # ANANSI_CMAKE_CXX_COMPILER is defined.              -
    #-----------------------------------------------------
    if (DEFINED ENV{ANANSI_CMAKE_CXX_COMPILER})
        message("ANANSI_CMAKE_CXX_COMPILER=$ENV{ANANSI_CMAKE_CXX_COMPILER}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_CMAKE_CXX_COMPILER is not defined. This \
        variable defines the C++ compiler for compiling anansi." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # ANANSI_CMAKE_C_COMPILER is defined.                -
    #-----------------------------------------------------
    if (DEFINED ENV{ANANSI_CMAKE_C_COMPILER})
        message("ANANSI_CMAKE_C_COMPILER=$ENV{ANANSI_CMAKE_C_COMPILER}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_CMAKE_C_COMPILER is not defined. This \
        variable defines the c compiler for compiling anansi." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable ANANSI_INSTALL_PREFIX-
    # is defined.                                        -
    #-----------------------------------------------------
    if (DEFINED ENV{ANANSI_INSTALL_PREFIX})
        message("ANANSI_INSTALL_PREFIX=$ENV{ANANSI_INSTALL_PREFIX}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_INSTALL_PREFIX is not defined. This \
        variable defines the root location to install anansi." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # ANANSI_INSTALL_BIN_DIRECTORY is defined.           -
    #-----------------------------------------------------
    if (DEFINED ENV{ANANSI_INSTALL_BIN_DIRECTORY})
        message("ANANSI_INSTALL_BIN_DIRECTORY=$ENV{ANANSI_INSTALL_BIN_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_INSTALL_BIN_DIRECTORY is not defined. This \
        variable defines the location to install anansi binaries." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # ANANSI_INSTALL_INCLUDE_DIRECTORY is defined.       -
    #-----------------------------------------------------
    if ( DEFINED ENV{ANANSI_INSTALL_INCLUDE_DIRECTORY} )
        message("ANANSI_INSTALL_INCLUDE_DIRECTORY=$ENV{ANANSI_INSTALL_INCLUDE_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_INSTALL_INCLUDE_DIRECTORY is not defined. This \
        variable defines the location to install anansi header files." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # ANANSI_INSTALL_LIB_DIRECTORY is defined.           -
    #-----------------------------------------------------
    if ( DEFINED ENV{ANANSI_INSTALL_LIB_DIRECTORY} )
        message("ANANSI_INSTALL_LIB_DIRECTORY=$ENV{ANANSI_INSTALL_LIB_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_INSTALL_LIB_DIRECTORY is not defined. This \
        variable defines the location to install anansi libraries." )
    endif()

    #-----------------------------------------------------
    # Verify environment variable                        -
    # ANANSI_BOOST_TOP_LEVEL is defined.                 -
    #-----------------------------------------------------
    if( DEFINED ENV{ANANSI_BOOST_TOP_LEVEL})
        message("ANANSI_BOOST_TOP_LEVEL=$ENV{ANANSI_BOOST_TOP_LEVEL}")
    else()
        message( FATAL_ERROR "The environmental ANANSI_BOOST_TOP_LEVEL is not defined. This \
        variable defines the location to BOOST top level." )
    endif()

endfunction()
