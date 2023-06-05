# =====================================================================================
#
#       Filename:  readcontrolfile.cmake
#
#    Description:  
#
#         Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#   Organization:  ORNL-National Center of Computational Sciences
#
# =====================================================================================

# ===  MACRO     ======================================================================
#         Name:  enable_building_readcontrolfile_package
#  Description:  Defines key environmental variables enabling the
#                building of the readcontrolfile packages.
# 
#  Arguments: 
#             install_lib_directory - The location to install the various libraries
#             install_include_directory - The location to install various header files
#             install_bin_directory - The location to install binaraies
#             cxx_standard - The C++ standard to build the library and binaries
# =====================================================================================
macro ( enable_building_readcontrolfile_package install_lib_directory
        install_include_directory
        install_bin_directory 
        cxx_standard
        logfilepath)

    set(readcontrolfile_install_lib_directory "${install_lib_directory}")
    set(readcontrolfile_install_include_directory "${install_include_directory}")
    set(readcontrolfile_install_bin_directory "${install_bin_directory}" )
    set(readcontrolfile_cxx_standard "${cxx_standard}" )
    set(readcontrolfile_logfilepath "${logfilepath}" )
endmacro()


