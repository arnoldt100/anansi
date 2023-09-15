# This CMakeLists.txt file creates the library libcontrol_file.a
# and its unit tests. To add source files, simply append the appropiate variable
# control_file_header_files or control_file_implementation_files.
#
# The target for the library is control_file.
#
# The following properties are set for the target control_file.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
# control_file_include         ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
# PUBLIC_HEADER                ${control_file_header_files}                        The list of headers files associated with this librarry.
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
    set(my_project_name "control_file")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Verify key variables are set.                      -
    #                                                    -
    #-----------------------------------------------------
    include(cmake_macros_and_functions/control_file_build_prerequisites.cmake)
    verify_control_file_build_prerequisites_are_met()

    #-----------------------------------------------------
    # This library needs access to the following header  -
    # files:                                             -
    #                                                    -
    #   communicator target header files                 -
    #                                                    -
    # We get the path to the above header files.         -
    #-----------------------------------------------------
    get_target_property(my_mm_include memory_management memory_management_include)
    get_target_property(my_property_tree_include property_tree property_tree_include)
    get_target_property(my_command_files_include command_files command_files_include)

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
    # control_file_header_files.                         -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (control_file_header_files
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ControlFileName.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ControlFile.hpp
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ControlFileTraits.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/BuilderControlFile.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/BuilderFile.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/StandardFileFactory.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/MasterControlFileNodeKeys.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/verify_controlfile_keys_are_valid.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/add_values_to_property_tree.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ControlFilePickle.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/unpickle_to_property_tree.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/pickle_ControlFile_property_tree.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/Exceptions/ControlFileNodeKeyNotFound.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # control_file_implementation_files.                 -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (control_file_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ControlFileName.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ControlFile.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/BuilderControlFile.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/BuilderFile.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/StandardFileFactory.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/MasterControlFileNodeKeys.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/verify_controlfile_keys_are_valid.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/add_values_to_property_tree.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ControlFilePickle.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/unpickle_to_property_tree.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/pickle_ControlFile_property_tree.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/Exceptions/ControlFileNodeKeyNotFound.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the control_file target.                                   @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# control_file.                                      -
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
               PRIVATE "${control_file_header_files}" 
               PRIVATE "${control_file_implementation_files}" )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files/Exceptions
                           PRIVATE "${my_property_tree_include}"
                           PRIVATE "${my_command_files_include}"
                           PRIVATE "${Boost_INCLUDE_DIR}")

target_link_libraries(${target}
                      PUBLIC communicator
                      PUBLIC property_tree
		      PUBLIC command_files_include
                      PUBLIC "${Boost_LIBRARIES}")

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      control_file_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD "${control_file_cxx_standard}"
                      PUBLIC_HEADER "${control_file_header_files}" )

install( TARGETS "${target}"
         ARCHIVE DESTINATION ${control_file_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${control_file_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
