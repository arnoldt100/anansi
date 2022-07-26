#! /usr/bin/env python3
"""Anansi Source Tree Diagram Generator

This script generates a tree diagram of Anansi's source. 

An image file will be written.

""" 

from lib_python import unix_tree_command

def main () :
    tree_diagram_options = []

    # This option prunes empty directories
    tree_diagram_options.append("--prune")

    # 
    my_tree = unix_tree_command.UnixTreeCommand(tree_diagram_options)
    my_tree()

if __name__ == "__main__" :

    main()
