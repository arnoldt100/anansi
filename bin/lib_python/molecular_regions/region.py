#! /usr/bin/env python3
## @package region

# System imports
import logging
import string
import argparse
import abc


# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

class Region(abc.ABC):
    def __init__(self):
        return

    ## Returns the volume of the region.
    ## 
    ## The volume of region.
    @property
    def volume(self):
        return self._volume()

    @abc.abstractmethod
    def _volume(self):
        pass

    @property
    def TYPE_OF_COORDINATE_SYSTEM(self):
        return self._type_of_coordinate_system()

    @abc.abstractmethod
    def _type_of_coordinate_system(self):
        pass

    def get_random_point_inside(self):
        return self._get_random_point_inside()

    @abc.abstractmethod
    def _get_random_point_inside(self):
        pass

    def get_random_rotation_matrix(self):
        return self._get_random_rotation_matrix()

    @abc.abstractmethod
    def _get_random_rotation_matrix(self):
        pass

    ## Write the region to disk.
    ## 
    ## The volume of region.
    def write_to_file(self):
        self._write_to_file();

    @abc.abstractmethod
    def _write_to_file(self):
        pass

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
