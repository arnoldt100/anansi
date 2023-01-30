
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    # ----------------------------------------------------
    # Verify the prerequisites for configuring package
    # md_taskgroups are satisfied.
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/md_taskgroups_build_prerequisites.cmake")
    verify_md_taskgroups_build_prerequisites_are_met()

    # Configure the tasks.
    add_subdirectory(GenericMDTask)
    add_subdirectory(MPICommunicatorTask)
    add_subdirectory(ReadControlFile)
    add_subdirectory(AnansiMDTaskFactory)
    add_subdirectory(CoreLoggingTasks)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

