import logging  # Needed for logging events.

def create_logger_description():
    """Returns a string whose content is the log level option help description.
    
    Returns:
        A string whose content is the log level option help description.
    """
    frmt_header = "{0:10s} {1:40.40s} {2:5s}\n"
    frmt_items = frmt_header
    header1 =  frmt_header.format("Level", "Description", "Option Value" )  
    header1_len = len(header1)
    log_option_desc = "The logging level. The standard levels are the following:\n\n"
    log_option_desc += header1
    log_option_desc += "-"*header1_len  + "\n"
    log_option_desc += frmt_items.format("NOTSET", "No messages will be processed", "0" )  
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

## @brief Creates and returns a logger object.
##
## @details Creates a logger object with name log_id and returns it.
## log level log_level.
##
## @param log_id A string
## @param log_level A logging level (e.g. logging.DEBUG, logging.INFO, etc.)
## @retval logger A logger object - see logging python documentation
def create_logger(log_id, log_level):
    logger = logging.getLogger(log_id)
    logger.setLevel(log_level)

    # create console handler and set level to debug
    ch = logging.StreamHandler()
    ch.setLevel(log_level)

    # create formatter
    my_log_format = _file_logger_format()
    formatter = logging.Formatter(my_log_format)

    # add formatter to ch
    ch.setFormatter(formatter)

    # add ch to logger
    logger.addHandler(ch)

## @brief Creates and returns a logger object.
##
## @details Creates a logger object with name log_id and returns it.
## log level log_level.
##
## @param log_id A string
## @param log_level A logging level (e.g. logging.DEBUG, logging.INFO, etc.)
## @param filename The file the logger writes to
## @retval logger A logger object - see logging python documentation
def create_file_logger(log_id, log_level,filename):
    logger = logging.getLogger(log_id)
    logger.setLevel(log_level)

    # create file handler and set level "log_level"
    fh = logging.FileHandler(filename)
    fh.setLevel(log_level)
    my_log_format = _file_logger_format()

    formatter = logging.Formatter(my_log_format)
    # add formatter to ch
    fh.setFormatter(formatter)

    # add ch to logger
    logger.addHandler(fh)
    return logger

def _file_logger_format():
    skip_2_lines = "\n\n"
    count = 1
    border = "#@-@-@-@-@-@-@-@-@-@-#"
    my_log_format = _horizontal_border(border,count)
    my_log_format += '\n%(asctime)s - %(name)s - %(levelname)s'
    my_log_format += _horizontal_border(border,count)
    my_log_format += '\n%(message)s\n'
    my_log_format += _horizontal_border(border,count)
    my_log_format += skip_2_lines
    return my_log_format

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
