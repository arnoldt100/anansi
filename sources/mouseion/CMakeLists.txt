#-----------------------------------------------------
# Check that the cmake minimum version is            -
# satisfied.                                         -
#                                                    -
#-----------------------------------------------------
cmake_minimum_required(VERSION $ENV{MOUSEION_MINIMUM_CMAKE_VERSION})

#-----------------------------------------------------
# Define the project.                                -
#                                                    -
#-----------------------------------------------------
project(mouseion)

# This CMakeLists.txt file creates the library libmouseion.a
# and its unit tests. To add source files, simply append the appropiate variable
# mouseion_header_files or mouseion_implementation_files.
#
# The target for the library is mouseion.
#
# The following properties are set for the target mouseion.
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
    set(my_project_name "mouseion")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

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


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the mouseion targets.                                      @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# mouseion.                                          -
#                                                    -
#-----------------------------------------------------

#-----------------------------------------------------
# Make available the project cmake modules.          -
#                                                    -
#-----------------------------------------------------
include( ${CMAKE_CURRENT_LIST_DIR}/cmake_macros_and_functions/mouseion_build_prerequisites.cmake )
include( ${CMAKE_CURRENT_LIST_DIR}/cmake_macros_and_functions/enable_compile_warnings.cmake )

#-----------------------------------------------------
# Check that key environmental variables are set.    -
#                                                    -
#-----------------------------------------------------
verify_key_environmental_are_set()

#-----------------------------------------------------
# Here we define some variables.                     -
# that are critical for building and deploying.      -
#-----------------------------------------------------
set(mouseion_cmake_cxx_compiler $ENV{MOUSEION_CMAKE_CXX_COMPILER})
set(mouseion_cxx_standard $ENV{MOUSEION_CXX_STANDARD})
set(mouseion_cmake_c_compiler $ENV{MOUSEION_CMAKE_C_COMPILER})
set(mouseion_install_prefix $ENV{MOUSEION_INSTALL_PREFIX})
set(mouseion_install_bin_directory $ENV{MOUSEION_INSTALL_BIN_DIRECTORY})
set(mouseion_install_include_directory $ENV{MOUSEION_INSTALL_INCLUDE_DIRECTORY})
set(mouseion_install_lib_directory $ENV{MOUSEION_INSTALL_LIB_DIRECTORY})

#-----------------------------------------------------
# Define the file to write messages to.              -
#                                                    -
#-----------------------------------------------------
set(mouseion_log_file $ENV{MOUSEION_LOG_FILE})

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the memory_management libraries,        -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
set(memory_management_install_lib_directory ${mouseion_install_lib_directory})
set(memory_management_install_include_directory ${mouseion_install_include_directory})
set(memory_management_install_bin_directory ${mouseion_install_bin_directory})
set(memory_management_cxx_standard ${mouseion_cxx_standard})

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the mpi_communicator libraries,         -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
set(mpi_communicator_install_lib_directory ${mouseion_install_lib_directory})
set(mpi_communicator_install_include_directory ${mouseion_install_include_directory})
set(mpi_communicator_install_bin_directory ${mouseion_install_bin_directory})
set(mpi_communicator_cxx_standard ${mouseion_cxx_standard})

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the mpi_communicator libraries,         -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
set(string_utilities_install_lib_directory ${mouseion_install_lib_directory})
set(string_utilities_install_include_directory ${mouseion_install_include_directory})
set(string_utilities_install_bin_directory ${mouseion_install_bin_directory})
set(string_utilities_cxx_standard ${mouseion_cxx_standard})

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the counterclass libraries,             -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
set(counterclass_install_lib_directory ${mouseion_install_lib_directory})
set(counterclass_install_include_directory ${mouseion_install_include_directory})
set(counterclass_install_bin_directory ${mouseion_install_bin_directory})
set(counterclass_cxx_standard ${mouseion_cxx_standard})

#-----------------------------------------------------
# Here we define variables which indicate where      -
# to install the meta_programming_library libraries, -
# header files, and associated binaries.             -
#                                                    -
#-----------------------------------------------------
set(mpl_install_lib_directory ${mouseion_install_lib_directory})
set(mpl_install_include_directory ${mouseion_install_include_directory})
set(mpl_install_bin_directory ${mouseion_install_bin_directory} )
set(mpl_cxx_standard ${mouseion_cxx_standard})

#-----------------------------------------------------
# Add the subdirectories for the various             -
# libraries.                                         -
#                                                    -
#-----------------------------------------------------
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/counter_classes)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/CPU_memory_management)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/string_utilities)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/communicator)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/sources/meta_programming_library)
