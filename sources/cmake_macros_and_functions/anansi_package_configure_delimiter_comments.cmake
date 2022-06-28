# =====================================================================================
#
#       Filename:  anansi_package_configure_delimiter_comments.cmake
#
#    Description:  Contains convenience functions for writing begin and 
#                  emd delimiting comments for configuring a package.
#
# =====================================================================================

# ===  FUNCTION  ======================================================================
#         Name:  package_config_begin_delimiter
#  Description:  Write the begin delimiter comments for configuring a package.
# 
#   Parameters: 
#               package_name : The name of the package being configured.
#               filepath : The name of the file to write the message.
# =====================================================================================
function ( package_config_begin_delimiter package_name filepath )

    log_message_to_file(${filepath} "===")
    set(my_message "Configuring package ${package_name}...\n")
    log_message_to_file(${filepath} ${my_message})

endfunction()



# ===  FUNCTION  ======================================================================
#         Name:  package_config_end_delimiter
#  Description:  Write the end delimiter comments for configuring a package.
# 
#   Parameters: 
#               package_name : The name of the package being configured.
#               filepath : The name of the file to write the message.
# =====================================================================================
function ( package_config_end_delimiter package_name filepath )

    set(my_message "Completed configuring package ${package_name}.")
    log_message_to_file(${filepath} ${my_message})
    log_message_to_file(${filepath} "===\n")

endfunction()
