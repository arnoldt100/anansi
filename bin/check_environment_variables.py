#! /usr/bin/env python3


# System imports
import string
import argparse # Needed for parsing command line arguments.
import logging  # Needed for logging events.

# Local imports

def create_logger_description():
    frmt_header = "{0:10s} {1:40.40s} {2:5s}\n"
    frmt_items = frmt_header
    header1 =  frmt_header.format("Level", "Description", "Option Value" )  
    header1_len = len(header1)
    log_option_desc = "The logging level. The standard levels are the following:\n\n"
    log_option_desc += header1
    log_option_desc += "-"*header1_len  + "\n"
    log_option_desc += frmt_items.format("NOTSET", "All messages will be", "0" )  
    log_option_desc += frmt_items.format("", "processed", " \n" )  
    log_option_desc += frmt_items.format("DEBUG", "Detailed information, typically of ", "10" )  
    log_option_desc += frmt_items.format("", "interest only when diagnosing problems.", "\n" )  
    log_option_desc += frmt_items.format("INFO", "Confirmation that things", "20" )  
    log_option_desc += frmt_items.format("", "are working as expected.", " \n" )  
    log_option_desc += frmt_items.format("WARNING ", "An indication that something unexpected , ", "30" )  
    log_option_desc += frmt_items.format("", "happened or indicative of some problem", "" )  
    log_option_desc += frmt_items.format("", "in the near future.", "\n" )  
    log_option_desc += frmt_items.format("ERROR ", "Due to a more serious problem ", "40" )  
    log_option_desc += frmt_items.format("", "the software has not been able ", "" )  
    log_option_desc += frmt_items.format("", "to perform some function. ", "\n" )  
    log_option_desc += frmt_items.format("CRITICAL ", "A serious error, indicating ", "50" )  
    log_option_desc += frmt_items.format("", "that the program itself may be unable", "" )  
    log_option_desc += frmt_items.format("", "to continue running.", "\n" )  
    return log_option_desc

def _create_logger(log_id, log_level):
    logger = logging.getLogger(log_id)
    logger.setLevel(log_level)

    # create console handler and set level to debug
    ch = logging.StreamHandler()
    ch.setLevel(log_level)

    # create formatter
    formatter = logging.Formatter(
        '%(asctime)s - %(name)s - %(levelname)s - %(message)s')

    # add formatter to ch
    ch.setFormatter(formatter)

    # add ch to logger
    logger.addHandler(ch)

    return logger

def parse_arguments():

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

def main():
    args = parse_arguments()

    logger = _create_logger(log_id='__LoggerID__',
                           log_level=args.log_level)

    logger.info("Start of main program")

    logger.info("End of main program")

if __name__ == "main":
    main()
