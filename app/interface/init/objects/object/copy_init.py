#!/usr/bin/env python3

# Command line program
import argparse
# Name check
import re
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
    parser = argparse.ArgumentParser(description='Copy inits')
    parser.add_argument('source', help='specify the name of source inits')
    parser.add_argument('name', help='specify the name of the copy')
    return parser.parse_args()

# source https://stackoverflow.com/questions/4205854/python-way-to-recursively-find-and-replace-string-in-text-files
def find_replace(folder, file_pattern, text, replacement):
    for dirpath, dirs, files in os.walk(folder, topdown=True):
        files = [os.path.join(dirpath, filename) for filename in fnmatch.filter(files, file_pattern)]
        if files:
            for line in fileinput.FileInput(files, inplace=True):
                print(line.replace(text, replacement), end='')

def edit(source, name, source_object_name = ""):
    object_name = os.path.basename(os.getcwd())
    if not source_object_name:
        source_object_name = object_name
    upper_camel_name = libchoose.object_to_upper_camel_case([name])
    upper_camel_source = libchoose.object_to_upper_camel_case([source])
    upper_camel_object_name = libchoose.object_to_upper_camel_case([object_name])
    upper_camel_source_object_name = libchoose.object_to_upper_camel_case([source_object_name])
    # replace source by name
    find_replace(name, "*.h", "_" + source.upper() + "_", "_" + name.upper() + "_")
    find_replace(name, "*.h", "param/init/objects/{object_name}/{name}".format(name=source, object_name=source_object_name), "param/init/objects/{object_name}/{name}".format(name=name, object_name=object_name))
    find_replace(name, "*.h", "Init{object_name}{name}".format(name=upper_camel_source, object_name=upper_camel_source_object_name), "Init{object_name}{name}".format(name=upper_camel_name, object_name=upper_camel_object_name))
    # add object to param/init/parameters.h
    for line in fileinput.FileInput("parameters.h", inplace=True):
        if line == '// FLAG: INCLUDE INIT END\n':
            print('#include "param/init/objects/{object_name}/{name}/choice.h"\n'.format(name=name, object_name=object_name), end='')
        if line == '        // FLAG: MAKE INIT END\n':
            print('        sInits.push_back(std::make_shared<Init{object_name}{name}<Type{object_name}Step>>(s{object_name}Step));\n'.format(name=upper_camel_name, object_name=upper_camel_object_name), end='')
        print(line, end='')

def main(source, name):
    name_check = re.compile('[][@!#$%^&*()<>?/\|}{~:+-.\'"]')
    if(name_check.search(name) == None):
        # copy
        shutil.copytree(source, name, symlinks=True)
        # edit
        edit(source, name)
    else:
        print("ERROR: name shouldn't contain special characters")

if __name__ == '__main__':
    args = parse()
    main(args.source, args.name)
