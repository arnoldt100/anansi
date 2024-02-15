#! /usr/bin/env python3
## \package receiver
#
# \brief This package's responsibility is to create the skeletal files
#        for a receiver.

from . import help_comments
from . import common_utilities

## This defines a unique key for this package.
package_key="receiver"

## \brief Adds the command line arguments to a ArgumentParser
#
# \param[in,out] parser An subparser of an ArgumentParser type
# \return ArgumentParser
def add_commandline_arguments(subparser):
    receiver_parser = subparser.add_parser(package_key,
                                            help="Creates skeletal files for a receiver class.")

    mandatory_args_group = receiver_parser.add_argument_group(title="Mandatory Arguments")

    mandatory_args_group.add_argument("--namespace",
                           required=True,
                           type=str,
                           help=help_comments.namespace_help)

    mandatory_args_group.add_argument("--receiver-name",
                                    required=True,
                                    type=str,
                                    help=help_comments.classname_help)

    mandatory_args_group.add_argument("--task-label",
                                    required=True,
                                    type=str,
                                    help="The task's label. This is a string of characters.")

    mandatory_args_group.add_argument("--ownership-policy",
                                    required=True,
                                    type=str,
                                    help="The ownership policy of the receiver's result.",
                                    choices=["CopyOwnershipPolicy",
                                             "NullOwnershipPolicy",
                                             "ShareCopyOwnershipPolicy",
                                             "ShareOwnershipPolicy",
                                             "TransferCopyOwnershipPolicy",
                                             "TransferOwnershipPolicy"] )

    return 

## \brief Creates the header and implementation files.
#
# \param args An object of the "argparse.Namespace".
class FileGenerator:
    def __init__(self,args):
        self._args = args

    def __call__(self):
        import re
        import os

        namespace = self._args.namespace
        receiverclassname = self._args.receiver_name
        header_file_suffix = ".h"
        impl_file_suffix = ".cpp"
        header_file_name = receiverclassname + header_file_suffix
        preprocessor_name = namespace + "_" + receiverclassname + "_INC"
        task_label = common_utilities.form_task_label(self._args.task_label)
        ownership_policy = self._args.ownership_policy 

        regex_dict = [ (re.compile("__NAMESPACE__"),namespace ),
                       (re.compile("__classname__"),receiverclassname),
                       (re.compile("__filename__"),receiverclassname),
                       (re.compile("__header_filename__"),header_file_name),
                       (re.compile("__filepreprocessordefine__"), preprocessor_name),
                       (re.compile("__tasklabel__"), task_label),
                       (re.compile("__ownershippolicy__"),ownership_policy) ]

        anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
        h_template_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiver-template.h")
        output_file = receiverclassname + header_file_suffix
        common_utilities.parse_file(regex_dict,h_template_file,output_file)

        i_template_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiver-template.cpp")
        output_file = receiverclassname + impl_file_suffix
        common_utilities.parse_file(regex_dict,i_template_file,output_file)

        h_results_traits_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiverResultsTraits-template.h")
        output_file = receiverclassname + "ResultsTraits" + header_file_suffix
        common_utilities.parse_file(regex_dict,h_results_traits_file,output_file)

        i_results_traits_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiverResultsTraits-template.cpp")
        output_file = receiverclassname + "ResultsTraits" + impl_file_suffix
        common_utilities.parse_file(regex_dict,i_results_traits_file,output_file)

        h_ownership_impl_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiverOwnershipImpl-template.h")
        output_file = receiverclassname + "ResultsTraitsOwnershipImpl" + header_file_suffix
        common_utilities.parse_file(regex_dict,h_ownership_impl_file,output_file)

        i_ownership_impl_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiverOwnershipImpl-template.cpp")
        output_file = receiverclassname + "ResultsTraitsOwnershipImpl" + impl_file_suffix
        common_utilities.parse_file(regex_dict,i_ownership_impl_file,output_file)


        return


