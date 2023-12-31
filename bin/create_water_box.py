#! /usr/bin/env python3
## @package create_water_box

# System imports
import string
import argparse

# Local imports
import logging
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger
import molecular_regions.rectangular
import molecular_regions.spherical
import molecular_regions.tip3p

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

    # Adding mandatory argument group.
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

    # Adding parser for the spherical region.
    parser_sphere = bounding_region_subparser.add_parser("spherical_bounding_region",help="Create a spherical bounding region.") 
    parser_sphere.add_argument("--origin",required=True,type=float,nargs=3,help="The origin of bounding sphere; in cartesian coordinates.",
                               metavar=("x","y","z") )
    parser_sphere.add_argument("--radius",required=True,type=float,help="The radius of the bounding sphere.")

    my_args = my_parser.parse_args()

    return my_args 

def _region_factory(args):
    my_region = None
    # Choose what kind of bounding region to fill in.
    if args.subparser_name == "rectangular_bounding_region":
        my_region = molecular_regions.rectangular.Rectangular()
    elif args.subparser_name == "spherical_bounding_region":
        my_region = molecular_regions.spherical.Spherical()
    return my_region

def _water_molecule_factory(args):
    my_molecule = None
    # Choose what kind of bounding region to fill in.
    if args.type_of_molecule == "tip3p":
        my_molecule = molecular_regions.tip3p.tip3p()
    return my_molecule

def _fill_region_with_water(region, molecule):
    pass

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

    logger.info("End of main program")

if __name__ == "__main__":
    main()

