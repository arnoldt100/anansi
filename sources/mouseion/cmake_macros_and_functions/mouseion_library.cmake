# =====================================================================================
# 
#        Filename:  mouseion_library.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_mouseion
#  Description:  Defines key environmental variables enabalng the
#                building of the mouseion library.
# 
#  Arguments: top_level - The top level of the main CmakeLists.txt file.
#             minimum_cmake_version - The minumum cmake version for building mouseion
#             
# =====================================================================================
macro (enable_building_mouseion top_level
       minimum_cmake_version
       cxx_standard
       cmake_c_compiler 
       cmake_cxx_compiler
       install_prefix
       install_bin_directory
       install_include_directory
       install_lib_directory
       mouseion_top_level
       boost_top_level)

    set(ENV{MOUSEION_MINIMUM_CMAKE_VERSION} ${minimum_cmake_version}) 
    set(ENV{MOUSEION_CXX_STANDARD} ${cxx_standard})
    set(ENV{MOUSEION_CMAKE_C_COMPILER} ${cmake_c_compiler})
    set(ENV{MOUSEION_CMAKE_CXX_COMPILER} ${cmake_cxx_compiler})
    set(ENV{MOUSEION_INSTALL_PREFIX} ${install_prefix})
    set(ENV{MOUSEION_INSTALL_BIN_DIRECTORY} ${install_bin_directory}) 
    set(ENV{MOUSEION_INSTALL_INCLUDE_DIRECTORY} ${install_include_directory})
    set(ENV{MOUSEION_INSTALL_LIB_DIRECTORY} ${install_lib_directory})
    set(ENV{MOUSEION_LOG_FILE} "mouseion_log.txt")
    set(ENV{MOUSEION_TOP_LEVEL} ${mouseion_top_level})
    set(ENV{MOUSEION_BOOST_TOP_LEVEL} $ENV{ANANSI_BOOST_TOP_LEVEL})
endmacro()
