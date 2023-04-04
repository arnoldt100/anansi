
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
    add_subdirectory(MDOwnershipPolicies)

    # ----------------------------------------------------
    #  This section configure target genericmdtask.
    # 
    # ----------------------------------------------------
    package_config_begin_delimiter("genericmdtask" "${md_taskgroups_logfilepath}")

    include( ${CMAKE_CURRENT_SOURCE_DIR}/GenericMDTask/cmake_macros_and_functions/genericmdtask.cmake )
    enable_building_genericmdtask_package("${md_taskgroups_install_lib_directory}"
                                          "${md_taskgroups_install_include_directory}"
                                          "${md_taskgroups_install_bin_directory}"
                                          "${md_taskgroups_cxx_standard}"
                                          "${md_taskgroups_logfilepath}")

    add_subdirectory(GenericMDTask)

    package_config_end_delimiter("genericmdtask" "${md_taskgroups_logfilepath}")

    add_subdirectory(MPICommunicatorTask)
    add_subdirectory(ReadControlFile)
    add_subdirectory(CoreLoggingTasks)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

