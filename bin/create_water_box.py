#! /usr/bin/env python3
## @package create_water_box

# System imports
import string
import argparse
import numpy as np
import copy
import xml.etree.ElementTree as ET

# Local imports
import logging
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger
import molecular_regions.rectangular
import molecular_regions.spherical
import molecular_regions.tip3p
from molecular_regions import molecule_xml_element

#  ====================  PROTECTED     =======================================

## @fn _parse_arguments( )
## @brief Parses the command line arguments.
##
## @details Parses the command line arguments and
## returns a tuple of namespaces.
##
## @return A tuple of namespaces. The namespaces contains attributes
##         that are the command line arguments.
def _parse_arguments():

    # Create a string of the description of the 
    # program
    program_description = ( f"""This program creates water boxes for Anansi.\n\n"""
                            f"""Typical uage is : create_water_box.py --type-of-molecule <...> rectangular_bounding_region --origin <...> --dimensions <...>\n\n"""
                            f"""For help on a subcommand do : create_water_box.py <subcommand> --help\n"""
                            f"""All lengths and coordinates are in angstroms. """ )

    # Create text for 'type of water' option help.
    type_of_water_help = ( f"""The type of water (model) to fill the bounding.\n""")

    # Create text for 'type of bounding region' option help.
    type_of_water_help = ( f"""The type of bounding region.\n""")


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

    my_parser.add_argument("--output-file-name",
                       type=str,
                       default="a_water_box",
                       help="The prefix for the output file name. The default prefix is 'a_water_box'," )

    my_parser.add_argument("--region-name",
                       type=str,
                       default="All atoms",
                       help="The name of the region. The default name is 'All atoms'.")

    # Adding mandatorgument group.
    mandatory_args_group = my_parser.add_argument_group(title="Mandatory Arguments")

    mandatory_args_group.add_argument("--type-of-molecule",
                           required=True,
                           type=str,
                           choices=["tip3p"],
                           help=type_of_water_help)

    # Adding subparser for commands for defining the bounding region.
    bounding_region_subparser = my_parser.add_subparsers(help="Commands to create different types of bounding regions.",
                                                         title="Subcommand arguments for creating types of bounding regions",
                                                         dest="subparser_name")

    # Adding parser for the rectangular region.
    parser_rect = bounding_region_subparser.add_parser("rectangular_bounding_region",help="Create a rectangular bounding region.") 
    parser_rect.add_argument("--origin",required=True,nargs=3,type=float,help="The origin of the bounding rectangular box.",
                             metavar=("x-origin","y-origin","z-origin"))
    parser_rect.add_argument("--dimensions",required=True,nargs=3,type=float,help="The dimension of the rectangular bounding box",
                             metavar=("x-length","y-length","z-length"))
    parser_rect.add_argument("--boundary-conditions",required=True,nargs=3,type=str,help="The boundary conditions rectangular bounding box",
                             choices=["pbc","no-pbc"],
                             metavar=("x-boundary-conditions","y-boundary-conditions","z-boundary-conditions"))


    # Adding parser for the spherical region.
    parser_sphere = bounding_region_subparser.add_parser("spherical_bounding_region",help="Create a spherical bounding region.") 
    parser_sphere.add_argument("--origin",required=True,type=float,nargs=3,help="The origin of bounding sphere; in cartesian coordinates.",
                               metavar=("x","y","z") )
    parser_sphere.add_argument("--radius",required=True,type=float,help="The radius of the bounding sphere.")

    my_args = my_parser.parse_args()

    return my_args 

def _region_factory(args):
    my_region = None
    my_output_file_name = args.output_file_name + ".coordinatesystem"

    # Choose what kind of bounding region to fill in.
    if args.subparser_name == "rectangular_bounding_region":
        my_origin = np.array([args.origin[0],
                              args.origin[1],
                              args.origin[2]])
        my_dimensions = np.array([args.dimensions[0],
                                  args.dimensions[1],
                                  args.dimensions[2]])
        my_pbc = np.array([args.boundary_conditions[0], 
                           args.boundary_conditions[1],
                           args.boundary_conditions[2]])
        my_region = molecular_regions.rectangular.Rectangular(my_output_file_name,
                                                              origin=my_origin,pbc=my_pbc,dimensions=my_dimensions)
    elif args.subparser_name == "spherical_bounding_region":
        my_region = molecular_regions.spherical.Spherical()
    return my_region

def _water_molecule_factory(args):
    my_molecule = None
    # Choose what kind of molcule to fill in region.
    if args.type_of_molecule == "tip3p":
        my_molecule = molecular_regions.tip3p.tip3p()
    return my_molecule

def _create_coordinates(args,molecule,region,my_logger):

    number_of_molecules = __compute_number_molecules_in_region(molecule,region)
  
    all_molecules = __generate_molecules(molecule,region,number_of_molecules)

    __dump_coordinates_in_xml(args,all_molecules,region)

    return

def _create_coordinate_system(args,region,my_logger):
    region.write_to_file()
    return

#  ====================  PRIVATE       =======================================
def __region_name_element(region_name):
        my_element = ET.Element("Region Name") 
        my_element.text = region_name
        return my_element

def __type_of_coordinate_system_element(region):
        my_element = ET.Element("Coordinate System") 
        my_element.text = region.TYPE_OF_COORDINATE_SYSTEM
        return my_element

def __verify_molecule_is_valid(molecule,region):
    valid_molecule = molecule.valid_molecule()
    molecule_in_region = region.inside(molecule.points)
    return (valid_molecule and molecule_in_region)

def __compute_total_number_of_atoms(all_molecules):
    number_of_atoms = 0
    for a_molecule in all_molecules:
            number_of_atoms += a_molecule.number_of_atoms

    return number_of_atoms

def __coordinates_elements(all_molecules):
    my_element = ET.Element("Coordinates, Velocities, ...")

    total_number_of_atoms = __compute_total_number_of_atoms(all_molecules)
    my_nm_atoms_element = ET.Element("Total Number of Atoms")
    my_nm_atoms_element.text = str(total_number_of_atoms)
    my_element.append(my_nm_atoms_element) 

    # my_comment = ET.Comment(text=" Atom;    Symbol;     Atom Index;    Group-ID;    Group-Type;     x,y and z Coordinates; x, y and z Velocities ")
    my_comment = ET.Comment(text=all_molecules[0].get_comment_header())
    my_element.append(my_comment)


    index = 0
    for a_molecule in all_molecules:

        my_molecule_iterator = a_molecule.get_iterator()
        for my_atom_label in my_molecule_iterator:
            index += 1

            my_atom_element = ET.Element(f"""{index}""" )

            for a_xml_element in a_molecule.get_xml_elements(my_atom_label):
                my_atom_element.append(a_xml_element)
            my_element.append(my_atom_element)

    return my_element

def __compute_number_molecules_in_region(molecule,region):
    import math
    # Given the volume of the region and the density of the molecule, compute
    # the number of molecules to place in the region.
    volume = region.volume
    number_density = molecule.number_density
    number_of_molecules = math.ceil(volume*number_density)
    return number_of_molecules

def __generate_molecules(molecule,region,number_of_molecules):
    all_molecules = []
    atom_offset = 0
    for ip in range(0,number_of_molecules):
        print()
        print(f"""Molecule # {ip+1}: """)
        valid_molecule = False
        my_molecule = None
        while not valid_molecule : 
            my_molecule = copy.deepcopy(molecule)
            
            my_molecule.group_index = ip

            # First rotate water molecule.
            R = region.get_random_rotation_matrix()
            my_molecule.rotate(R)

            # Second, translate the water molecule.
            translation_vector = region.get_random_point_inside()
            my_molecule.translate(translation_vector)
    
            valid_molecule = __verify_molecule_is_valid(my_molecule,region)

        atom_offset = ip*(my_molecule.number_of_atoms)
        my_molecule.reset_atom_indices(atom_offset)

        my_molecule.print_coordinates()
        all_molecules.append(my_molecule)
    return all_molecules

def __dump_coordinates_in_xml(args,all_molecules,region):
    # Create the top level node <data>.
    top_level_node = ET.Element("data")

    region_name_element = __region_name_element(args.region_name)
    top_level_node.append(region_name_element)

    # Create the element <Type of Coordinate System>
    tocs_element = __type_of_coordinate_system_element(region)
    top_level_node.append(tocs_element)

    my_coordinates_elements = __coordinates_elements(all_molecules)
    top_level_node.append(my_coordinates_elements)


    # We indent the the tree for human readability.
    ET.indent(top_level_node)

    # Convert to an ElementTree class and write to file.
    my_tree = ET.ElementTree(top_level_node)

    my_output_file_name = args.output_file_name + ".coordinates"
    my_tree.write(my_output_file_name,encoding="us-ascii",
                  method="xml",
                  short_empty_elements=True)
    return

#  ====================  PUBLIC        =======================================

## @fn main ()
## @brief The main function.
def main():
    args = _parse_arguments()

    logger = create_logger(log_id='main_logger',
                           log_level=args.log_level)

    logger.info("Start of main program")

    # Choose what kind of molecule to fill in the region.

    my_molecule = _water_molecule_factory(args)

    my_region = _region_factory(args)

    _create_coordinate_system(args,my_region,logger)

    _create_coordinates(args,my_molecule,my_region,logger)

    logger.info("End of main program")

if __name__ == "__main__":
    main()

