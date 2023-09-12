# This CMakeLists.txt file creates the library libcommand_files.a
# and its unit tests. To add source files, simply append the appropiate variable
# command_files_header_files or command_files_implementation_files.
#
# The target for the library is command_files.
#
# The following properties are set for the target command_files.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
# command_files_include        ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
# PUBLIC_HEADER                ${command_files_header_files}                       The list of headers files associated with this librarry.
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
    set(my_project_name "command_files")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})
    
    # ----------------------------------------------------
    # Verify that all build prerequisites are satisfied 
    # for target 'file_parsers'.
    # 
    # ----------------------------------------------------
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/command_files_build_prerequisites.cmake)
    verify_command_files_build_prerequisites_are_met()
    
    #-----------------------------------------------------
    # This library needs access to the following header  -
    # files:                                             -
    #                                                    -
    #   communicator target header files                 -
    #                                                    -
    # We get the path to the above header files.         -
    #-----------------------------------------------------
    # get_target_property(my_mm_include memory_management memory_management_include)
    # get_target_property(my_property_tree_include property_tree property_tree_include)

    #-----------------------------------------------------
    # Define the property name for the include directory.
    # 
    #-----------------------------------------------------
    set(my_target_include_property_name "${target}_include" )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_header_files.               -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (command_files_header_files
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/CommandFiles.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (command_files_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/CommandFiles.cpp )

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
               PRIVATE ${command_files_header_files}
               PRIVATE ${command_files_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files )

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
                      "${my_target_include_property_name}" ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      PUBLIC_HEADER "${command_files_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${command_files_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${command_files_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
