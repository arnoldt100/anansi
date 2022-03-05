# =====================================================================================
# 
#        Filename:  simulation_state.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_simulation_state_library
#  Description:  Defines key environmental variables enabling the
#                building of the simulation state library.
# 
#  Arguments: 
#             install_lib_directory - The location to install the actual library
#             install_include_directory - The location to install header files
#             install_bin_directory - The location to install binaraies
#             cxx_standard - The C++ standard to build the library and binaries
# =====================================================================================
macro ( enable_building_simulation_state_library install_lib_directory
        install_include_directory
        install_bin_directory 
        cxx_standard)

    set(simulation_state_install_lib_directory ${install_lib_directory})
    set(simulation_state_install_include_directory ${install_include_directory})
    set(simulation_state_install_bin_directory ${install_bin_directory} )
    set(simulation_state_cxx_standard ${cxx_standard} )
endmacro()
