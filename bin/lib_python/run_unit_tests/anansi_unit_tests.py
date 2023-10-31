#! /usr/bin/env python3
## @package anansi_unit_tests

# System imports
import logging
import argparse
import xml.etree.ElementTree as ET
import os

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger
from run_unit_tests.unit_test_status import TestStatus

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
        
    def _get_cmd(self):
        cmd = f"""{self._binary} {self._binary_arguments}"""
        return cmd

    command = property(fget=_get_cmd,doc="The command that runs the test.")

    def _get_test_name(self):
        return self._test_name

    test_name = property(fget=_get_test_name,doc="The name of the unit test.")

    def _get_active(self):
        return self._active

    active = property(fget=_get_active,doc="Indicates if test is active.")

    def _get_binary(self):
        return self._binary

    binary = property(fget=_get_binary,doc="The name of the unit test binary.")

    def _get_binary_args(self):
        return self._binary_arguments

    binary_args = property(fget=_get_binary_args,doc="The binary arguments.")

## Returns a list all Anansi's unit tests.
def _get_all_tests():
    path_to_xml_file = os.getenv("ANANSI_UNIT_TEST_CONFIGURATION")
    root_path_unit_tests = os.getenv("ANANSI_INSTALL_BIN_DIRECTORY")
    tree = ET.parse(path_to_xml_file)
    root = tree.getroot()
    all_tests = []
    for unit_test in root.findall('unit_test'):
        tag = unit_test.tag
        name = unit_test.attrib["name"]
        active = unit_test.find('active').text
        active = active.strip()
        test_binary = unit_test.find('test_binary').text
        test_binary = test_binary.strip()
        test_binary_full_qualified_path = os.path.join(root_path_unit_tests,test_binary)
        test_arguments = unit_test.find('test_arguments').text 
        test_arguments = test_arguments.strip()
        all_tests.append(UnitTest(test_name=name,
                                  active=active,
                                  binary=test_binary_full_qualified_path,
                                  binary_arguments=test_arguments))
    return all_tests


## Lists all tests
#
# Lists oall tests using the primary_logger.
# @param primary_logger An object that logs to a file.
def list_all_tests(primary_logger):
    # We define the separator.
    separator = ":"
    hidden_separator = "  "

    # We define the widths for for the column 1, the text, and 
    # the separating text between column 1 and the text.
    col1_width = 30
    sep_width = len(separator)
    text_width = 50

    # We define the horizontal border.
    hborder = _horizontal_border("=",col1_width,sep_width,text_width)

    frmt_row = _2_column_frmt_entry(col1_field_name='col1_name',
                                    col1_width=col1_width,
                                    col2_field_name='text',
                                    col2_width=text_width,
                                    sep_chars=hidden_separator)

    all_tests = _get_all_tests()
    message = "\nBelow is a detailed list of all Anansi's unit tests:\n"
    skip_2_lines = "\n\n"

    counter = 0
    for tmp_test in all_tests:
        if counter == 0:
            message += skip_2_lines

        message += hborder

        message += frmt_row.format(col1_name="Test Name",
                                   sep_chars=separator,
                                   text=tmp_test.test_name)

        message += frmt_row.format(col1_name="Active",
                                   sep_chars=separator,
                                   text=tmp_test.active)

        message += frmt_row.format(col1_name="Binary Name",
                                   sep_chars=separator,
                                   text=tmp_test.binary)

        message += frmt_row.format(col1_name="Binary Arguments",
                                   sep_chars=separator,
                                   text=tmp_test.binary_args)
        message += hborder
        message += skip_2_lines
        counter += 1
    primary_logger.info(message)

## Runs all tests.
#
# @param unit_test_logger The main logger for the unit tests.
def test_all_tests(unit_test_logger):

    all_tests = _get_all_tests()

    _start_test_prologue_message(unit_test_logger,all_tests)

    all_tests_results = []
    for tmp_test in all_tests:

        if tmp_test.active == "yes" :
            test_status = _run_active_test(tmp_test)
            _test_result_message(unit_test_logger,test_status)
            all_tests_results.append(test_status) 
        elif tmp_test.active == "no" :
            test_status = _run_not_active_test(tmp_test)
            _test_result_message(unit_test_logger,test_status)
            all_tests_results.append(test_status) 

    _end_test_epilog_message(unit_test_logger,all_tests_results)

## Creates an log file and returns its path.
##
## The base_dir and file_name are concatenated to form 
## a fully qualified path to the logging file. The empty 
## logging file is created and its path is returned.
##
## @param base_dir The base directory of the logging file path.
## @param file_name The file name of the logging file.
def create_unit_test_log_file(base_dir, file_name="unit-test-log.txt"):
    import os

    os.makedirs(base_dir,exist_ok=True)
    logger_file1 = os.path.join(base_dir,file_name)
    logger_file = os.path.abspath(logger_file1)
    if not os.path.lexists(logger_file) :
        with open(logger_file,mode='w') as fh:
            pass

    return logger_file

## Returns a horizonatal line composed of "chars".
#
# *widths are integer numbers whose sum is the number
# 'chars' that make the horizontal line.
def _horizontal_border(chars,*widths):
    bwidth = 0
    for arg in widths:
        bwidth += arg
    hline = chars * (bwidth)
    hborder = "\n{0}".format(hline)
    return hborder

def _2_column_frmt_entry(col1_field_name="", col1_width=0, col2_field_name="", col2_width=0, sep_chars=""):
    frmt = '\n{' + col1_field_name + ':' + str(col1_width) + '}' + \
             '{sep_chars:' + str(len(sep_chars)) + '}' + \
             '{' + col2_field_name + ':' + str(col2_width) + '}'
    return frmt

## Runs a single active test and returns the status/result of the test.
#
# @param a_test A test that is to run 
# 
def _run_active_test(a_test):
    import subprocess
    import shlex
    test_status = [None]
    args = shlex.split(a_test.command)
    try:
        my_process = subprocess.run(args,capture_output=True)
        test_status[0] = TestStatus(a_test.test_name,
                                    stdout=my_process.stdout,
                                    stderr=my_process.stderr,
                                    test_status=my_process.returncode)
    except FileNotFoundError as exc:
        print(f"Unit test failed because the executable could not be found.\n{exc}")
    return test_status[0]

## Runs a single not-active test and returns the status/result of the test.
#
# @param a_test A test that is to run 
# 
def _run_not_active_test(a_test):
    stdout_not_active = "Test is inactive".encode()
    stderr_not_active = "Test is inactive".encode()
    ret_code = 0
    test_status = TestStatus(a_test.test_name,
                             stdout=stdout_not_active,
                             stderr=stderr_not_active,
                             test_status=ret_code)
    return test_status

def _start_test_prologue_message(unit_test_logger,unit_tests):
    message = "\nStarting run of the below Anansi's unit tests:"
    for tmp_test in unit_tests:
        test_name = tmp_test.test_name
        message += f"""\n\t{test_name}"""
    message += "\n\n"
    unit_test_logger.info(message)

def _test_result_message(unit_test_logger,test_status):
    # We define the separator.
    separator = ":"
    hidden_separator = "  "

    # We define the widths for for the column 1, the text, and 
    # the separating text between column 1 and the text.
    col1_width = 30
    sep_width = len(separator)
    text_width = 50

    frmt_row = _2_column_frmt_entry(col1_field_name='col1_name',
                                    col1_width=col1_width,
                                    col2_field_name='text',
                                    col2_width=text_width,
                                    sep_chars=hidden_separator)

    # We define the horizontal border.
    hborder = _horizontal_border("=",col1_width,sep_width,text_width)
    skip_1_lines = "\n"

    message = hborder 
    message += frmt_row.format(col1_name="Test Name",
                               sep_chars=separator,
                               text=test_status.testid)
    message += frmt_row.format(col1_name="STDOUT",
                               sep_chars = separator,
                               text = test_status.stdout.decode() )
    message += frmt_row.format(col1_name="STDERR",
                               sep_chars = separator,
                               text = test_status.stderr.decode() )
    message += hborder 
    message += skip_1_lines
    unit_test_logger.info(message)
    return

def _end_test_epilog_message(unit_test_logger,unit_tests):
    test_id_width = 30
    test_status_width = 11
    sep_width = 2

    line1 = '=' * (test_id_width + test_status_width + sep_width )
    hborder = "\n{0}".format(line1)

    col1_frmt  = str(test_id_width) 
    sep_frmt = str(sep_width) 
    col2_frmt = str(test_status_width)

    frmt1 = '\n{test_name:' + col1_frmt + '}' 
    frmt1 +=  '{sep_char:' + sep_frmt + '}'
    frmt1 +=  '{test_status:' + col2_frmt + '}'
    message = "\nEpilog of Anansi's Unit Test:\n"
    message +="\nBelow is a summary of the results of Anansi's unit tests."
    message += "\nA non-zero integer indicates a failure.\n"
    message += hborder
    message += frmt1.format(test_name="Test ID", sep_char=" ", test_status= "Test Status")
    message += hborder
    for tmp_test in unit_tests:
        message += frmt1.format(test_name=tmp_test.testid, sep_char=" " , test_status=tmp_test.test_status)
    message += hborder
    unit_test_logger.info(message)

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
    program_description = "Main program for module anansi_unit_tests.py" 

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

