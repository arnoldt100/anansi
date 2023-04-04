# This CMakeLists.txt file creates the library libgenericmdtask.a
# and its unit tests. To add source files, simply append the appropiate variable
# genericmdtask_header_files or genericmdtask_implementation_files.
#
# The target for the library is genericmdtask.
#
# The following properties are set for the target genericmdtask.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
# genericmdtask_include                 ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
# PUBLIC_HEADER                         ${genericmdtask_header_files}                         The list of headers files associated with this librarry.


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "genericmdtask")
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
    set(my_target_include_property_name "genericmdtask_include" )

    # ----------------------------------------------------
    # Verify that all genericmdtask build prerequisities
    # are satisfied.
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/genericmdtask_build_prerequisites.cmake")
    verify_genericmdtask_build_prerequisites_are_met()

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property(my_tasks_include tasks tasks_include)
    get_target_property(my_receiver_include receiver receiver_include)


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
    set (genericmdtask_header_files
          header_files/GenericMDTask.hpp
          header_files/DefaultFunctorImpl.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (genericmdtask_implementation_files
         implementation_files/GenericMDTask.cpp
         implementation_files/DefaultFunctorImpl.cpp )

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
    PRIVATE ${genericmdtask_header_files} ${genericmdtask_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${my_tasks_include}
                           PRIVATE ${my_receiver_include})

#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
#-----------------------------------------------------
target_link_libraries( ${target}
                       PUBLIC tasks
                       PUBLIC receiver)

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
                      CXX_STANDARD "${md_taskgroups_cxx_standard}"
                      PUBLIC_HEADER "${genericmdtask_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${md_taskgroups_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${md_taskgroups_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
#add_subdirectory(unit_tests)
