#! /usr/bin/env python3
## @package create_files_for_function
# This module creates the skeletal header and implementation files for a function.
# 
# This module intended to be executed as script. Typical usage is
# 
#     create_files_for_function.py --namespace <namespace> --function-name <functionname> --function-type <functiontype>
# 
# where
# 
# \<namespace\> is the namespace for the function
# \<functioname\> is the name of the function
# \<functioname\> is the type of function (i.e. general, template, ...)
# 

# System imports
import string
import argparse

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

_file_types = { "general" : ["functions.h","functions.cpp"],
                 "template" : ["functions.hpp","functions.hpp.cpp"]
              }

_file_suffixes = { "general" : [".h",".cpp"],
                   "template" : [".hpp",".cpp"]  }

def _main():
    args = _parse_arguments()

    namespace = args.namespace
    function_name = args.function_name
    function_type = args.function_type

    _create_header_file(namespace,function_name,function_type)
    _create_implementation_file(namespace,function_name,function_type)

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

    # Create text for function typ help
    functiontype_help = ( f"""The type of function to create.\n"""
                          f"""    general - the traditional function format.\n""" 
                          f"""    template - A template function format.\n""" )
    
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

    #Adding option function type.
    my_parser.add_argument("--function-type",
                           type=str,
                           default="general",
                           choices=["general","template"],
                           help=functiontype_help)
    
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

def _create_header_file(namespace,function_name,function_type):
    import os
    import re
    print("Creating header file for function " + function_name + ".")
    anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
    template_file = os.path.join(anansi_top_level,"templates",_file_types[function_type][0])
    output_file = function_name + _file_suffixes[function_type][0]
    preprocessor_name = namespace + "_" + function_name + "_INC"
    regex_array = [ (re.compile("__NAMESPACE__"),namespace),
                    (re.compile("__function__"),function_name),
                    (re.compile("__filepreprocessordefine__"), preprocessor_name),
                   ]

    _parse_file(regex_array,template_file, output_file)

    return

def _create_implementation_file(namespace,function_name,function_type):
    import os
    import re
    print("Creating implementation file for function " + function_name + ".")
    anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
    template_file = os.path.join(anansi_top_level,"templates",_file_types[function_type][1])
    output_file = function_name + _file_suffixes[function_type][1]
    regex_array = [ (re.compile("__NAMESPACE__"),namespace ),
                    (re.compile("__function__"),function_name),
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
