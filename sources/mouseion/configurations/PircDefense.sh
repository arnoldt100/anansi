#! /usr/bin/env bash

#-----------------------------------------------------
# Define the top level directory of mouseion         -
#                                                    -
#-----------------------------------------------------
if [ -z ${MOUSEION_TOP_LEVEL+x} ]
then
    export MOUSEION_TOP_LEVEL=${HOME}/mouseion
fi

#-----------------------------------------------------
# Define the c++ compiler.                           -
#                                                    -
#-----------------------------------------------------
export MOUSEION_CMAKE_CXX_COMPILER=mpiCC

#-----------------------------------------------------
# Define the c compiler.                             -
#                                                    -
#-----------------------------------------------------
export MOUSEION_CMAKE_C_COMPILER=mpicc

#-----------------------------------------------------
# Define the install prefix.                         -
#                                                    -
#-----------------------------------------------------
export MOUSEION_INSTALL_PREFIX=${HOME}/sw/mouseion

#-----------------------------------------------------
# Define the mouseion bin directory.                   -
#                                                    -
#-----------------------------------------------------
export MOUSEION_INSTALL_BIN_DIRECTORY=${MOUSEION_INSTALL_PREFIX}/bin

#-----------------------------------------------------
# Define the mouseion include directory.               -
#                                                    -
#-----------------------------------------------------
export MOUSEION_INSTALL_INCLUDE_DIRECTORY=${MOUSEION_INSTALL_PREFIX}/include

#-----------------------------------------------------
# Define the mouseion include directory.               -
#                                                    -
#-----------------------------------------------------
export MOUSEION_INSTALL_LIB_DIRECTORY=${MOUSEION_INSTALL_PREFIX}/lib

#-----------------------------------------------------
# Define the mouseion boost root path.                 -
#                                                    -
#-----------------------------------------------------
export MOUSEION_BOOST_TOP_LEVEL=${BOOST_TOP_LEVEL}

#-----------------------------------------------------
# This mouseion core configuration must be sourced.    -
#                                                    -
#-----------------------------------------------------
source ${MOUSEION_TOP_LEVEL}/configurations/mouseion_core_configurations.sh


