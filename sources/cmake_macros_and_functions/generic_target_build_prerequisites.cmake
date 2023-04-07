#-----------------------------------------------------
# This function verifies the variables               -
# variables are defined.                             -
#                                                    -
# Parameters: target_name : The name of the target.  -
#             prerequisite_list : The variable name  -
#             of a list of                           -
#             prerequisites which will be combined   -
#             with the target_name to form the       -
#             to check if defined.                   -
#                                                    -
#-----------------------------------------------------
function(generic_target_build_prerequisites 
         target_name
         prerequisite_list)

    #-----------------------------------------------------
    # Verify variable log file path variable is          -
    # defined.                                           -
    #-----------------------------------------------------

    # ${target_name}_logfilepath is the vraiable name
    # To get the value of the file path do ${${target_name}_logfilepath}
    if(NOT DEFINED ${target_name}_logfilepath)
        message( FATAL_ERROR "The variable ${target_name}_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"${target_name}\" build prerequisities are satisfied.")
    log_message_to_file(${${target_name}_logfilepath} "---")
    log_message_to_file(${${target_name}_logfilepath} ${my_message})

    foreach( tmp_prerequisite ${${prerequisite_list}})
        anansi_test_variable_is_defined( "${target_name}_${tmp_prerequisite}" "${${target_name}_logfilepath}" )
    endforeach()

    set(my_message "Package \"${target_name}\" build prerequisities are satisfied.")
    log_message_to_file( ${${target_name}_logfilepath} ${my_message} )
    log_message_to_file( ${${target_name}_logfilepath} "---\n")



endfunction()