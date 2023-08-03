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

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

def _main():
    args = _parse_arguments()

    namespace = args.namespace
    class_name = args.class_name

    _create_header_file(namespace,class_name)
    _create_implementation_file(namespace,class_name)

## Parses the command line arguments and returns A namespace.
#
# @returns A namespace contains attributes that are the command line arguments.
def _parse_arguments():

    import logging

    # Create a string of the description of the 
    # program.
    program_description = "This program creates the skeletal header and implementation files for a class."

    # Create text for namspace option help.
    namespace_help = ( f"""The namespace should conform to the language standards.\n """
                       f"""For example, most languages require namespaces to have only alphanumeric characters.\n""")

    # Create text for funtion name option help.
    classname_help = ( f"""The class name should conform to the language standards.\n """
                       f"""For example, most languages require class names to have only alphanumeric characters.\n""")

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

    mandatory_args_group.add_argument("--class-name",
                           required=True,
                           type=str,
                           help=classname_help)
    my_args = my_parser.parse_args()

    return my_args 

def _create_header_file(namespace,class_name):
    import os
    import re
    print("Creating header file " + class_name + ".h")
    anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
    template_file = os.path.join(anansi_top_level,"templates","Class.h")
    output_file = class_name + ".h"
    preprocessor_name = namespace + "_" + class_name + "_INC"
    regex_array = [ (re.compile("__NAMESPACE__"),namespace),
                    (re.compile("__classname__"),class_name),
                    (re.compile("__filename__"),class_name),
                    (re.compile("__filepreprocessordefine__"), preprocessor_name),
                   ]

    _parse_file(regex_array,template_file,output_file)

    return

def _create_implementation_file(namespace,class_name):
    import os
    import re
    print("Creating implementation file " + class_name + ".cpp")
    anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
    template_file = os.path.join(anansi_top_level,"templates","Class.cpp")
    output_file = class_name + ".cpp"
    regex_array = [ (re.compile("__NAMESPACE__"),namespace ),
                    (re.compile("__classname__"),class_name),
                    (re.compile("__filename__"),class_name),
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


if __name__ == "__main__":
    _main()
