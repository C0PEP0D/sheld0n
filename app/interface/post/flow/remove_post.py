#!/usr/bin/env python3

# Command line program
import argparse
# Directory operations
import shutil
import os
# Replace operations
import fnmatch
import fileinput


def parse():
    parser = argparse.ArgumentParser(description='Remove a post.')
    parser.add_argument('name', help='specify the name of the post to remove')
    return parser.parse_args()

def edit(name):
    for line in fileinput.FileInput("parameters.h", inplace=True):
        if (line == '#include "param/post/flow/{name}/choice.h"\n'.format(name=name)):
            pass
        elif (line == '        data.push_back(std::make_shared<PostFlow{name}>(sFlow, sMesh));\n'.format(name=name.capitalize())):
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
