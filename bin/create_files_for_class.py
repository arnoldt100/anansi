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
import class_types.standard
import class_types.abstract_task
import class_types.type_erasure_non_template

def _main():

    # Create a list of the class type packages.
    class_type_packages = [class_types.receiver,
                           class_types.standard,
                           class_types.abstract_task,
                           class_types.type_erasure_non_template]

   
    file_creator = _register_packages(class_type_packages)

    args = _parse_arguments(class_type_packages)

    print (args)

    
    # _create_header_file(namespace,class_name,class_type)
    # _create_implementation_file(namespace,class_name,class_type)

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

def _register_packages(package_list):
    """ Registers the functions that create the source files.

    Returns:
        The FunctionDispatcher with the registered functions.
    """

    a_function_dispatcher = function_dispatcher.create_function_dispatcher()

    for a_package in package_list:
        function_dispatcher.register_function(a_function_dispatcher,
                                              a_package.package_key,
                                              a_package.create_files)

    return (a_function_dispatcher)

def _create_header_file(namespace,class_name,class_type):
    import os
    import re
    (template_file,dummy_file,header_file_suffix,i_file_suffix) = _select_template_files(class_type)
    print("Creating header file " + class_name + header_file_suffix)
    anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
    output_file = class_name + header_file_suffix
    header_file_name = class_name + header_file_suffix
    preprocessor_name = namespace + "_" + class_name + "_INC"
    regex_array = [ (re.compile("__NAMESPACE__"),namespace),
                    (re.compile("__classname__"),class_name),
                    (re.compile("__filename__"),class_name),
                    (re.compile("__header_filename__"),header_file_name),
                    (re.compile("__filepreprocessordefine__"), preprocessor_name),
                   ]

    _parse_file(regex_array,template_file,output_file)

    return

def _create_implementation_file(namespace,class_name,class_type):
    import os
    import re
    (dummy_file,template_file,header_file_suffix,i_file_suffix) = _select_template_files(class_type)
    print("Creating implementation file " + class_name + i_file_suffix)
    anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
    output_file = class_name + i_file_suffix
    header_file_name = class_name + header_file_suffix
    regex_array = [ (re.compile("__NAMESPACE__"),namespace ),
                    (re.compile("__classname__"),class_name),
                    (re.compile("__filename__"),class_name),
                    (re.compile("__header_filename__"),header_file_name)
                   ]
    _parse_file(regex_array,template_file,output_file)
    return

def _parse_file(regex_array,template_file, output_file):
    # Read lines in from template fileself.
    import os

    if os.path.exists(output_file):
        print("Aborting: File " + output_file + " exists!" )
        return

    template_file_lines = []
    with open(output_file,"w") as output_fileobj :
        with open(template_file,"r") as template_fileobj :
            template_file_lines = template_fileobj.readlines()
            for tmp_record in template_file_lines: 

                for (regex_pattern,replacement) in regex_array:
                    tmp_record = regex_pattern.sub(replacement,tmp_record)    
                output_fileobj.write(tmp_record)


def _select_template_files(class_type):
    import os
    anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
    i_file_suffix = ".cpp"
    if class_type == "Standard":
        h_template_file = os.path.join(anansi_top_level,"templates","Class.h")
        i_template_file = os.path.join(anansi_top_level,"templates","Class.cpp")
        header_file_suffix = ".h"
    elif class_type == "TypeErasure-Non-Template":
        h_template_file = os.path.join(anansi_top_level,"templates","TypeErasure.non-template.h")
        i_template_file = os.path.join(anansi_top_level,"templates","TypeErasure.non-template.cpp")
        header_file_suffix = ".h"
    elif class_type == "AbstractTask":
        h_template_file = os.path.join(anansi_top_level,"templates","BaseTask-template.h")
        i_template_file = os.path.join(anansi_top_level,"templates","BaseTask-template.cpp")
        header_file_suffix = ".h"
    elif class_type == "NA":
        h_template_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiver-template.h")
        i_template_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiver-template.cpp")
        header_file_suffix = ".h"


    return (h_template_file,i_template_file,header_file_suffix,i_file_suffix)

if __name__ == "__main__":
    _main()
