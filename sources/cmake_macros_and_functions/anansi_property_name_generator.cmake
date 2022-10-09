# ----------------------------------------------------
# Contains functions to generate property names in a
# consistent manner.
#
# ----------------------------------------------------


# ===  FUNCTION  ======================================================================
#         Name:  target_include_property_name
#
# Description: The property name is stored in variable "${target}_include_property_name" which
# is return to the parent scope by using set with PARENT_SCOPE.
# 
# Parameters: 
#   target - The name of the target.
# =====================================================================================
function (target_include_property_name target )

    set(tmp_target "${target}" )

    string(CONCAT ${tmp_target} "_include")

    set( "${target}_include_property_name" ${tmp_target} PARENT_SCOPE)
endfunction()
