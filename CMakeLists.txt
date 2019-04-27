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
# Modify the variable CMAKE_MODULE_PATH              -
# to include for anansi cmake modules.               -
#                                                    -
#-----------------------------------------------------
set( CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/$ENV{ANANSI_CMAKE_MODULE_PATH}" )

#-----------------------------------------------------
# Make availble the project cmake modules.           -
#                                                    -
#-----------------------------------------------------
include(anansi_build_prerequisites)

#-----------------------------------------------------
# Check that key environmental variables are set.    -
#                                                    -
#-----------------------------------------------------
verify_key_environmental_are_set()

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

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/main_programs)
