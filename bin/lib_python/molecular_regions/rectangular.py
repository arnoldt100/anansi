#! /usr/bin/env python3
## @package rectangular

# System imports
import random
import logging
import numpy as np
import argparse
import xml.etree.ElementTree as ET
import math

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger
from molecular_regions.region import Region


class AtomicCoordinate:
    #  ====================  LIFECYCLE     =======================================
    def __init__(self,atom_id,atom_symbol,x,y,z):
        self._atomID = atom_id
        self._atomSymbol = atom_symbol
        self._x = x
        self._y = y
        self._z = z

    #  ====================  PUBLIC        =======================================

    #  ====================  PROTECTED     =======================================

    #  ====================  PRIVATE       =======================================


class Molecule:
    #  ====================  LIFECYCLE     =======================================
    def __init__(self,atoms):
        self._atoms = atoms

    #  ====================  PUBLIC        =======================================

    #  ====================  PROTECTED     =======================================

    #  ====================  PRIVATE       =======================================

class Coordinates:
    #  ====================  LIFECYCLE     =======================================
    def __init__(self) :
        self._atomicCoordinates = []


    #  ====================  PUBLIC        =======================================

    #  ====================  PROTECTED     =======================================

    #  ====================  PRIVATE       =======================================

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


    #  ====================  PRIVATE       =======================================

    __XML_INDENT = "    "

    def __get_z_rotation_matrix(self,alpha):
        R_z = np.ndarray((3,3))
        R_z[0,0] = math.cos(alpha)
        R_z[0,1] = -math.sin(alpha)
        R_z[0,2] = 0.00
        R_z[1,1] = math.sin(alpha)
        R_z[1,1] = math.cos(alpha)
        R_z[1,2] = 0
        R_z[2,0] = 0 
        R_z[2,1] = 0 
        R_z[2,2] = 1
        return R_z

    def __get_y_rotation_matrix(self,beta):
        R_y = np.ndarray((3,3))
        R_y[0,0] = math.cos(beta)
        R_y[0,1] = 0.00
        R_y[0,2] = math.sin(beta)
        R_y[1,1] = 0.00
        R_y[1,1] = 0.00
        R_y[1,2] = 1.00
        R_y[2,0] = -math.sin(beta)
        R_y[2,1] = 0.00
        R_y[2,2] = math.cos(beta)
        return R_y 

    def __get_x_rotation_matrix(self,gamma):
        R_x = np.ndarray((3,3))
        R_x[0,0] = 1.00
        R_x[0,1] = 0.00
        R_x[0,2] = 0.00
        R_x[1,1] = 0.00
        R_x[1,1] = math.cos(gamma)
        R_x[1,2] = -math.sin(gamma)
        R_x[2,0] = 0.00
        R_x[2,1] = math.sin(gamma)
        R_x[2,2] = math.cos(gamma)
        return R_x 

    #  ====================  PROTECTED     =======================================
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

        # Here we define useful lamdas for calculating the 
        # upper and lower bounds of this rectangular region.
        region_lower_bound = lambda a : self._origin[a]
        region_upper_bound = lambda a : self._origin[a] + self._dimensions[a]

        # Create upper and lower x dimension bounds XML Elements
        x_low_value = region_lower_bound(0)
        x_lower_element = ET.Element("x-lower") 
        x_lower_element.text = f"""{x_low_value}"""
        x_high_value = region_upper_bound(0)
        x_upper_element = ET.Element("x-upper") 
        x_upper_element.text = f"""{x_high_value}"""

        # Create upper and lower y dimension bounds XML Elements
        y_low_value = region_lower_bound(1)
        y_lower_element = ET.Element("y-lower") 
        y_lower_element.text = f"""{y_low_value}"""
        y_high_value = region_upper_bound(1)
        y_upper_element = ET.Element("y-upper") 
        y_upper_element.text = f"""{y_high_value}"""

        # Create upper and lower z dimension bounds XML Elements
        z_low_value = region_lower_bound(2)
        z_lower_element = ET.Element("z-lower") 
        z_lower_element.text = f"""{z_low_value}"""
        z_high_value = region_upper_bound(2)
        z_upper_element = ET.Element("z-upper") 
        z_upper_element.text = f"""{z_high_value}"""

        # Append elenents to the parent element "my_element".
        my_element.append(x_lower_element)
        my_element.append(x_upper_element)
        my_element.append(y_lower_element)
        my_element.append(y_upper_element)
        my_element.append(z_lower_element)
        my_element.append(z_upper_element)

        return my_element

    def _boundary_conditions_xml_element(self):
        my_element = ET.Element("boundary conditions") 

        # Create x boundary condition XML Element.
        x_bc_element = ET.Element("x")
        x_bc_element.text= f"""{self._pbc[0]}"""

        # Create y boundary condition XML Element.
        y_bc_element = ET.Element("y")
        y_bc_element.text= f"""{self._pbc[1]}"""

        # Create z boundary condition XML Element.
        z_bc_element = ET.Element("z")
        z_bc_element.text= f"""{self._pbc[2]}"""

        # Append elenents to the parent element "my_element".
        my_element.append(x_bc_element)
        my_element.append(y_bc_element)
        my_element.append(z_bc_element)

        return my_element

    def _type_of_coordinate_system_element(self):
        my_element = ET.Element("Coordinate System") 
        my_element.text = self.TYPE_OF_COORDINATE_SYSTEM

        # Append the bounding region element.
        bounding_region_element = self.__bounding_region_xml_element()
        my_element.append(bounding_region_element)

        # Append the origin element
        my_origin_element = self._origin_xml_element()
        my_element.append(my_origin_element)

        # Append the boundary condition element.
        my_boundary_condition_element = self._boundary_conditions_xml_element()
        my_element.append(my_boundary_condition_element)

        return my_element

    def _write_to_file(self):
        # Create the top level node <data>.
        top_level_node = ET.Element("data")

        # Create the element <Type of Coordinate System>
        my_tocs_element = self._type_of_coordinate_system_element()

        # Append the element <Type of Coordinate System> to 
        # the top level node <data>
        top_level_node.append(my_tocs_element) 

        # We indent the the tree for human readability.
        ET.indent(top_level_node)

        # Convert to an ElementTree class and write to file.
        my_tree = ET.ElementTree(top_level_node)
        my_tree.write(self._filename,encoding="us-ascii",
                      method="xml",
                      short_empty_elements=True)
        return

    def _get_random_point_inside(self):
        dx = self._origin[0] + self._dimensions[0]*random.random()
        dy = self._origin[1] + self._dimensions[1]*random.random()
        dz = self._origin[2] + self._dimensions[2]*random.random()
        return np.array([dx,dy,dz])

    def _get_random_rotation_matrix(self):
        # alpha = 0.00 + 2*math.pi*random.random() # z-axiz
        alpha = math.pi # z-axiz
        R_z = self.__get_z_rotation_matrix(alpha)

        # beta = 0.00 + 2*math.pi*random.random() # y-axis
        beta = 0.00
        R_y = self.__get_y_rotation_matrix(beta)

        # gamma = 0.00 + 2*math.pi*random.random() # x-axis
        gamma = 0.00
        R_x = self.__get_x_rotation_matrix(gamma)

        R_yx = np.matmul(R_y,R_x)
        R_zyx = np.matmul(R_z,R_yx) 
        return R_zyx

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

