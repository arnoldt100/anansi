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

    # ----------------------------------------------------
    # The path to the Doxygen configuration file.
    # 
    # ----------------------------------------------------
    export ANANSI_DOXYGEN_CONFIGURATION="${ANANSI_TOP_LEVEL}/etc/anansi_doxgen.rc"

    # ----------------------------------------------------
    # The path to the XML file that configures Anansi's unit 
    # tests.
    # 
    # ----------------------------------------------------
    export ANANSI_UNIT_TEST_CONFIGURATION="${ANANSI_TOP_LEVEL}/etc/anansi_unit_tests.xml"

    # ----------------------------------------------------
    # Define the anansi bin directory.
    #
    # ----------------------------------------------------
    export ANANSI_BIN_DIRECTORY=${ANANSI_TOP_LEVEL}/bin

    # ----------------------------------------------------
    # Defing the directory to run doygen.
    # This is needed because doxygen tagfiles needs
    # relative paths with respect to where doxygen
    # is ran.
    #
    # ----------------------------------------------------
    export ANANSI_DOXYGEN_RUN_DIRECTORY="${ANANSI_TOP_LEVEL}/doxygen_documentation"

    #-----------------------------------------------------
    # The minimum cmake version required to build
    # this project.
    #
    # This variable is mandatory.
    #-----------------------------------------------------
    export ANANSI_MINIMUM_CMAKE_VERSION="3.16"

    #-----------------------------------------------------
    # Define the path to Anansi cmake modules.
    #
    # This variable is mandatory.
    #-----------------------------------------------------
    export ANANSI_CMAKE_MODULE_PATH=${ANANSI_TOP_LEVEL}/cmake_macros_and_functions

    #-----------------------------------------------------
    # Modify your path variable to include
    # the Anansi's bin directory.
    #
    #-----------------------------------------------------
    export PATH="${ANANSI_TOP_LEVEL}/bin":"$PATH"

    #-----------------------------------------------------
    # The pylint runtime configuration file.
    #
    #-----------------------------------------------------
    export PYLINTR=${ANANSI_TOP_LEVEL}/etc/anansi_pylint.rc

    # ----------------------------------------------------
    # Modify PYTHONPATH
    # 
    # ----------------------------------------------------
    export PYTHONPATH="${ANANSI_TOP_LEVEL}/bin/lib_python":"${PYTHONPATH}"
fi
