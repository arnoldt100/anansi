#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# CMake preamble section.                                         @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

    include( cmake_macros_and_functions/project_properties.cmake )

    #-----------------------------------------------------
    # Define the project.                                -
    #                                                    -
    #-----------------------------------------------------
    DEFINE_PROJECT_NAME()
    project(${my_project_name})

    #-----------------------------------------------------
    # Define the target name.                            -
    #                                                    -
    #-----------------------------------------------------
    set(target ${my_project_name})

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
    # library_headers associated with the                -
    # library                                            -
    #                                                    -
    #-----------------------------------------------------
    set (memory_management_library_headers
         header_files/Pointer.hpp
         header_files/Pointer2d.hpp
         header_files/Array1d.hpp
         header_files/Array2d.hpp
         header_files/Array1dChar.hpp
         header_files/CantorPairing.h
         header_files/MemoryExceptionDeletingNullPointer.hpp
         header_files/AllocatingArrayDimensionToNonPositiveSize.hpp
         header_files/PointerInitializationTraits.hpp
         header_files/ExceptionLengthOfCharPointerIsTooSmall.h
         header_files/write_column_major_array.hpp )

    #-----------------------------------------------------
    # Here we define the variable                        -
    # memory_management_implementation associated with   -
    # the molecular dynamics library                     -
    #                                                    -
    #-----------------------------------------------------
    set (memory_management_implementation_files
         implementation_files/Pointer.cpp
         implementation_files/Pointer2d.cpp
         implementation_files/Array1d.cpp
         implementation_files/Array2d.cpp
         implementation_files/Array1dChar.cpp
         implementation_files/CantorPairing.cpp
         implementation_files/MemoryExceptionDeletingNullPointer.cpp
         implementation_files/AllocatingArrayDimensionToNonPositiveSize.cpp
         implementation_files/PointerInitializationTraits.cpp
         implementation_files/ExceptionLengthOfCharPointerIsTooSmall.cpp
         implementation_files/write_column_major_array.cpp )

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# End of defining the sources and header files associated         @
# with the memory_management targets.                             @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

#-----------------------------------------------------
# Add the library target.                            -
#                                                    -
#-----------------------------------------------------
add_library( ${target} STATIC 
             "" )

target_sources(${target}
               PRIVATE ${memory_management_library_headers} ${memory_management_implementation_files} )

#-----------------------------------------------------
# Add the directory header_files to search for       -
# header files.                                      -
#                                                    -
#-----------------------------------------------------
target_include_directories(${target} 
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/header_files)

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
                      memory_management_include ${CMAKE_CURRENT_SOURCE_DIR}/header_files
                      CXX_STANDARD ${memory_management_cxx_standard}
                      PUBLIC_HEADER "${memory_management_library_headers}" )

install( TARGETS ${target}
         ARCHIVE DESTINATION ${memory_management_install_lib_directory}
         PUBLIC_HEADER DESTINATION ${memory_management_install_include_directory} )

#-----------------------------------------------------
# We now define the unit test code.                  -
#                                                    -
#-----------------------------------------------------
add_subdirectory(unit_tests)
