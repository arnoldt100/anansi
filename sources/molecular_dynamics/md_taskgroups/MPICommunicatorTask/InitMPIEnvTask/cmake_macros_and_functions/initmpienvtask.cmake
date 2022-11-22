# =====================================================================================
#
#       Filename:  initmpienvtask.cmake
#
#    Description:  
#
#         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#   Organization:  ORNL-National Center of Computational Sciences
#
# =====================================================================================

# ===  MACRO     ======================================================================
#         Name:  enable_building_initmpienvtask_package
#  Description:  Defines key environmental variables enabling the
#                building of the initmpienvtask packages.
# 
#  Arguments: 
#             install_lib_directory - The location to install the various libraries
#             install_include_directory - The location to install various header files
#             install_bin_directory - The location to install binaraies
#             cxx_standard - The C++ standard to build the library and binaries
# =====================================================================================
macro ( enable_building_initmpienvtask_package install_lib_directory
        install_include_directory
        install_bin_directory 
        cxx_standard
        logfilepath)

    set(initmpienvtask_install_lib_directory "${install_lib_directory}")
    set(initmpienvtask_install_include_directory "${install_include_directory}")
    set(initmpienvtask_install_bin_directory "${install_bin_directory}" )
    set(initmpienvtask_cxx_standard "${cxx_standard}" )
    set(initmpienvtask_logfilepath "${logfilepath}" )
endmacro()


