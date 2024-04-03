
#  =====================================================================================
# 
#        Filename:  enable_anansi_precision.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================



 
# ===  MACRO     ======================================================================
#         Name:  enable_anansi_precision
#  Description:  Enables various levels of Anansi calculation precision.
# 
#  Arguments: MY_TARGET; The target to enable the compile warnings.
# =====================================================================================

macro(enable_anansi_precision MY_TARGET)
     target_compile_options(${MY_TARGET}
         PRIVATE $<$<BOOL:$ENV${ANANSI_COMPUTE_PRECISION}>: -DANANSI_COMPUTE_PRECISION=$ENV{ANANSI_COMPUTE_PRECISION} 
                                                            -DANANSI_LOW_PRECISION=$ENV{ANANSI_LOW_PRECISION} 
                                                            -DANANSI_MEDIUM_PRECISION=$ENV{ANANSI_MEDIUM_PRECISION} 
                                                            -DANANSI_HIGH_PRECISION=$ENV{ANANSI_HIGH_PRECISION} > )
 endmacro()
