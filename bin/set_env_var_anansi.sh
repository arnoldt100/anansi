#! /usr/bin/env bash

#-----------------------------------------------------
# This scripts performs three tasks:                 -
#                                                    -
# (1) Sets the environmental variable                -
# ANANSI_TOP_LEVEL.                                  -
#                                                    -
# (2) Modifies your PATH environmental               -
# variable to include Anansi's software package      -
# bin directory.                                     -
#                                                    -
# (3) Modifies your PYTHONPATH environmental         -
# variable to include Anansi's software package      -
# python_packages directory.                         -
#                                                    -
# This file is to be sourced while                   -
# the current working directory is the top level     -
# of the Anansi software package:                    -
#                                                    -
# source ./bin/set_env_var_anansi_top_level.sh       -
#                                                    -
#-----------------------------------------------------

export ANANSI_TOP_LEVEL=$(pwd)

export PATH="${ANANSI_TOP_LEVEL}/bin:${PATH}"

export PYTHONPATH="${ANANSI_TOP_LEVEL}/python_packages:${PYTHONPATH}"
