# This CMakeLists.txt file creates the library libmpi_communicator.a
# and its unit tests. To add source files, simply append the appropiate variable
# mpi_communicator_header_files or mpi_communicator_implementation_files.
#
# The target for the library is mpi_communicator.
#
# The following properties are set for the target :
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
    # Include various functions and macros.              -
    #                                                    -
    #-----------------------------------------------------
    include(cmake_macros_and_functions/communicator_build_prerequisites.cmake)

    #-----------------------------------------------------
    # Verify key variables are set.                      -
    #                                                    -
    #-----------------------------------------------------
    verify_key_environmental_are_set()

    #-----------------------------------------------------
    # This library needs access to the following header  -
    # files:                                             -
    #                                                    -
    #   memory_management target header files            -
    #   string_utilities target header files             -
    #                                                    -
    # We get the path to the above header files.         -
    #-----------------------------------------------------
    get_target_property(my_mm_include memory_management memory_management_include)
    get_target_property(my_su_include string_utilities string_utilities_include)
    get_target_property(my_cc_include counterclass counterclass_include)

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
    # mpi_communicator_header_files.                     -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (mpi_communicator_header_files
         header_files/CommunicatorFactory.h
         header_files/Communicator.h
         header_files/Identification.h
         header_files/MasterSlaveIdentification.h
         header_files/MasterSlaveIdentification_Specialization_0.h
         header_files/MasterSlaveIdentification_Specialization_1.h
         header_files/MPIGather.h
         header_files/MPIAllgather.h
         header_files/MPIAllGatherException.h
         header_files/MPIGatherException.h
         header_files/MPIAllReduceException.h
         header_files/MPICommDuplicateException.h
         header_files/MPICommSplitException.h
         header_files/MPICommunicatorFactory.h
         header_files/MPICommunicator.h
         header_files/MPIDataType.h
         header_files/MPIFinalizedException.h
         header_files/MPIFreeException.h
         header_files/MPICommSizeException.h
         header_files/MPIGenericException.h
         header_files/MPIInitException.h
         header_files/MPIInitializedException.h
         header_files/MPIEnvironment.h
         header_files/MPIReduce.h
         header_files/MPIReductionOperation.h
         header_files/MPIUtilityFunctions.h
         header_files/MPIAllgather.h)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # mpi_communicator_implementation_files.             -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (mpi_communicator_implementation_files
         implementation_files/CommunicatorFactory.cpp
         implementation_files/Identification.cpp
         implementation_files/MasterSlaveIdentification.cpp
         implementation_files/MasterSlaveIdentification_Specialization_0.cpp
         implementation_files/MasterSlaveIdentification_Specialization_1.cpp
         implementation_files/MasterSlaveIdentification.cpp
         implementation_files/MPICommunicatorFactory.cpp 
         implementation_files/Communicator.cpp 
         implementation_files/MPIGather.cpp
         implementation_files/MPIDataType.cpp
         implementation_files/MPICommunicator.cpp
         implementation_files/MPIInitializedException.cpp
         implementation_files/MPICommSizeException.cpp
         implementation_files/MPIGenericException.cpp
         implementation_files/MPIFreeException.cpp
         implementation_files/MPICommSplitException.cpp
         implementation_files/MPIAllReduceException.cpp
         implementation_files/MPIFinalizedException.cpp
         implementation_files/MPIInitException.cpp
         implementation_files/MPIReductionOperation.cpp
         implementation_files/MPIEnvironment.cpp
         implementation_files/MPICommDuplicateException.cpp
         implementation_files/MPIAllGatherException.cpp
         implementation_files/MPIGatherException.cpp
         implementation_files/MPIUtilityFunctions.cpp
         implementation_files/MPIAllgather.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the mpi_communicator targets.                              @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# mpi_communicator.                                  -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
             "")

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

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
                           PRIVATE ${my_su_include}
                           PRIVATE ${my_mm_include}
                           PRIVATE ${my_cc_include})

#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
#-----------------------------------------------------
target_link_libraries( ${my_library_target}
                       string_utilities
                       memory_management 
                       counterclass )

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      mpi_communicator_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${mpi_communicator_cxx_standard}
                      PUBLIC_HEADER "${mpi_communicator_header_files}" )

install(TARGETS ${target}
        ARCHIVE DESTINATION ${mpi_communicator_install_lib_directory}
        PUBLIC_HEADER DESTINATION ${mpi_communicator_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
