#! /usr/bin/env python3
""" Checks that critical environmental variables are defined.

    This program checks that critical environmental variables are
    defined. If any critical environmental variables are undefinded the
    the program exists with a non-zero status and writes to stdout a
    warning message of the undefined environmental variables.

    The critical environmental are stored in the INI file
    that is given on the command line by the option
    "--env-config-file".
"""

# System imports
import argparse
import logging
import configparser
import os

# Local imports

#-----------------------------------------------------
# Public methods, definitions, etc.                  -
#                                                    -
#-----------------------------------------------------

def main():
    """ The main program

    """
    args = _parse_arguments()

    logger = _create_logger(log_id=__name__,
                            log_level=args.log_level)

    logger.info("Start of main program")

    # The variable 'message_env_def' stores a message on the critical
    # defined environmental variables.
    message_env_def = "\nCrititcal environmental variables that are defined\n"
    message_env_def += "-"*(len(message_env_def)-2) + "\n"

    # The variable 'message_env_undef' stores a message on the critical
    # undefined environmental variables.
    message_env_undef = "\nCritical environmental variables that are undefined\n"
    message_env_undef += "-"*(len(message_env_undef)-2) + "\n"

    # The variable 'critical_env_variables' is a list of the critical
    # environmental variables.
    critical_env_variables = \
        _get_list_critical_env_var(args.env_config_file)

    for env_var_name in critical_env_variables:
        env_var_value = os.getenv(env_var_name)
        if env_var_value:
            message_env_def += f"{env_var_name}={env_var_value}\n"
        else:
            message_env_undef += f"{env_var_name}\n"

    message = message_env_undef + "\n\n" + message_env_def
    logger.info(message)
    logger.info("End of main program")

#-----------------------------------------------------
# Private methods, definitions, etc.                 -
#                                                    -
#-----------------------------------------------------

def _create_logger_description():
    frmt_header = "{0:10s} {1:40.40s} {2:5s}\n"
    frmt_items = frmt_header
    header1 = frmt_header.format("Level", "Description", "Option Value")
    header1_len = len(header1)
    log_option_desc = "The logging level. The standard levels are the following:\n\n"
    log_option_desc += header1
    log_option_desc += "-"*header1_len  + "\n"
    log_option_desc += frmt_items.format("NOTSET", "All messages will be", "0")
    log_option_desc += frmt_items.format("", "processed", " \n")
    log_option_desc += frmt_items.format("DEBUG", "Detailed information, typically of ", "10")
    log_option_desc += frmt_items.format("", "interest only when diagnosing problems.", "\n")
    log_option_desc += frmt_items.format("INFO", "Confirmation that things", "20")
    log_option_desc += frmt_items.format("", "are working as expected.", " \n")
    log_option_desc += \
            frmt_items.format("WARNING ", "An indication that something unexpected , ", "30")
    log_option_desc += frmt_items.format("", "happened or indicative of some problem", "")
    log_option_desc += frmt_items.format("", "in the near future.", "\n")
    log_option_desc += frmt_items.format("ERROR ", "Due to a more serious problem ", "40")
    log_option_desc += frmt_items.format("", "the software has not been able ", "")
    log_option_desc += frmt_items.format("", "to perform some function. ", "\n")
    log_option_desc += frmt_items.format("CRITICAL ", "A serious error, indicating ", "50")
    log_option_desc += frmt_items.format("", "that the program itself may be unable", "")
    log_option_desc += frmt_items.format("", "to continue running.", "\n")
    return log_option_desc

def _create_logger(log_id, log_level):
    logger = logging.getLogger(log_id)
    logger.setLevel(log_level)

    # create console handler and set level to debug
    console_handler = logging.StreamHandler()
    console_handler.setLevel(log_level)

    # create formatter
    formatter = logging.Formatter(
        '%(asctime)s - %(name)s - %(levelname)s - %(message)s')

    # add formatter to console_handler
    console_handler.setFormatter(formatter)

    # add console_handler to logger
    logger.addHandler(console_handler)

    return logger

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
                           default=logging.INFO,
                           help=_create_logger_description())

    my_parser.add_argument("--env-config-file",
                           type=str,
                           help=('The path to the INI config file that '
                                 'defines the mandatory environmental '
                                 'variables.'),
                           required=True)

    my_args = my_parser.parse_args()

    return my_args

def _get_list_critical_env_var(env_config_file):
    # Read the INI file that contains the critical environmental
    # variable information.
    config = configparser.ConfigParser()
    config.read(env_config_file)

    # Create the list of environmental variable names.
    a_list = []
    for section in config.sections():
        for (key, env_var_name) in config.items(section):
            a_list.append(env_var_name)

    return a_list

#-----------------------------------------------------
# Main entry point of module.                        -
#                                                    -
#-----------------------------------------------------

if __name__ == "__main__":
    main()
