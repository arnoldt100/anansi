# =====================================================================================
# 
#        Filename:  task_group.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================


# ===  MACRO     ======================================================================
#         Name:  enable_building_task_group_library
#  Description:  Defines key variables enabling the
#                building of the task_group library.
# 
#  Arguments: 
#             install_lib_directory - The location to install the actual library
#             install_include_directory - The location to install header files
#             install_bin_directory - The location to install binaraies
#             cxx_standard - The C++ standard to build the library and binaries
# =====================================================================================
macro ( enable_building_task_group_library install_lib_directory
        install_include_directory
        install_bin_directory 
        cxx_standard)

    set(task_group_install_lib_directory ${install_lib_directory})
    set(task_group_install_include_directory ${install_include_directory})
    set(task_group_install_bin_directory ${install_bin_directory} )
    set(task_group_cxx_standard ${cxx_standard} )
endmacro()

