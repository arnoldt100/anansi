# This CMakeLists.txt file creates the library libtask_group.a
# and its unit tests. To add source files, simply append the appropiate variable
# task_group_header_files or task_group_implementation_files.
#
# The target for the library is task_group.
#
# The following properties are set for the target task_group.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#   task_group_include                  ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
#   PUBLIC_HEADER                       ${task_group_header_files}                          The list of headers files associated with this librarry.
#
# The build will abort unless the following variables are defined to
# install the library archive, header files, and unit tests:
#   task_group_install_lib_directory
#   task_group_install_include_directory
#   task_group_install_bin_directory
#   task_group_cxx_standard

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "task_group")
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
    get_target_property(my_command_line_arguments_include command_line_arguments command_line_arguments_include )
    get_target_property(my_comm_include communicator communicator_include)
    get_target_property(my_generic_object_factory_include generic_object_factory generic_object_factory_include)

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
    set (task_group_header_files
         header_files/TaskGroup.h
         header_files/TransferIngredients.hpp
         header_files/Ingredients.hpp
         header_files/WorldCommunicatorIngredientTraits.h
         header_files/CommandLineArgumentsIngredientTraits.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (task_group_implementation_files
         implementation_files/TaskGroup.cpp
         implementation_files/TransferIngredients.cpp
         implementation_files/Ingredients.cpp
         implementation_files/WorldCommunicatorIngredientTraits.cpp
         implementation_files/CommandLineArgumentsIngredientTraits.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# command_line_arguments.                            -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
             "")

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
    PRIVATE ${task_group_header_files} ${task_group_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${my_comm_include}
                           PRIVATE ${my_command_line_arguments_include} 
                           PRIVATE ${my_generic_object_factory_include} )


#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
#-----------------------------------------------------
target_link_libraries( ${target}
                       PUBLIC command_line_arguments
                       PUBLIC communicator
                       PUBLIC generic_object_factory )

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      task_group_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${task_group_cxx_standard}
                      PUBLIC_HEADER "${task_group_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION "${task_group_install_lib_directory}" 
         PUBLIC_HEADER DESTINATION "${task_group_install_lib_directory}" )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
