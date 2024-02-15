#! /usr/bin/env python3
## @package create_files_for_class
# This module creates the skeletal header and implementation files for a class.
# 
# This module intended to be executed as script. Typical usage is
# 
#     create_files_for_class.py --namespace <namespace> --class-name <classname>
# 
# where
# 
# \<namespace\> is the namespace for the class
# \<classname\> is the name of the class
# 

# System imports
import string
import argparse
import function_dispatcher

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger
import class_types.receiver
import class_types.macro_receiver
import class_types.standard
import class_types.abstract_task
import class_types.type_erasure_non_template

def _main():
    # Create a list of the class type packages.
    class_type_packages = [class_types.receiver,
                           class_types.standard,
                           class_types.abstract_task,
                           class_types.type_erasure_non_template
                           class_types.receiver_macro]

    # Parse the command line arguments.
    args = _parse_arguments(class_type_packages)
    print (args)
   
    file_creator = _register_packages(class_type_packages,args)

    function_dispatcher.execute(file_creator,args.subparser_class_type)
    

## Parses the command line arguments and returns A namespace.
#
# @returns A namespace contains attributes that are the command line arguments.
def _parse_arguments(class_type_packages):

    import logging

    # Create a string of the description of the 
    # program.
    program_description = "This program creates the skeletal header and implementation files for a class."

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

    # Add subparser for different class type.
    class_type_subparser = my_parser.add_subparsers(help="Commands to create different type of classes.",
                                                    title="Subcommand arguments for creating types of classes.",
                                                    dest="subparser_class_type")

    # Add command line arguments for all class type packages.
    for a_package in class_type_packages:
        a_package.add_commandline_arguments(class_type_subparser)

    # Finally parse the command line arguments.
    my_args = my_parser.parse_args()

    return my_args 

def _register_packages(package_list,args):
    """ Registers the functions that create the source files.

    Returns:
        The FunctionDispatcher with the registered functions.
    """

    a_function_dispatcher = function_dispatcher.create_function_dispatcher()

    for a_package in package_list:
        my_callable_object = a_package.FileGenerator(args)
        function_dispatcher.register_function(a_function_dispatcher,
                                              a_package.package_key,
                                              my_callable_object)

    return (a_function_dispatcher)

if __name__ == "__main__":
    _main()
