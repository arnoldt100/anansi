#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    include( cmake_macros_and_functions/project_properties.cmake )
    include( ${CMAKE_CURRENT_SOURCE_DIR}/md_taskgroups/cmake_macros_and_functions/md_taskgroups.cmake )

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    DEFINE_PROJECT_NAME() 
    project(${molecular_dynamics_project_name})

    #-----------------------------------------------------
    # Define the variable my_main_target_binary.         -
    # This variable stores the name of main md binary.   -
    #                                                    -
    #-----------------------------------------------------
    string(TOLOWER ${PROJECT_NAME}_md my_main_target_binary)

    #-----------------------------------------------------
    # Define the variable anansi.                        -
    # This variable stores the name if the anansi md     -
    # target.                                            -
    #                                                    -
    #-----------------------------------------------------
    string(TOLOWER ${PROJECT_NAME} my_anansi_md_library)

    # ----------------------------------------------------
    # Verify that all molecular_dynamics build prerequisities
    # are satisfied.
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/molecular_dynamics_build_prerequisites.cmake")
    verify_molecular_dynamics_build_prerequisites_are_met()

    # ----------------------------------------------------
    # This section configures the md_taskgroups package.
    # 
    # ----------------------------------------------------
    package_config_begin_delimiter("md_taskgroups" "${molecular_dynamics_logfilepath}")
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/molecular_dynamics.cmake")
    enable_building_md_taskgroups_packages(${molecular_dynamics_install_lib_directory}
                                           ${molecular_dynamics_install_include_directory}
                                           ${molecular_dynamics_install_bin_directory}
                                           ${molecular_dynamics_cxx_standard}
                                           ${molecular_dynamics_logfilepath})
    add_subdirectory(md_taskgroups)
    package_config_end_delimiter("md_taskgroups" "${molecular_dynamics_logfilepath}")

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property(mm_include_dir memory_management memory_management_include)
    get_target_property(my_command_line_include_dir command_line_arguments command_line_arguments_include)
    get_target_property(simulation_parameters_include_dir simulation_parameters simulation_parameters_include)
    get_target_property(my_cc_include counterclass counterclass_include)
    get_target_property(my_cf_include  file_parsers file_parsers_include)
    get_target_property(my_generic_abstract_factory_include generic_abstract_factory generic_abstract_factory_include )
    get_target_property(my_s_include  simulation simulation_include)
    get_target_property(my_ss_include  simulation_state simulation_state_include)
    get_target_property(my_comm_include  communicator simulation_state_include)
    get_target_property(my_mpicomm_include  mpi_communicator mpi_communicator_include)
    get_target_property(my_task_group_include task_group task_group_include)
    get_target_property(my_foreach_loop_include generic_foreach_loop generic_foreach_loop_include)
    get_target_property(my_md_taskgroup_include md_taskgroups md_taskgroups_include)


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
    # anansi_main_md_public_headers that stores header   -
    # files associated with the anansi_main_md target.   -
    #                                                    -
    #-----------------------------------------------------
    set(anansi_main_md_public_headers 
        header_files/anansi_main_md.h )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_main_md_public_implementation that stores   -
    # implementation files associated with the           -
    # anansi_main_md target.                             -
    #                                                    -
    #-----------------------------------------------------
    set(anansi_main_md_public_implementation
        implementation_files/anansi_main_md.cpp )

    
    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_md_library_headers associated with the      -
    # molecular dynamics library                         -
    #                                                    -
    #-----------------------------------------------------
    set (anansi_md_library_headers  
        header_files/AnansiMolecularDynamics.h
        header_files/MDNullSimulationVisitor.h
        header_files/MDNullSimulation.h
        header_files/MDInitSimEnv.h
        header_files/MDInitSimEnvVisitor.h
        header_files/MDProcessCmdLine.h
        header_files/MDProcessCmdLineVisitor.h
        header_files/MDInitInitialConditions.h
        header_files/MDInitInitialConditionsVisitor.h
        header_files/MDPerformSimulationVisitor.h
        header_files/MDPerformSimulation.h
        header_files/MDTerminateSimulationVisitor.h
        header_files/MDTerminateSimulation.h
        header_files/MDSimulationStateFactory.h
        header_files/ISEStatus.h
        header_files/AnansiMolecularDynamicsFactory.h 
        header_files/AnansiMDStateInt2Type.hpp)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_md_library_implementation associated with   -
    # the molecular dynamics library                     -
    #                                                    -
    #-----------------------------------------------------
    set (anansi_md_library_implementation  
        implementation_files/AnansiMolecularDynamics.cpp
        implementation_files/MDNullSimulationVisitor.cpp
        implementation_files/MDNullSimulation.cpp
        implementation_files/MDInitSimEnv.cpp
        implementation_files/MDInitSimEnvVisitor.cpp
        implementation_files/MDProcessCmdLine.cpp
        implementation_files/MDProcessCmdLineVisitor.cpp
        implementation_files/MDInitInitialConditions.cpp
        implementation_files/MDInitInitialConditionsVisitor.cpp
        implementation_files/MDPerformSimulationVisitor.cpp
        implementation_files/MDPerformSimulation.cpp
        implementation_files/MDTerminateSimulationVisitor.cpp
        implementation_files/MDTerminateSimulation.cpp
        implementation_files/MDSimulationStateFactory.cpp
        implementation_files/ISEStatus.cpp
        implementation_files/AnansiMolecularDynamicsFactory.cpp 
        implementation_files/AnansiMDStateInt2Type.cpp)

 
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the anansi_md targets.                                     @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Start of section that adds the anansi libray target.            @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the  library target called from the source     -
# files listed in the command invocation.            -
#                                                    -
#-----------------------------------------------------
add_library( ${my_anansi_md_library} STATIC 
             "" )

target_sources(${my_anansi_md_library}
               PRIVATE ${anansi_md_library_implementation} ${anansi_md_library_headers}  )

#-----------------------------------------------------
# Set the list of directories to search for          -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories( ${my_anansi_md_library} 
                            PUBLIC header_files
                            PRIVATE ${Boost_INCLUDE_DIR}
                            PRIVATE ${my_command_line_include_dir}
                            PRIVATE ${my_cc_include}
                            PRIVATE ${my_cf_include}
                            PRIVATE ${my_s_include}
                            PRIVATE ${my_ss_include}
                            PRIVATE ${my_mpicomm_include}
                            PRIVATE ${my_task_group_include} 
                            PRIVATE ${my_generic_abstract_factory_include}
                            PRIVATE ${my_foreach_loop_include} 
                            PRIVATE ${my_md_taskgroup_include} )

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${my_anansi_md_library}
                      PUBLIC string_utilities
                      PUBLIC communicator
                      PUBLIC simulation_parameters
                      PUBLIC command_line_arguments
                      PUBLIC counterclass
                      PUBLIC file_parsers
                      PUBLIC simulation
                      PUBLIC simulation_state
                      PUBLIC mpi_communicator
                      PUBLIC task_group
                      PUBLIC generic_abstract_factory
                      PUBLIC generic_foreach_loop
                      PUBLIC md_taskgroups
                      PUBLIC ${Boost_LIBRARIES} )

#-----------------------------------------------------
# Here we set the propertes on target.               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${my_anansi_md_library} PROPERTIES 
    PUBLIC_HEADER "${anansi_md_library_headers}" 
    CXX_STANDARD ${anansi_cxx_standard} )

install( TARGETS ${my_anansi_md_library}
         ARCHIVE DESTINATION ${anansi_install_lib_directory}
         PUBLIC_HEADER DESTINATION ${anansi_install_include_directory} )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Start of section that adds the main binary target.              @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

add_executable( ${my_main_target_binary}
                "" )

add_dependencies(${my_main_target_binary} 
                 ${my_anansi_md_library})

target_sources(${my_main_target_binary}
               PRIVATE ${anansi_main_md_public_implementation} ${anansi_main_md_public_headers} )

target_include_directories( ${my_main_target_binary} 
                            PUBLIC header_files 
                            PRIVATE ${Boost_INCLUDE_DIR} )

target_link_libraries(${my_main_target_binary}
                      PRIVATE ${my_anansi_md_library} )

                  
set_target_properties(${my_main_target_binary} PROPERTIES
                      CXX_STANDARD ${anansi_cxx_standard} )

install( TARGETS ${my_main_target_binary} 
         RUNTIME DESTINATION ${anansi_install_bin_directory} )
                     

#-----------------------------------------------------
# Add the unit tests.                                -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
