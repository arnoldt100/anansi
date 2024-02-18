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
    get_target_property(my_common_md_taskgroup_headers_include common_md_taskgroup_headers common_md_taskgroup_headers_include)
    get_target_property(my_physical_data_structures_include  physical_data_structures physical_data_structures_include)


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
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/SDPConstructorHelpers.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/message_missing_mandatory_node_tag.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/simulation_decomposition_task_details/SimulationDecompositionTaskTraits.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/processor_lattice_spatial_dimensions/ProccesorTopologyLatticeSpatialDimensionsHelpers.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/processor_lattice_spatial_dimensions/processor_lattice_spatial_dimensions_details.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/workload_decomposition_type/WorkloadDecompositionTypeHelpers.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/workload_decomposition_type/workload_decomposition_type_details.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/processor_lattice_type/ProcessorTopologyLatticeTypeHelpers.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/processor_lattice_type/processor_lattice_type_details.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/processor_topology_number_compute_units_per_spatial_domain/ProcessorTopologyNumberComputeUnitsPerSpatialDomainHelpers.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/processor_topology_number_compute_units_per_spatial_domain/processor_topology_number_compute_units_per_spatial_domain_details.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/Exceptions/ErrorInvalidSimulationDecompositionParameters.h
         ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/Exceptions/ErrorMissingSimulationDecompositionParameters.h)

         # ----------------------------------------------------
         # Source files for ReadPointAtoms task
         # 
         # ----------------------------------------------------
         list( APPEND simulationdecomposition_header_files ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ReadPointAtoms/ReadPointAtomsResultsTraits.h)
         list( APPEND simulationdecomposition_header_files ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ReadPointAtoms/ReadPointAtomsResultsOwnershipImpl.hpp)
         list( APPEND simulationdecomposition_header_files ${CMAKE_CURRENT_SOURCE_DIR}/header_files/ReadPointAtoms/ReadPointAtoms.h)

         # ----------------------------------------------------
         # Source files for PointAtomsDecomposer task
         # 
         # ----------------------------------------------------
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/header_files/PointAtomsDecomposer/PointAtomsDecomposerResultsTraits.h)
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/header_files/PointAtomsDecomposer/PointAtomsDecomposerResultsOwnershipImpl.hpp)
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/header_files/PointAtomsDecomposer/PointAtomsDecomposer.h)

         # ----------------------------------------------------
         # Source files for PointAtomsCommunicator task
         # 
         # ----------------------------------------------------
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/header_files/PointAtomsCommunicator/PointAtomsCommunicatorResultsTraits.h)
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/header_files/PointAtomsCommunicator/PointAtomsCommunicatorResultsOwnershipImpl.hpp)
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/header_files/PointAtomsCommunicator/PointAtomsCommunicator.h)

         # ----------------------------------------------------
         # Source files for SimulationDecompositionTaskTraits 
         # 
         # ----------------------------------------------------
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/header_files/SimulationDecompositionTaskTraits.h)

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
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/SDPConstructorHelpers.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/message_missing_mandatory_node_tag.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/simulation_decomposition_task_details/SimulationDecompositionTaskTraits.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/processor_lattice_spatial_dimensions/ProccesorTopologyLatticeSpatialDimensionsHelpers.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/processor_lattice_spatial_dimensions/processor_lattice_spatial_dimensions_details.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/workload_decomposition_type/WorkloadDecompositionTypeHelpers.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/workload_decomposition_type/workload_decomposition_type_details.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/processor_lattice_type/ProcessorTopologyLatticeTypeHelpers.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/processor_lattice_type/processor_lattice_type_details.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/processor_topology_number_compute_units_per_spatial_domain/ProcessorTopologyNumberComputeUnitsPerSpatialDomainHelpers.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/processor_topology_number_compute_units_per_spatial_domain/processor_topology_number_compute_units_per_spatial_domain_details.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/Exceptions/ErrorInvalidSimulationDecompositionParameters.cpp
         ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/details/Exceptions/ErrorMissingSimulationDecompositionParameters.cpp)

         # ----------------------------------------------------
         # Source files for ReadPointAtoms task
         # 
         # ----------------------------------------------------
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ReadPointAtoms/ReadPointAtomsResultsTraits.cpp)
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ReadPointAtoms/ReadPointAtomsResultsOwnershipImpl.cpp)
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/ReadPointAtoms/ReadPointAtoms.cpp)

         # ----------------------------------------------------
         # Source files for PointAtomsDecomposer task
         # 
         # ----------------------------------------------------
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/PointAtomsDecomposer/PointAtomsDecomposerResultsTraits.cpp)
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/PointAtomsDecomposer/PointAtomsDecomposerResultsOwnershipImpl.cpp)
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/PointAtomsDecomposer/PointAtomsDecomposer.cpp)

         # ----------------------------------------------------
         # Source files for PointAtomsCinnunicator task
         # 
         # ----------------------------------------------------
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/PointAtomsCommunicator/PointAtomsCommunicatorResultsTraits.cpp)
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/PointAtomsCommunicator/PointAtomsCommunicatorResultsOwnershipImpl.cpp)
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/PointAtomsCommunicator/PointAtomsCommunicator.cpp)

         # ----------------------------------------------------
         # Source files for SimulationDecompositionTaskTraits 
         # 
         # ----------------------------------------------------
         list( APPEND simulationdecomposition_implementation_files ${CMAKE_CURRENT_SOURCE_DIR}/implementation_files/SimulationDecompositionTaskTraits.cpp)
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
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header_files"
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/Exceptions"
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header_files/ReadPointAtoms" 
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header_files/PointAtomsDecomposer" 
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header_files/PointAtomsCommunicator" 
                           PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/header_files/details"
                           PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/simulation_decomposition_task_details"
                           PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/processor_lattice_spatial_dimensions"
                           PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/workload_decomposition_type"
                           PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/processor_lattice_type"
                           PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/header_files/details/processor_topology_number_compute_units_per_spatial_domain"
                           PUBLIC "${my_physical_data_structures_include}"
                           PRIVATE "${my_common_md_taskgroup_headers_include}"
                           PRIVATE "${my_comm_include}" )

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${target}
                      PUBLIC communicator
                      PUBLIC common_md_taskgroup_headers )


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
