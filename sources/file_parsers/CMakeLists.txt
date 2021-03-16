# This CMakeLists.txt file creates the library libfile_parsers.a
# and its unit tests. To add source files, simply append the appropiate variable
# file_parsers_header_files or file_parsers_implementation_files.
#
# The target for the library is file_parsers.
#
# The following properties are set for the target file_parsers.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
# file_parsers_include         ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
# PUBLIC_HEADER                ${file_parsers_header_files}                        The list of headers files associated with this librarry.
#
# The build will abort unless the following variables are defined to
# install the library archive, header files, and unit tests:
#   file_parsers_install_lib_directory
#   file_parsers_install_include_directory
#   file_parsers_install_bin_directory

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "file_parsers")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Include various functions and macros.              -
    #                                                    -
    #-----------------------------------------------------
    include(cmake_macros_and_functions/file_parsers_build_prerequisites.cmake)

    #-----------------------------------------------------
    # Verify key variables are set.                      -
    #                                                    -
    #-----------------------------------------------------
    verify_key_variables_are_set()

    #-----------------------------------------------------
    # This library needs access to the following header  -
    # files:                                             -
    #                                                    -
    #   mpi_communicator target header files            -
    #                                                    -
    # We get the path to the above header files.         -
    #-----------------------------------------------------
    get_target_property(my_mm_include memory_management memory_management_include)

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
    # file_parsers_header_files.                         -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (file_parsers_header_files
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/FileParser.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ControlFileParser.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/BuilderControlFileParser.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/BuilderFileParser.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/StandardFileParserFactory.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # file_parsers_implementation_files.                 -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (file_parsers_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/FileParser.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ControlFileParser.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/BuilderControlFileParser.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/BuilderFileParser.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/StandardFileParserFactory.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the file_parsers target.                                   @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# file_parsers.                                      -
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
               PRIVATE ${file_parsers_header_files} ${file_parsers_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files)

target_link_libraries(${target}
                      mpi_communicator)

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      file_parsers_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${file_parsers_cxx_standard}
                      PUBLIC_HEADER "${file_parsers_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${file_parsers_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${file_parsers_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
