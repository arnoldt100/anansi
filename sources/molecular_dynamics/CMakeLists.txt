#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
    include( cmake_macros_and_functions/project_properties.cmake )

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

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property(mm_include_dir memory_management memory_management_include)
    get_target_property(command_line_include_dir command_line_arguments command_line_arguments_include)
    get_target_property(simulation_parameters_include_dir simulation_parameters simulation_parameters_include)
    get_target_property(my_cc_include counterclass counterclass_include)
    get_target_property(my_cf_include  file_parsers file_parsers_include)
    get_target_property(my_mpl_include  mpl mpl_include)
    get_target_property(my_s_include  simulation simulation_include)
    get_target_property(my_ss_include  simulation_state simulation_state_include)
    get_target_property(my_comm_include  communicator simulation_state_include)
    get_target_property(my_mpicomm_include  mpi_communicator mpi_communicator_include)
    get_target_property(my_task_group_include task_group task_group_include)

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
        header_files/TaskGroupFactory.h
        header_files/DefaultTaskGroup.h
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
        implementation_files/DefaultTaskGroup.cpp
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
        implementation_files/TaskGroupFactory.cpp
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
                            PRIVATE ${my_cc_include}
                            PRIVATE ${my_cf_include}
                            PRIVATE ${my_s_include}
                            PRIVATE ${my_ss_include}
                            PRIVATE ${my_mpl_include}
                            PRIVATE ${my_mpicomm_include}
                            PRIVATE ${my_task_group_include} )

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${my_anansi_md_library}
                      string_utilities
                      communicator
                      simulation_parameters
                      command_line_arguments
                      counterclass
                      file_parsers
                      simulation
                      simulation_state
                      mpi_communicator
                      mpl
                      task_group
                      ${Boost_LIBRARIES} )

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
                      PRIVATE ${my_anansi_md_library} 
                      command_line_arguments
                      simulation_parameters
                      communicator
                      counterclass
                      mpl
                      simulation
                      simulation_state
                      mpi_communicator
                      task_group
                      ${Boost_LIBRARIES} )

                  
set_target_properties(${my_main_target_binary} PROPERTIES
                      CXX_STANDARD ${anansi_cxx_standard} )

install( TARGETS ${my_main_target_binary} 
         RUNTIME DESTINATION ${anansi_install_bin_directory} )
                     

#-----------------------------------------------------
# Add the unit tests.                                -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
