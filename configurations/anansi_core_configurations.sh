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
    export ANANSI_MINIMUM_CMAKE_VERSION="3.16"

    #-----------------------------------------------------
    # Define the path to Anansi cmake modules.           -
    #                                                    -
    # This variable is mandatory.                        -
    #-----------------------------------------------------
    export ANANSI_CMAKE_MODULE_PATH=${ANANSI_TOP_LEVEL}/cmake_macros_and_functions

    #-----------------------------------------------------
    # Modify your path variable to include               -
    # the Anansi's bin directory.                        -
    #                                                    -
    #-----------------------------------------------------
    export PATH="${ANANSI_TOP_LEVEL}/bin":"$PATH"

    #-----------------------------------------------------
    # The pylint runtime configuration file.             -
    #                                                    -
    #-----------------------------------------------------
    export PYLINTR=${ANANSI_TOP_LEVEL}/etc/anansi_pylint.rc

    # ----------------------------------------------------
    # Modify PYTHONPATH
    # 
    # ----------------------------------------------------
    export PYTHONPATH="${ANANSI_TOP_LEVEL}/bin/lib_python:${PYTHONPATH}"
fi
