
#  =====================================================================================
# 
#        Filename:  enable_anansi_data_storage.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================



 
# ===  MACRO     ======================================================================
#         Name:  enable_anansi_data_storage
#  Description:  Enables various levels of Anansi calculation precision.
# 
#  Arguments: MY_TARGET; The target to enable the compile warnings.
# =====================================================================================

macro(enable_anansi_data_storage MY_TARGET)

     if (DEFINED ENV{ANANSI_DATA_POLICY})
         set(ENV_VARIABLE_IS_DEFINED 1) 	
     else()
        set(ENV_VARIABLE_IS_DEFINED 0) 	
     endif()

     target_compile_options(${MY_TARGET}
	     PRIVATE $<$<BOOL:ENV_VARIABLE_IS_DEFINED>: -DANANSI_DATA_POLICY=$ENV{ANANSI_DATA_POLICY} 
                                                    -DANANSI_LOW_PRECISION=$ENV{ANANSI_LOW_PRECISION} 
                                                    -DANANSI_HIGH_PRECISION=$ENV{ANANSI_HIGH_PRECISION} > )
 endmacro()
