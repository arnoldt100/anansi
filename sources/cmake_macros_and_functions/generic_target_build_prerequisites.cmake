#-----------------------------------------------------
# This function verifies the variables               -
# variables are defined.                             -
#                                                    -
# Parameters: target_name : The name of the target.  -
#             prerequisite_list : A list of          -
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
    if(NOT DEFINED ${target_name}_logfilepath)
        message( FATAL_ERROR "The variable ${target_name}_logfilepath is not defined.")
    endif()

    foreach( tmp_prerequisite ${${prerequisite_list}})
        anansi_test_variable_is_defined( ${target_name}_${tmp_prerequisite} ${target_name}_logfilepath )
    endforeach()



endfunction()
