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

    __XML_INDENT = "    "

    def _type_of_coordinate_system(self):
        return "3D Cartesian Coordinates" 

    def _volume(self):
        volume = (self._dimensions[0])*(self._dimensions[1])*(self._dimensions[2])
        return volume

    def _origin_xml_element(self):
        pass

    def _bounding_region_xml_element(self):
        pass

    def _boundary_conditions_xml_element(self):
        pass

    def _type_of_coordinate_system_element(self):
        my_element = ET.Element("Type of Coordinate System") 
        my_element.text = self.TYPE_OF_COORDINATE_SYSTEM
        return my_element

    def _write_to_file(self):
        # Create the top level node <data>.
        top_level_node = ET.Element("data")

        # Create the element <Type of Coordinate System>
        my_tocs_element = self._type_of_coordinate_system_element()

        # Create sthe origin element

        # Create sthe bounding region element

        # Create the boundary condition element.

        # Append the element <Type of Coordinate System> to 
        # the top level node <data>
        top_level_node.append(my_tocs_element) 
        ET.indent(top_level_node,space=self.__XML_INDENT)
        print(ET.tostring(top_level_node,encoding='unicode'))

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

