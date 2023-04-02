# e@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Check that the cmake minimum version is            -
    # satisfied.                                         -
    #                                                    -
    #-----------------------------------------------------
    cmake_minimum_required(VERSION "$ENV{ANANSI_MINIMUM_CMAKE_VERSION}")

    #-----------------------------------------------------
    # Define the Anansi build targets. Currently we only -
    # have one target:                                   -
    #   ANANSI_MD                                        -
    #                                                    -
    #-----------------------------------------------------
    set(ANANSI_MD 2) 

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    project(anansi)

    #-----------------------------------------------------
    # Make available the anansi project cmake modules.   -
    #                                                    -
    #-----------------------------------------------------
    include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_build_prerequisites.cmake" )
    include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_mpi.cmake" )
    include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_boost.cmake" )
    include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/enable_compile_warnings.cmake" )
    include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/enable_debug_flags.cmake" )
    include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_log_message.cmake" )
    include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_test_variable.cmake" )
    include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_package_configure_delimiter_comments.cmake") 
    include( "${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/anansi_property_name_generator.cmake") 

    enable_cache_debug_flags()

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
set(anansi_top_level "$ENV{ANANSI_TOP_LEVEL}") 
set(anansi_cxx_standard 20)
set(anansi_cmake_cxx_compiler "$ENV{ANANSI_CMAKE_CXX_COMPILER}")
set(anansi_cmake_c_compiler "$ENV{ANANSI_CMAKE_C_COMPILER}")
set(anansi_install_prefix "$ENV{ANANSI_INSTALL_PREFIX}")
set(anansi_install_bin_directory "$ENV{ANANSI_INSTALL_BIN_DIRECTORY}")
set(anansi_install_include_directory "$ENV{ANANSI_INSTALL_INCLUDE_DIRECTORY}")
set(anansi_install_lib_directory "$ENV{ANANSI_INSTALL_LIB_DIRECTORY}")
set(anansi_minimum_cmake_version "$ENV{ANANSI_MINIMUM_CMAKE_VERSION}")
set(anansi_log_file "${anansi_top_level}/anansi_log.txt")

set(my_message "Start of configuring project anansi\n")
log_message_to_file("${anansi_log_file}" "${my_message}")

#-----------------------------------------------------
# This section checks that MPI is available.         -
#                                                    -
#-----------------------------------------------------
enable_mpi()
    
#-----------------------------------------------------
# This section permits use to find the header files  -
# and link against the BOOST library.                -
#                                                    -
#-----------------------------------------------------
enable_boost("$ENV{ANANSI_BOOST_TOP_LEVEL}") # The enable_boost macro 
                                             # sets up the boost library for
                                             # linking against.


# ----------------------------------------------------
# This subdirectory builds the core package 
# dependencies for anansi, and it must be done first.
# 
# ----------------------------------------------------
package_config_begin_delimiter("core_packages" "${anansi_log_file}")

include( "${CMAKE_CURRENT_SOURCE_DIR}/core_packages/cmake_macros_and_functions/core_packages.cmake" )
enable_building_core_packages_package("${anansi_minimum_cmake_version}" 
                                      "${anansi_cxx_standard}"  
                                      "${anansi_cmake_c_compiler}" 
                                      "${anansi_cmake_cxx_compiler}" 
                                      "${anansi_install_prefix}"
                                      "${anansi_install_bin_directory}"
                                      "${anansi_install_include_directory}"
                                      "${anansi_install_lib_directory}"
                                      "${anansi_log_file}")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/core_packages")

package_config_end_delimiter("core_packages" "${anansi_log_file}")

#-----------------------------------------------------
# This subdirectory builds the molecular             -
# dynamics class.                                    -
#                                                    -
#-----------------------------------------------------
package_config_begin_delimiter("molecular_dynamics" "${anansi_log_file}")

include( "${CMAKE_CURRENT_SOURCE_DIR}/molecular_dynamics/cmake_macros_and_functions/molecular_dynamics.cmake" )

enable_building_molecular_dynamics_package("${anansi_minimum_cmake_version}" 
                                           "${anansi_cxx_standard}"  
                                           "${anansi_cmake_c_compiler}" 
                                           "${anansi_cmake_cxx_compiler}" 
                                           "${anansi_install_prefix}"
                                           "${anansi_install_bin_directory}"
                                           "${anansi_install_include_directory}"
                                           "${anansi_install_lib_directory}"
                                           "${anansi_log_file}")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/molecular_dynamics")

package_config_end_delimiter("molecular_dynamics" "${anansi_log_file}")

