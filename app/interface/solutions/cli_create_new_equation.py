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
    # compute
    name_check = re.compile(r'[][@!#$%^&*()<>?/\|}{~:+.\'"]')
    if(name_check.search(args.name) == None):
        # copy
        script_dir = os.path.dirname(os.path.realpath(__file__))
        param_dir = ".."
        code_dir = script_dir + "/../../.."
        shutil.copytree(code_dir + "/app/default/param/solutions/passive_particles", args.name, ignore=shutil.ignore_patterns('__*'))
        os.symlink(os.path.relpath(code_dir + "/app/interface/solutions/equation/_choose.py", args.name), args.name + "/choose")
        os.symlink(os.path.relpath(code_dir + "/app/interface/solutions/equation/cli_choose.py", args.name), args.name + "/.cli_choose")
        os.symlink(os.path.relpath(code_dir + "/app/interface/gui_choose.py", args.name), args.name + "/.gui_choose")
        # edit
        libchoose.edit_choice(args.name, ["passive_particles"], [args.name])
        # choose parameters
        os.chdir(args.name)
        os.system('./.cli_choose ' + args.parameters)
        os.chdir('..')
        # # register
        # is_static = True
        # is_dynamic = False
        # with open(args.name + '/parameters.h', 'r') as file:
        #     for line in file:
        #         if line.startswith("// FLAG: DYNAMIC"):
        #             is_static = False
        #             is_dynamic = True
        #             break
        #         elif line.startswith("namespace c0p {"):
        #             break
        # if is_static:
        #     libchoose.edit_add_equation_static(args.name)
        # elif is_dynamic:
        #     libchoose.edit_add_equation_dynamic(args.name)
    else:
        print("ERROR: name shouldn't contain special characters")

def main():
    # parser
    parser = argparse.ArgumentParser(description='create a new equation based on the default one')
    parser.add_argument('name', help='specify the name of the new equation')
    choices = list(libchoose.get_choices_file("solutions/passive_particles", []).keys())
    choices.sort()
    parser.add_argument('-p', '--parameters', default='cpp_passive_particles', choices=choices, help='choose among different default parameters to specify which equation you will solve')
    # parse
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
