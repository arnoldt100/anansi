# This CMakeLists.txt file creates the library libphysical_data_structures.a
# and its unit tests. To add source files, simply append the appropiate variable
# physical_data_structures_header_files or physical_data_structures_implementation_files.
#
# The target for the library is physical_data_structures.
#
# The following properties are set for the target physical_data_structures.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#
#   physical_data_structures_include    ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
#   PUBLIC_HEADER                       ${physical_data_structures_header_files}            The list of headers files associated with this librarry.


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "physical_data_structures")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    # ----------------------------------------------------
    # Verify that all build prerequisites are met to
    # configure physical_data_structures for building.
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/physical_data_structures_build_prerequisites.cmake")
    verify_physical_data_structures_build_prerequisites_are_met()

    #-----------------------------------------------------
    # Define the property name for the include directory.
    # 
    #-----------------------------------------------------
    set(my_target_include_property_name "physical_data_structures_include" )

    # ----------------------------------------------------
    # Get the properties of various other targets that 
    # physical_data_structures depend on.
    # 
    # ----------------------------------------------------

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
    # physical_data_structures_header_files.             -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (physical_data_structures_header_files 
         header_files/PhysicalDataStructure.h 
         header_files/coordinates.h
         header_files/PointAtoms.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # physical_data_structures_implementation_files.     -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (physical_data_structures_implementation_files 
         implementation_files/PhysicalDataStructure.cpp
         implementation_files/coordinates.cpp
         implementation_files/PointAtoms.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the physical_data_structures target.                       @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# physical_data_structures.                          -
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
               PRIVATE ${physical_data_structures_header_files} 
               PRIVATE ${physical_data_structures_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files)

#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
#-----------------------------------------------------
target_link_libraries( ${target} )

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
                      CXX_STANDARD "${physical_data_structures_cxx_standard}"
                      PUBLIC_HEADER "${physical_data_structures_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${physical_data_structures_install_lib_library_directory} 
         PUBLIC_HEADER DESTINATION ${physical_data_structures_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
