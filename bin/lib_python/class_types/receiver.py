#! /usr/bin/env python3
## \package receiver
#
# \brief This package's responsibility is to create the skeletal files
#        for a receiver.
import re
import os

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

        get_attribute = lambda a, b : vars(a)[b] if hasattr(a,b) else "--not-defined--"
        self._args = args
        self._tasklabel = get_attribute(self._args,"task_label")
        self._receiver_class_name = get_attribute(args,"receiver_name")
        self._namepace = get_attribute(args,"namespace")
        self._ownershipPolicy = get_attribute(self._args,"ownership_policy")
        self._h_file_suffix = ".h"
        self._hpp_file_suffix = ".hpp"
        self._impl_file_suffix = ".cpp"
        return

    @property
    def receiver_class_name(self):
        return self._receiver_class_name

    @property
    def trait_class_name(self):
        return self.receiver_class_name + "ResultsTraits"

    @property
    def ownership_impl_class_name(self):
        return self.receiver_class_name + "ResultsOwnershipImpl"

    @property
    def namespace (self):
        return self._namepace

    @property
    def ownership_policy (self):
        return self._ownershipPolicy

    @property
    def receiver_preprocessordefine (self):
        return self.namespace + "_" + self.receiver_class_name + "_" + "INC"

    @property
    def traits_preprocessordefine (self):
        return self.namespace + "_" + self.trait_class_name + "_" + "INC"

    @property
    def ownershipimpl_preprocessordefine(self):
        return self.namespace + "_" + self.ownership_impl_class_name + "_" + "INC"

    @property
    def tasklabel(self):
        return self._tasklabel

    ## \brief This returns tuple of receiver's file names.
    #
    #  \details The tuples elements are respectively the header and implementation file
    #           names.
    def receiver_file_names(self):
        return (self.receiver_class_name + self._h_file_suffix,
                self.receiver_class_name + self._impl_file_suffix)

    ## \brief This returns tuple of receiver's results trait file names.
    #
    #  \details The tuples elements are respectively the header and implementation file
    #           names.
    def results_trait_files(self):
        return (self.trait_class_name + self._h_file_suffix,
                self.trait_class_name + self._impl_file_suffix)

    ## \brief This returns header file name ownership policy.
    def results_ownership_policy_header_file_name(self):
            return self.ownership_policy + self._hpp_file_suffix

    ## \brief This returns tuple of receiver's ownership implementation file names.
    #
    #  \details The tuples elements are respectively the header and implementation file
    #           names.
    def results_ownership_impl_files(self):
        return (self.ownership_impl_class_name + self._hpp_file_suffix,
                self.ownership_impl_class_name + self._impl_file_suffix)

    def __call__(self):
        self._createReceiverFile()

        self._createReceiverResultsTraitsFile()

        self._createResultsOwnershipImplFile()

        return

    def _createReceiverFile(self):

        (receiver_header_file_name,receiver_impl_file_name) = self.receiver_file_names()
        (traits_header_file_name,traits_impl_file_name) = self.results_trait_files()
        (ownershipimpl_header_file_name,ownershipimpl_impl_file_name) = self.results_ownership_impl_files()
        ownership_policy_header_file_name = self.results_ownership_policy_header_file_name()

        regex_dict = [ (re.compile("__NAMESPACE__"),self.namespace ),
                       (re.compile("__classname__"),self.receiver_class_name),
                       (re.compile("__header_filename__"),receiver_header_file_name),
                       (re.compile("__resultstraitsheaderfilename__"),traits_header_file_name),
                       (re.compile("__resultsownershipimplheaderfilename__"),ownershipimpl_header_file_name),
                       (re.compile("__ownershippolicyheaderfilename__"),ownership_policy_header_file_name),
                       (re.compile("__filepreprocessordefine__"), self.receiver_preprocessordefine),
                       (re.compile("__tasklabel__"), self.tasklabel),
                       (re.compile("__classnameresultstraits__"),self.trait_class_name),
                       (re.compile("__classnameownershipimpl__"),self.ownership_impl_class_name),
                       (re.compile("__ownershippolicy__"),self.ownership_policy) 
                     ]

        anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
        h_template_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiver-template.h")
        output_file = receiver_header_file_name
        common_utilities.parse_file(regex_dict,h_template_file,output_file)

        i_template_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiver-template.cpp")
        output_file = receiver_impl_file_name
        common_utilities.parse_file(regex_dict,i_template_file,output_file)

        return

    def _createReceiverResultsTraitsFile(self):
        (traits_header_file_name, traits_impl_file_name) = self.results_trait_files()

        regex_dict = [ (re.compile("__NAMESPACE__"),self.namespace ),
                       (re.compile("__header_filename__"),traits_header_file_name),
                       (re.compile("__filepreprocessordefine__"), self.traits_preprocessordefine),
                       (re.compile("__classname__"),self.trait_class_name),
                       (re.compile("__header_filename__"),traits_header_file_name)
                     ]

        anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
        h_template_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiverResultsTraits-template.h")
        output_file = traits_header_file_name
        common_utilities.parse_file(regex_dict,h_template_file,output_file)

        i_template_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiverResultsTraits-template.cpp")
        output_file = traits_impl_file_name
        common_utilities.parse_file(regex_dict,i_template_file,output_file)
        return

    def _createResultsOwnershipImplFile(self):
        (ownershipimpl_header_file_name, ownershipimpl_impl_file_name) = self.results_ownership_impl_files()

        regex_dict = [ (re.compile("__NAMESPACE__"),self.namespace),
                       (re.compile("__header_filename__"),ownershipimpl_header_file_name),
                       (re.compile("__filepreprocessordefine__"), self.ownershipimpl_preprocessordefine),
                       (re.compile("__classname__"),self.ownership_impl_class_name),
                       (re.compile("__header_filename__"),ownershipimpl_header_file_name)
                     ]

        anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
        h_template_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiverOwnershipImpl-template.hpp")
        output_file = ownershipimpl_header_file_name
        common_utilities.parse_file(regex_dict,h_template_file,output_file)

        i_template_file = os.path.join(anansi_top_level,"templates","ConcreteTaskReceiverOwnershipImpl-template.cpp")
        output_file = ownershipimpl_impl_file_name
        common_utilities.parse_file(regex_dict,i_template_file,output_file)

        return

