# =====================================================================================
# 
#        Filename:  tasks.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_tasks_library
#  Description:  Defines key variables enabling the
#                building of the tasks library.
# 
#  Arguments: 
#             install_lib_directory - The location to install the actual library
#             install_include_directory - The location to install header files
#             install_bin_directory - The location to install binaraies
#             cxx_standard - The C++ standard to build the library and binaries
# =====================================================================================
macro ( enable_building_tasks_library install_lib_directory
                                      install_include_directory
                                      install_bin_directory 
                                      cmake_c_compiler
                                      cmake_cxx_compiler
                                      cxx_standard
                                      logfilepath)

    set(tasks_install_lib_directory ${install_lib_directory})
    set(tasks_install_include_directory ${install_include_directory})
    set(tasks_install_bin_directory ${install_bin_directory} )
    set(tasks_cmake_c_compiler ${cmake_c_compiler} )
    set(tasks_cmake_cxx_compiler ${cmake_cxx_compiler} )
    set(tasks_cxx_standard ${cxx_standard} )
    set(tasks_logfilepath ${logfilepath} )
endmacro()

