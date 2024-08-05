
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
#  Description:  Enables whether the calculation is cpu or gpu centered.
# 
#  Arguments: MY_TARGET; The target to enable the definitions.
# =====================================================================================

macro(enable_anansi_data_storage MY_TARGET)

     if (DEFINED ENV{ANANSI_DATA_POLICY})
         set(ENV_VARIABLE_IS_DEFINED 1) 	
     else()
        set(ENV_VARIABLE_IS_DEFINED 0) 	
     endif()

     target_compile_options(${MY_TARGET}
	     PRIVATE $<$<BOOL:ENV_VARIABLE_IS_DEFINED>: -DANANSI_DATA_POLICY=$ENV{ANANSI_DATA_POLICY} 
                                                    -DANANSI_DATA_STORAGE_CPU=$ENV{ANANSI_DATA_STORAGE_CPU} 
                                                    -DANANSI_DATA_STORAGE_GPU=$ENV{ANANSI_DATA_STORAGE_GPU} > )
 endmacro()
