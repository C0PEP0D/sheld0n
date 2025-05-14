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
    name_check = re.compile(r'[][@!#$%^&*()<>?/\|}{~:+.\'"]')
    if(name_check.search(args.name) == None):
        # copy
        script_dir = os.path.dirname(os.path.realpath(__file__))
        param_dir = ".."
        code_dir = script_dir + "/../../.."
        shutil.copytree(code_dir + "/app/default/param/solutions/passive_particles", args.name, ignore=shutil.ignore_patterns('__*'))
        os.symlink(os.path.relpath(code_dir + "/app/interface/solutions/equation/cli_choose.py", args.name), args.name + "/cli_choose")
        os.symlink(os.path.relpath(code_dir + "/app/interface/gui_choose.py", args.name), args.name + "/gui_choose")
        # edit
        libchoose.edit_choice(args.name, ["passive_particles"], [args.name])
        libchoose.edit_add_equation(args.name)
        # choose parameters
        os.chdir(args.name)
        os.system('./cli_choose ' + args.parameters)
        os.chdir('..')
    else:
        print("ERROR: name shouldn't contain special characters")

@Cli2Gui(run_function=run)
def main():
    # parser
    parser = argparse.ArgumentParser(description='create a new equation based on the default one')
    parser.add_argument('name', help='specify the name of the new equation')
    parser.add_argument('-p', '--parameters', default='passive_particles', choices=libchoose.get_choices_file("solutions/passive_particles", []), help='match the new case to an example case')
    # parse
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
