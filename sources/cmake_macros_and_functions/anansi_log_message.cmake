
# ===  FUNCTION  ======================================================================
#         Name:  log_message_to_file
#  Description:  Write a message to file by appending the message to the file.
# 
#   Parameters: 
#               filepath : The name of the file to write the message
#               message : The message to be logged to file
#        Return:
# =====================================================================================
function ( log_message_to_file filepath message )

    string(TIMESTAMP my_date) 
    set (log_message "${my_date} : ${message}")
    file (APPEND  ${filepath} ${log_message} )

endfunction()
