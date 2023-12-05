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
 
    run_build_command_(args)

## Parses the command line arguments and returns A namespace.
#
# @returns A namespace contains attributes that are the command line arguments.
def _parse_arguments():

    import logging

    # Create a string of the description of the 
    # program.
    program_description = "This program runs the make command to build Anansi."

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

    # Add an optional argument for the make target.
    target_help = ( f"""The name of the target to build.\n"""
                    f"""The default target is 'all'.\n\n""")

    my_parser.add_argument("--target",
                           required=False,
                           type=str,
                           default="all",
                           help=target_help)

    # Add an optional argument for the number of make threads.
    nm_make_threads_help = ( f"""The number of make threads (i.e. make's -j option).\n"""
                             f"""This must be a positive integer <= 4. The default value is 1.\n\n""" )

    my_parser.add_argument("--nm-make-threads",
                           type=int,
                           default=1,
                           choices=list(range(1,5)),
                           help=nm_make_threads_help)

    my_args = my_parser.parse_args()
    return my_args

## Run make command to build Anansi
def run_build_command_(args):
    import os
    import shlex
    import subprocess

    # Define the CMake build directory. This is 
    # the working directory for the make command
    anansi_top_level=os.getenv("ANANSI_TOP_LEVEL")
    anansi_cmake_build_dir=os.path.join(anansi_top_level,"build")
    
    # Define the make options.
    options=""

    nm_make_threads=args.nm_make_threads;
    options+=" -j " + str(nm_make_threads) + " "

    target=args.target
    options+=" " + target + " "

    # Use subprocess to run make command.
    make_cmd = "make " + options
    args_make = shlex.split(make_cmd)
    process_make = subprocess.run(args_make,cwd=anansi_cmake_build_dir)
    if process_make.returncode == 0:
        print ("The command " + "'" + make_cmd + "'" + " succeeded.\n\n")
    else: 
        print ("The command " + "'" + make_cmd + "'" + " failed.\n")
        print ("The return code is " + str(process_make.returncode) + "\n\n")
        return

    # Use subprocess to run make install command.
    make_install_cmd = "make install"
    args_install = shlex.split(make_install_cmd)
    process_make_install = subprocess.run(args_install,cwd=anansi_cmake_build_dir)
    if process_make_install.returncode == 0:
        print ("The command " + "'" + make_install_cmd + "'" + " succeeded.\n\n")
    else:
        print ("The command " + "'" + make_install_cmd + "'" + " failed.\n")
        print ("The return code is " + str(process_make_install.returncode) + "\n\n")
        return
  

if __name__ == "__main__":
    _main()
