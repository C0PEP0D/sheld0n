#!/usr/bin/env python3

# Command line program
import argparse
import argcomplete
# Name check
import re
# Directory operations
import shutil
import os
# Replace operations
import fileinput
# Custom Libraries
import sys
script_dir = os.path.dirname(os.path.realpath(__file__))
lib_directory = script_dir[:script_dir.find("interface") + len("interface")]
sys.path.append(lib_directory)
import libchoose

def parse():
    # parser
    parser = argparse.ArgumentParser(description='copy an object')
    parser.add_argument('source', help='specify the name of source object')
    parser.add_argument('name', help='specify the name of the copy')
    # autocompletion
    argcomplete.autocomplete(parser)
    # parse
    return parser.parse_args()

def edit(source, name):
    # object
    upper_camel_name = libchoose.object_to_upper_camel_case([name])
    ## replace source by name
    libchoose.edit_choice(name, [source], "dynamic", [name], "dynamic")
    ## add object to param/env/objects/parameters.h
    for line in fileinput.FileInput("../parameters.h", inplace=True):
        if line == '// FLAG: INCLUDE OBJECT END\n':
            print('#include "param/env/objects/dynamic/{}/choice.h"\n'.format(name), end='')
        if line == '\t// FLAG: DECLARE OBJECT END\n':
            print('\tstd::shared_ptr<{Name}Step> s{Name}Step;\n'.format(Name=upper_camel_name), end='')
            print('\tunsigned int {name}Index;\n'.format(name=name), end='')
        if line == '\t\t// FLAG: MAKE OBJECT END\n':
            print('\t\t// // {}\n'.format(name), end='')
            print('\t\ts{Name}Step = std::make_shared<{Name}Step>(sFlow, sObjects);\n'.format(Name=upper_camel_name), end='')
            print('\t\tsObjectsDynamicSteps.push_back(s{Name}Step);\n'.format(Name=upper_camel_name), end='')
            print('\t\t{name}Index = sObjectsDynamicSteps.size() - 1;\n'.format(name=name), end='')
            print('\t\tobjectsDynamicNames.push_back("{name}");\n'.format(name=name), end='')
        print(line, end='')
    # post
    ## replace source by name
    libchoose.edit_choice("../../../post/objects/" + name, [source], "", [name], "")
    for line in fileinput.FileInput("../../../post/objects/" + name + "/parameters.h", inplace=True):
        print(line.replace('name = "{}"'.format(source), 'name = "{}"'.format(name)), end='')
    ## add object to param/post/objects/parameters.h
    for line in fileinput.FileInput("../../../post/objects/parameters.h", inplace=True):
        if line == '// FLAG: INCLUDE OBJECT END\n':
            print('#include "param/post/objects/{}/parameters.h"\n'.format(name), end='')
        if line == '\t\t// FLAG: MAKE OBJECT END\n':
            print('\t\tsPostsDynamic.push_back(std::make_shared<PostPost<Post{Name}Parameters, {Name}Step>>(sObjectsParameters->s{Name}Step));\n'.format(Name=upper_camel_name), end='')
        print(line, end='')
    # init
    ## replace source by name
    libchoose.edit_choice("../../../init/objects/" + name, [source], "", [name], "")
    ## add object to param/init/objects/parameters.h
    for line in fileinput.FileInput("../../../init/objects/parameters.h", inplace=True):
        if line == '// FLAG: INCLUDE OBJECT END\n':
            print('#include "param/init/objects/{}/parameters.h"\n'.format(name), end='')
        if line == '\t\t// FLAG: MAKE OBJECT END\n':
            print('\t\tsInitsDynamic.push_back(std::make_shared<InitInitDynamic<Init{Name}Parameters, {Name}Step>>(sObjectsParameters->s{Name}Step));\n'.format(Name=upper_camel_name), end='')
        print(line, end='')

def main(source, name):
    name_check = re.compile('[][@!#$%^&*()<>?/\|}{~:+.\'"]')
    if(name_check.search(name) == None):
        # copy
        ## object
        shutil.copytree(source, name, symlinks=True)
        ## post
        shutil.copytree("../../../post/objects/" + source, "../../../post/objects/" + name, symlinks=True)
        ## init
        shutil.copytree("../../../init/objects/" + source, "../../../init/objects/" + name, symlinks=True)
        # edit
        edit(source, name)
    else:
        print("ERROR: name shouldn't contain special characters")

if __name__ == '__main__':
    # main
    args = parse()
    main(args.source, args.name)
