#! /usr/bin/env bash

# ----------------------------------------------------
# This script relocates files from the mouseion communicator repository
# to the Anansi mpi_communicator repository.
# 
# ----------------------------------------------------

# Define the file to be transferred
hfile=MPIFreeException.h
ifile=MPIFreeException.cpp

# Define the source and destination directories for files to be transferred.
source_header_dir="${ANANSI_TOP_LEVEL}/sources/mouseion/sources/communicator/header_files"
source_implementation_dir="${ANANSI_TOP_LEVEL}/sources/mouseion/sources/communicator/implementation_files"
dest_header_dir="${ANANSI_TOP_LEVEL}/sources/mpi_communicator/header_files"
dest_implementation_dir="${ANANSI_TOP_LEVEL}/sources/mpi_communicator/implementation_files"

# Transfer the implementation file
cp "$source_implementation_dir/$ifile" "$dest_implementation_dir"

#Transfer the header file.
cp "$source_header_dir/$hfile" "$dest_header_dir"

# Stop tracking files in mouseion repository.
cd "${source_implementation_dir}"
git rm "$ifile"

cd "${source_header_dir}"
git rm "$hfile"

#Start tracking files in Anansi repository.
cd ${dest_header_dir}
git add "${hfile}"

cd "${dest_implementation_dir}"
git add "${ifile}"
