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
    parser = argparse.ArgumentParser(description='Remove objects.')
    parser.add_argument('objects', nargs='+', help='specify the names of the objects to remove')
    return parser.parse_args()

def edit(name):
    # object
    upper_camel_name = libchoose.object_to_upper_camel_case([name])
    # remove object from param/env/objects/parameters.h
    for line in fileinput.FileInput("parameters.h", inplace=True):
        if (line == '#include "param/env/objects/{}/choice.h"\n'.format(name)):
            pass
        elif (line == '    std::shared_ptr<{Name}Step> s{Name}Step;\n'.format(Name=upper_camel_name)):
            pass
        elif (line == '    unsigned int {name}Index;\n'.format(name=name)):
            pass
        elif (line == '        // // {}\n'.format(name)):
            pass
        elif (line == '        s{Name}Step = std::make_shared<{Name}Step>(sFlow, pObjects);\n'.format(Name=upper_camel_name)):
            pass
        elif (line == '        data.push_back(s{Name}Step);\n'.format(Name=upper_camel_name)):
            pass
        elif (line == '        {name}Index = data.size() - 1;\n'.format(name=name)):
            pass
        else:
            print(line, end='')
    # remove object from param/post/objects/parameters.h
    for line in fileinput.FileInput("../../post/objects/parameters.h", inplace=True):
        if (line == '#include "param/post/objects/{}/parameters.h"\n'.format(name)):
            pass
        elif (line == '        data.push_back(std::make_shared<PostPost<Post{Name}Parameters, {Name}Step>>(objects.parameters.s{Name}Step));\n'.format(Name=upper_camel_name)):
            pass
        else:
            print(line, end='')
    # remove object from param/env/objects/parameters.h
    for line in fileinput.FileInput("../../init/objects/parameters.h", inplace=True):
        if (line == '#include "param/init/objects/{}/parameters.h"\n'.format(name)):
            pass
        elif (line == '        data.push_back(std::make_shared<InitInit<Init{Name}Parameters, {Name}Step>>(objects.parameters.s{Name}Step));\n'.format(Name=upper_camel_name)):
            pass
        else:
            print(line, end='')

def main(name):
    # edit
    edit(name)
    # remove dir
    shutil.rmtree(name)
    shutil.rmtree("../../post/objects/" + name)
    shutil.rmtree("../../init/objects/" + name)

if __name__ == '__main__':
    # main
    args = parse()
    for obj in args.objects:
        main(os.path.normpath(obj))
