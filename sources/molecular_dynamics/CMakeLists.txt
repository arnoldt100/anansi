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
    get_target_property(my_ss_include  simulation_state simulation_state_include)

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
        header_files/MolecularDynamicsTypeLists.h
        header_files/AnansiMolecularDynamics.h
        header_files/AnansiMDState.h
        header_files/AnansiMDStateNull.h
        header_files/AnansiMDStateISE.h
        header_files/AnansiMDStatePCL.h
        header_files/AnansiMDStateIIC.h
        header_files/AnansiMDStatePS.h
        header_files/AnansiMDStateTSE.h
        header_files/ISEStatus.h
        header_files/MolecularDynamics.h 
        header_files/MolecularDynamicsFactory.h 
        header_files/AnansiMolecularDynamicsFactory.h 
        header_files/AnansiMDStateTypeList.hpp
        header_files/AnansiMDStateInt2Type.hpp )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # anansi_md_library_implementation associated with   -
    # the molecular dynamics library                     -
    #                                                    -
    #-----------------------------------------------------
    set (anansi_md_library_implementation  
        implementation_files/MolecularDynamicsTypeLists.cpp
        implementation_files/AnansiMolecularDynamics.cpp
        implementation_files/AnansiMDState.cpp
        implementation_files/AnansiMDStateNull.cpp
        implementation_files/AnansiMDStateISE.cpp
        implementation_files/AnansiMDStatePCL.cpp
        implementation_files/AnansiMDStateIIC.cpp
        implementation_files/AnansiMDStatePS.cpp
        implementation_files/AnansiMDStateTSE.cpp
        implementation_files/ISEStatus.cpp
        implementation_files/MolecularDynamics.cpp
        implementation_files/MolecularDynamicsFactory.cpp
        implementation_files/AnansiMolecularDynamicsFactory.cpp 
        implementation_files/AnansiMDStateInt2Type.cpp
        implementation_files/AnansiMDStateTypeList.cpp)

 
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
                            PRIVATE ${my_ss_include}
                            PRIVATE ${my_mpl_include} )

#-----------------------------------------------------
# Set the list of libraries to link against.         -
#                                                    -
#-----------------------------------------------------
target_link_libraries(${my_anansi_md_library}
                      string_utilities
                      mpi_communicator
                      simulation_parameters
                      command_line_arguments
                      counterclass
                      file_parsers
                      simulation_state
                      mpl
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
                      mpi_communicator
                      counterclass
                      mpl
                      simulation_state
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
