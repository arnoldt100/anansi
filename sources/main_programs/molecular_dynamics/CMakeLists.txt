#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "anansi_md")
    project(anansi_${my_project_name})

    #-----------------------------------------------------
    # Define the variable my_target_binary.              -
    # This variable stores the name of binary.           -
    #                                                    -
    #-----------------------------------------------------
    string(TOLOWER ${PROJECT_NAME} my_target_binary)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Here we define the sources and header files associated          @
# with the anansi_md targets.                                     @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_md_public_headers that stores header files  -
    # associated with the anansi_md target.              -
    #                                                    -
    #-----------------------------------------------------
    set(anansi_md_public_headers 
        header_files/anansi_md.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_md_public_implementation that stores        -
    # implementation files associated with the anansi_md -
    # target.                                            -
    #                                                    -
    #-----------------------------------------------------
    set(anansi_md_public_implementation
        implementation_files/anansi_md.cpp )

    #-----------------------------------------------------
    # Add the directory header_files to search for       -
    # header files.                                      -
    #                                                    -
    #-----------------------------------------------------
    include_directories( header_files )
 
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the anansi_md targets.                                     @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Start of section that adds the executable target.               @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
#                                                    -
#                                                    -
#-----------------------------------------------------
add_execurable( ${my_target_binary}
                ${anansi_md_public_implementation} )


