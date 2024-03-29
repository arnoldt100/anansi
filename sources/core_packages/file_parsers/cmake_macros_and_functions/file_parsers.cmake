# =====================================================================================
# 
#        Filename:  file_parsers.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_file_parsers_library
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
macro ( enable_building_file_parsers_package 
        install_lib_directory
        install_include_directory
        install_bin_directory 
        cxx_standard
        logfilepath)

    set(file_parsers_install_lib_directory "${install_lib_directory}")
    set(file_parsers_install_include_directory "${install_include_directory}")
    set(file_parsers_install_bin_directory "${install_bin_directory}" )
    set(file_parsers_cxx_standard "${cxx_standard}" )
    set(file_parsers_logfilepath "${logfilepath}")
endmacro()
