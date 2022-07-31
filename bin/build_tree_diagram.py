#! /usr/bin/env python3
"""Anansi Source Tree Diagram Generator

This script generates a tree diagram of Anansi's source. 

An image file will be written.

""" 

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
    my_exclude_option = unix_tree_command.CreateExcludeOption(exclude_patterns)
    return my_exclude_option() 

def main () :
    tree_diagram_options = []

    # This option prunes empty directories
    tree_diagram_options.append("--prune")

    # This sections define the files an directories to exclude which
    # we use to create the exclude option.
    my_exclude_option = _exclude_option()
    tree_diagram_options.append(my_exclude_option)

    # Instantaie the tree diagram generator.
    my_tree = unix_tree_command.UnixTreeCommand(tree_diagram_options)
    print(my_tree.tree_command())
    my_tree.create_diagram()

if __name__ == "__main__" :

    main()
