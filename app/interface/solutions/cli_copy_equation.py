#!/usr/bin/env python3

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
        if os.path.exists(args.name + "/parameters_" + args.source + ".pyx"):
            os.rename(args.name + "/parameters_" + args.source + ".pyx", args.name + "/parameters_" + args.name + ".pyx")
        if os.path.exists(args.name + "/parameters_" + args.source + ".h"):
            os.remove(args.name + "/parameters_" + args.source + ".h")
        if os.path.exists(args.name + "/parameters_" + args.source + ".cpp"):
            os.remove(args.name + "/parameters_" + args.source + ".cpp")
        # edit
        libchoose.edit_choice(args.name, [args.source], [args.name])
        # register
        is_static = True
        is_dynamic = False
        with open(args.name + '/parameters.h', 'r') as file:
            for line in file:
                if line.startswith("// FLAG: DYNAMIC"):
                    is_static = False
                    is_dynamic = True
                    break
                elif line.startswith("namespace c0p {"):
                    break
        if is_static:
            libchoose.edit_add_equation_static(args.name)
        elif is_dynamic:
            libchoose.edit_add_equation_dynamic(args.name)
    else:
        print("ERROR: name shouldn't contain special characters")

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
