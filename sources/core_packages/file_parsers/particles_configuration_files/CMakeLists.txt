# This CMakeLists.txt file creates the library libparticles_configuration_files.a
# and its unit tests. To add source files, simply append the appropiate variable
# particles_configuration_files_header_files or particles_configuration_files_implementation_files.
#
# The target for the library is particles_configuration_files.
#
# The following properties are set for the target particles_configuration_files.
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
    set(my_project_name "particles_configuration_files")
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
    include(cmake_macros_and_functions/particles_configuration_files_build_prerequisites.cmake)
    verify_particles_configuration_files_build_prerequisites_are_met()

    get_target_property(my_file_parsers_core_include file_parsers_core file_parsers_core_include)
     
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
    # particles_configuration_files_header_files.        -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (particles_configuration_files_header_files
        ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ParticlesConfigurationFiles.hpp)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # particles_configuration_files_implementation_files.-
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (particles_configuration_files_implementation_files 
        ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ParticlesConfigurationFiles.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the particles_configuration_files targets.                 @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# particles_configuration_files.                     -
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
    PRIVATE "${particles_configuration_files_header_files}"
    PRIVATE "${particles_configuration_files_implementation_files}" )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header_files"
                           PRIVATE "${Boost_INCLUDE_DIR}"
                           PRIVATE "${my_file_parsers_core_include}")

target_link_libraries(${target}
                      PUBLIC "${Boost_LIBRARIES}"
                      PUBLIC file_parsers_core)

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
                      particles_configuration_files_include "${CMAKE_CURRENT_SOURCE_DIR}/header_files"
                      CXX_STANDARD "${particles_configuration_files_cxx_standard}"
                      PUBLIC_HEADER "${particles_configuration_files_header_files}" )

install( TARGETS "${target}"
         ARCHIVE DESTINATION "${particles_configuration_files_install_lib_directory}" 
         PUBLIC_HEADER DESTINATION "${particles_configuration_files_install_include_directory}" )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
