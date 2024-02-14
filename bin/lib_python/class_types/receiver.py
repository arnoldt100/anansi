#! /usr/bin/env python3
## \package receiver
#
# \brief This package's responsibility is to create the skeletal files
#        for a receiver.

from . import help_comments

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

    mandatory_args_group.add_argument("--receiver-name",
                                    required=True,
                                    type=str,
                                    help=help_comments.classname_help)

    mandatory_args_group.add_argument("--task-label",
                                    required=True,
                                    type=str,
                                    help="The task's label.")

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

    mandatory_args_group.add_argument("--ownership-implementation",
                                      required=True,
                                      type=str,
                                      help="The class implementing the ownership policy.")

    return 

class FileGenerator:
    def __init__(self,args):
        self._args = args

    def __call__(self):
        print("Creating files for abstract-tasks")
        return


