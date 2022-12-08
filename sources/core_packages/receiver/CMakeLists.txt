# This CMakeLists.txt file creates the library libreceiver.a
# and its unit tests. To add source files, simply append the appropiate variable
# receiver_header_files or receiver_implementation_files.
#
# The target for the library is receiver.
#
# The following properties are set for the target receiver.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
#   receiver_include                    ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
#   PUBLIC_HEADER                       ${receiver_header_files}                            The list of headers files associated with this librarry.


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "receiver")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    # ----------------------------------------------------
    # Verify that all build prerequisites are met to
    # configure receiver for building.
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/receiver_build_prerequisites.cmake")
    verify_receiver_build_prerequisites_are_met()

    #-----------------------------------------------------
    # Define the property name for the include directory.
    # 
    #-----------------------------------------------------
    set(my_target_include_property_name "receiver_include" )

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
    set (receiver_header_files
         header_files/ReceiverInterface.hpp
         header_files/StringLiteralTraits.hpp
         header_files/GenericReceiverFactory.hpp)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (receiver_implementation_files
         implementation_files/ReceiverInterface.cpp
         implementation_files/StringLiteralTraits.cpp
         implementation_files/GenericReceiverFactory.cpp )

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
    PRIVATE ${receiver_header_files} ${receiver_implementation_files} )

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
                      CXX_STANDARD "${receiver_cxx_standard}"
                      PUBLIC_HEADER "${receiver_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${receiver_install_lib_library_directory} 
         PUBLIC_HEADER DESTINATION ${receiver_install_lib_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
