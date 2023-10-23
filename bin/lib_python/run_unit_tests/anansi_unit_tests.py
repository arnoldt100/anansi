#! /usr/bin/env python3
## @package anansi_unit_tests
#  Contains the AnansiUnitTest class

# System imports
import string
import argparse
import xml.etree.ElementTree as ET
import os

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger

## @class UnitTest
class UnitTest:

    ## The constructor
    # @param test_name The name of the test.
    # @param active The state of running this test. If active is true, then the test will be run. Otherwise the test will not be run.
    # @param binary The path to the unit test binary.
    # @param binary_argumerent The command line arguments of the unit test binary.
    def __init__(self,test_name,active=False,binary=None,binary_arguments=None):
        self._test_name = test_name
        self._active = active
        self._binary = binary
        self._binary_arguments = binary_arguments
    
    def printForDebugging(self):
        message =  f"""===\n"""
        message += f"""Test name: {self._test_name}\n"""
        message += f"""Active: {self._active}\n"""
        message += f"""Path to binary: {self._binary}\n"""
        message += f"""Binary arguments: {self._binary_arguments}\n"""
        message += f"""===\n\n"""
        print(message)

    def runUnitTest(self):
        message = f"""Stud: runUnitTest, running unit test - {self._test_name}\n"""
        print(message)
        
## Returns a list all Anansi's unit tests.
def get_all_tests():
    path_to_xml_file = os.getenv("ANANSI_UNIT_TEST_CONFIGURATION")
    root_path_unit_tests = os.getenv("ANANSI_INSTALL_BIN_DIRECTORY")
    tree = ET.parse(path_to_xml_file)
    root = tree.getroot()
    all_tests = []
    for unit_test in root.findall('unit_test'):
        tag = unit_test.tag
        name = unit_test.attrib["name"]
        active = unit_test.find('active').text
        test_binary = unit_test.find('test_binary').text
        test_binary_full_qualified_path = os.path.join(root_path_unit_tests,test_binary)
        test_arguments = unit_test.find('test_arguments').text 
        all_tests.append(UnitTest(test_name=name,
                                  active=active,
                                  binary=test_binary_full_qualified_path,
                                  binary_arguments=test_arguments))
    return all_tests
## Lists all tests
def list_all_tests():
    all_tests = get_all_tests()
    for tmp_test in all_tests:
        tmp_test.printForDebugging()

## Runs all tests.
def test_all_tests():
    all_tests = get_all_tests()
    for tmp_test in all_tests:
        tmp_test.runUnitTest()
    
 
## @fn _main ()
## @brief The main function.
def _main():
    args = _parse_arguments()

    logger = _create_logger(log_id='anansi_unit_test_logger',
                           log_level=args.log_level)

    logger.info("Start of main program")

    logger.info("End of main program")

if __name__ == "__main__":
    _main()

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

