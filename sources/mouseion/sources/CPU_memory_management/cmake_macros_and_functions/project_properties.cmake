
#  =====================================================================================
# 
#        Filename:  project_properties.cmake
# 
#     Description:  Defines properties of the project.
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================



 
# ===  MACRO     ======================================================================
#         Name:  DEFINE_PROJECT_NAME 
#  Description:  Defines the project name. The variable my_project_name is defined
#                to the project name. 
# 
#  Arguments: 
# =====================================================================================
macro( DEFINE_PROJECT_NAME )
    set(my_project_name "memory_management")
endmacro()
