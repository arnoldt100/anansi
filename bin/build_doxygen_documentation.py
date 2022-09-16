#! /usr/bin/env python3
"""This module builds the Anansi source code doxygen documentation.

This module intended to be executed as script. Typical usage is

    build_doxygen_documentation --publish-mode *publishmode*

where

* *publishmode* is the publication mode of the documentation.

For a list of available publication modes do

    build_doxygen_documentation --help
"""


# System imports
import string
import argparse

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger
import function_dispatcher

def main():
    doc_relocater = function_dispatcher.create_function_dispatcher()
    function_dispatcher.register_function(doc_relocater,"standard",_relocate_standard_mode)
    function_dispatcher.register_function(doc_relocater,"github-pages",_relocate_github_mode)
    function_dispatcher.register_function(doc_relocater,"gitlab-pages",_relocate_gitlab_mode)

    args = _parse_arguments()


    logger = create_logger(log_id='MainLogger',
                           log_level=args.log_level)

    logger.info("Start of main program")

    _run_doxygen_command()

    _relocate_documentation(doc_relocater,args.publish_mode)

    logger.info("End of main program")


def _parse_arguments():
    """Parses the command line arguments.

    Parses the command line arguments and returns A namespace.

    Returns:
        A namespace. The namespace contains attributes
        that are the command line arguments.
    """

    import logging

    # Create a string of the description of the 
    # program.
    program_description = "This program build the Doxygen documentation for Anansi." 

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

    publish_mode_help = ( f"""The standard mode places the documentation in directory ${{ANANSI_TOP_LEVEL}}/doxygen_doxygen/html\n"""
            f"""The gitlab-pages mode publishes documentation in directory ${{ANANSI_TOP_LEVEL}}/public\n"""
            f"""The github-pages mode publishes documentation in branch gh-pages to directory ${{ANANSI_TOP_LEVEL}}/docs\n""")
    my_parser.add_argument("--publish-mode",
                           required=True,
                           type=str,
                           choices=['standard','gitlab-pages','github-pages'],
                           help=publish_mode_help)

    my_args = my_parser.parse_args()

    return my_args 



def _run_doxygen_command():
    """Runs the doxygen command to build Anansi's doxygen documentation.

    Args:
        No arguments

    Returns:
        Nothing returned
    """
    import sys
    import os
    import subprocess
    import shlex

    doxygen_binary = "doxygen"
    doxygen_config_file = os.getenv("ANANSI_DOXYGEN_CONFIGURATION")
    command = f"""{doxygen_binary} {doxygen_config_file}"""
    args = shlex.split(command)
    my_process = subprocess.run(args)

    return

def _relocate_github_mode():
    """Relocate files according to GitHub Pages requirements."""
    print ("Executing _relocate_github_mode.")

def _relocate_gitlab_mode():
    """Relocate files according to GitLab Pages requirements."""
    print ("Executing _relocate_gitlab_mode.")

def _relocate_standard_mode():
    """Relocate files according to standard requirements."""
    print ("Executing relocation of documentation in standard mode.")

def _relocate_documentation(a_function_dispatcher,publish_mode):
    """Relocates the Doxygen generated documentation.

    Args: 
        a_function_dispatcher (FunctionDispatcher) : The object that contains the function to call.
        publish_mode: A string flag that signals which publishing mode the program is in.
    """
    try:
        function_dispatcher.execute(a_function_dispatcher,publish_mode)
    except  function_dispatcher.FunctionDispatcherAPIError as err:
        print(err.message)
        sys.exit(1) 

    return

if __name__ == "__main__":
    main()
