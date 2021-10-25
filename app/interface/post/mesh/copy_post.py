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


def parse():
    parser = argparse.ArgumentParser(description='Copy posts')
    parser.add_argument('source', help='specify the name of source posts')
    parser.add_argument('name', help='specify the name of the copy')
    return parser.parse_args()

# source https://stackoverflow.com/questions/4205854/python-way-to-recursively-find-and-replace-string-in-text-files
def find_replace(folder, file_pattern, text, replacement):
    for dirpath, dirs, files in os.walk(folder, topdown=True):
        files = [os.path.join(dirpath, filename) for filename in fnmatch.filter(files, file_pattern)]
        if files:
            for line in fileinput.FileInput(files, inplace=True):
                print(line.replace(text, replacement), end='')

def edit(source, name):
    # replace source by name
    find_replace(name, "*.h", "_" + source.upper() + "_", "_" + name.upper() + "_")
    find_replace(name, "*.h", "param/post/mesh/{name}".format(name=source), "param/post/mesh/{name}".format(name=name))
    find_replace(name, "*.h", "PostMesh{name}".format(name=source.capitalize()), "PostMesh{name}".format(name=name.capitalize()))
    # add post to param/post/mesh/parameters.h
    for line in fileinput.FileInput("parameters.h", inplace=True):
        if line == '// FLAG: INCLUDE POST END\n':
            print('#include "param/post/mesh/{name}/choice.h"\n'.format(name=name), end='')
        if line == '        // FLAG: MAKE POST END\n':
            print('        data.push_back(std::make_shared<PostMesh{name}>(sMesh));\n'.format(name=name.capitalize()), end='')
        print(line, end='')

def main(source, name):
    name_check = re.compile('[][@!#$%^&*()<>?/\|}{~:+-.\'"]')
    if(name_check.search(name) == None):
        # copy
        shutil.copytree(source, name)
        # edit
        edit(source, name)
    else:
        print("ERROR: name shouldn't contain special characters")

if __name__ == '__main__':
    args = parse()
    main(args.source, args.name)
