#! /usr/bin/env python3
## @package create_task
#
# This module creates a skeletel task,
#
# The module is to be executed as a script . Typical usage The ISC License (ISC)
#
#   create_task.py --class-name <classname> --ownership-policy <ownershippolicy>
#
# where
#
# \<classname\> is the class name of the task 
# \<ownershippolicy\> is the ownership policy of the task results
# 
# For a list of available ownership policies do
# 
#   create_task.py --help

# System imports
import argparse

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

def _main():
    ownership_policy_choices = _register_ownership_policy_choices()
    ownership_policy_help_message = _register_ownership_policy_help_message()
    args = _parse_arguments(ownership_policy_choices,ownership_policy_help_message)

    logger = create_logger(log_id='MainLogger',
                           log_level=args.log_level)

    logger.info("Start of main program")

## Parses the command line arguments and returns A namespace.
#
# @param [in] ownership_policy_choices A string list of ownership policy choices
# @param [in] ownership_policy_help A string that contains the ownership policy help messages.
#
# @returns A namespace contains attributes that are the command line arguments.
def _parse_arguments(ownership_policy_choices,ownership_policy_help):

    import logging

    # Create a string of the description of the 
    # program.
    program_description = "This program creates a skeletal task." 

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

    mandatory_args_group.add_argument("--ownership-policy",
                           required=True,
                           type=str,
                           choices=ownership_policy_choices,
                           help=ownership_policy_help)

    my_args = my_parser.parse_args()

    return my_args

def _register_ownership_policy_choices():
    """Creates the choices avaiable for the ownership policies

    Returns:
        An array of strings.

    """
    ownership_policy_choices = [ "NullOwnershipPolicy",
                                 "TransferOwnershipPolicy" ,
                                 "ShareCopyOwnershipPolicy" ,
                                 "TransferCopyOwnershipPolicy" ,
                                 "ShareOwnershipPolicy",
                                 "CopyOwnershipPolicy" ]

    return ownership_policy_choices 

def _register_ownership_policy_help_message():
    """Creates the help message for the publish mode argument.

    Returns:
        A string.

    """
    help_message = (f"""Ownership Policy       : Copyable Shareable Transferable\n""" 
                    f"""--------------------------------------------------------\n"""
                    f"""NullOwnershipPolicy    :  No      No        No          \n """
                    f"""TransferOwnershipPolicy:  No      No        Yes         \n"""
                    f"""ShareCopyOwnershipPolicy:  No      No        Yes         \n"""



                    )
    return help_message

def _register_publishing_mode_choices():
    """Creates the choices avaiable for the publishing mode.

    Returns:
        An array of strings.

    """
    publishing_mode_choices = ['standard','gitlab-pages','github-pages']
    return publishing_mode_choices 
if __name__ == "__main__":
    _main()

