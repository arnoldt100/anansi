#! /usr/bin/env python3
## @package __packagename__
#  __BriefDoxygenDescription__
#
# __DetailedDoxygenDescription__

# System imports
import string
import argparse
import logging

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

Separator=";"

Fields = {"atom_label": "Atom",
          "atom_symbol_label" : "Symbol",
          "atom_index_label" : "Global-Atom-Index",
          "global_group_index" : "Global-Group-Index", 
          "atom_molecule_type_label" : "Group-Type",
          "x_coordinate_label" : "X-coordinate",
          "y_coordinate_label" : "Y-coordinate",
          "z_coordinate_label" : "Z-coordinate",
          "x_velocity_label" : "X-Velocity",
          "y_velocity_label" : "Y-Velocity",
          "z_velocity_label" : "Z-velocity"}

Labels_Format = {"atom_label": "{atom_label:<10s}",
                 "atom_symbol_label" : "{atom_symbol_label:<10s}",
                 "atom_index_label" : "{atom_index_label:<25s}",
                 "global_group_index" : "{global_group_index:<32s}", 
                 "atom_molecule_type_label" : "{atom_molecule_type_label:<32s}",
                 "x_coordinate_label" : "{x_coordinate_label:<32s}",
                 "y_coordinate_label" : "{y_coordinate_label:<32s}",
                 "z_coordinate_label" : "{z_coordinate_label:<32s}",
                 "x_velocity_label" : "{x_velocity_label:<32s}",
                 "y_velocity_label" : "{y_velocity_label:<32s}",
                 "z_velocity_label" : "{z_velocity_label:<32s}"}

Values_Format = {"atom_label": "{atom_label:<10s}",
                 "atom_symbol_label" : "{atom_symbol_label:<10s}",
                 "atom_index_label" : "{atom_index_label:<d}",
                 "global_group_index" : "{global_group_index:<d}", 
                 "atom_molecule_type_label" : "{atom_molecule_type_label:<s}",
                 "x_coordinate_label" : "{x_coordinate_label:<.16e}",
                 "y_coordinate_label" : "{y_coordinate_label:<.16e}",
                 "z_coordinate_label" : "{z_coordinate_label:<.16e}",
                 "x_velocity_label" : "{x_velocity_label:<.16e}",
                 "y_velocity_label" : "{y_velocity_label:<.16e}",
                 "z_velocity_label" : "{z_velocity_label:<.16e}"}
Open_Commnet = "<!--"
Close_Commnet = "-->"

class Comment_Header:

    #  ====================  LIFECYCLE     =======================================
    def __init__(self) :
        return

    def __call__(self):
        return 


    #  ====================  PUBLIC        =======================================

    #  ====================  PROTECTED     =======================================

    #  ====================  PRIVATE       =======================================

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
