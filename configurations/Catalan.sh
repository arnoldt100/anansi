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
# Define the c compiler.                           -
#                                                    -
#-----------------------------------------------------
export ANANSI_CMAKE_CXX_COMPILER=mpicc

#-----------------------------------------------------
# This anansi core configuration must be sourced.    -
#                                                    -
#-----------------------------------------------------
source ${ANANSI_TOP_LEVEL}/configurations/anansi_core_configurations.sh






