#! /usr/bin/env python3
## @package build_doxygen_documentation
# This module builds the Anansi source code doxygen documentation.
# 
# This module intended to be executed as script. Typical usage is
# 
#     build_doxygen_documentation.py --publish-mode <publishmode>
# 
# where
# 
# <publishmode> is the publication mode of the documentation.
# 
# For a list of available publication modes do
# 
#     build_doxygen_documentation.py --help


# System imports
import string
import argparse

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger
import function_dispatcher
import os
import shutil

def _main():
    doc_relocater = function_dispatcher.create_function_dispatcher()
    choices = []
    help_message = ""


    doc_relocater = _register_functions()
    p_choices = _register_publishing_mode_choices()
    p_help_message = _register_publishing_mode_help_message ()

    args = _parse_arguments(p_choices, p_help_message)

    logger = create_logger(log_id='MainLogger',
                           log_level=args.log_level)

    logger.info("Start of main program")

    _run_doxygen_command()

    _relocate_documentation(doc_relocater,args.publish_mode)

    logger.info("End of main program")

## Parses the command line arguments and returns A namespace.
#
# @param [in] publishing_mode_choices A string list of publishing mode choices.
# @param [in] publishing_mode_help  A string that contains the publishing mode help message
#
# @returns A namespace contains attributes that are the command line arguments.
def _parse_arguments(publishing_mode_choices,publishing_mode_help ):

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

    # Adding mandatory argument group.
    mandatory_args_group = my_parser.add_argument_group(title="Mandatory Arguments")

    mandatory_args_group.add_argument("--publish-mode",
                           required=True,
                           type=str,
                           choices=publishing_mode_choices,
                           help=publishing_mode_help)

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
    import subprocess
    import shlex

    doxygen_binary = "doxygen"
    doxygen_config_file = os.getenv("ANANSI_DOXYGEN_CONFIGURATION")
    command = f"""{doxygen_binary} {doxygen_config_file}"""
    args = shlex.split(command)
    my_process = subprocess.run(args)

    return

def _relocate_github_mode():
    """Relocate files according to GitHub Pages requirements.

    In the gitlab-pages mode the documentation is relocated from
    the default location as specified in the doxygen configuration
    file to ${ANANSI_TOP_LEVEL}/docs.
    """

    print ("Executing relocation of documentation in github mode.")

    top_level_dir = os.getenv("ANANSI_TOP_LEVEL")
    src_dir = os.path.join(top_level_dir,"doxygen_documentation","html" )
    dest_dir = os.path.join(top_level_dir,"docs")
    shutil.copytree(src_dir,dest_dir,dirs_exist_ok=True)

def _relocate_gitlab_mode():
    """Relocate files according to GitLab Pages requirements.

    In the gitlab-pages mode the documentation is relocated from
    the default location as specified in the doxygen configuration
    file to ${ANANSI_TOP_LEVEL}/public.
    """

    top_level_dir = os.getenv("ANANSI_TOP_LEVEL")
    src_dir = os.path.join(top_level_dir,"doxygen_documentation","html" )
    dest_dir = os.path.join(top_level_dir,"public")
    shutil.copytree(src_dir,dest_dir,dirs_exist_ok=True)

def _relocate_standard_mode():
    """Relocate files according to standard requirements.

    In the standard mode the documentation is not relocated from
    the default location as specified in the doxygen configuration
    file.
    """
    pass

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

def _register_functions():
    """ Registers the functions that relocate the generated Doxygen documentation.

    Returns:
        The FunctionDispatcher with the registered functions.
    """

    a_function_dispatcher = function_dispatcher.create_function_dispatcher()

    # Registers the function for standard mode.
    function_dispatcher.register_function(a_function_dispatcher,"standard",_relocate_standard_mode)

    # Registers the function for github-pages mode.
    function_dispatcher.register_function(a_function_dispatcher,"github-pages",_relocate_github_mode)

    # Registers the function for gitlag-pages mode.
    function_dispatcher.register_function(a_function_dispatcher,"gitlab-pages",_relocate_gitlab_mode)

    return (a_function_dispatcher)

def _register_publishing_mode_choices():
    """Creates the choices avaiable for the publishing mode.

    Returns:
        An array of strings.

    """
    publishing_mode_choices = ['standard','gitlab-pages','github-pages']
    return publishing_mode_choices 

def _register_publishing_mode_help_message():
    """Creates the help message for the publish mode argument.

    Returns:
        A string.

    """
    help_message = ( f"""The standard mode places the documentation in directory ${{ANANSI_TOP_LEVEL}}/doxygen_doxygen/html\n"""
        f"""The gitlab-pages mode publishes documentation in directory ${{ANANSI_TOP_LEVEL}}/public\n"""
        f"""The github-pages mode publishes documentation in branch gh-pages to directory ${{ANANSI_TOP_LEVEL}}/docs\n""")

    return help_message

if __name__ == "__main__":
    _main()
