#-----------------------------------------------------
# Check that the cmake minimum version is            -
# satisfied.                                         -
#                                                    -
#-----------------------------------------------------
cmake_minimum_required(VERSION 3.10)

project(anansi)

include(cmake_macros_and_functions/version_check.cmake)

verify_cmake_mimimum_version()
