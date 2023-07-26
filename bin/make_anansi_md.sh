#  /usr/bin/env bash

#-----------------------------------------------------
# Define the Anansi buld directory.                  -
#                                                    -
#-----------------------------------------------------
declare -r anansi_cmake_build_dir="${ANANSI_TOP_LEVEL}/build"

#-----------------------------------------------------
# The number of make threads.                        -
#                                                    -
#-----------------------------------------------------
declare -r -i NM_MAKE_THREADS=4

#-----------------------------------------------------
# Define a log file                                  -
#                                                    -
#-----------------------------------------------------
declare -r log_file="${ANANSI_TOP_LEVEL}/anansi_log.txt"

#-----------------------------------------------------
# No edits should be needed below this line.         -
#                                                    -
#-----------------------------------------------------

if [ -f ${log_file} ]
then
    rm -f ${log_file}
fi

cd ${anansi_cmake_build_dir}

make -j ${NM_MAKE_THREADS} all && make install 
