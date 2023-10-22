#! /usr/bin/env python3
## @package run_unit_tests
# This module runs Anansi's unit tests.
# 
# This module is intended to be executed as script. Typical usage is
# 
#     run_unit_tests.py --targets <the unit tests to run>
# 
# where
# 
# \<targets> is a list of tests to run separated by a semi-colon, ";". For example
#
# run_unit_tests.py --targets test_target 1; test_target 2; test_target 3
#
# will run the unite tests for test_target 1, test_target 2, and test_target 3. If the test is not
# implemeneted a warning will be issued and the missing test is considered a failure.

# System imports
import string
import argparse

# Local imports
from loggerutils.logger import create_logger_description
from loggerutils.logger import create_logger
from run_unit_tests.anansi_unit_tests import list_all_tests

def _main():
    args = _parse_arguments()
    
    if args.test_all_targets:
        test_all_tests()
    elif args.list_all_targets:
        list_all_tests()
    elif args.test_targets:
        pass

def _parse_arguments():
    import logging

    # Create an argument parser.
    my_parser = argparse.ArgumentParser(
            description=_get_program_description(),
            formatter_class=argparse.RawTextHelpFormatter,
            add_help=True)

    # Add an optional argument for the logging level.
    my_parser.add_argument("--log-level",
                           type=int,
                           default=logging.WARNING,
                           help=create_logger_description() )

    # We now add a group of arguments of which at least one is mamdatory.
    mandatory_group = my_parser.add_argument_group("Mutually Exclusive Arguments",
                                                   "The arguments in this group are mutually exclusive and require at least 1 be present.")

    group = mandatory_group.add_mutually_exclusive_group(required=True)

    group.add_argument("--test-all-targets",
                       action="store_true",
                       help=_get_test_all_targets_description()) 

    group.add_argument("--list-all-targets",
                       action="store_true",
                       help=_get_list_all_targets_description()) 

    group.add_argument("--test-targets",
                       type=str,
                       nargs='+',
                       metavar="target",
                       help=_get_test_targets_description()) 

    my_args = my_parser.parse_args()
    return my_args

def _get_program_description():
    pd =  ("""This program runs Anansi's unit tests.\n""")
    pd += ("""Typical usage is\n\n""")
    pd += ("""  run_unit_tests.py --test-targets target1 target2 ... targetN\n\n""")
    pd += ("""Note that each test is separated by spaces,\n""")
    pd += ("""therefore a test argument name shouldn't contain spaces.\n""")
    pd += ("""\n""")
    pd += ("""To list the available tests do\n\n""")
    pd += ("""  run_unit_tests.py --list-test-targets\n\n""")
    pd += ("""To run all available tests do\n\n""")
    pd += ("""  run_unit_tests.py ---test-all-targets\n\n""")
    return pd

def _get_test_all_targets_description():
    description = ("""Instructs the program to run all available tests.\n\n""")
    return description

def _get_list_all_targets_description():
    description = ("""Instructs the program to list all available tests.\n\n""")
    return description

def _get_test_targets_description():
    description =  ("""Instructs the program to run the unit tests on the list of targets.\n""")
    description += ("""At least 1 test target must be listed.\n\n""")
    return description

if __name__ == "__main__":
    _main()
