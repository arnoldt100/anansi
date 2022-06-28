# =====================================================================================
# 
#        Filename:  molecular_dynamics.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================

# ===  MACRO     ======================================================================
#         Name:  enable_building_molecular_dynamics_package
#  Description:  Defines key variables enabling the
#                building of the subpackages in molecular_dynamics. 
#
#  Arguments: 
#             install_lib_directory - The location to install the actual library files.
#             install_include_directory - The location to install the subpackages header files 
#             install_bin_directory - The location to install the subpackages binaraies
#             cxx_standard - The C++ standard to build the subpackages library and binaries
#             logfilepath - The path to the molecular_dynamics logging file.
# =====================================================================================
macro ( enable_building_molecular_dynamics_package
        minimum_cmake_version
        cxx_standard  
        cmake_c_compiler 
        cmake_cxx_compiler 
        install_prefix
        install_bin_directory
        install_include_directory
        install_lib_directory
        logfilepath) 

    set (molecular_dynamics_minimum_cmake_version ${minimum_cmake_version})
    set (molecular_dynamics_cxx_standard ${cxx_standard})
    set (molecular_dynamics_cmake_c_compiler ${cmake_c_compiler})
    set (molecular_dynamics_cmake_cxx_compiler ${cmake_cxx_compiler})
    set (molecular_dynamics_install_prefix ${install_prefix})
    set (molecular_dynamics_install_bin_directory ${install_bin_directory})
    set (molecular_dynamics_install_include_directory ${install_include_directory})
    set (molecular_dynamics_install_lib_directory ${install_lib_directory})
    set (molecular_dynamics_logfilepath ${logfilepath})


endmacro()
