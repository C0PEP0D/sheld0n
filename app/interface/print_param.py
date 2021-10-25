#!/usr/bin/env python3

# Command line program
import argparse
# Directory operations
import glob
# Regular expressions
import re

def parse():
    parser = argparse.ArgumentParser(description='Prints all simulation parameters. Useful to check all parameters before running a simulation.')
    return parser.parse_args()

def main():
    args = parse()
    # get all parameter files
    parameter_files = ["./param/parameters.h"]
    parameter_files += glob.glob('./param/env/**/parameters.h', recursive=True)
    parameter_files += glob.glob('./param/init/**/parameters.h', recursive=True)
    parameter_files += glob.glob('./param/post/**/parameters.h', recursive=True)
    # build output
    output = " ------------ file : "
    for parameter_file in parameter_files:
        with open(parameter_file, "r") as reader:
            file_content = reader.read()
        output += '"' + parameter_file + '"'
        file_content = file_content[file_content.find("struct"):]
        matches_start = re.finditer("{", file_content)
        matches_start = [match.start() for match in matches_start]
        matches_end = re.finditer("}", file_content)
        matches_end = [match.start() for match in matches_end]
        output += file_content[matches_start[0] + 1:matches_end[-2]] + "\n ------------ file : "
    # print output
    print(output)

if __name__ == '__main__':
    main()
