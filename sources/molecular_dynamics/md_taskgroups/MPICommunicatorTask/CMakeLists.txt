#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#---------------------------------------------------
# The section configures the initmpienvtask package.
#
#---------------------------------------------------
package_config_begin_delimiter("initmpienvtask" "${md_taskgroups_logfilepath}")

include( ${CMAKE_CURRENT_SOURCE_DIR}/InitMPIEnvTask/cmake_macros_and_functions/initmpienvtask.cmake )

enable_building_initmpienvtask_package("${md_taskgroups_install_lib_directory}"
                                       "${md_taskgroups_install_include_directory}"
                                       "${md_taskgroups_install_bin_directory}"
                                       "${md_taskgroups_cxx_standard}"
                                       "${md_taskgroups_logfilepath}")

add_subdirectory(InitMPIEnvTask)

package_config_end_delimiter("initmpienvtask" "${md_taskgroups_logfilepath}")


#---------------------------------------------------
#The section configures the initworldcommunicatortask package.
#
#---------------------------------------------------
package_config_begin_delimiter("initworldcommunicator" "${md_taskgroups_logfilepath}")

include( ${CMAKE_CURRENT_SOURCE_DIR}/InitWorldCommunicatorTask/cmake_macros_and_functions/initworldcommunicator.cmake )

enable_building_initworldcommunicator_package("${md_taskgroups_install_lib_directory}"
                                              "${md_taskgroups_install_include_directory}"
                                              "${md_taskgroups_install_bin_directory}"
                                              "${md_taskgroups_cxx_standard}"
                                              "${md_taskgroups_logfilepath}")

add_subdirectory(InitWorldCommunicatorTask)

package_config_end_delimiter("initworldcommunicator" "${md_taskgroups_logfilepath}")
