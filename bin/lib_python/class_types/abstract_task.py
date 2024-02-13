#! /usr/bin/env python3
## \package abstract_tasks

from .  import help_comments

## This defines a unique key for this package.
package_key="abstract-tasks"

# \brief This package's responsibility is to create the skeletal files
#        for an abstract task.

## \brief Adds the command line arguments to a ArgumentParser
#
# \param[in,out] parser An subparser of an ArgumentParser type
# \return ArgumentParser
def add_commandline_arguments(subparser):
    abstract_task_parser = subparser.add_parser(package_key,
                                                help="Creates skeletal files for a abstract task class.")

    mandatory_args_group = abstract_task_parser.add_argument_group(title="Mandatory Arguments")

    mandatory_args_group.add_argument("--namespace",
                           required=True,
                           type=str,
                           help=help_comments.namespace_help)

    mandatory_args_group.add_argument("--class-name",
                           required=True,
                           type=str,
                           help=help_comments.classname_help)

    return


def create_files(args):
    return;
