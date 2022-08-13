#! /usr/bin/env python3
"""Anansi Source Tree Diagram Generator

This script generates a tree diagram of Anansi's source. 

An image file will be written.

""" 

import argparse
from lib_python import unix_tree_command

def _exclude_option():
    """Convenience fuction for creating exclude options

    Returns a string for the exlcude option.
    """
    exclude_patterns = ['templates']
    exclude_patterns.append('anansi_cmake_build_dir')
    exclude_patterns.append('__pycache__')
    exclude_patterns.append('stderr*')
    exclude_patterns.append('stdout*')
    exclude_patterns.append('anansi_log.txt')
    exclude_patterns.append('build')
    my_exclude_option = unix_tree_command.CreateExcludeOption(exclude_patterns)
    return my_exclude_option() 

def _get_args():
    """Returns the program arguments"""
    parser = argparse.ArgumentParser(description='Process the top-level path to tree diagram')

    required = parser.add_argument_group('required named arguments')
    required.add_argument('--top-level-dir', 
                        type=str, 
                        metavar='DIRPATH',
                        required=True,
                        nargs=1,
                        help='The top-level path of the directory to create a diagram of the list of all files')


    args = parser.parse_args()
    return args

def main () :

    # Process the command line arguments and get the top-level directory
    # to generate the list files diagram.
    args = _get_args()
    topleveldir=args.top_level_dir[0]

    # We initialize the a list of tree command options. 
    tree_command_options = []

    # This is the directory 
    tree_command_options.append(topleveldir)

    # This option prunes empty directories
    tree_command_options.append("--prune")

    # This option outputs XML format
    tree_command_options.append("-H ./html_files")

    # This sections define the files an directories to exclude which
    # we use to create the exclude option.
    my_exclude_option = _exclude_option()
    tree_command_options.append(my_exclude_option)

    # Instantiate the tree diagram generator and create the diagram
    my_tree = unix_tree_command.UnixTreeCommand(tree_command_options)
    print(my_tree.tree_command())
    my_tree.create_diagram()

if __name__ == "__main__" :

    main()
