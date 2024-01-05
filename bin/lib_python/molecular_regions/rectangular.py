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

def _indent(elem, level=0):
   # Add indentation
   indent_size = "    "
   i = "\n" + level * indent_size
   if len(elem):
      if not elem.text or not elem.text.strip():
         elem.text = i + indent_size
      if not elem.tail or not elem.tail.strip():
         elem.tail = i
      for elem in elem:
         _indent(elem, level + 1)
      if not elem.tail or not elem.tail.strip():
         elem.tail = i
   else:
      if level and (not elem.tail or not elem.tail.strip()):
         elem.tail = i

class Rectangular(Region):

    #  ====================  LIFECYCLE     =======================================
    def __init__(self, 
                 filename,
                 origin=np.array([0.00,0.00,0.00]), 
                 dimensions=np.array([10.00,10.00,10.00]), 
                 pbc=np.array(["no-pbc","no-pbc","no-pbc"]) ):
        self._filename=filename
        self._origin = origin
        self._dimensions = dimensions
        self._pbc = pbc

    #  ====================  PUBLIC        =======================================

    #  ====================  PROTECTED     =======================================

    #  ====================  PRIVATE       =======================================

    __XML_INDENT = "    "

    def _type_of_coordinate_system(self):
        return "3D Cartesian Coordinates" 

    def _volume(self):
        volume = (self._dimensions[0])*(self._dimensions[1])*(self._dimensions[2])
        return volume

    def _origin_xml_element(self):
        my_element = ET.Element("origin") 

        x_element = ET.Element("x") 
        x_element.text = f"""{self._origin[0]}"""
        my_element.append(x_element)

        y_element = ET.Element("y") 
        y_element.text = f"""{self._origin[1]}"""
        my_element.append(y_element)

        z_element = ET.Element("z") 
        z_element.text = f"""{self._origin[2]}"""
        my_element.append(z_element)

        return my_element

    def __bounding_region_xml_element(self):
        my_element = ET.Element("bounding region") 

        my_low = lambda a : self._origin[a]
        my_high = lambda a : self._origin[a] + self._dimensions[a]

        x_low_value = my_low(0)
        x_high_value = my_high(0)
        x_lower_element = ET.Element("x-lower") 
        x_lower_element.text = f"""{x_low_value}"""
        x_upper_element = ET.Element("x-upper") 
        x_upper_element.text = f"""{x_high_value}"""

        y_low_value = my_low(1)
        y_high_value = my_high(1)
        y_lower_element = ET.Element("y-lower") 
        y_lower_element.text = f"""{y_low_value}"""
        y_upper_element = ET.Element("y-upper") 
        y_upper_element.text = f"""{y_high_value}"""

        z_low_value = my_low(2)
        z_high_value = my_high(2)
        z_lower_element = ET.Element("z-lower") 
        z_lower_element.text = f"""{z_low_value}"""
        z_upper_element = ET.Element("z-upper") 
        z_upper_element.text = f"""{z_high_value}"""

        my_element.append(x_lower_element)
        my_element.append(x_upper_element)
        my_element.append(y_lower_element)
        my_element.append(y_upper_element)
        my_element.append(z_lower_element)
        my_element.append(z_upper_element)

        return my_element

    def _boundary_conditions_xml_element(self):
        pass

    def _type_of_coordinate_system_element(self):
        my_element = ET.Element("Coordinate System") 
        my_element.text = self.TYPE_OF_COORDINATE_SYSTEM

        # Append the bounding region element.
        bounding_region_element = self.__bounding_region_xml_element()
        my_element.append(bounding_region_element)

        # Append the origin element
        my_origin_element = self._origin_xml_element()
        my_element.append(my_origin_element)

        return my_element

    def _write_to_file(self):
        # Create the top level node <data>.
        top_level_node = ET.Element("data")

        # Create the element <Type of Coordinate System>
        my_tocs_element = self._type_of_coordinate_system_element()

        # Create the bounding region element

        # Create the boundary condition element.

        # Append the element <Type of Coordinate System> to 
        # the top level node <data>
        top_level_node.append(my_tocs_element) 

        _indent(top_level_node)

        ET.dump(top_level_node)

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

