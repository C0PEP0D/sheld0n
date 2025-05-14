#!/usr/bin/env python3

# gui
from cli2gui import Cli2Gui
# command line program
import argparse
# name check
import re
# directory operations
import shutil
import os
# replace operations
import fileinput
# custom Libraries
import sys
script_dir = os.path.dirname(os.path.realpath(__file__))
lib_directory = script_dir[:script_dir.find("interface") + len("interface")]
sys.path.append(lib_directory)
import libchoose

def run(args):
    name_check = re.compile('[][@!#$%^&*()<>?/\\|}{~:+.\'"]')
    if(name_check.search(args.name) == None):
        # copy
        shutil.copytree(args.source, args.name, symlinks=True)
        # edit
        libchoose.edit_choice(args.name, [args.source], [args.name])
        libchoose.edit_add_equation(args.name)
    else:
        print("ERROR: name shouldn't contain special characters")

@Cli2Gui(run_function=run)
def main():
    # parser
    parser = argparse.ArgumentParser(description='copy an equation')
    parser.add_argument('source', choices=[equation for equation in os.listdir(".") if os.path.isdir(equation)], help='specify the name of source equation')
    parser.add_argument('name', help='specify the name of the copy')
    # parse
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
