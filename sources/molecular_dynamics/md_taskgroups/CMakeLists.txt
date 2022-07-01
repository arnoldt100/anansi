# This CMakeLists.txt file creates the library libmd_taskgroups.a
# and its unit tests. To add source files, simply append the appropiate variable
# md_taskgroups_header_files or md_taskgroups_implementation_files.
#
# The target for the library is md_taskgroups.
#
# The following properties are set for the target md_taskgroups.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
# md_taskgroups_include         ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
# PUBLIC_HEADER                ${md_taskgroups_header_files}                        The list of headers files associated with this librarry.

# The build will abort unless the following variables are defined to
# install the library archive, header files and unit tests:
#   md_taskgroups_install_lib_directory
#   md_taskgroups_install_include_directory
#   md_taskgroups_install_bin_directory
#   md_taskgroups_logfilepath


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "md_taskgroups")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    # ----------------------------------------------------
    # Verify the prerequisites for configuring package
    # md_taskgroups are satisfied.
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/md_taskgroups_build_prerequisites.cmake")
    verify_md_taskgroups_build_prerequisites_are_met()

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property(my_generic_object_factory_include generic_object_factory generic_object_factory_include )
    get_target_property(my_task_group_include task_group task_group_include )
    get_target_property(my_foreach_loop_include generic_foreach_loop generic_foreach_loop_include)

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
    set (md_taskgroups_header_files
         header_files/MDTaskGroupTraits.h
         header_files/MDTaskGroupFactory.hpp
         header_files/DefaultTaskGroup.h
         header_files/WorldTaskGroupEnableVisitor.h
         header_files/WorldTaskGroupConvenienceFunctions.h
         header_files/WorldTaskGroup.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (md_taskgroups_implementation_files
         implementation_files/MDTaskGroupTraits.cpp
         implementation_files/MDTaskGroupFactory.cpp
         implementation_files/DefaultTaskGroup.cpp
         implementation_files/WorldTaskGroupEnableVisitor.cpp
         implementation_files/WorldTaskGroupConvenienceFunctions.cpp
         implementation_files/WorldTaskGroup.cpp )

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
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
    PRIVATE ${md_taskgroups_header_files} ${md_taskgroups_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files 
                           PRIVATE ${my_generic_object_factory_include}
                           PRIVATE ${my_task_group_include} 
                           PRIVATE ${my_foreach_loop_include} ) 

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${target}
                      generic_object_factory
                      task_group 
                      generic_foreach_loop )


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
                      md_taskgroups_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${md_taskgroups_cxx_standard}
                      PUBLIC_HEADER "${md_taskgroups_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${md_taskgroups_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${md_taskgroups_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
#add_subdirectory(unit_tests)
