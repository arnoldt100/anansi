#! /usr/bin/env python3
## @package rectangular

# System imports
import logging
import numpy as np
import string
import argparse
import xml.etree.ElementTree as ET

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger
from molecular_regions.region import Region

class Rectangular(Region):
    def __init__(self, 
                 filename,
                 origin=np.array([0.00,0.00,0.00]), 
                 dimensions=np.array([10.00,10.00,10.00]), 
                 pbc=np.array(["no-pbc","no-pbc","no-pbc"]) ):
        self._filename=filename
        self._origin = origin
        self._dimensions = dimensions
        self._pbc = pbc

    def _volume(self):
        volume = (self._dimensions[0])*(self._dimensions[1])*(self._dimensions[2])
        return volume

    def _write_to_file(self):
        # Create a <data> node.
        root_node = ET.TreeBuilder()
        root_node.start("data")
        root_node.end("data")

        tree = ET.ElementTree(elemenet=root_node)
        tree.write(self._filename)

        return

## @fn _parse_arguments( )
## @brief Parses the command line arguments.
##
## @details Parses the command line arguments and
## returns A namespace.
##
## @return A namespace. The namespace contains attributes
##         that are the command line arguments.
def _parse_arguments():

    # Create a string of the description of the 
    # program
    program_description = "Your program description" 

    # Create an argument parser.
    my_parser = argparse.ArgumentParser(
            description=program_description,
            formatter_class=argparse.RawTextHelpFormatter,
            add_help=True)

    # Add an optional argument for the logging level.
    my_parser.add_argument("--log-level",
                           type=int,
                           default=logging.WARNING,
                           help=create_logger_description() )

    my_args = my_parser.parse_args()

    return my_args 

## @fn main ()
## @brief The main function.
def main():
    args = _parse_arguments()

    logger = create_logger(log_id='__LoggerID__',
                           log_level=args.log_level)

    logger.info("Start of main program")

    logger.info("End of main program")

if __name__ == "__main__":
    main()

