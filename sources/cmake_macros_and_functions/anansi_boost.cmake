
#  =====================================================================================
# 
#        Filename:  anansi_boost.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================



 
# ===  MACRO     ======================================================================
#         Name:  enable_boost
#  Description:  Enables linking against the boost library.
# 
#  Arguments: MY_BOOST_ROOT; The boost root directory path.
# =====================================================================================

macro(enable_boost MY_BOOST_ROOT)

    set(BOOST_ROOT ${MY_BOOST_ROOT})
    set(Boost_USE_STATIC_LIBS ON)  # Force to use static boost libraries.
    set(Boost_USE_STATIC_RUNTIME OFF) 
    set(Boost_USE_DEBUG_LIBS OFF) # ignore debug libs and
    set(Boost_USE_RELEASE_LIBS ON)  # only find release libs
    set(Boost_USE_MULTITHREADED ON)
    
    
    # Find the Boost package. If the boost package is not found 
    # the generate a fatal error message and exit.
    find_package( Boost
                  COMPONENTS program_options 
                             log
                             system 
                             unit_test_framework 
                             chrono
                  REQUIRED)
    
    if( NOT Boost_FOUND) # If boost package is not found, the exit with fatal error. 
        message( FATAL_ERROR "The boost package was not found or one of the components of the boost library was not found.\n"
                             "The cmake macro 'enable_boost' controls linking against the boost library.")
    endif()
endmacro()
