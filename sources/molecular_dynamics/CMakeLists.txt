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
    string(TOLOWER ${PROJECT_NAME}_md my_main_target_binary)

    #-----------------------------------------------------
    # Define the variable anansi.                        -
    # This variable stores the name if the anansi md     -
    # target.                                            -
    #                                                    -
    #-----------------------------------------------------
    string(TOLOWER ${PROJECT_NAME} my_anansi_md_library)

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property(mm_include_dir memory_management memory_management_include)
    get_target_property(command_line_include_dir command_line_arguments command_line_arguments_include)
    get_target_property(simulation_parameters_include_dir simulation_parameters simulation_parameters_include)

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
        header_files/AnansiMolecularDynamics.h
        header_files/MolecularDynamics.h 
        header_files/MolecularDynamicsFactory.h 
        header_files/AnansiMolecularDynamicsFactory.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_md_library_implementation associated with   -
    # the molecular dynamics library                     -
    #                                                    -
    #-----------------------------------------------------
    set (anansi_md_library_implementation  
        implementation_files/AnansiMolecularDynamics.cpp
        implementation_files/MolecularDynamics.cpp
        implementation_files/MolecularDynamicsFactory.cpp
        implementation_files/AnansiMolecularDynamicsFactory.cpp)

 
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
             "" )

target_sources(${my_anansi_md_library}
               PRIVATE ${anansi_md_library_implementation} ${anansi_md_library_headers}  )

#-----------------------------------------------------
# Set the list of directories to search for          -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories( ${my_anansi_md_library} 
                            PUBLIC header_files
                            PRIVATE ${Boost_INCLUDE_DIR} )

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${my_anansi_md_library}
                      memory_management 
                      mpi_communicator
                      simulation_parameters
                      command_line_arguments
                      ${Boost_LIBRARIES} )

#-----------------------------------------------------
# Here we set the propertes on target.               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${my_anansi_md_library} PROPERTIES 
    PUBLIC_HEADER "${anansi_md_library_headers}" 
    CXX_STANDARD ${anansi_cxx_standard} )

install( TARGETS ${my_anansi_md_library}
         ARCHIVE DESTINATION ${anansi_install_lib_directory}
         PUBLIC_HEADER DESTINATION ${anansi_install_include_directory} )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Start of section that adds the main binary target.              @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

add_executable( ${my_main_target_binary}
                "" )

target_sources(${my_main_target_binary}
               PRIVATE ${anansi_main_md_public_implementation} ${anansi_main_md_public_headers} )

target_include_directories( ${my_main_target_binary} 
                            PUBLIC header_files 
                            PRIVATE ${Boost_INCLUDE_DIR} )

target_link_libraries(${my_main_target_binary}
                      PRIVATE ${my_anansi_md_library} 
                      command_line_arguments
                      simulation_parameters
                      mpi_communicator
                      memory_management 
                      string_utilities 
                      ${Boost_LIBRARIES} )

                  
set_target_properties(${my_main_target_binary} PROPERTIES
                      CXX_STANDARD ${anansi_cxx_standard} )

install( TARGETS ${my_main_target_binary} 
         RUNTIME DESTINATION ${anansi_install_bin_directory} )
                     


#-----------------------------------------------------
# Add the unit tests.                                -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
