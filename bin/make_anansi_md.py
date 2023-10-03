#! /usr/bin/env python3
## @package make_anansi_md
# This module runs the make command which builds anansi.
# 
# This module is intended to be executed as script. Typical usage is
# 
#     make_anansi_md.py  [--nm-make-threads <A positive number> ] [--target <The make target> ]
# 
# where
# 
# \<nm-make-threads\> is the number of make threads
# \<target\> is the make target
# 
# If no options are given --nm-make-thread defaults to 1, and
# --target defaults to all. 
#

# System imports
import string
import argparse

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

def _main():
    args = _parse_arguments()

## Parses the command line arguments and returns A namespace.
#
# @returns A namespace contains attributes that are the command line arguments.
def _parse_arguments():

    import logging

    # Create a string of the description of the 
    # program.
    program_description = "This program runs the make command to build Anansi."

    # Create text for namspace option help.
    nm_make_threads_help = ( f"""The number of make threads (i.e. make's -j option).\n"""
                             f"""This must be a positive integer. The default value is 1.\n""" )

    # Create text for funtion name option help.
    target_help = ( f"""The name of the target to build.""" )

    # Create an argument parser.
    my_parser = argparse.ArgumentParser(
            description=program_description,
            formatter_class=argparse.RawTextHelpFormatter,
            add_help=True)

    # Add an optional argument for the logging level.
    my_parser.add_argument("--log-level",
                           type=int,
                           default=logging.WARNING,
                           help=create_logger_description() )

    my_parser.add_argument("--target",
                           required=False,
                           type=str,
                           help=target_help)


if __name__ == "__main__":
    _main()

#  #-----------------------------------------------------
#  # Define the Anansi buld directory.                  -
#  #                                                    -
#  #-----------------------------------------------------
#  declare -r anansi_cmake_build_dir="${ANANSI_TOP_LEVEL}/build"
#  
#  #-----------------------------------------------------
#  # The number of make threads.                        -
#  #                                                    -
#  #-----------------------------------------------------
#  declare -r -i NM_MAKE_THREADS=2
#  
#  
#  #-----------------------------------------------------
#  # Define a log file                                  -
#  #                                                    -
#  #-----------------------------------------------------
#  declare -r log_file="${ANANSI_TOP_LEVEL}/anansi_log.txt"
#  
#  #-----------------------------------------------------
#  # No edits should be needed below this line.         -
#  #                                                    -
#  #-----------------------------------------------------
#  
#  if [ -f ${log_file} ]
#  then
#      rm -f ${log_file}
#  fi
#  
#  cd ${anansi_cmake_build_dir}
#  
#  make -j ${NM_MAKE_THREADS} all && make install 
