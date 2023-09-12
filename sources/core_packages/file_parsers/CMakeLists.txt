#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "file_parsers")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})
    include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_macros_and_functions/file_parsers_build_prerequisites.cmake)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    # ----------------------------------------------------
    #  Verify that all build prerequisites are satisfied 
    # for target 'file_parsers'.
    # 
    # ----------------------------------------------------
    verify_file_parsers_build_prerequisites_are_met()

    # ----------------------------------------------------
    # Here we define variables which indicate where
    # to install the command_files libraries,
    # header files, and associated binariers.
    # 
    # ----------------------------------------------------
    include(${CMAKE_CURRENT_SOURCE_DIR}/property_tree/cmake_macros_and_functions/command_files.cmake)
    enable_building_command_files_package( "${file_parsers_install_lib_directory}"
                                           "${file_parsers_install_include_directory}"
                                           "${file_parsers_install_bin_directory}" 
                                           "${file_parsers_cmake_c_compiler}"
                                           "${file_parsers_cmake_cxx_compiler}"
                                           "${file_parsers_cxx_standard}"
                                           "${file_parsers_logfilepath}" ) 
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/command_files)

    # ----------------------------------------------------
    # Here we define variables which indicate where
    # to install the property_tree libraries,
    # header files, and associated binariers.
    # 
    # ----------------------------------------------------
    include(${CMAKE_CURRENT_SOURCE_DIR}/property_tree/cmake_macros_and_functions/property_tree.cmake)
    enable_building_property_tree_package( "${file_parsers_install_lib_directory}"
                                           "${file_parsers_install_include_directory}"
                                           "${file_parsers_install_bin_directory}" 
                                           "${file_parsers_cmake_c_compiler}"
                                           "${file_parsers_cmake_cxx_compiler}"
                                           "${file_parsers_cxx_standard}"
                                           "${file_parsers_logfilepath}" ) 
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/property_tree)

    # ----------------------------------------------------
    # Here we define variables which indicate where
    # to install the control_file libraries,
    # header files, and associated binariers.
    # 
    # ----------------------------------------------------
    include(${CMAKE_CURRENT_SOURCE_DIR}/control_file/cmake_macros_and_functions/control_file.cmake)
    enable_building_control_file_package( "${file_parsers_install_lib_directory}"
                                          "${file_parsers_install_include_directory}"
                                          "${file_parsers_install_bin_directory}" 
                                          "${file_parsers_cmake_c_compiler}"
                                          "${file_parsers_cmake_cxx_compiler}"
                                          "${file_parsers_cxx_standard}"
                                          "${file_parsers_logfilepath}" ) 
    add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/control_file)


