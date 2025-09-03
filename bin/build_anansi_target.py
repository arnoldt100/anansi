#! /usr/bin/env python3
## @package build_anansi_target,py
#  This program creates directories and copies files to build Anansi 
#  for the targeted architecture,
#
#  This program creates the directories
#  ${ANANSI_TOP_LEVEL}|-----/build
#                     |
#                     |-----/configurations
#                     |
#                     |-----/documentation
#                     |
#                     |-----/unit_test_logs
# 
# The environmental varable "ANANSI_TARGET_ARCHITECTURE" must
# be defined or the program will abort.

# System imports
import string
import argparse

# Local imports
import logging
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

## @fn _verify_environmental_variables_set( )
## @brief Verifies critical environmental variables are set.
##
## @details If critical environmental variables are not set
## the progrom will abort.
##
## @return None
def _verify_environmental_variables_set():
    # We define a list of environmental variables to check if defined.
    critical_environmental_variables = ["ANANSI_TARGET_ARCHITECTURE"]

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
    program_description =  "This program creates directories and copies configuration files\n" 
    program_description += "for building the target architecture. The environmental variable\n" 
    program_description += "'ANANSI_TARGET_ARCHITECTURE' must be defined or the program will abort.\n"
# "
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
    try:
        _verify_environmental_variables_set()
    except:
        pass

    args = _parse_arguments()

    logger = create_logger(log_id='__LoggerID__',
                           log_level=args.log_level)

    logger.info("Start of main program")

    logger.info("End of main program")

if __name__ == "__main__":
    main()
