#-----------------------------------------------------
# This function verifies the key                     -
# variables are set.                                 -
#                                                    -
#                                                    -
#-----------------------------------------------------
function(verify_key_variables_are_set)

    #-----------------------------------------------------
    # Verify variable file_parsers_install_lib_directory -
    # is defined.                                        -
    #-----------------------------------------------------
    if(NOT DEFINED file_parsers_install_lib_directory)
        message( FATAL_ERROR "The variable file_parsers_install_lib_directory is not defined. This \
        variable defines the install directory of the file_parsers library." )
    endif()

    #-----------------------------------------------------
    # Verify variable                                    -
    # file_parsers_install_include_directory is defined. -
    #-----------------------------------------------------
    if ( NOT DEFINED file_parsers_install_include_directory )
        message( FATAL_ERROR "The variable file_parsers_install_include_directory is not defined. This \
        variable defines the install directory of the file_parser header files." )
    endif()

    #-----------------------------------------------------
    # Verify variable                                    -
    # file_parsers_install_bin_directory is defined.     -
    #-----------------------------------------------------
    if ( NOT DEFINED file_parsers_install_bin_directory )
        message( FATAL_ERROR "The variable file_parsers_install_bin_directory is not defined. This \
        variable defines the install directory of the unit tests associated file_parser library." )
    endif()
endfunction()
