#! /usr/bin/env python3
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
    
