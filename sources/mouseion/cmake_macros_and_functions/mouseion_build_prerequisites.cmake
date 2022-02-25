#-----------------------------------------------------
# This function verifies the key environmental       -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_key_environmental_are_set)

    #-----------------------------------------------------
    # Verify environmental variable MOUSEION_TOP_LEVEL is  -
    # defined.                                           -
    #-----------------------------------------------------
    if(DEFINED ENV{MOUSEION_TOP_LEVEL})
        message("MOUSEION_TOP_LEVEL=$ENV{MOUSEION_TOP_LEVEL}")
    else()
        message( FATAL_ERROR "The environmental MOUSEION_TOP_LEVEL is not defined. This \
        variable defines the top level directory of the mouseion package." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_CMAKE_CXX_COMPILER is defined.              -
    #-----------------------------------------------------
    if (DEFINED ENV{MOUSEION_CMAKE_CXX_COMPILER})
        message("MOUSEION_CMAKE_CXX_COMPILER=$ENV{MOUSEION_CMAKE_CXX_COMPILER}")
    else()
        message( FATAL_ERROR "The environmental MOUSEION_CMAKE_CXX_COMPILER is not defined. This \
        variable defines the C++ compiler for compiling mouseion." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_CMAKE_C_COMPILER is defined.                -
    #-----------------------------------------------------
    if (DEFINED ENV{MOUSEION_CMAKE_C_COMPILER})
        message("MOUSEION_CMAKE_C_COMPILER=$ENV{MOUSEION_CMAKE_C_COMPILER}")
    else()
        message( FATAL_ERROR "The environmental MOUSEION_CMAKE_C_COMPILER is not defined. This \
        variable defines the c compiler for compiling mouseion." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_INSTALL_PREFIX  is defined.               -
    #                                                    -
    #-----------------------------------------------------
    if (DEFINED ENV{MOUSEION_INSTALL_PREFIX})
        message("MOUSEION_INSTALL_PREFIX=$ENV{MOUSEION_INSTALL_PREFIX}")
    else()
        message( FATAL_ERROR "The environmental MOUSEION_INSTALL_PREFIX is not defined. This \
        variable defines the root location to install mouseion." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_INSTALL_BIN_DIRECTORY is defined.         -
    #-----------------------------------------------------
    if (DEFINED ENV{MOUSEION_INSTALL_BIN_DIRECTORY})
        message("MOUSEION_INSTALL_BIN_DIRECTORY=$ENV{MOUSEION_INSTALL_BIN_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental MOUSEION_INSTALL_BIN_DIRECTORY is not defined. This \
        variable defines the location to install mouseion binaries." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_INSTALL_INCLUDE_DIRECTORY is defined.     -
    #-----------------------------------------------------
    if ( DEFINED ENV{MOUSEION_INSTALL_INCLUDE_DIRECTORY} )
        message("MOUSEION_INSTALL_INCLUDE_DIRECTORY=$ENV{MOUSEION_INSTALL_INCLUDE_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental MOUSEION_INSTALL_INCLUDE_DIRECTORY is not defined. This \
        variable defines the location to install mouseion header files." )
    endif()

    #-----------------------------------------------------
    # Verify environmental variable                      -
    # MOUSEION_INSTALL_LIB_DIRECTORY is defined.         -
    #-----------------------------------------------------
    if ( DEFINED ENV{MOUSEION_INSTALL_LIB_DIRECTORY} )
        message("MOUSEION_INSTALL_LIB_DIRECTORY=$ENV{MOUSEION_INSTALL_LIB_DIRECTORY}")
    else()
        message( FATAL_ERROR "The environmental MOUSEION_INSTALL_LIB_DIRECTORY is not defined. This \
        variable defines the location to install mouseion libraries." )
    endif()

    #-----------------------------------------------------
    # Verify environment variable                        -
    # MOUSEION_BOOST_TOP_LEVEL is defined.               -
    #-----------------------------------------------------
    if( DEFINED ENV{MOUSEION_BOOST_TOP_LEVEL})
        message("MOUSEION_BOOST_TOP_LEVEL=$ENV{MOUSEION_BOOST_TOP_LEVEL}")
    else()
        message( FATAL_ERROR "The environmental MOUSEION_BOOST_TOP_LEVEL is not defined. This \
        variable defines the location to BOOST top level." )
    endif()

endfunction()
