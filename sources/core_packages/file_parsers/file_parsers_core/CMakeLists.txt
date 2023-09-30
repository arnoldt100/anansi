# This CMakeLists.txt file creates the library libfile_parsers_core.a
# and its unit tests. To add source files, simply append the appropiate variable
# file_parsers_core_header_files or file_parsers_core_implementation_files.
#
# The target for the library is file_parsers_core.
#
# The following properties are set for the target file_parsers_core.
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
    set(my_project_name "file_parsers_core")
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
    include(cmake_macros_and_functions/file_parsers_core_build_prerequisites.cmake)
    verify_file_parsers_core_build_prerequisites_are_met()

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
    # file_parsers_core_header_files.                    -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (file_parsers_core_header_files
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/CommandFileName.h
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/XMLFileReader.h
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/XMLFileWriter.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # file_parsers_core_implementation_files.            -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (file_parsers_core_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/CommandFileName.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/XMLFileReader.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/XMLFileWriter.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the file_parsers_core targets.                             @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# file_parsers_core.                                 -
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
    PRIVATE "${file_parsers_core_header_files}"
    PRIVATE "${file_parsers_core_implementation_files}" )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header_files"
                           PRIVATE "${Boost_INCLUDE_DIR}" )

target_link_libraries(${target}
                      PUBLIC "${Boost_LIBRARIES}")

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
                      file_parsers_core_include "${CMAKE_CURRENT_SOURCE_DIR}/header_files"
                      CXX_STANDARD "${file_parsers_core_cxx_standard}"
                      PUBLIC_HEADER "${file_parsers_core_header_files}" )

install( TARGETS "${target}"
         ARCHIVE DESTINATION "${file_parsers_core_install_lib_directory}" 
         PUBLIC_HEADER DESTINATION "${file_parsers_core_install_include_directory}" )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
