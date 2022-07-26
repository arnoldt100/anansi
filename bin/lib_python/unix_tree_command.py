#! /usr/bin/env python3
import copy
import subprocess

class UnixTreeCommand:
    """This class encapsulates the unix/linux tree command."""
 
    def __init__(self,options) :
        
        self.options_ = copy.deepcopy(options)
        return

    def __call__(self):
        cmd = ["tree"] + self.options_
        my_process = subprocess.run(cmd)
        return

