#! /usr/bin/env bash

#-----------------------------------------------------
# Define the top level directory of anansi           -
#                                                    -
#-----------------------------------------------------
if [ -z ${ANANSI_TOP_LEVEL+x} ]
then
    export ANANSI_TOP_LEVEL=${HOME}/anansi
fi

#-----------------------------------------------------
# This anansi core variables must be sourced.        -
#                                                    -
#-----------------------------------------------------
source ${ANANSI_TOP_LEVEL}/configurations/anansi_core_variables.sh

#-----------------------------------------------------
# Define the c++ compiler.                           -
#                                                    -
#-----------------------------------------------------
export ANANSI_CMAKE_CXX_COMPILER=mpic++

#-----------------------------------------------------
# Define the c compiler.                             -
#                                                    -
#-----------------------------------------------------
export ANANSI_CMAKE_C_COMPILER=mpicc

# ----------------------------------------------------
#  Define the mpi run command.
# 
# ----------------------------------------------------
export ANANSI_MPI_RUN_COMMAND="mpirun -np"

#-----------------------------------------------------
# Define the install prefix.                         -
#                                                    -
#-----------------------------------------------------
export ANANSI_INSTALL_PREFIX="${HOME}/sw/Anansi"

#-----------------------------------------------------
# Define the anansi bin directory.                   -
#                                                    -
#-----------------------------------------------------
export ANANSI_INSTALL_BIN_DIRECTORY="${ANANSI_INSTALL_PREFIX}/bin"

#-----------------------------------------------------
# Define the anansi include directory.               -
#                                                    -
#-----------------------------------------------------
export ANANSI_INSTALL_INCLUDE_DIRECTORY="${ANANSI_INSTALL_PREFIX}/include"

#-----------------------------------------------------
# Define the anansi include directory.               -
#                                                    -
#-----------------------------------------------------
export ANANSI_INSTALL_LIB_DIRECTORY="${ANANSI_INSTALL_PREFIX}/lib"

#-----------------------------------------------------
# Define the directory to store the Anansi unit test -
# log files.                                         -
#                                                    -
#-----------------------------------------------------
export ANANSI_TEST_LOG_BASE_DIRECTORY="KingsIndian-unit-test-logs"

#-----------------------------------------------------
# Define the anansi boost root path.                 -
#                                                    -
#-----------------------------------------------------
export ANANSI_BOOST_TOP_LEVEL=${BOOST_TOP_LEVEL}

#-----------------------------------------------------
# Define the anansi debug environmental variables
#
#-----------------------------------------------------
export ANANSI_DEBUG_VALID_VALUES=${ANANSI_ON}
export MOUSEION_DEBUG_VALID_VALUES=${MOUSEION_ON}

# ---------------------------------------------------
# Define the anansi data centric policy
#
# --------------------------------------------------- 
export ANANSI_DATA_CENTRIC_POLICY=${ANANSI_DATA_STORAGE_CPU}

# ---------------------------------------------------
# Define the anansi precision policy
#
# --------------------------------------------------- 
export ANANSI_PRECISION_POLICY=${ANANSI_MEDIUM_COMPUTE_PRECISION}

#-----------------------------------------------------
# This anansi core configuration is sourced last.
#
#
#-----------------------------------------------------
source ${ANANSI_TOP_LEVEL}/configurations/anansi_core_configurations.sh

