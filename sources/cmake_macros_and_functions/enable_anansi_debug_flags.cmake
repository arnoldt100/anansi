
#  =====================================================================================
# 
#        Filename:  enable_anansi_debug_flags.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================

 
# ===  MACRO     ======================================================================
#         Name:  enable__anansi_debug_flags
#  Description:  Enables debug flags for target
# 
#  Arguments: MY_TARGET; The target to enable the debug flags.
# =====================================================================================

macro(enable_anansi_debug_flags MY_TARGET)

    target_compile_options(${MY_TARGET}
        PRIVATE $<$ENV{ANANSI_DEBUG_VALID_VALUES}:-DANANSI_DBG_VALID_VALUES>)
endmacro()
