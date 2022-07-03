#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(target "molecular_dynamics")
    project("${target}")

    # ----------------------------------------------------
    # Verify that all molecular_dynamics build prerequisities
    # are satisfied.
    # 
    # ----------------------------------------------------
    include("${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/molecular_dynamics_build_prerequisites.cmake")
    verify_molecular_dynamics_build_prerequisites_are_met()

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

# ----------------------------------------------------
# This section configures the md_taskgroups package.
# 
# ----------------------------------------------------
package_config_begin_delimiter("md_taskgroups" "${molecular_dynamics_logfilepath}")

include( ${CMAKE_CURRENT_SOURCE_DIR}/md_taskgroups/cmake_macros_and_functions/md_taskgroups.cmake )

enable_building_md_taskgroups_packages("${molecular_dynamics_install_lib_directory}"
                                       "${molecular_dynamics_install_include_directory}"
                                       "${molecular_dynamics_install_bin_directory}"
                                       "${molecular_dynamics_cxx_standard}"
                                       "${molecular_dynamics_logfilepath}")
add_subdirectory(md_taskgroups)

package_config_end_delimiter("md_taskgroups" "${molecular_dynamics_logfilepath}")



# ----------------------------------------------------
# This section configures the md_core_package package.
# 
# ----------------------------------------------------
package_config_begin_delimiter("md_core_package" "${molecular_dynamics_logfilepath}")

include( ${CMAKE_CURRENT_SOURCE_DIR}/md_core_package/cmake_macros_and_functions/md_core_package.cmake )

enable_building_md_core_package("${molecular_dynamics_install_lib_directory}"
                                "${molecular_dynamics_install_include_directory}"
                                "${molecular_dynamics_install_bin_directory}"
                                "${molecular_dynamics_cxx_standard}"
                                "${molecular_dynamics_logfilepath})"

add_subdirectory(md_core_package)

#[[

package_config_end_delimiter("md_core_package" "${molecular_dynamics_logfilepath}")

# ----------------------------------------------------
# This section configures the molecular_dynamics_main package.
# 
# ----------------------------------------------------
package_config_begin_delimiter("molecular_dynamics_main" "${molecular_dynamics_logfilepath}")

include( ${CMAKE_CURRENT_SOURCE_DIR}/molecular_dynamics_main/cmake_macros_and_functions/molecular_dynamics_main.cmake )

enable_building_molecular_dynamics_main_package("${molecular_dynamics_install_lib_directory}"
                                                "${molecular_dynamics_install_include_directory}"
                                                "${molecular_dynamics_install_bin_directory}"
                                                "${molecular_dynamics_cxx_standard}"
                                                "${molecular_dynamics_logfilepath}")
add_subdirectory(molecular_dynamics_main)

package_config_end_delimiter("molecular_dynamics_main" "${molecular_dynamics_logfilepath}")

]]
