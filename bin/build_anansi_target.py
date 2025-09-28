#! /usr/bin/env python3
## @package build_anansi_target,py
#  This program creates directories and copies files to build Anansi 
#  for the targeted architecture,
#
#  This program creates the directories
#  ${ANANSI_TARGET_ARCHITECTURE}
#                     |-----/build
#                     |
#                     |-----/unit_test_logs
# 
# The environmental variable "ANANSI_TARGET_ARCHITECTURE" and "ANANSI_TOP_LEVEL"
# must be defined or the program will abort with failure.
# 
# The directories to be created must not exist prior of the program will abort with failure.

# System imports
import string
import argparse
import os
import sys

# Local imports
import logging
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

## @fn main ()
## @brief The main function.
def main():
    try:
        _verify_environmental_variables_set()
    except _UndefinedCriticalEnvironmentalVariableError as my_error:
        print(my_error)
        sys.exit(1)

    args = _parse_arguments()

    logger = create_logger(log_id='__LoggerID__',
                           log_level=args.log_level)

    logger.info("Start of main program")

    try:
        _create_target_architecture_directories()
    except _TargetPathExistsError as my_error:
        print(my_error)
        sys.exit(1)

    logger.info("End of main program")

## @class _UndefinedCriticalEnvironmentalVariableError
## @brief This error is thrown when a critical environmental variable is undefined.
class _UndefinedCriticalEnvironmentalVariableError(Exception):
    def __init__(self,message):
        self._message = f"The crtitical environmental variable '{message}' is undefined."
        super().__init__(self._message)

    def __str__(self):
        return self._message

## @class _UndefinedCriticalEnvironmentalVariableError
## @brief This error is thrown when a critical environmental variable is undefined.
class _TargetPathExistsError(Exception):
    def __init__(self,message):
        self._message = f"The target directory file path '{message}' already exists."
        super().__init__(self._message)

    def __str__(self):
        return self._message

## @fn _verify_environmental_variables_set( )
## @brief Verifies critical environmental variables are set.
##
## @details If critical environmental variables are not set
## the progrom will abort.
##
## @return None
def _verify_environmental_variables_set():
    # We define a list of environmental variables to check if defined.
    critical_environmental_variables = ["ANANSI_TARGET_ARCHITECTURE",
                                        "ANANSI_TOP_LEVEL"]

    for variable in critical_environmental_variables:
        value = os.getenv(variable)
        if value == None:
           raise _UndefinedCriticalEnvironmentalVariableError(variable)

## @fn _create_target_architecture_directories( )
## @brief Creates the directories needed for building the target architecture.
def _create_target_architecture_directories():
    anansi_top_level = os.getenv("ANANSI_TOP_LEVEL")
    anansi_target_architecture = os.getenv("ANANSI_TARGET_ARCHITECTURE")
    target_top_level = os.path.join(anansi_top_level,anansi_target_architecture)

    if os.path.exists(target_top_level):
        raise _TargetPathExistsError(target_top_level)

    directories_to_create = ( os.path.join(target_top_level,'etc'),
                              os.path.join(target_top_level,'build'),
                              os.path.join(target_top_level,'configuration'),
                              os.path.join(target_top_level,'documentation'),
                              os.path.join(target_top_level,'umit_test_logs') )

    for tmp_dir in directories_to_create:
        os.makedirs(tmp_dir)


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
    program_description += "for building the target architecture. The environmental variables\n"
    program_description += "'ANANSI_TARGET_ARCHITECTURE' and 'ANANSI_TOP_LEVEL' must be \n"
    program_description += "defined or the program will abort with failure.\n"

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


if __name__ == "__main__":
    main()
