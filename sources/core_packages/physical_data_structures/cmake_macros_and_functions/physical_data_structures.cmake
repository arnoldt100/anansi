# =====================================================================================
# 
#        Filename:  physical_data_structures.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_physical_data_structures_package
#  Description:  Defines key environmental variables enabling the
#                building of the physical_data_structures library.
# 
#  Arguments: 
#             install_lib_directory - The location to install the actual library
#             install_include_directory - The location to install header files
#             install_bin_directory - The location to install binaraies
#             cxx_standard - The C++ standard to build the library and binaries
#             logfilepath - The path to the logging file.
# =====================================================================================
macro ( enable_building_physical_data_structures_package install_lib_directory
        install_include_directory
        install_bin_directory 
        cmake_c_compiler
        cmake_cxx_compiler
        cxx_standard
        logfilepath)

    set(physical_data_structures_install_lib_directory ${install_lib_directory})
    set(physical_data_structures_install_include_directory ${install_include_directory})
    set(physical_data_structures_install_bin_directory ${install_bin_directory} )
    set(physical_data_structures_cmake_c_compiler ${cmake_c_compiler} )
    set(physical_data_structures_cmake_cxx_compiler ${cmake_cxx_compiler} )
    set(physical_data_structures_cxx_standard ${cxx_standard} )
    set(physical_data_structures_logfilepath ${logfilepath})
endmacro()

