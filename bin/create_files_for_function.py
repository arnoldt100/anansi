#! /usr/bin/env python3
## @package create_files_for_function
# This module creates the skeletal header and implementation files for a function.
# 
# This module intended to be executed as script. Typical usage is
# 
#     create_files_for_function.py --namespace <namespace> --function-name <functionname>
# 
# where
# 
# \<namespace\> is the namespace for the function
# \<functioname\> is the name of the function
# 

# System imports
import string
import argparse

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

def _main():
    args = _parse_arguments()
    _create_header_file()
    _create_implementation_file()

## Parses the command line arguments and returns A namespace.
#
# @returns A namespace contains attributes that are the command line arguments.
def _parse_arguments():

    import logging

    # Create a string of the description of the 
    # program.
    program_description = "This program creates the skeletal header and implementation files for a function."

    # Create text for namspace option help.
    namespace_help = ( f"""The namespace should conform to the language standards.\n """
                       f"""For example, most languages require namespaces to have only alphanumeric characters.\n""")

    # Create text for funtion name option help.
    functionname_help = ( f"""The function name should conform to the language standards.\n """
                          f"""For example, most languages require function names to have only alphanumeric characters.\n""")

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

    mandatory_args_group.add_argument("--namespace",
                           required=True,
                           type=str,
                           help=namespace_help)

    mandatory_args_group.add_argument("--function-name",
                           required=True,
                           type=str,
                           help=functionname_help)
    my_args = my_parser.parse_args()

    return my_args 

def _create_header_file():
    pass

def _create_implementation_file():
    pass

if __name__ == "__main__":
    _main()
