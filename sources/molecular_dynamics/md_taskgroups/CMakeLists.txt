
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

    # ----------------------------------------------------
    #  This section configures target mdownershippolicies.
    # 
    # ----------------------------------------------------
    
    package_config_begin_delimiter("mdownershippolicies" "${md_taskgroups_logfilepath}")

    include( ${CMAKE_CURRENT_SOURCE_DIR}/MDOwnershipPolicies/cmake_macros_and_functions/mdownershippolicies.cmake )

    enable_building_mdownershipolicies_package("${md_taskgroups_install_lib_directory}"
                                               "${md_taskgroups_install_include_directory}"
                                               "${md_taskgroups_install_bin_directory}"
                                               "${md_taskgroups_cxx_standard}"
                                               "${md_taskgroups_logfilepath}")

    add_subdirectory(MDOwnershipPolicies)

    package_config_end_delimiter("mdownershippolicies" "${md_taskgroups_logfilepath}")
    
    # ----------------------------------------------------
    #  (End of section)
    # ----------------------------------------------------

    # ----------------------------------------------------
    #  This section configures target genericmdtask.
    # 
    # ----------------------------------------------------
    package_config_begin_delimiter("genericmdtask" "${md_taskgroups_logfilepath}")

    include( ${CMAKE_CURRENT_SOURCE_DIR}/GenericMDTask/cmake_macros_and_functions/genericmdtask.cmake )

    enable_building_genericmdtask_package("${md_taskgroups_install_lib_directory}"
                                          "${md_taskgroups_install_include_directory}"
                                          "${md_taskgroups_install_bin_directory}"
                                          "${md_taskgroups_cxx_standard}"
                                          "${md_taskgroups_logfilepath}")

    package_config_end_delimiter("genericmdtask" "${md_taskgroups_logfilepath}")
    # ----------------------------------------------------
    #  (End of section)
    # ----------------------------------------------------


    add_subdirectory(GenericMDTask)


    # ----------------------------------------------------
    #  This section configures targets in MPICommunicatorTask.
    # 
    # ----------------------------------------------------
    add_subdirectory(MPICommunicatorTask)

    # ----------------------------------------------------
    #  (End of section)
    # ----------------------------------------------------

    # ----------------------------------------------------
    #  This section configures target readcontrolfile.
    # 
    # ----------------------------------------------------
    package_config_begin_delimiter("readcontrolfile" "${md_taskgroups_logfilepath}")

    include( ${CMAKE_CURRENT_SOURCE_DIR}/ReadControlFile/cmake_macros_and_functions/readcontrolfile.cmake )
    enable_building_readcontrolfile_package("${md_taskgroups_install_lib_directory}"
                                            "${md_taskgroups_install_include_directory}"
                                            "${md_taskgroups_install_bin_directory}"
                                            "${md_taskgroups_cxx_standard}"
                                            "${md_taskgroups_logfilepath}")
    add_subdirectory(ReadControlFile)

    package_config_end_delimiter("readcontrolfile" "${md_taskgroups_logfilepath}")
    
    # ----------------------------------------------------
    #  (End of section)
    # ----------------------------------------------------

    # ----------------------------------------------------
    #  This section configures targets in CoreLoggingTasks
    # 
    # ----------------------------------------------------

    add_subdirectory(CoreLoggingTasks)

    # ----------------------------------------------------
    #  (End of section)
    # ----------------------------------------------------

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

