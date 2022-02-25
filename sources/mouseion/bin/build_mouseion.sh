#! /usr/bin/env bash

#-----------------------------------------------------
# Define the Anansi buld directory.                  -
#                                                    -
#-----------------------------------------------------
mouseion_cmake_build_dir="mouseion_cmake_build_dir"

#-----------------------------------------------------
# Define a log file                                  -
#                                                    -
#-----------------------------------------------------
log_file="${MOUSEION_TOP_LEVEL}/mouseion_log.txt"

#-----------------------------------------------------
# No edits should be needed below this line.         -
#                                                    -
#-----------------------------------------------------

if [ -f ${log_file} ]
then
    rm -f ${log_file}
fi

if [ -d ${mouseion_cmake_build_dir} ]
then
    rm -rf ${mouseion_cmake_build_dir}
fi
mkdir ${mouseion_cmake_build_dir}

cd ${mouseion_cmake_build_dir}

export MOUSEION_CXX_STANDARD=17

cmake ${MOUSEION_TOP_LEVEL} \
      -DCMAKE_VERBOSE_MAKEFILE=BOOL:ON \
      -DCMAKE_CXX_COMPILER=${MOUSEION_CMAKE_CXX_COMPILER} \
      -DCMAKE_C_COMPILER=${MOUSEION_CMAKE_C_COMPILER} \
      -DCMAKE_INSTALL_PREFIX=${MOUSEION_INSTALL_PREFIX} \
      -DCMAKE_BUILD_TYPE=Debug

make

make install
