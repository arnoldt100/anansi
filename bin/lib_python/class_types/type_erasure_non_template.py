#! /usr/bin/env python3
## \package type_erasure_non_template

# \brief This package's responsibility is to create the skeletal files
#        for a nontemplate type-erasure

from . import help_comments
from . import common_utilities

## This defines a unique key for this package.
package_key="type-erasure-non-template"

## \brief Adds the command line arguments to a ArgumentParser
#
# \param[in,out] parser An subparser of an ArgumentParser type
# \return ArgumentParser

def add_commandline_arguments(subparser):
    type_erasure_parser = subparser.add_parser(package_key,
                                                help="Creates skeletal files for a non-templated type-erasure")

    mandatory_args_group = type_erasure_parser.add_argument_group(title="Mandatory Arguments")

    mandatory_args_group.add_argument("--namespace",
                           required=True,
                           type=str,
                           help=help_comments.namespace_help)

    mandatory_args_group.add_argument("--class-name",
                           required=True,
                           type=str,
                           help=help_comments.classname_help)
    return

class FileGenerator:
    def __init__(self,args):
        self._args = args

    def __call__(self):
        import re
        import os

        namespace = self._args.namespace
        classname = self._args.class_name
        header_file_suffix = ".h"
        i_file_suffix = ".cpp"
        header_file_name = classname + header_file_suffix
        preprocessor_name = namespace + "_" + classname + "_INC"

        regex_dict = [ (re.compile("__NAMESPACE__"),namespace ),
                       (re.compile("__classname__"),classname),
                       (re.compile("__filename__"),classname),
                       (re.compile("__header_filename__"),header_file_name),
                       (re.compile("__filepreprocessordefine__"), preprocessor_name),
                     ]
        
        anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
        h_template_file = os.path.join(anansi_top_level,"templates","TypeErasure.non-template.h")
        output_file = classname + header_file_suffix
        common_utilities.parse_file(regex_dict,h_template_file,output_file);

        i_template_file = os.path.join(anansi_top_level,"templates","TypeErasure.non-template.h")
        output_file = classname + i_file_suffix
        common_utilities.parse_file(regex_dict,i_template_file,output_file);

        return