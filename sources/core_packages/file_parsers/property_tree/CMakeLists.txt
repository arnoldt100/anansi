# This CMakeLists.txt file creates the library libproperty_tree.a
# and its unit tests. To add source files, simply append the appropiate variable
# property_tree_header_files or property_tree_implementation_files.
#
# The target for the library is property_tree.
#
# The following properties are set for the target property_tree.
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
    set(my_project_name "property_tree")
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
    include(cmake_macros_and_functions/property_tree_build_prerequisites.cmake)
    verify_property_tree_build_prerequisites_are_met()

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
    # property_tree_header_files.                        -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (property_tree_header_files
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/BaseInputFile.h
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/CommandFileName.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # property_tree_implementation_files.                -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (property_tree_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/BaseInputFile.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/CommandFileName.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the property_tree targets.                                 @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# property_tree.                                     -
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
    PRIVATE "${property_tree_header_files}"
    PRIVATE "${property_tree_implementation_files}" )

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
                      property_tree_include "${CMAKE_CURRENT_SOURCE_DIR}/header_files"
                      CXX_STANDARD "${property_tree_cxx_standard}"
                      PUBLIC_HEADER "${property_tree_header_files}" )

install( TARGETS "${target}"
         ARCHIVE DESTINATION "${property_tree_install_lib_directory}" 
         PUBLIC_HEADER DESTINATION "${property_tree_install_include_directory}" )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
