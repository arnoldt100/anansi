#! /usr/bin/env bash


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
#                                                                 @
# Mouseion environmental variables.                               @
#                                                                 @
# Please do not modfiy the below environmental variables.         @
#                                                                 @
# These environmental variables store the location of             @
# various top level CMakeLists.txt files, directories, etc.       @
#                                                                 @
#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


if [ -z ${MOUSEION_TOP_LEVEL+x} ]
then
    echo "Warning!"
    echo "The environmental variable MOUSEION_TOP_LEVEL is not set."
    echo "This variable must be set the the top level directory of anansi."
    echo "Mouseion will not build correctly till this variable is set."
else
    #-----------------------------------------------------
    # Define the top level of the anansi md program.     -
    #                                                    -
    #-----------------------------------------------------
    export MOUSEION_TOP_LEVEL_MD=${MOUSEION_TOP_LEVEL}/source/main_programs/molecular_dynamics

    #-----------------------------------------------------
    # Define the anansi bin directory.                   -
    #                                                    -
    #-----------------------------------------------------
    export MOUSEION_BIN_DIRECTORY=${MOUSEION_TOP_LEVEL}/bin

    #-----------------------------------------------------
    # The minimum cmake version required to build        -
    # this project.                                      -
    #                                                    -
    # This variable is mandatory.                        -
    #-----------------------------------------------------
    export MOUSEION_MINIMUM_CMAKE_VERSION="3.16"

    #-----------------------------------------------------
    # Define the path to Mouseion cmake modules.           -
    #                                                    -
    # This variable is mandatory.                        -
    #-----------------------------------------------------
    export MOUSEION_CMAKE_MODULE_PATH=${MOUSEION_TOP_LEVEL}/cmake_macros_and_functions
fi
