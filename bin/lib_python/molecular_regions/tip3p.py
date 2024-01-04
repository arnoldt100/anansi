#! /usr/bin/env python3
## @package tip3p

# System imports
import string
import argparse

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

class tip3p:
    group_type = "tip3p-rigid-molecule"
    def __init__(self):
        pass

    def rotate(self):
        pass

    def translate(self):
        pass

    def reset(self):
        pass

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
