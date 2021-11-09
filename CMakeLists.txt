#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    #-----------------------------------------------------
    # Check that the cmake minimum version is            -
    # satisfied.                                         -
    #                                                    -
    #-----------------------------------------------------
    cmake_minimum_required(VERSION $ENV{ANANSI_MINIMUM_CMAKE_VERSION})

    #-----------------------------------------------------
    # Define the Anansi build targets. Currently we only -
    # have one target:                                   -
    #   ANANSI_MD                                        -
    #                                                    -
    #-----------------------------------------------------
    set(ANANSI_MD 1) 

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    project(anansi)

    #-----------------------------------------------------
    # Set for the target anansi the target property      -
    # the build type.                                    -
    #                                                    -
    #-----------------------------------------------------
    # set_target_properties(anansi,
    #                       PROPERTIES target_build ${ANANSI_MD})

    #-----------------------------------------------------
    # Make available the project cmake modules.          -
    #                                                    -
    #-----------------------------------------------------
    include( $ENV{ANANSI_CMAKE_MODULE_PATH}/anansi_build_prerequisites.cmake )
    include( $ENV{ANANSI_CMAKE_MODULE_PATH}/anansi_boost.cmake )
    include( $ENV{ANANSI_CMAKE_MODULE_PATH}/enable_compile_warnings.cmake )
    include( $ENV{ANANSI_CMAKE_MODULE_PATH}/mouseion_library.cmake )


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Start of C++ build and release section                          @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Turn on verbose debugging.                         -
    #                                                    -
    #-----------------------------------------------------
    set(CMAKE_VERBOSE_MAKEFILE ON)

    #-----------------------------------------------------
    # Check that key environmental variables are set.    -
    #                                                    -
    #-----------------------------------------------------
    verify_key_environmental_are_set()

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of C++ build and release section                            @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Here we define some variables.                     -
# that are critical for building and deploying.      -
#-----------------------------------------------------
set(anansi_top_level $ENV{ANANSI_TOP_LEVEL}) 
set(anansi_cxx_standard 17)
set(anansi_cmake_cxx_compiler $ENV{ANANSI_CMAKE_CXX_COMPILER})
set(anansi_cmake_c_compiler $ENV{ANANSI_CMAKE_C_COMPILER})
set(anansi_install_prefix $ENV{ANANSI_INSTALL_PREFIX})
set(anansi_install_bin_directory $ENV{ANANSI_INSTALL_BIN_DIRECTORY})
set(anansi_install_include_directory $ENV{ANANSI_INSTALL_INCLUDE_DIRECTORY})
set(anansi_install_lib_directory $ENV{ANANSI_INSTALL_LIB_DIRECTORY})
set(anansi_minimum_cmake_version $ENV{ANANSI_MINIMUM_CMAKE_VERSION})

#-----------------------------------------------------
# Define the file to write messages to.              -
#                                                    -
#-----------------------------------------------------
set(anansi_log_file "${anansi_top_level}/anansi_log.txt")

#-----------------------------------------------------
# Call the macro that enables building of mouseion   -
# target.                                            -
#                                                    -
#-----------------------------------------------------
enable_building_mouseion("${anansi_top_level}"
                         "${anansi_minimum_cmake_version}" 
                         "${anansi_cxx_standard}"  
                         "${anansi_cmake_c_compiler}" 
                         "${anansi_cmake_cxx_compiler}" 
                         "${anansi_install_prefix}"
                         "${anansi_install_bin_directory}"
                         "${anansi_install_include_directory}"
                         "${anansi_install_lib_directory}"
                         "${anansi_top_level}/sources/mouseion"
                         "$ENV{ANANSI_BOOST_TOP_LEVEL}")

                     #    set(ENV{MOUSEION_MINIMUM_CMAKE_VERSION} ${anansi_minimum_cmake_version}) 
                     #    set(ENV{MOUSEION_CXX_STANDARD} ${anansi_cxx_standard})
                     #    set(ENV{MOUSEION_CMAKE_C_COMPILER} ${anansi_cmake_c_compiler})
                     #    set(ENV{MOUSEION_CMAKE_CXX_COMPILER} ${anansi_cmake_cxx_compiler})
                     #    set(ENV{MOUSEION_INSTALL_PREFIX} ${anansi_install_prefix})
                     #    set(ENV{MOUSEION_INSTALL_BIN_DIRECTORY} ${anansi_install_bin_directory}) 
                     #    set(ENV{MOUSEION_INSTALL_INCLUDE_DIRECTORY} ${anansi_install_include_directory})
                     #    set(ENV{MOUSEION_INSTALL_LIB_DIRECTORY} ${anansi_install_lib_directory})
                     #    set(ENV{MOUSEION_LOG_FILE} "mouseion_log.txt")
                     #    set(ENV{MOUSEION_TOP_LEVEL} "${anansi_top_level}/sources/mouseion")
                     #    set(ENV{MOUSEION_BOOST_TOP_LEVEL} $ENV{ANANSI_BOOST_TOP_LEVEL})

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the command_line_arguments libraries,   -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
set(command_line_arguments_install_lib_directory ${anansi_install_lib_directory})
set(command_line_arguments_install_include_directory ${anansi_install_include_directory})
set(command_line_arguments_install_bin_directory ${anansi_install_bin_directory} )
set(command_line_arguments_cxx_standard ${anansi_cxx_standard} )

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the simulation_parameters libraries,    -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
set(simulation_parameters_install_lib_directory ${anansi_install_lib_directory})
set(simulation_parameters_install_include_directory ${anansi_install_include_directory})
set(simulation_parameters_install_bin_directory ${anansi_install_bin_directory} )
set(simulation_parameters_cxx_standard ${anansi_cxx_standard} )

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the file_parsers libraries,             -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
set(file_parsers_install_lib_directory ${anansi_install_lib_directory})
set(file_parsers_install_include_directory ${anansi_install_include_directory})
set(file_parsers_install_bin_directory ${anansi_install_bin_directory} )
set(file_parsers_cxx_standard ${anansi_cxx_standard} )

#-----------------------------------------------------
# This section permits use to find the header files  -
# and link against the BOOST library.                -
#                                                    -
#-----------------------------------------------------
enable_boost($ENV{ANANSI_BOOST_TOP_LEVEL}) # The enable_boost macro 
                                           # sets up the boost library for
                                           # linking against.

#-----------------------------------------------------
# Add the subdirectories for the various             -
# libraries.                                         -
#                                                    -
#-----------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/mouseion)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/command_line_arguments)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/simulation_parameters)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/file_parsers)

# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/force_fields)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/neighbor_lists)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/integrators)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/file_parsers)
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/molecular_topologies)

#-----------------------------------------------------
# This subdirectory builds the main molecular        -
# dynamics program.                                  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/molecular_dynamics)
