#! /usr/bin/env python3
## @package tip3p

# System imports
import string
import argparse
import numpy as np
import math
import copy
import xml.etree.ElementTree as ET

# Local imports
import logging
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger
from molecular_regions import molecule_xml_element

class tip3p:
    group_type = "tip3p-rigid-molecule"

    atomic_symbols = {"tip3p-O1" : "O",
                      "tip3p-H2" : "H",
                      "tip3p-H3" : "H"}

    atom_labels = {"tip3p-O1" : "O1",
                   "tip3p-H2" : "H2",
                   "tip3p-H3" : "H3"}

    atomic_monopoles = {"tip3p-O1" : -0.834,
                        "tip3p-H2" : 0.417,
                        "tip3p-H3" : 0.417}

    atom_mass = {"tip3p-O1" : 15.999,
                 "tip3p-H2" : 1.00784,
                 "tip3p-H3" : 1.00784 }

    bond_constraints = { 
                         "1" : ["tip3p-O1","tip3p-H2",0.9572],
                         "2" : ["tip3p-O1","tip3p-H3",0.9572]
                       }

    bond_constraints_tolerance = 1.00e-15

    angle_constraints = {
                         "1" : ["tip3p-H2","tip3p-O1","tip3p-H3" ,1.82421813],
                       }

    angle_constraints_tolerance = 1.00e-08

    initial_coordinates = {
                           "tip3p-O1" : np.array([0.00,0.00,0.00]),
                           "tip3p-H2" : np.array([0.00,0.9572,0.00]),
                           "tip3p-H3" : np.array([0.00,
                                                 0.9572*math.cos(104.52*(math.pi/180.00)),
                                                 0.9572*math.sin(104.52*(math.pi/180.00))]) 
                          }

    initial_velocities = {
                           "tip3p-O1" : np.array([0.00,0.00,0.00]),
                           "tip3p-H2" : np.array([0.00,0.0000,0.00]),
                           "tip3p-H3" : np.array([0.00,0.00,0.00])
                          }

    #  ====================  LIFECYCLE     =======================================
    def __init__(self):
        self.__group_id = 0
        self._coordinates = copy.deepcopy(self.initial_coordinates)
        self._velocities = copy.deepcopy(self.initial_velocities)
        self.__atom_index = { "tip3p-O1" : 1,
                              "tip3p-H2" : 2,
                              "tip3p-H3" : 3 }

    #  ====================  PUBLIC        =======================================
    def get_comment_header(self):
        text = molecule_xml_element.Labels_Format["atom_label"].format(atom_label = molecule_xml_element.Fields["atom_label"])
        text += molecule_xml_element.Labels_Format["atom_symbol_label"].format(atom_symbol_label = molecule_xml_element.Fields["atom_symbol_label"])
        text += molecule_xml_element.Labels_Format["atom_index_label"].format(atom_index_label = molecule_xml_element.Fields["atom_index_label"])
        text += molecule_xml_element.Labels_Format["global_group_index"].format(global_group_index = molecule_xml_element.Fields["global_group_index"])
        text += molecule_xml_element.Labels_Format["atom_molecule_type_label"].format(atom_molecule_type_label = molecule_xml_element.Fields["atom_molecule_type_label"])
        text += molecule_xml_element.Labels_Format["x_coordinate_label"].format(x_coordinate_label = molecule_xml_element.Fields["x_coordinate_label"])
        text += molecule_xml_element.Labels_Format["y_coordinate_label"].format(y_coordinate_label = molecule_xml_element.Fields["y_coordinate_label"])
        text += molecule_xml_element.Labels_Format["z_coordinate_label"].format(z_coordinate_label = molecule_xml_element.Fields["z_coordinate_label"])
        return text

    def get_xml(self,atom_label):
        my_text =  f"""{atom_label}; {self.atom_labels[atom_label]}; {self.__atom_index[atom_label]}; {self.__group_id}; {self.group_type};  """
        my_text += f"""{self._coordinates[atom_label][0]} {self._coordinates[atom_label][1]} {self._coordinates[atom_label][2]};"""
        my_text += f"""{self._velocities[atom_label][0]} {self._velocities[atom_label][1]} {self._velocities[atom_label][2]}"""
        return my_text

    def get_xml_elements(self,atom_label):
        all_xml_elements = []
        my_element = ET.Element(molecule_xml_element.Fields["atom_label"])
        my_element.text = atom_label
        all_xml_elements.append(my_element )

        atom_symbol_element = ET.Element(molecule_xml_element.Fields["atom_symbol_label"])
        atom_symbol_element.text = self.atomic_symbols[atom_label]
        all_xml_elements.append(atom_symbol_element )
        
        atom_index_element = ET.Element(molecule_xml_element.Fields["atom_index_label"])
        atom_index_element.text = molecule_xml_element.Values_Format["atom_index_label"].format(atom_index_label=self.__atom_index[atom_label])
        all_xml_elements.append(atom_index_element )

        global_group_index_element = ET.Element(molecule_xml_element.Fields["global_group_index"])
        global_group_index_element.text = molecule_xml_element.Values_Format["global_group_index"].format(global_group_index=self.__group_id)
        all_xml_elements.append(global_group_index_element)

        group_type_element = ET.Element(molecule_xml_element.Fields["atom_molecule_type_label"])
        group_type_element.text = molecule_xml_element.Values_Format["atom_molecule_type_label"].format(atom_molecule_type_label=self.group_type)
        all_xml_elements.append(group_type_element)

        x_coord_element = ET.Element(molecule_xml_element.Fields["x_coordinate_label"])
        x_coord_element.text = molecule_xml_element.Values_Format["x_coordinate_label"].format(x_coordinate_label=self._coordinates[atom_label][0]) 
        all_xml_elements.append(x_coord_element)

        y_coord_element = ET.Element(molecule_xml_element.Fields["y_coordinate_label"])
        y_coord_element.text = molecule_xml_element.Values_Format["y_coordinate_label"].format(y_coordinate_label=self._coordinates[atom_label][1]) 
        all_xml_elements.append(y_coord_element)

        z_coord_element = ET.Element(molecule_xml_element.Fields["z_coordinate_label"])
        z_coord_element.text = molecule_xml_element.Values_Format["z_coordinate_label"].format(z_coordinate_label=self._coordinates[atom_label][2]) 
        all_xml_elements.append(z_coord_element)

        x_velocity_element = ET.Element(molecule_xml_element.Fields["x_velocity_label"])
        x_velocity_element.text = molecule_xml_element.Values_Format["x_velocity_label"].format(x_velocity_label=self._velocities[atom_label][0]) 
        all_xml_elements.append(x_velocity_element)

        y_velocity_element = ET.Element(molecule_xml_element.Fields["y_velocity_label"])
        y_velocity_element.text = molecule_xml_element.Values_Format["y_velocity_label"].format(y_velocity_label=self._velocities[atom_label][1]) 
        all_xml_elements.append(y_velocity_element)

        z_velocity_element = ET.Element(molecule_xml_element.Fields["z_velocity_label"])
        z_velocity_element.text = molecule_xml_element.Values_Format["z_velocity_label"].format(z_velocity_label=self._velocities[atom_label][2]) 
        all_xml_elements.append(z_velocity_element)


        return all_xml_elements


    def get_iterator(self):
        return iter(self.atomic_symbols)

    def rotate(self,R):
        # Rotate atom "tip3p-O1" with rotation matrix R.
        M1 = np.matmul(R,self._coordinates["tip3p-O1"])
        self._coordinates["tip3p-O1"] = M1

        M2 = np.matmul(R,self._coordinates["tip3p-H2"])
        self._coordinates["tip3p-H2"] = M2

        M3 = np.matmul(R,self._coordinates["tip3p-H3"])
        self._coordinates["tip3p-H3"] = M3
        return

    def translate(self,dr):
        M1 = np.add(self._coordinates["tip3p-O1"],dr)
        self._coordinates["tip3p-O1"] = M1

        M2 = np.add(self._coordinates["tip3p-H2"],dr)
        self._coordinates["tip3p-H2"] = M2

        M3 = np.add(self._coordinates["tip3p-H3"],dr)
        self._coordinates["tip3p-H3"] = M3

    def print_coordinates(self):
        print(f"""tip3p-O1: {self._coordinates["tip3p-O1"]} """)
        print(f"""tip3p-H2: {self._coordinates["tip3p-H2"]} """)
        print(f"""tip3p-H3: {self._coordinates["tip3p-H3"]} """)
        print(f"""group_index: {self.group_index}""")
        return

    def reset(self):
        self._coordinates = copy.deepcopy(self.initial_coordinates) 

    def reset_atom_indices(self,offset):

        ip = 0
        for key,value in self.__atom_index.items():
            ip += 1
            self.__atom_index[key] = offset + ip
        return

    @property
    def number_of_atoms(self):
        return len(self.atom_labels)

    @property
    def group_index(self):
        return self.__group_id

    @group_index.setter
    def group_index(self,id):
        self.__group_id = id

    ## The nuber of water molecules per angstroms^3
    @property
    def number_density(self):
        return ((3.34)*(10**-2))

    @property
    def points(self):
        my_points = []
        for key,value in self._coordinates.items():
            my_points.append(value)
        return  copy.deepcopy(my_points)

    def valid_molecule(self):

        # Verify all bond constraints.
        all_bonds_valid = self._validiate_bond_length()

        all_angles_valid = self._validate_angles()

        ret_value = (all_bonds_valid and all_angles_valid ) 

        return ret_value 

    #  ====================  PROTECTED     =======================================

    #  ====================  PRIVATE       =======================================
    def _validiate_bond_length(self):
        all_bonds_valid = True
        for (key,value) in self.bond_constraints.items():
            atom_label_1 = value[0]
            r1 = self._coordinates[atom_label_1]

            atom_label_2 = value[1]
            r2 = self._coordinates[atom_label_2]

            bond_length = np.linalg.norm(r2-r1)
            target_bond_length = value[2]

            dx = math.fabs(bond_length - target_bond_length )
            if ( dx > self.bond_constraints_tolerance) :
                all_bonds_valid = False
                break
        return all_bonds_valid

    def _validate_angles(self):
        all_angles_valid = True
        for (key,value) in self.angle_constraints.items():
            atom_label_1 = value[0]
            r1 = self._coordinates[atom_label_1]

            atom_label_2 = value[1]
            r2 = self._coordinates[atom_label_2]

            atom_label_3 = value[2]
            r3 = self._coordinates[atom_label_3]

            target_angle = value[3]
            # Form vector r1 - r2
            v1 = r1 - r2

            # Form vector r3 - r2
            v2 = r3 -r2

            cos_theta = (np.vdot(v1,v2))/(np.linalg.norm(v1)*np.linalg.norm(v2))
            theta = math.acos(cos_theta)
            dtheta = math.fabs(theta - target_angle)
            if (dtheta > self.angle_constraints_tolerance):
                all_angles_valid = False
                print("Invalid angle")
                break

        return all_angles_valid 



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
