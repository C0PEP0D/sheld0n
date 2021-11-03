#!/usr/bin/env python3

# Command line program
import argparse
import argcomplete
# Name check
import re
# Directory operations
import shutil
import os
# Replace operations
import fileinput
# Custom Libraries
import sys
script_dir = os.path.dirname(os.path.realpath(__file__))
lib_directory = script_dir[:script_dir.find("interface") + len("interface")]
sys.path.append(lib_directory)
import libchoose

def parse():
    # parser
    parser = argparse.ArgumentParser(description='copy all post processing of an object to an other object')
    parser.add_argument('source', help='specify the name of source object')
    parser.add_argument('dest', help='specify the name of the destination object')
    # autocompletion
    argcomplete.autocomplete(parser)
    # parse
    return parser.parse_args()

def edit(source, name):
    upper_camel_name = libchoose.object_to_upper_camel_case([name])
    # post
    ## replace source by name
    libchoose.edit_choice(name, [source], [name])
    for line in fileinput.FileInput(name + "/parameters.h", inplace=True):
        print(line.replace('name = "{}"'.format(source), 'name = "{}"'.format(name)), end='')

def main(source, name):
    name_check = re.compile('[][@!#$%^&*()<>?/\|}{~:+.\'"]')
    if(name_check.search(name) == None):
        if os.path.exists(name):
            # remove
            shutil.rmtree(name)
            # copy
            shutil.copytree(source, name, symlinks=True)
            # edit
            edit(source, name)
        else:
            print("ERROR: destination object not found")
    else:
        print("ERROR: name shouldn't contain special characters")

if __name__ == '__main__':
    # main
    args = parse()
    main(args.source, args.dest)
