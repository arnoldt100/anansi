# This CMakeLists.txt file creates the library libsimulationdecomposition.a
# and its unit tests. To add source files, simply append the appropiate variable
# simulationdecomposition_header_files or simulationdecomposition_implementation_files.
#
# The target for the library is simulationdecomposition.
#
# The following properties are set for the target simulationdecomposition.
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
    set(my_project_name "simulationdecomposition")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Define the property name for the include directory.
    # 
    # We use the function "target_include_property_name" to define the property
    # name.
    #-----------------------------------------------------
    set(my_target_include_property_name "${target}_include" )

    # ----------------------------------------------------
    # Verify that all simulationdecomposition build prerequisities
    # are satisfied.
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/simulationdecomposition_build_prerequisites.cmake")
    verify_simulationdecomposition_build_prerequisites_are_met()

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property(my_debugging_utilities_include  debugging_utilities  debugging_utilities_include  )  
    get_target_property(my_comm_include  communicator communicator_include)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# command_line_arguments.                            -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
             "")

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
    set (simulationdecomposition_header_files
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/setup_simulationdecomposition_invoker.h 
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/disable_simulationdecomposition_invoker.h 
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/SimulationDecompositionParameters.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/SDPConstructorHelpers.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/message_missing_mandatory_node_tag.h

         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/processor_lattice_spatial_dimensions/ProccesorTopologyLatticeSpatialDimensionsHelpers.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/processor_lattice_spatial_dimensions/processor_lattice_spatial_dimensions_details.h

         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/workload_decomposition_type/WorkloadDecompositionTypeHelpers.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/workload_decomposition_type/workload_decomposition_type_details.h

         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/processor_lattice_type/ProcessorTopologyLatticeTypeHelpers.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/processor_lattice_type/processor_lattice_type_details.h

         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/processor_topology_number_compute_units_per_spatial_domain/ProcessorTopologyNumberComputeUnitsPerSpatialDomainHelpers.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/processor_topology_number_compute_units_per_spatial_domain/processor_topology_number_compute_units_per_spatial_domain_details.h

         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/Exceptions/ErrorInvalidSimulationDecompositionParameters.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/Exceptions/ErrorMissingSimulationDecompositionParameters.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (simulationdecomposition_implementation_files
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/setup_simulationdecomposition_invoker.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/disable_simulationdecomposition_invoker.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/SimulationDecompositionParameters.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/SDPConstructorHelpers.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/message_missing_mandatory_node_tag.cpp

         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/processor_lattice_spatial_dimensions/ProccesorTopologyLatticeSpatialDimensionsHelpers.cpp
	     ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/processor_lattice_spatial_dimensions/processor_lattice_spatial_dimensions_details.cpp

         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/workload_decomposition_type/WorkloadDecompositionTypeHelpers.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/workload_decomposition_type/workload_decomposition_type_details.cpp

         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/processor_lattice_type/ProcessorTopologyLatticeTypeHelpers.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/processor_lattice_type/processor_lattice_type_details.cpp

         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/processor_topology_number_compute_units_per_spatial_domain/ProcessorTopologyNumberComputeUnitsPerSpatialDomainHelpers.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/processor_topology_number_compute_units_per_spatial_domain/processor_topology_number_compute_units_per_spatial_domain_details.cpp

         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/Exceptions/ErrorInvalidSimulationDecompositionParameters.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/Exceptions/ErrorMissingSimulationDecompositionParameters.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# end of defining the sources and header files associated         @
# with the simulationdecomposition targets.                       @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#-----------------------------------------------------
# Set the list of directories to search for          -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files/Exceptions
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files/workload_decomposition_type
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files/processor_lattice_type
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files/processor_lattice_spatial_dimensions
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files/processor_topology_number_compute_units_per_spatial_domain
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${my_comm_include})

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${target}
                      PUBLIC  communicator)


#-----------------------------------------------------
#                                                    -
# we associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
               PRIVATE ${simulationdecomposition_header_files} ${simulationdecomposition_implementation_files} )

#-----------------------------------------------------
# enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
# here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      "${my_target_include_property_name}" ${cmake_current_source_dir}/header_files
                      CXX_STANDARD "${simulationdecomposition_cxx_standard}"
                      PUBLIC_HEADER "${simulationdecomposition_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${simulationdecomposition_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${simulationdecomposition_install_include_directory} )

#-----------------------------------------------------
# add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
