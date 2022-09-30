# The target for the library is md_taskgroups.
#
# The following properties are set for the target md_taskgroups.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#

# The build will abort unless the following variables are defined to
# install the library archive, header files and unit tests:
#   md_taskgroups_install_lib_directory
#   md_taskgroups_install_include_directory
#   md_taskgroups_install_bin_directory
#   md_taskgroups_logfilepath


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

    # configure the ingredients and tasks.
    add_subdirectory(Ingredients)
    add_subdirectory(MPIEnvTask)
    add_subdirectory(ConsoleLoggingTask)
    add_subdirectory(AnansiMDTaskFactory)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

