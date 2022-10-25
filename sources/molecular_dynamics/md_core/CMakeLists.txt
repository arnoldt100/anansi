# This CMakeLists.txt file creates the library libmd_core.a
# and its unit tests. To add source files, simply append the appropiate variable
# md_core_header_files or md_core_implementation_files.
#
# The target for the library is md_core.
#
# The following properties are set for the target md_core.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#  md_core_include                      "${CMAKE_CURRENT_SOURCE_DIR}/header_files"          The location of the header files for
#                                                                                           this package.



#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "md_core")
    project("${my_project_name}")

    #-----------------------------------------------------
    # Define the target name variable.                   -
    #                                                    -
    #-----------------------------------------------------
    set(md_core_target "${PROJECT_NAME}")

    # ----------------------------------------------------
    # Verify the md_core target build prerequisites are met
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/md_core_build_prerequisites.cmake")
    verify_md_core_build_prerequisites_are_met()

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
    get_target_property(my_comm_include  communicator communicator_include)
    get_target_property(my_mpicomm_include  mpi_communicator mpi_communicator_include)
    get_target_property(my_tasks_include tasks tasks_include)
    get_target_property(my_foreach_loop_include generic_foreach_loop generic_foreach_loop_include)
    get_target_property(my_mdanansitaskfactory_include mdanansitaskfactory mdanansitaskfactory_include )
    get_target_property(my_mpienvtask_include mpienvtask mpienvtask_include )
    get_target_property(my_genericmdtask_include genericmdtask genericmdtask_include )
    get_target_property(my_invoker_include invoker invoker_include )

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
    # Here we define the variable
    # md_core_library_headers associated
    # with the molecular dynamics library
    # 
    #-----------------------------------------------------
    set (md_core_header_files
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
    
    # ----------------------------------------------------
    # These files are for communicattion environment invoker.
    # 

    #-----------------------------------------------------
    # Here we define the variable                        -
    # md_core_library_implementation associated with     -
    # the molecular dynamics library                     -
    #                                                    -
    #-----------------------------------------------------
    set (md_core_implementation_files
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
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with md_core_target
#
#-----------------------------------------------------
add_library( "${md_core_target}" STATIC 
             "")

#-----------------------------------------------------
# Set the list of directories to search for          -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories( "${md_core_target}" 
                            PUBLIC header_files
                            PRIVATE "${Boost_INCLUDE_DIR}"
                            PRIVATE "${my_command_line_include_dir}"
                            PRIVATE "${my_cc_include}"
                            PRIVATE "${my_cf_include}"
                            PRIVATE "${my_s_include}"
                            PRIVATE ${my_mpienvtask_include}
                            PRIVATE ${my_genericmdtask_include}
                            PRIVATE ${my_ss_include}
                            PRIVATE ${my_mpicomm_include}
                            PRIVATE ${my_tasks_include} 
                            PRIVATE ${my_invoker_include}
                            PRIVATE ${my_generic_abstract_factory_include}
                            PRIVATE ${my_foreach_loop_include} 
                            PRIVATE ${my_mdanansitaskfactory_include} )

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries("${md_core_target}"
                      PUBLIC string_utilities
                      PUBLIC communicator
                      PUBLIC simulation_parameters
                      PUBLIC command_line_arguments
                      PUBLIC counterclass
                      PUBLIC mpienvtask
                      PUBLIC genericmdtask
                      PUBLIC file_parsers
                      PUBLIC simulation
                      PUBLIC simulation_state
                      PUBLIC mpi_communicator
                      PUBLIC tasks
                      PUBLIC invoker
                      PUBLIC generic_abstract_factory
                      PUBLIC generic_foreach_loop
                      PUBLIC mdanansitaskfactory
                      PUBLIC "${Boost_LIBRARIES}" )

#-----------------------------------------------------
# We associate the source files with the md_core_target.
# 
#-----------------------------------------------------
target_sources("${md_core_target}"
    PRIVATE "${md_core_header_files}" "${md_core_implementation_files}" )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories("${md_core_target}" 
                           PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header_files" )

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings("${md_core_target}")

#-----------------------------------------------------
# Here we set the properties on md_core_target.
#
#-----------------------------------------------------
set_target_properties("${md_core_target}" PROPERTIES 
    PUBLIC_HEADER "${md_core_library_headers}" 
    CXX_STANDARD "${md_core_cxx_standard}" )

install( TARGETS "${md_core_target}"
         ARCHIVE DESTINATION "${md_core_install_lib_directory}"
         PUBLIC_HEADER DESTINATION "${md_core_install_include_directory}" )

set_target_properties("${md_core_target}" PROPERTIES
                      md_core_include "${CMAKE_CURRENT_SOURCE_DIR}/header_files"
                      PUBLIC_HEADER "${md_core_header_files}" )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
