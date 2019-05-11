#! /usr/bin/env bash


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Anansi environmental variables.                                 @
#                                                                 @
# Please do not modfiy the below environmental variables.         @
#                                                                 @
# These environmental variables store the location of             @
# various top level CMakeLists.txt files, directories, etc.       @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


if [ -z ${ANANSI_TOP_LEVEL+x} ]
then
    echo "Warning!"
    echo "The environmental variable ANANSI_TOP_LEVEL is not set."
    echo "This variable must be set the the top level directory of anansi."
    echo "Anansi will not build correctly till this variable is set."
else
    #-----------------------------------------------------
    # Define the top level of the anansi md program.     -
    #                                                    -
    #-----------------------------------------------------
    export ANANSI_TOP_LEVEL_MD=${ANANSI_TOP_LEVEL}/source/main_programs/molecular_dynamics

    #-----------------------------------------------------
    # Define the anansi bin directory.                   -
    #                                                    -
    #-----------------------------------------------------
    export ANANSI_BIN_DIRECTORY=${ANANSI_TOP_LEVEL}/bin

    #-----------------------------------------------------
    # The minimum cmake version required to build        -
    # this project.                                      -
    #                                                    -
    # This variable is mandatory.                        -
    #-----------------------------------------------------
    export ANANSI_MINIMUM_CMAKE_VERSION="3.10"

    #-----------------------------------------------------
    # Define the path to Anansi cmake modules.           -
    #                                                    -
    # This variable is mandatory.                        -
    #-----------------------------------------------------
    export ANANSI_CMAKE_MODULE_PATH=${ANANSI_TOP_LEVEL}/cmake_macros_and_functions
fi
