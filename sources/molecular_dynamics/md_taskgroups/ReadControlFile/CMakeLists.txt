# This CMakeLists.txt file creates the library libreadcontrolfile.a
# and its unit tests. To add source files, simply append the appropiate variable
# readcontrolfile_header_files or readcontrolfile_implementation_files.
#
# The target for the library is readcontrolfile.
#
# The following properties are set for the target readcontrolfile.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
# readcontrolfile_include             ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
# PUBLIC_HEADER                         ${readcontrolfile_header_files}                   The list of headers files associated with this librarry.


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "readcontrolfile")
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
    set(my_target_include_property_name "readcontrolfile_include")

    # ----------------------------------------------------
    # Verify all readcontrolfile prerequisites are satisfied. 
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/readcontrolfile_build_prerequisites.cmake")
    verify_readcontrolfile_build_prerequisites_are_met() 

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
    set (readcontrolfile_header_files
         header_files/MasterProcess.h
         header_files/ControlFileXMLReceiver.h
         header_files/ControlFileXMLOwnershipImpl.hpp
         header_files/ControlFileXMLMPICommReceiver.h
         header_files/ControlFileXMLMPICommOwnershipImpl.hpp
         header_files/ControlFileMacroOwnershipImpl.hpp
         header_files/ControlFileMacroReceiver.h
         header_files/ReadControlFileTraits.h
         header_files/setup_controlfile_invoker.h
         header_files/disable_controlfile_invoker.h
         header_files/setup_ControlFileXMLReceiver.h
         header_files/setup_ControlFileXMLMPICommReceiver.h
         header_files/setup_ControlFileMacroReceiver.h
         )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (readcontrolfile_implementation_files
         implementation_files/MasterProcess.cpp
         implementation_files/ControlFileXMLReceiver.cpp
         implementation_files/ControlFileXMLOwnershipImpl.cpp
         implementation_files/ControlFileXMLMPICommReceiver.cpp
         implementation_files/ControlFileXMLMPICommOwnershipImpl.cpp
         implementation_files/ControlFileMacroOwnershipImpl.cpp
         implementation_files/ControlFileMacroReceiver.cpp
         implementation_files/ReadControlFileTraits.cpp 
         implementation_files/setup_controlfile_invoker.cpp
	 implementation_files/disable_controlfile_invoker.cpp
         implementation_files/setup_ControlFileXMLReceiver.cpp
         implementation_files/setup_ControlFileXMLMPICommReceiver.cpp
         implementation_files/setup_ControlFileMacroReceiver.cpp
         )

    # -----------------------------------------------------
    # Set various variables for include directories.
    # 
    # -----------------------------------------------------
    get_target_property(my_common_md_taskgroup_headers_include common_md_taskgroup_headers common_md_taskgroup_headers_include)
    get_target_property(my_mpi_communicator_include mpi_communicator mpi_communicator_include)
    get_target_property(my_invoker_include invoker invoker_include )
    get_target_property(my_tasks_include tasks tasks_include)
    get_target_property(my_receiver_include receiver receiver_include )
    get_target_property(my_genericmdtask_include genericmdtask genericmdtask_include)
    get_target_property(my_generic_abstract_factory_include generic_abstract_factory generic_abstract_factory_include )
    get_target_property(my_mdownershippolicies_include mdownershippolicies mdownershippolicies_include )
    get_target_property(my_control_file_include  control_file control_file_include)

    
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
    PRIVATE ${readcontrolfile_header_files} ${readcontrolfile_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE "${my_common_md_taskgroup_headers_include}"
                           PRIVATE "${my_mdownershippolicies_include}"
                           PRIVATE "${my_genericmdtask_include}" 
                           PRIVATE "${my_generic_abstract_factory_include}"
                           PRIVATE "${my_invoker_include}"
                           PRIVATE "${my_control_file_include}"
                           PRIVATE "${my_mpi_communicator_include}")

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${target}
                      PUBLIC common_md_taskgroup_headers
                      PUBLIC mdownershippolicies
                      PUBLIC genericmdtask
                      PUBLIC generic_abstract_factory
                      PUBLIC invoker
                      PUBLIC control_file
                      PUBLIC mpi_communicator) 


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
                      CXX_STANDARD "${readcontrolfile_cxx_standard}"
                      PUBLIC_HEADER "${readcontrolfile_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${readcontrolfile_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${readcontrolfile_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
