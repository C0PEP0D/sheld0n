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
    parser = argparse.ArgumentParser(description='create a new equation based on the default one')
    parser.add_argument('name', help='specify the name of the new equation')
    # autocompletion
    argcomplete.autocomplete(parser)
    # parse
    return parser.parse_args()

def main(name):
    name_check = re.compile(r'[][@!#$%^&*()<>?/\|}{~:+.\'"]')
    if(name_check.search(name) == None):
        # copy
        script_dir = os.path.dirname(os.path.realpath(__file__))
        param_dir = ".."
        code_dir = script_dir + "/../../.."
        shutil.copytree(code_dir + "/app/default/param/solutions/__group_of_points", args.name, ignore=shutil.ignore_patterns('__*'))
        os.symlink(os.path.relpath(code_dir + "/app/interface/solutions/equation/choose.py", args.name), args.name + "/choose")
        # edit
        libchoose.edit_choice(name, ["group_of_points"], [name])
        libchoose.edit_add_equation(name)
    else:
        print("ERROR: name shouldn't contain special characters")

if __name__ == '__main__':
    # main
    args = parse()
    main(args.name)
