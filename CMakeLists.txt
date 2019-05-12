#-----------------------------------------------------
# Check that the cmake minimum version is            -
# satisfied.                                         -
#                                                    -
#-----------------------------------------------------
cmake_minimum_required(VERSION $ENV{ANANSI_MINIMUM_CMAKE_VERSION})

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

#-----------------------------------------------------
# Check that key environmental variables are set.    -
#                                                    -
#-----------------------------------------------------
verify_key_environmental_are_set()


#-----------------------------------------------------
# Here we define some variables.                     -
#                                                    -
#-----------------------------------------------------
set(anansi_top_level $ENV{ANANSI_TOP_LEVEL}) 
set(anansi_cmake_cxx_compiler $ENV{ANANSI_CMAKE_CXX_COMPILER})
set(anansi_cmake_c_compiler $ENV{ANANSI_CMAKE_C_COMPILER})
set(anansi_install_prefix $ENV{ANANSI_INSTALL_PREFIX})
set(anansi_install_bin_directory $ENV{ANANSI_INSTALL_BIN_DIRECTORY})
set(anansi_install_include_directory $ENV{ANANSI_INSTALL_INCLUDE_DIRECTORY})
set(anansi_install_lib_directory $ENV{ANANSI_INSTALL_LIB_DIRECTORY})
set(anansi_minimum_cmake_version $ENV{ANANSI_MINIMUM_CMAKE_VERSION})

#-----------------------------------------------------
# Add the subdirectories for the various             -
# libraries.                                         -
#                                                    -
#-----------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/boundary_conditions)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/force_fields)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/neighbor_lists)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/integrators)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/file_parsers)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/molecular_topologies)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/communicator)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/CPUMemoryAllocation)

#-----------------------------------------------------
#                                                    -
#                                                    -
#-----------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/molecular_dynamics)
