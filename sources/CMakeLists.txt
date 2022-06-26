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
    # Make available the anansi project cmake modules.   -
    #                                                    -
    #-----------------------------------------------------
    include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_build_prerequisites.cmake )
    include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_boost.cmake )
    include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/enable_compile_warnings.cmake )
    include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_log_message.cmake )
    include( ${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_test_variable.cmake )


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
set(anansi_log_file "${anansi_top_level}/anansi_log.txt")

set(my_message "Start of configuring project anansi\n")
log_message_to_file(${anansi_log_file} ${my_message})

#-----------------------------------------------------
# This section permits use to find the header files  -
# and link against the BOOST library.                -
#                                                    -
#-----------------------------------------------------
enable_boost($ENV{ANANSI_BOOST_TOP_LEVEL}) # The enable_boost macro 
                                           # sets up the boost library for
                                           # linking against.


# ----------------------------------------------------
# This subdirectory builds the code package 
# dependencies for anansi, and it must be done first.
# 
# ----------------------------------------------------
log_message_to_file(${anansi_log_file} "===")
set(my_message "Configuring project core_packages...\n")
log_message_to_file(${anansi_log_file} ${my_message})

include( ${CMAKE_CURRENT_SOURCE_DIR}/core_packages/cmake_macros_and_functions/core_packages.cmake )
enable_building_core_packages_package("${anansi_minimum_cmake_version}" 
                                      "${anansi_cxx_standard}"  
                                      "${anansi_cmake_c_compiler}" 
                                      "${anansi_cmake_cxx_compiler}" 
                                      "${anansi_install_prefix}"
                                      "${anansi_install_bin_directory}"
                                      "${anansi_install_include_directory}"
                                      "${anansi_install_lib_directory}"
                                      "${anansi_log_file}")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/core_packages)

set(my_message "Completed configuring project core_packages.")
log_message_to_file(${anansi_log_file} ${my_message})
log_message_to_file(${anansi_log_file} "===\n")

#-----------------------------------------------------
# This subdirectory builds the main molecular        -
# dynamics program.                                  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/molecular_dynamics)

set(my_message "End of building project anansi\n")
log_message_to_file( ${anansi_log_file} ${my_message})
