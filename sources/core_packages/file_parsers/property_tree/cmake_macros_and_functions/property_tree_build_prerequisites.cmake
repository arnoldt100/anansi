# =====================================================================================
#
#       Filename:  property_tree_build_prerequisites.cmake
#    Description:  Contains convenience functions that help verify the
#                  prerequisites for building the package property_tree
#                  are satisfied.
#
# =====================================================================================

function(verify_property_tree_build_prerequisites_are_met)

    # Ensure that variable "property_tree_logfilepath" is defined.
    if (NOT DEFINED property_tree_logfilepath) 
        message (FATAL_ERROR "property_tree_logfilepath is not defined.")
    endif()

    set(my_message "Verifying package \"property_tree\" build prerequisities are satisfied.")
    log_message_to_file(${property_tree_logfilepath} "---")
    log_message_to_file(${property_tree_logfilepath} ${my_message})

    # Again verfying that variable 'property_tree_logfilepath' is defined ... repeated
    # for consistency.
    anansi_test_variable_is_defined("property_tree_logfilepath" "${property_tree_logfilepath}")
    
    # Verfying that variable 'property_tree_cmake_c_compiler' is defined.
    anansi_test_variable_is_defined("property_tree_cmake_c_compiler"  "${property_tree_logfilepath}")

    # Verfying that variable 'property_tree_cmake_cxx_compiler' is defined.
    anansi_test_variable_is_defined("property_tree_cmake_cxx_compiler"  "${property_tree_logfilepath}")

    # Verfying that variable 'property_tree_cxx_standard' is defined.
    anansi_test_variable_is_defined("property_tree_cxx_standard"  "${property_tree_logfilepath}")

    # Verfying that variable 'property_tree_install_bin_directory' is defined.
    anansi_test_variable_is_defined("property_tree_install_bin_directory"  "${property_tree_logfilepath}")

    # Verfying that variable 'property_tree_install_include_directory' is defined.
    anansi_test_variable_is_defined("property_tree_install_include_directory"  "${property_tree_logfilepath}")

    # Verfying that variable 'property_tree_install_lib_directory' is defined.
    anansi_test_variable_is_defined("property_tree_install_lib_directory"  "${property_tree_logfilepath}")

    set(my_message "Package \"property_tree\" build prerequisities are satisfied.")
    log_message_to_file(${property_tree_logfilepath} ${my_message})
    log_message_to_file(${property_tree_logfilepath} "---\n")

endfunction()
