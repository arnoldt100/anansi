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
    class_type = args.class_type

    _create_header_file(namespace,class_name,class_type)
    _create_implementation_file(namespace,class_name,class_type)

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

    # Create text for funtion name option help.
    classtype_help = ( f"""The class type can be: \n """
                       f"""\tStandard - Normal C++ class\n """
                       f"""\tAbstractTask - Used for creating abstract task class\n """
                       f"""\tReceiver - Used for creating the concrete task\n """
                       f"""\tTypeErasure-Non-Template - TypeErasure base class\n """)

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

    mandatory_args_group.add_argument("--class-type",
                           required=True,
                           type=str,
                           choices=["TypeErasure-Non-Template","Standard","AbstractTask"],
                           help=classtype_help)

    my_args = my_parser.parse_args()

    return my_args 

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

    return (h_template_file,i_template_file,header_file_suffix,i_file_suffix)

if __name__ == "__main__":
    _main()
