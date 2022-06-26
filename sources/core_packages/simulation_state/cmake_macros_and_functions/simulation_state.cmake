# =====================================================================================
# 
#        Filename:  simulation_state.cmake
# 
#     Description:  
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_simulation_state_package
#  Description:  Defines key environmental variables enabling the
#                building of the simulation state library.
# 
#  Arguments: 
#             install_lib_directory - The location to install the actual library
#             install_include_directory - The location to install header files
#             install_bin_directory - The location to install binaraies
#             cxx_standard - The C++ standard to build the library and binaries
#             logfilepath - The logging file path.
# =====================================================================================
macro ( enable_building_simulation_state_package install_lib_directory
        install_include_directory
        install_bin_directory 
        cxx_standard
        logfilepath)

    set(simulation_state_install_lib_directory ${install_lib_directory})
    set(simulation_state_install_include_directory ${install_include_directory})
    set(simulation_state_install_bin_directory ${install_bin_directory} )
    set(simulation_state_cxx_standard ${cxx_standard} )
    set(simulation_state_logfilepath ${logfilepath} )
endmacro()

