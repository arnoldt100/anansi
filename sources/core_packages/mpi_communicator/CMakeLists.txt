# This CMakeLists.txt file creates the library libmpi_communicator.a
# and its unit tests. To add source files, simply append the appropiate variable
# mpi_communicator_header_files or mpi_communicator_implementation_files.
#
# The target for the library is mpi_communicator.
#
# The following properties are set for the target mpi_communicator.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#   mpi_communicator_include            ${CMAKE_CURRENT_SOURCE_DIR}/header_files            The location of the header files.
#   PUBLIC_HEADER                       ${mpi_communicator_header_files}                    The list of headers files associated with this librarry.
#
# The build will abort unless the following variables are defined to
# install the library archive, header files, and unit tests:
#   mpi_communicator_install_lib_directory
#   mpi_communicator_install_include_directory
#   mpi_communicator_install_bin_directory
#   mpi_communicator_cxx_standard



#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "mpi_communicator")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property(my_receiver_include receiver receiver_include)
    get_target_property(my_comm_include communicator communicator_include)
    get_target_property(my_mm_include memory_management memory_management_include)
    get_target_property(my_su_include string_utilities string_utilities_include)
    get_target_property(my_command_line_arguments_include command_line_arguments command_line_arguments_include)
    get_target_property(my_cc_include counterclass counterclass_include)
    get_target_property(my_debbugging_utilities_include debugging_utilities debugging_utilities_include)

    # ----------------------------------------------------
    #  Verify all build prerequisites are satisfied.
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/mpi_communicator_build_prerequisites.cmake")
    verify_mpi_communicator_build_prerequisites_are_met()

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
    set (mpi_communicator_header_files
         header_files/MPIFreeException.h
         header_files/MPIReductionOperation.h
         header_files/MPICommSplitException.h
         header_files/ErrorMPIBroadcast.h
         header_files/MPIBroadcast.h
         header_files/BroadcastVectorStringCache.h
         header_files/MPIBarrier.h
         header_files/MPIBarrierException.h
         header_files/MPICommDuplicateException.h
         header_files/MPIAllReduceException.h
         header_files/MPIReduce.h
         header_files/ErrorInvalidMPIEnvironmentChange.h
         header_files/MPIGenericException.h
         header_files/MPIAllGatherException.h
         header_files/MPIGatherException.h
         header_files/MPIDataType.h
         header_files/MPICommSizeException.h
         header_files/MPIFinalizedException.h
         header_files/MPIInitializedException.h
         header_files/MPIEnvironment.h
         header_files/Identification.h
         header_files/MPIGather.h
         header_files/MasterSlaveIdentification.h
         header_files/MPIAllgather.h
         header_files/MasterSlaveIdentification_Specialization_0.h
         header_files/MasterSlaveIdentification_Specialization_1.h
         header_files/MPIEnvironmentState.h
         header_files/MPIInitException.h
         header_files/MPIUtilityFunctions.h
         header_files/MPICommunicatorFactory.h
         header_files/DisabledMPIEnvironment.h
         header_files/EnabledMPIEnvironment.h 
         header_files/NullMPIEnvironment.h
         header_files/MPICommunicator.h
         header_files/MPIInitException.h
         header_files/details/create_cartesian_mpi_communicator.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (mpi_communicator_implementation_files
         implementation_files/MPIFreeException.cpp
         implementation_files/MPIReductionOperation.cpp
         implementation_files/MPICommSplitException.cpp
         implementation_files/ErrorMPIBroadcast.cpp
         implementation_files/MPIBroadcast.cpp
         implementation_files/BroadcastVectorStringCache.cpp
         implementation_files/MPIBarrier.cpp
         implementation_files/MPIBarrierException.cpp
         implementation_files/MPICommDuplicateException.cpp
         implementation_files/MPIAllReduceException.cpp
         implementation_files/MPIReduce.cpp
         implementation_files/ErrorInvalidMPIEnvironmentChange.cpp
         implementation_files/MPIGenericException.cpp
         implementation_files/MPIAllGatherException.cpp
         implementation_files/MPIGatherException.cpp
         implementation_files/MPIDataType.cpp
         implementation_files/MPICommSizeException.cpp
         implementation_files/MPIFinalizedException.cpp
         implementation_files/MPIInitializedException.cpp
         implementation_files/MPIEnvironment.cpp
         implementation_files/Identification.cpp
         implementation_files/MPIGather.cpp
         implementation_files/MasterSlaveIdentification.cpp
         implementation_files/MPIAllgather.cpp
         implementation_files/MasterSlaveIdentification_Specialization_0.cpp
         implementation_files/MasterSlaveIdentification_Specialization_1.cpp
         implementation_files/MPIEnvironmentState.cpp
         implementation_files/MPIInitException.cpp
         implementation_files/MPIUtilityFunctions.cpp
         implementation_files/MPICommunicatorFactory.cpp
         implementation_files/DisabledMPIEnvironment.cpp
         implementation_files/EnabledMPIEnvironment.cpp 
         implementation_files/NullMPIEnvironment.cpp
         implementation_files/MPICommunicator.cpp
         implementation_files/MPIInitException.cpp
         implementation_files/details/create_cartesian_mpi_communicator.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# mpi_communicator                                   -
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
    PRIVATE ${mpi_communicator_header_files} ${mpi_communicator_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${MPI_C_INCLUDE_DIRS}
                           PRIVATE ${my_command_line_arguments_include} 
                           PRIVATE ${my_receiver_include}
                           PRIVATE ${my_su_include}
                           PRIVATE ${my_comm_include} 
                           PRIVATE ${my_mm_include}
                           PRIVATE ${my_cc_include}
                           PRIVATE ${my_debbugging_utilities_include}
                           PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header_files/details )

                       
#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
#-----------------------------------------------------
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries( ${target}
                       PUBLIC MPI::MPI_C
                       PUBLIC receiver
                       PUBLIC command_line_arguments
                       PUBLIC Threads::Threads
                       PUBLIC string_utilities
                       PUBLIC communicator
                       PUBLIC memory_management 
                       PUBLIC counterclass
                       PUBLIC debugging_utilities)

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      mpi_communicator_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${mpi_communicator_cxx_standard}
                      PUBLIC_HEADER "${mpi_communicator_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION "${mpi_communicator_install_lib_directory}"
         PUBLIC_HEADER DESTINATION "${mpi_communicator_install_include_directory}" )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
