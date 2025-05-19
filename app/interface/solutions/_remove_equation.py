#!/usr/bin/env python3

# gui
from cli2gui import Cli2Gui
# command line program
import argparse
# directory operations
import shutil
import os
# replace operations
import fnmatch
import fileinput
# custom Libraries
import sys
script_dir = os.path.dirname(os.path.realpath(__file__))
lib_directory = script_dir[:script_dir.find("interface") + len("interface")]
sys.path.append(lib_directory)
import libchoose
    
def edit(name):
    upper_camel_name = libchoose.object_to_upper_camel_case([name])
    # solutions
    for line in fileinput.FileInput("parameters.h", inplace=True):
        if (line == '#include "param/solutions/{}/parameters.h"\n'.format(name)):
            pass
        elif ('_{Name}::'.format(Name=upper_camel_name) in line):
            pass
        else:
            print(line, end='')

def run_aux(name):
    # edit
    edit(name)
    # remove dir
    shutil.rmtree(name)
    # shutil.rmtree("../../../init/solutions/" + name)

def run(args):
    if "--cli2gui" in sys.argv:
        run_aux(os.path.normpath(args.equations))
    else:
        for equation in args.equations:
            run_aux(os.path.normpath(equation))

@Cli2Gui(run_function=run)
def main():
    parser = argparse.ArgumentParser(description='remove equations')
    parser.add_argument('equations', nargs='+', choices=[equation for equation in os.listdir(".") if os.path.isdir(equation)], help='select the equations to remove')
    args = parser.parse_args()
    # run
    run(args)
    

if __name__ == '__main__':
    main()
    
