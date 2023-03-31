
#  =====================================================================================
# 
#        Filename:  anansi_mpi.cmake
# 
#     Description:  
# 
#          Author:  Arnold N. Tharrington (), arnoldt@ornl.gov
#    Organization:  ORNL-National Center of Computational Sciences
# 
#  =====================================================================================



 
# ===  MACRO     ======================================================================
#         Name:  enable_mpi
#  Description:  Enables linking against the mpi library.
# 
# =====================================================================================

macro(enable_mpi)

    # Find the Boost package. If the mpi package is not found 
    # the generate a fatal error message and exit.
    find_package( MPI
                  REQUIRED)

              message ("MPI_VERSION is ${MPI_VERSION}") 
              message ("MPI_C_INCLUDE_DIRS is ${MPI_C_INCLUDE_DIRS}") 
              message ("MPI_CXX_INCLUDE_DIRS is ${MPI_CXX_INCLUDE_DIRS}") 
    
    if( NOT MPI_FOUND) # If mpi package is not found, the exit with fatal error. 
        message( FATAL_ERROR "The mpi package was not found or one of the components of the mpi library was not found.\n"
                             "The cmake macro 'enable_mpi' controls linking against the mpi library.")
    endif()
endmacro()
