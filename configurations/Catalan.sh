#! /usr/bin/env bash

#-----------------------------------------------------
# Define the top level directory of anansi           -
#                                                    -
#-----------------------------------------------------
export ANANSI_TOP_LEVEL=${HOME}/anansi

#-----------------------------------------------------
# Define the c++ compiler.                           -
#                                                    -
#-----------------------------------------------------
export ANANSI_CMAKE_CXX_COMPILER=mpiCC

#-----------------------------------------------------
# Define the c compiler.                             -
#                                                    -
#-----------------------------------------------------
export ANANSI_CMAKE_C_COMPILER=mpicc

#-----------------------------------------------------
# Define the install prefix.                         -
#                                                    -
#-----------------------------------------------------
export ANANSI_INSTALL_PREFIX=${HOME}/sw/Anansi

#-----------------------------------------------------
# Define the anansi bin directory.                   -
#                                                    -
#-----------------------------------------------------
export ANANSI_INSTALL_BIN_DIRECTORY=${ANANSI_INSTALL_PREFIX}/bin

#-----------------------------------------------------
# Define the anansi include directory.               -
#                                                    -
#-----------------------------------------------------
export ANANSI_INSTALL_INCLUDE_DIRECTORY=${ANANSI_INSTALL_PREFIX}/include

#-----------------------------------------------------
# Define the anansi include directory.               -
#                                                    -
#-----------------------------------------------------
export ANANSI_INSTALL_LIB_DIRECTORY=${ANANSI_INSTALL_PREFIX}/lib

#-----------------------------------------------------
# This anansi core configuration must be sourced.    -
#                                                    -
#-----------------------------------------------------
source ${ANANSI_TOP_LEVEL}/configurations/anansi_core_configurations.sh






