# =====================================================================================
# 
#        Filename:  file_parsers_core.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_file_parsers_core_library
#  Description:  Defines key environmental variables enabling the
#                building of the file parsers library.
# 
#  Arguments: 
#             install_lib_directory - The location to install the actual library
#             install_include_directory - The location to install header files
#             install_bin_directory - The location to install binaraies
#             cxx_standard - The C++ standard to build the library and binaries
#             logfilepath - The path to the logging file.
# =====================================================================================
macro ( enable_building_file_parsers_core_package 
        install_lib_directory
        install_include_directory
        install_bin_directory 
        cmake_c_compiler
        cmake_cxx_compiler
        cxx_standard
        logfilepath)

    set(file_parsers_core_install_lib_directory "${install_lib_directory}")
    set(file_parsers_core_install_include_directory "${install_include_directory}")
    set(file_parsers_core_install_bin_directory "${install_bin_directory}" )
    set(file_parsers_core_cmake_c_compiler "${cmake_c_compiler}" )
    set(file_parsers_core_cmake_cxx_compiler "${cmake_cxx_compiler}" )
    set(file_parsers_core_cxx_standard "${cxx_standard}" )
    set(file_parsers_core_logfilepath "${logfilepath}")
endmacro()
