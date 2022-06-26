# =====================================================================================
#
#       Filename:  anansi_test_defined_variable.cmake
#
#    Description: Contains convenience functions that help verify the
#                 that variables are defined and inform user of undefined
#                 variables.
#
# =====================================================================================

# ===  FUNCTION  ======================================================================
#         Name:  anansi_test_variable_is_defined
#  Description:  
#   Parameters: variable_name : The name of the varaiable.
#               logfilepath : The path to write the logging message.
#
# =====================================================================================

function(anansi_test_variable_is_defined 
         variable_name
         logfilepath)

    if ( DEFINED "${variable_name}" )
        set ( my_message "${variable_name}=${${variable_name}}")
        message("${my_message}") 
        log_message_to_file("${logfilepath}" "${my_message}")
    else()
        set (my_message "The variable ${variable_name} is not defined.")
        log_message_to_file("${logfilepath}" "Fatal Error: ${my_message}")
        message( FATAL_ERROR "${my_message}" )
    endif()

endfunction()
