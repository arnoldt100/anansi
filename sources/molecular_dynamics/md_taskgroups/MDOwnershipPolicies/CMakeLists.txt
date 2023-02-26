# This CMakeLists.txt file creates the library libmdownershippolicies.a
# and its unit tests. To add source files, simply append the appropiate variable
# mdownershippolicies_header_files or mdownershippolicies_implementation_files.
#
# The target for the library is mdownershippolicies.
#
# The following properties are set for the target mdownershippolicies.
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
    set(my_project_name "mdownershippolicies")
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

    #-----------------------------------------------------
    # Define the property name for the include directory.
    # 
    #-----------------------------------------------------
    set(my_target_include_property_name "${target}_include" )

    # ----------------------------------------------------
    # 
    # Set various variables for include directories.
    # 
    # ----------------------------------------------------
    get_target_property(my_receiver_include receiver receiver_include)
    
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
    # Here we define the variable                        -
    # command_line_arguments_header_files.               -
    # A list of header files is stored in                -
    # this variable.                                     -
    #                                                    -
    #-----------------------------------------------------
    set (mdownershippolicies_header_files
         header_files/CopyResult.hpp  
         header_files/NullOwnershipPolicy.hpp  
         header_files/CopyOwnershipPolicy.hpp  
         header_files/ShareOwnershipPolicy.hpp
         header_files/ShareCopyOwnershipPolicy.hpp
         header_files/TransferOwnershipPolicy.hpp
         header_files/TransferCopyOwnershipPolicy.hpp
         header_files/ErrorOwnershipPolicy.hpp)

    #-----------------------------------------------------
    # Here we define the variable                        -
    # command_line_arguments_implementation_files.       -
    # A list of implementation files is stored in this   -
    # variable.                                          -
    #                                                    -
    #-----------------------------------------------------
    set (mdownershippolicies_implementation_files
         implementation_files/CopyResult.cpp  
         implementation_files/NullOwnershipPolicy.cpp  
         implementation_files/CopyOwnershipPolicy.cpp  
         implementation_files/ShareOwnershipPolicy.cpp
         implementation_files/ShareCopyOwnershipPolicy.cpp
         implementation_files/TransferOwnershipPolicy.cpp
         implementation_files/TransferCopyOwnershipPolicy.cpp
         implementation_files/ErrorOwnershipPolicy.cpp)

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the command_line_arguments targets.                        @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library associated with target             -
# command_line_arguments.                            -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
             "")

#-----------------------------------------------------
#                                                    -
# We associate the source files with the target.     -
#                                                    -
#-----------------------------------------------------
target_sources(${target}
    PRIVATE ${mdownershippolicies_header_files} ${mdownershippolicies_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                           PRIVATE ${my_receiver_include})


#-----------------------------------------------------
# The libraries to use when linking to target.       -
#                                                    -
#-----------------------------------------------------
target_link_libraries( ${target}
                       PUBLIC receiver)

#-----------------------------------------------------
# Enable compile warnings.                           -
#                                                    -
#-----------------------------------------------------
enable_compile_warnings(${target})

#-----------------------------------------------------
# Here we set the properties on target               -
#                                                    -
#-----------------------------------------------------
set_target_properties(${target} PROPERTIES
                      "${my_target_include_property_name}" ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD "${md_taskgroups_cxx_standard}"
                      PUBLIC_HEADER "${mdownershippolicies_header_files}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${md_taskgroups_install_lib_directory} 
         PUBLIC_HEADER DESTINATION ${md_taskgroups_install_include_directory} )

#-----------------------------------------------------
# Add the subdirectory for creating the unit tests.  -
#                                                    -
#-----------------------------------------------------
# add_subdirectory(unit_tests)
