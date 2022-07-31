#! /usr/bin/env python3
"""Provides classes and convenience functions for generating the Linux/Unix tree command.

Exported class:
     UnixTreeCommand :  Callable and provides the abstraction the tree command.
     CreateExcludeOption : Callable and creates the option to exclude files.

Typical Usage example:

    my_tree = unix_tree_command.UnixTreeCommand(tree_diagram_options)
    my_tree()

    where 'tree_diagram_options' is a string ofthe tree command options.
"""
import copy
import subprocess

class UnixTreeCommand:
    """This class encapsulates the unix/linux tree command."""

    def __init__(self,options):
        self._options = copy.deepcopy(options)

    def create_diagram(self):
        """Creates a tree diagram of the directory structure"""
        cmd = self.tree_command()
        subprocess.run(cmd,check=True,shell=True)

    def tree_command(self):
        """Returns the tree command as a string"""
        cmd = 'tree'
        for tmp_option in self._options:
            cmd = cmd + " " + tmp_option
        return cmd


class CreateExcludeOption:
    """This class creates the exclude option for a list of patterns

    This class is callable and when called returns a string for the
    include option.
    """

    def __init__(self,exclude_patterns=None):
        """Initializes CreateExcludeOption

        exclude_patterns : A list of strings. The list contains the patterns to exclude
                           and has the form of [pattern1,pattern2,...,patternN].
        """

        self._option = ""

        if exclude_patterns is None:
            exclude_patterns = []

        if len(exclude_patterns) > 0:

            self._option =  "-I " + "'" + exclude_patterns[0]

            for tmp_pattern in exclude_patterns[1:] :
                self._option += "|" +  tmp_pattern

        if len(exclude_patterns) > 0:
            self._option += "'"

    def __call__(self):
        """ Returns the tree option for excluding files

        The option is in the form of

            -I 'pattern1|pattern2|...|patternN'.

        The
        single quotes are important for the unix shell to correctly parse the
        command.
        """
        return self._option
