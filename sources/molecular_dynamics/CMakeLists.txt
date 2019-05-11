#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "anansi")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the variable my_main_target_binary.         -
    # This variable stores the name of main md binary.   -
    #                                                    -
    #-----------------------------------------------------
    string(TOLOWER ${PROJECT_NAME}_main_md my_main_target_binary)

    #-----------------------------------------------------
    # Define the variable anansi.                        -
    # This variable stores the name if the anansi md     -
    # target.                                            -
    #                                                    -
    #-----------------------------------------------------
    string(TOLOWER ${PROJECT_NAME} my_anansi_md_library)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Here we define the sources and header files associated          @
# with the various targets.                                       @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_main_md_public_headers that stores header   -
    # files associated with the anansi_main_md target.   -
    #                                                    -
    #-----------------------------------------------------
    set(anansi_main_md_public_headers 
        header_files/anansi_main_md.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_main_md_public_implementation that stores   -
    # implementation files associated with the           -
    # anansi_main_md target.                             -
    #                                                    -
    #-----------------------------------------------------
    set(anansi_main_md_public_implementation
        implementation_files/anansi_main_md.cpp )

    
    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_md_library_headers associated with the      -
    # molecular dynamics library                         -
    #                                                    -
    #-----------------------------------------------------
    set (anansi_md_library_headers  
         header_files/anansi_molecular_dynamics.h
         header_files/MolecularDynamics.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_md_library_implementation associated with   -
    # the molecular dynamics library                     -
    #                                                    -
    #-----------------------------------------------------
    set (anansi_md_library_implementation  
         implementation_files/anansi_molecular_dynamics.cpp
         implementation_files/MolecularDynamics.cpp )

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
# Start of section that adds the anansi libray target.            @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the  library target called from the source     -
# files listed in the command invocation.            -
#                                                    -
#-----------------------------------------------------
add_library( ${my_anansi_md_library} STATIC 
             ${anansi_md_library_implementation} )

#-----------------------------------------------------
# Here we set the PUBLIC_HEADER property on target   -
# errors_and_exceptions. This property will define   -
# the header files associated with the               -
# with the errors_and_exceptions library.            -
#                                                    -
#-----------------------------------------------------
set_target_properties(${my_anansi_md_library} PROPERTIES
                      PUBLIC_HEADER "${anansi_md_library_headers}" )
       
install( TARGETS ${my_anansi_md_library}
         ARCHIVE DESTINATION ${anansi_install_lib_directory}
         PUBLIC_HEADER DESTINATION ${anansi_install_include_directory} )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Start of section that adds the main binary target.              @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
#                                                    -
#                                                    -
#-----------------------------------------------------
add_executable( ${my_main_target_binary}
                ${anansi_main_md_public_implementation} )

install ( TARGETS ${my_main_target_binary} 
          RUNTIME DESTINATION ${anansi_install_bin_directory} )
                     


