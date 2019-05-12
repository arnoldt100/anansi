#! /usr/bin/env bash

#-----------------------------------------------------
# Define the Anansi buld directory.                  -
#                                                    -
#-----------------------------------------------------
anansi_cmake_build_dir="anansi_cmake_build_dir"

#-----------------------------------------------------
# Define the Anansi source directory.                -
#                                                    -
#-----------------------------------------------------
anasi_source_dir=${ANANSI_TOP_LEVEL}


if [ -d ${anansi_cmake_build_dir} ]
then
    rm -rf ${anansi_cmake_build_dir}
fi
mkdir ${anansi_cmake_build_dir}

cd ${anansi_cmake_build_dir}

cmake ${ANANSI_TOP_LEVEL} \
      -DCMAKE_CXX_COMPILER=${ANANSI_CMAKE_CXX_COMPILER} \
      -DCMAKE_C_COMPILER=${ANANSI_CMAKE_C_COMPILER} \
      -DCMAKE_INSTALL_PREFIX=${ANANSI_INSTALL_PREFIX}

make

make install
