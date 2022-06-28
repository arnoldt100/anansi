## =====================================================================================
##
##       Filename:  md_taskgroups.cmake
##
##    Description:  
##
##         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
##   Organization:  ORNL-National Center of Computational Sciences
##
## =====================================================================================

# ===  MACRO     ======================================================================
#         Name:  enable_building_md_taskgroups_packages
#  Description:  Defines key environmental variables enabling the
#                building of the md_tasks_groups packages.
# 
#  Arguments: 
#             install_lib_directory - The location to install the various sub-packages libraries
#             install_include_directory - The location to install various sub-package header files
#             install_bin_directory - The location to install sub-package binaraies
#             cxx_standard - The C++ standard to build the sub-package library and binaries
# =====================================================================================
macro ( enable_building_md_taskgroups_packages install_lib_directory
        install_include_directory
        install_bin_directory 
        cxx_standard
        logfilepath)

    set(md_taskgroups_install_lib_directory ${install_lib_directory})
    set(md_taskgroups_install_include_directory ${install_include_directory})
    set(md_taskgroups_install_bin_directory ${install_bin_directory} )
    set(md_taskgroups_cxx_standard ${cxx_standard} )
    set(md_taskgroups_logfilepath ${logfilepath} )
endmacro(enable_building_md_taskgroups_packages)
