# =====================================================================================
# 
#        Filename:  core_packages.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================

# ===  MACRO     ======================================================================
#         Name:  enable_building_core_packages_package
#  Description:  Defines key variables enabling the
#                building of the subpackages in core_packages. 
#
#                The variable core_packages_required_variables is a list
#                whose elements are the names of the required key variables
#                that must be defined, this list of variable names must match 
#                the variables names in the function's argument.               
# 
#  Arguments: 
#             install_lib_directory - The location to install the actual library files.
#             install_include_directory - The location to install the subpackages header files 
#             install_bin_directory - The location to install the subpackages binaraies
#             cxx_standard - The C++ standard to build the subpackages library and binaries
#             logfilepath - The path to the core_packages logging file.
# =====================================================================================
macro ( enable_building_core_packages_package
        minimum_cmake_version
        cxx_standard  
        cmake_c_compiler 
        cmake_cxx_compiler 
        install_prefix
        install_bin_directory
        install_include_directory
        install_lib_directory
        logfilepath) 

    set (core_packages_minimum_cmake_version ${minimum_cmake_version})
    set (core_packages_cxx_standard ${cxx_standard})
    set (core_packages_cmake_c_compiler ${cmake_c_compiler})
    set (core_packages_cmake_cxx_compiler ${cmake_cxx_compiler})
    set (core_packages_install_prefix ${install_prefix})
    set (core_packages_install_bin_directory ${install_bin_directory})
    set (core_packages_install_include_directory ${install_include_directory})
    set (core_packages_install_lib_directory ${install_lib_directory})
    set (core_packages_logfilepath ${logfilepath})


endmacro()
