#! /usr/bin/env python3
## @package tip3p

# System imports
import string
import argparse
import numpy as np
import math

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

class tip3p:
    group_type = "tip3p-rigid-molecule"

    atomic_symbols = {"tip3p-O1" : "O",
                      "tip3p-H2" : "H",
                      "tip3p-H3" : "H"}

    atomic_labels = {"tip3p-O1" : "O",
                     "tip3p-H2" : "H1",
                     "tip3p-H3" : "H2"}

    atomic_monopoles = {"tip3p-O1" : -0.834,
                        "tip3p-H2" : 0.417,
                        "tip3p-H3" : 0.417}

    atom_mass = {"tip3p-O1" : 15.999,
                 "tip3p-H2" : 1.00784,
                 "tip3p-H3" : 1.00784 }

    bond_constraints = { 
                         "1" : ["tip3p-O1","tip3p-H1",0.9572],
                         "2" : ["tip3p-O1","tip3p-H2",0.9572]
                       }

    angle_constraint = {
                         "1" : ["tip3p-H1","tip3p-O1","tip3p-H2" ,1.82421813],
                       }
    initial_coordinates = {
                           "tip3p-O1" : np.array([0.00,0.00,0.00]),
                           "tip3p-H2" : np.array([0.00,0.9572,0.00]),
                           "tip3p-H3" : np.array([0.00,
                                                 0.9572*math.cos(104.52*(math.pi/180.00)),
                                                 0.9572*math.sin(104.52*(math.pi/180.00))]) 
                          }

    def __init__(self):
        self._coordinates = self.initial_coordinates
                                                    

    def rotate(self,phi,theta,psi):
        return

    def translate(self,dr):
        return

    def reset(self):
        self._coordinates = self.initial_coordinates 

    ## The nuber of water molecules per angstroms^3
    @property
    def number_density(self):
        return ((3.34)*(10**-2))

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

    logger = _create_logger(log_id='__LoggerID__',
                           log_level=args.log_level)

    logger.info("Start of main program")

    logger.info("End of main program")

if __name__ == "__main__":
    main()
