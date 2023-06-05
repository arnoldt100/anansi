# This CMakeLists.txt file creates the library libwritetexttoconsoletask.a
# and its unit tests. To add source files, simply append the appropiate variable
# writetexttoconsoletask_header_files or writetexttoconsoletask_implementation_files.
#
# The target for the library is writetexttoconsoletask.
#
# The following properties are set for the target writetexttoconsoletask.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
# writetexttoconsoletask_include        ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
# PUBLIC_HEADER                         ${writetexttoconsoletask_header_files}              The list of headers files associated with this librarry.


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @a
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "writetexttoconsoletask")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Define the property name for the include directory.
    # 
    # We use the function "target_include_property_name" to define the property
    # name.
    #-----------------------------------------------------
    target_include_property_name("${target}")
    set(my_target_include_property_name "${target}_include" )

    # ----------------------------------------------------
    # Verify that all writetexttoconsoletask build prerequisities
    # are satisfied.
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/writetexttoconsoletask_build_prerequisites.cmake")
    verify_writetexttoconsoletask_build_prerequisites_are_met()

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
    set (writetexttoconsoletask_header_files
         header_files/WriteTextToConsoleTaskReceiver.h
         header_files/WriteTextToConsoleTaskOwnershipImpl.hpp
         header_files/WriteTextToConsoleTaskTraits.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (writetexttoconsoletask_implementation_files
         implementation_files/WriteTextToConsoleTaskReceiver.cpp
         implementation_files/WriteTextToConsoleTaskOwnershipImpl.cpp
         implementation_files/WriteTextToConsoleTaskTraits.cpp)


    # -----------------------------------------------------
    # Set various variables for include directories.
    # 
    # -----------------------------------------------------
    get_target_property(my_tasks_include tasks tasks_include) 
    get_target_property(my_logger_include logger logger_include)
    get_target_property(my_receiver_include receiver receiver_include )
    get_target_property(my_communicator_include communicator communicator_include)
    get_target_property(my_genericmdtask_include genericmdtask genericmdtask_include )
    get_target_property(my_mdownershippolicies_include mdownershippolicies mdownershippolicies_include )

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
    PRIVATE ${writetexttoconsoletask_header_files} ${writetexttoconsoletask_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${my_tasks_include}
                           PRIVATE ${my_logger_include}
                           PRIVATE ${my_receiver_include}
                           PRIVATE ${my_mdownershippolicies_include}
                           PRIVATE ${my_communicator_include}
                           PRIVATE ${my_genericmdtask_include})

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${target}
                      PUBLIC tasks
                      PUBLIC logger
                      PUBLIC receiver
                      PUBLIC mdownershippolicies
                      PUBLIC communicator
                      PUBLIC genericmdtask)

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
                      CXX_STANDARD "${writetexttoconsoletask_cxx_standard}"
                      PUBLIC_HEADER "${writetexttoconsoletask_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${writetexttoconsoletask_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${writetexttoconsoletask_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
