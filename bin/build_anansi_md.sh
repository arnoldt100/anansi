#! /usr/bin/env bash

#-----------------------------------------------------
# Define the Anansi buld directory.                  -
#                                                    -
#-----------------------------------------------------
anansi_cmake_build_dir="anansi_cmake_build_dir"

#-----------------------------------------------------
# Define a log file                                  -
#                                                    -
#-----------------------------------------------------
log_file="${ANANSI_TOP_LEVEL}/anansi_log.txt"

#-----------------------------------------------------
# No edits should be needed below this line.         -
#                                                    -
#-----------------------------------------------------

if [ -f ${log_file} ]
then
    rm -f ${log_file}
fi

if [ -d ${anansi_cmake_build_dir} ]
then
    rm -rf ${anansi_cmake_build_dir}
fi
mkdir ${anansi_cmake_build_dir}

cd ${anansi_cmake_build_dir}

cmake ${ANANSI_TOP_LEVEL}/sources \
      -DCMAKE_CXX_COMPILER=${ANANSI_CMAKE_CXX_COMPILER} \
      -DCMAKE_C_COMPILER=${ANANSI_CMAKE_C_COMPILER} \
      -DCMAKE_INSTALL_PREFIX=${ANANSI_INSTALL_PREFIX} \
      -DCMAKE_BUILD_TYPE=Debug

make -j 2

make install
