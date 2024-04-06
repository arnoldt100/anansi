# This CMakeLists.txt file creates the library libdataandexecutionpolicies.a
# and its unit tests. To add source files, simply append the appropiate variable
# dataandexecutionpolicies_header_files or dataandexecutionpolicies_implementation_files.
#
# The target for the library is dataandexecutionpolicies.
#
# The following properties are set for the target dataandexecutionpolicies.
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
    set(my_project_name "dataandexecutionpolicies")
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
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/dataandexecutionpolicies_build_prerequisites.cmake)
    verify_dataandexecutionpolicies_build_prerequisites_are_met()
 
    #-----------------------------------------------------
    # Define the property name for the include directory.
    # 
    # We use the function "target_include_property_name" to define the property
    # name.
    #-----------------------------------------------------
    target_include_property_name("${target}")

    #-----------------------------------------------------
    # Define the property name for the include directory.
    # 
    #-----------------------------------------------------
    set(my_target_include_property_name "${target}_include" )

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
     # command_line_arguments_header_files.               -
     # A list of header files is stored in                -
     # this variable.                                     -
     #                                                    -
     #-----------------------------------------------------
     set (dataandexecutionpolicies_header_files
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/CPUCentricStoragePolicy.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/GPUCentricStoragePolicy.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/DataStoragePolicy.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/MediumPrecision.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/LowPrecision.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/HighPrecision.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/PrecisionPolicy.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/DataPartitioner.hpp
         )
 
     #-----------------------------------------------------
     # Here we define the variable                        -
     # command_line_arguments_implementation_files.       -
     # A list of implementation files is stored in this   -
     # variable.                                          -
     #                                                    -
     #-----------------------------------------------------
     set (dataandexecutionpolicies_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/CPUCentricStoragePolicy.cpp 
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/GPUCentricStoragePolicy.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/DataStoragePolicy.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/MediumPrecision.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/LowPrecision.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/HighPrecision.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/PrecisionPolicy.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/DataPartitioner.cpp)
 
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# command_line_arguments.                            -
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
    PRIVATE ${dataandexecutionpolicies_header_files} ${dataandexecutionpolicies_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files )

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
# Enable anansi for gpu or cpu centered calculations -
#                                                    -
#-----------------------------------------------------
enable_anansi_data_storage(${target})

#-----------------------------------------------------
# Enable anansi precision.                           -
#                                                    -
#-----------------------------------------------------
enable_anansi_precision(${target})

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      "${my_target_include_property_name}" ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD "${dataandexecutionpolicies_cxx_standard}"
                      PUBLIC_HEADER "${dataandexecutionpolicies_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${dataandexecutionpolicies_install_lib_directory}
         PUBLIC_HEADER DESTINATION ${dataandexecutionpolicies_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
