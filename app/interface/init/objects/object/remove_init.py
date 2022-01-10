#!/usr/bin/env python3

# Command line program
import argparse
# Directory operations
import shutil
import os
# Replace operations
import fnmatch
import fileinput
# Custom Libraries
import sys
script_dir = os.path.dirname(os.path.realpath(__file__))
lib_directory = script_dir[:script_dir.find("interface") + len("interface")]
sys.path.append(lib_directory)
import libchoose

def parse():
    parser = argparse.ArgumentParser(description='Remove an init.')
    parser.add_argument('name', help='specify the name of the init to remove')
    return parser.parse_args()

def edit(name):
    object_name = os.path.basename(os.getcwd())
    upper_camel_name = libchoose.object_to_upper_camel_case([name])
    upper_camel_object_name = libchoose.object_to_upper_camel_case([object_name])
    for line in fileinput.FileInput("parameters.h", inplace=True):
        if (line == '#include "param/init/objects/{object_name}/{name}/choice.h"\n'.format(name=name, object_name=object_name)):
            pass
        elif (line == '        sInits.push_back(std::make_shared<Init{object_name}{name}<Type{object_name}Step>>(s{object_name}Step));\n'.format(name=upper_camel_name, object_name=upper_camel_object_name)):
            pass
        else:
            print(line, end='')

def main(name):
    # edit
    edit(name)
    # remove dir
    shutil.rmtree(name)

if __name__ == '__main__':
    args = parse()
    main(args.name)
