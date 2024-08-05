

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
# The section configures the writetexttoconsoletask package.
#
#---------------------------------------------------
package_config_begin_delimiter("writetexttoconsoletask" "${md_taskgroups_logfilepath}")

include( ${CMAKE_CURRENT_SOURCE_DIR}/WriteTextToConsoleTask/cmake_macros_and_functions/writetexttoconsoletask.cmake )

enable_building_writetexttoconsoletask_package("${md_taskgroups_install_lib_directory}"
                                               "${md_taskgroups_install_include_directory}"
                                               "${md_taskgroups_install_bin_directory}"
                                               "${md_taskgroups_cxx_standard}"
                                               "${md_taskgroups_logfilepath}")

add_subdirectory(WriteTextToConsoleTask)

package_config_end_delimiter("writetexttoconsoletask"
    "${md_taskgroups_logfilepath}")
