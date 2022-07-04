# This CMakeLists.txt file creates the program molecular_dynamics_main.
# and its unit tests. To add source files, simply append the appropiate variable
# molecular_dynamics_main_header_files or molecular_dynamics_main_implementation_files.
#
# The target for the executable is molecular_dynamics_main.
#
# The following properties are set for the target molecular_dynamics_main.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "molecular_dynamics_main")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------

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
    # Here we define the variable
    # molecular_dynamics_main_public_headers that stores header
    # files associated with the molecular_dynamics_main target.
    #  
    #-----------------------------------------------------
    set(molecular_dynamics_main_public_headers 
        header_files/anansi_main_md.h )

    #-----------------------------------------------------
    # Here we define the variable molecular_dynamics_main_public_implementation that
    # stores implementation files associated with the molecular_dynamics_main target.
    # 
    #
    #-----------------------------------------------------
    set(molecular_dynamics_main_public_implementation
        implementation_files/anansi_main_md.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Start of section that adds the main binary target.              @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

add_executable( ${target}
                "" )

add_dependencies(${target} 
                 ${my_molecular_dynamics_main_library})

target_sources(${target}
               PRIVATE ${molecular_dynamics_main_public_implementation} 
               PRIVATE ${molecular_dynamics_main_public_headers} )

target_include_directories( ${target} 
                            PUBLIC header_files 
                            PRIVATE ${Boost_INCLUDE_DIR} )

target_link_libraries(${target}
                      PRIVATE ${my_molecular_dynamics_main_library} )

                  
set_target_properties(${target} PROPERTIES
                      CXX_STANDARD ${anansi_cxx_standard} )

install( TARGETS ${target} 
         RUNTIME DESTINATION ${anansi_install_bin_directory} )
                     

#-----------------------------------------------------
# Add the unit tests.                                -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
