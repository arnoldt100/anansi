#! /usr/bin/env python3
## @package unit_test_status
# This module 
# 

# System imports
import logging
import argparse

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger


## @class TestStatus
class TestStatus:

    def __init__(self, testid, stdout="", stderr="", test_status=False):
        self._testid = testid
        self._stderr = stderr
        self._stdout = stdout
        self._test_status = test_status

    def _get_testid(self):
        return self._testid

    testid = property(fget=_get_testid,doc="The id of the test.")

    def _get_stderr(self):
        return self._stderr

    stderr = property(fget=_get_stderr,doc="The stderr of the test.")

    def _get_stdout(self):
        return self._stdout

    stdout = property(fget=_get_stdout,doc="The stdout of the test.")

    def _get_test_status(self):
        return self._test_status

    test_status = property(fget=_get_test_status,doc="The status of test run.")

# ------------------------------------------------------------------
# Main module functions
# ------------------------------------------------------------------

## @fn _parse_arguments( )
# @brief Parses the command line arguments.
#
# @details Parses the command line arguments and
# returns A namespace.
#
# @return A namespace. The namespace contains attributes
#         that are the command line arguments.
def _parse_arguments():

    # Create a string of the description of the 
    # program
    program_description = "Main program for module unit_test_status.py" 

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

## @fn _main ()
## @brief The main function.
def _main():
    args = _parse_arguments()

    logger = create_logger(log_id='anansi_unit_test_logger',
                           log_level=args.log_level)

    logger.info("Start of main program")

    logger.info("End of main program")

if __name__ == "__main__":
    _main()
