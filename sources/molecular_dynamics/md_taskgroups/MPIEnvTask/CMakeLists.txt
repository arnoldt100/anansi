# This CMakeLists.txt file creates the library libmpienvtask.a
# and its unit tests. To add source files, simply append the appropiate variable
# mpienvtask_header_files or mpienvtask_implementation_files.
#
# The target for the library is mpienvtask.
#
# The following properties are set for the target mpienvtask.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
# mpienvtask_include         ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
# PUBLIC_HEADER              ${mpienvtask_header_files}                        The list of headers files associated with this librarry.


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "mpienvtask")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Define the property name for the include directory.
    # 
    #-----------------------------------------------------
    set(my_target_include_property_name "mpienvtask_include" )

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
    # command_line_arguments_header_files.               -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (mpienvtask_header_files
         header_files/MPIEnvReceiver.h 
         header_files/MPIEnvironmentTraits.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (mpienvtask_implementation_files
        implementation_files/MPIEnvReceiver.cpp 
        implementation_files/MPIEnvironmentTraits.cpp )

    # -----------------------------------------------------
    # Set various variables for include directories.
    # 
    # -----------------------------------------------------
    get_target_property(my_tasks_include tasks tasks_include)
    get_target_property(my_command_line_arguments_include command_line_arguments command_line_arguments_include )
    get_target_property(my_mpi_communicator_include mpi_communicator mpi_communicator_include)
    get_target_property(my_receiver_include receiver receiver_include )
    get_target_property(my_genericmdtask_include genericmdtask genericmdtask_include)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# mpienvtask                                         -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
             "")

add_dependencies(${target} 
                 command_line_arguments
                 tasks
                 mpi_communicator
                 receiver)

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
    PRIVATE ${mpienvtask_header_files} ${mpienvtask_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${my_mpi_communicator_include}
                           PRIVATE ${my_tasks_include}
                           PRIVATE ${my_genericmdtask_include}
                           PRIVATE ${my_command_line_arguments_include} 
                           PRIVATE ${my_receiver_include})

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${target}
                      PUBLIC mpi_communicator
                      PUBLIC tasks
                      PUBLIC genericmdtask
                      PUBLIC command_line_arguments 
                      PUBLIC receiver)

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
# Here we set the properties on target 
# 
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      "${my_target_include_property_name}" ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      PUBLIC_HEADER "${mpienvtask_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${md_taskgroups_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${md_taskgroups_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
