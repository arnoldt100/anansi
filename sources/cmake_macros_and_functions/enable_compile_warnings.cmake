
#  =====================================================================================
# 
#        Filename:  enable_compile_warnings.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================



 
# ===  MACRO     ======================================================================
#         Name:  enable_compile_warnings
#  Description:  Enables compile warnings on target.
# 
#  Arguments: MY_TARGET; The target to enable the compile warnings.
# =====================================================================================

macro(enable_compile_warnings MY_TARGET)

    target_compile_options(${MY_TARGET}
                           PRIVATE  $<$<CXX_COMPILER_ID:GNU>:-Wall>)
endmacro()
