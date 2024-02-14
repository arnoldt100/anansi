#!/usr/bin/env python3

## \brief Parses file "template_file" with respect to the dictionary of regular
#          expressions, regex_array, and write the result to file "output_file".
#
# \details If the output already exists this function does nothing andsimpy returns.
#          
# \param regex_dict A dictionary of whey the key,value pairs have the form of
#                   { regular_expression_pattern, replacement_string }
#
# \param template_file The file to be parsed with respect to "regex_dict".
#
# \param output_file The file the parsed results are wriiten to,
def parse_file(regex_dict,template_file,output_file):
    import os

    if os.path.exists(output_file):
        print("Aborting: File " + output_file + " exists!" )
        return

    print("Creating file ", output_file)
    template_file_lines = []
    with open(output_file,"w") as output_fileobj :
        with open(template_file,"r") as template_fileobj :
            template_file_lines = template_fileobj.readlines()
            for tmp_record in template_file_lines: 
                for (regex_pattern,replacement) in regex_dict:
                    tmp_record = regex_pattern.sub(replacement,tmp_record)    
                output_fileobj.write(tmp_record)


