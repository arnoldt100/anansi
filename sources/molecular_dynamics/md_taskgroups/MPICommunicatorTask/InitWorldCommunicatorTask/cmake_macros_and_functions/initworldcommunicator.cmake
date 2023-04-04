# =====================================================================================
#
#       Filename:  initworldcommunicator.cmake
#
#    Description:  
#
#         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#   Organization:  ORNL-National Center of Computational Sciences
#
# =====================================================================================

# ===  MACRO     ======================================================================
#         Name:  enable_building_initworldcommunicator_package
#  Description:  Defines key environmental variables enabling the
#                building of the initworldcommunicator packages.
# 
#  Arguments: 
#             install_lib_directory - The location to install the various libraries
#             install_include_directory - The location to install various header files
#             install_bin_directory - The location to install binaraies
#             cxx_standard - The C++ standard to build the library and binaries
# =====================================================================================
macro ( enable_building_initworldcommunicator_package install_lib_directory
        install_include_directory
        install_bin_directory 
        cxx_standard
        logfilepath)

    set(initworldcommunicator_install_lib_directory "${install_lib_directory}")
    set(initworldcommunicator_install_include_directory "${install_include_directory}")
    set(initworldcommunicator_install_bin_directory "${install_bin_directory}" )
    set(initworldcommunicator_cxx_standard "${cxx_standard}" )
    set(initworldcommunicator_logfilepath "${logfilepath}" )
endmacro()

