# This CMakeLists.txt file creates the library libcounterclass.a
# and its unit tests. To add source files, simply append the appropiate variable
# counterclass_header_files or counterclass_implementation_files.
#
# The target for the library is counterclass.
#
# The following properties are set for the target counterclass.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
#   counterclass_include                ${CMAKE_CURRENT_SOURCE_DIR}/header_files


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "counterclass")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

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
    set (counterclass_header_files
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ClassInstanceLimiter.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/TooManyInstancesError.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/MaxInstancesNegativeError.hpp)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (counterclass_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ClassInstanceLimiter.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/TooManyInstancesError.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/MaxInstancesNegativeError.cpp)

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
    PRIVATE ${counterclass_header_files} ${counterclass_implementation_files} )

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
                      counterclass_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${counterclass_cxx_standard}
                      PUBLIC_HEADER "${counterclass_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION "${counterclass_install_lib_directory}" 
         PUBLIC_HEADER DESTINATION "${counterclass_install_include_directory}" )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
