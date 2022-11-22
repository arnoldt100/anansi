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

// ---------------------------------------------------
// The section configures the initmpienvtask package.
// 
// ---------------------------------------------------
package_config_begin_delimiter("initmpienvtask" "${md_taskgroups_logfilepath}")

add_subdirectory(InitMPIEnvTask)

package_config_end_delimiter("initmpienvtask" "${md_taskgroups_logfilepath}")
// ---------------------------------------------------
// The section configures the initworldcommunicatortask package.
// 
// ---------------------------------------------------
add_subdirectory(InitWorldCommunicatorTask)
