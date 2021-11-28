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
    # Make available the project cmake modules.          -
    #                                                    -
    #-----------------------------------------------------
    include( $ENV{ANANSI_CMAKE_MODULE_PATH}/anansi_build_prerequisites.cmake )
    include( $ENV{ANANSI_CMAKE_MODULE_PATH}/anansi_boost.cmake )
    include( $ENV{ANANSI_CMAKE_MODULE_PATH}/enable_compile_warnings.cmake )
    include( ${CMAKE_CURRENT_SOURCE_DIR}/sources/mouseion/cmake_macros_and_functions/mouseion_library.cmake )
    include( ${CMAKE_CURRENT_SOURCE_DIR}/sources/command_line_arguments/cmake_macros_and_functions/command_line_arguments.cmake)
    include( ${CMAKE_CURRENT_SOURCE_DIR}/sources/simulation_parameters/cmake_macros_and_functions/simulation_parameters.cmake)
    include( ${CMAKE_CURRENT_SOURCE_DIR}/sources/file_parsers/cmake_macros_and_functions/file_parsers.cmake)


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
                         "${CMAKE_CURRENT_LIST_DIR}/sources/mouseion"
                         "$ENV{ANANSI_BOOST_TOP_LEVEL}")

#-----------------------------------------------------
# Call the macro that enables building of command    -
# line arguments target.                             -
#                                                    -
#-----------------------------------------------------
enable_building_command_line_arguments_library( "${anansi_install_lib_directory}"
                                                "${anansi_install_include_directory}"
                                                "${anansi_install_bin_directory}" 
                                                "${anansi_cxx_standard}")


#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the simulation_parameters libraries,    -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
enable_building_simulation_parameters_library( "${anansi_install_lib_directory}"
                                               "${anansi_install_include_directory}"
                                               "${anansi_install_bin_directory}" 
                                               "${anansi_cxx_standard}" )

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the file_parsers libraries,             -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
enable_building_file_parsers_library( "${anansi_install_lib_directory}"
                                      "${anansi_install_include_directory}"
                                      "${anansi_install_bin_directory}" 
                                      "${anansi_cxx_standard}" )

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

#-----------------------------------------------------
# This subdirectory builds the main molecular        -
# dynamics program.                                  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/molecular_dynamics)
