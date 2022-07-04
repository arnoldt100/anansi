# This CMakeLists.txt file creates the program md_main.
# and its unit tests. To add source files, simply append the appropiate variable
# md_main_header_files or md_main_implementation_files.
#
# The target for the executable is md_main.
#
# The following properties are set for the target md_main.
#
#   Property                            Value                                               Description
#----------------------------------------------------------------------------------------------------------------------------
#


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    set(my_project_name "md_main")
    project("${my_project_name}")

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target "${my_project_name}")

    #-----------------------------------------------------
    # Set various variables for include directories.     -
    #                                                    -
    #-----------------------------------------------------
    get_target_property( my_md_core_include md_core md_core_include)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of CMake preamble section.                                  @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Here we define the sources and header files associated          @
# with the various targets.                                       @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    #-----------------------------------------------------
    # Here we define the variable
    # md_main_public_headers that stores header
    # files associated with the md_main target.
    #  
    #-----------------------------------------------------
    set(md_main_public_header_files 
        header_files/anansi_main_md.h )

    #-----------------------------------------------------
    # Here we define the variable md_main_public_implementation that
    # stores implementation files associated with the md_main target.
    # 
    #
    #-----------------------------------------------------
    set(md_main_public_implementation_files
        implementation_files/anansi_main_md.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Start of section that adds the main binary target.              @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

add_executable( "${target}"
                "" )

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings("${target}")

add_dependencies("${target}" 
                 md_core)

target_sources("${target}"
               PRIVATE "${md_main_public_implementation_files}" 
               PRIVATE "${md_main_public_header_files}" )

target_include_directories( "${target}" 
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/header_files"
                            PRIVATE "${my_md_core_include}" )

target_link_libraries("${target}"
                      PUBLIC md_core )

                  
set_target_properties("${target}" PROPERTIES
                      CXX_STANDARD "${md_main_cxx_standard}" )

install( TARGETS "${target}" 
         RUNTIME DESTINATION "${md_main_install_bin_directory}" )
                     

#-----------------------------------------------------
# Add the unit tests.                                -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
