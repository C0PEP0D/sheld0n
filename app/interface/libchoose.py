#!/usr/bin/env python3

# Command line program
import argparse
import argcomplete
# Name check
import re
# Directory operations
import os
import shutil
import glob
# File edit
import fileinput
import fnmatch

# getters

## current choice
def get_selected():
    for name in [os.path.basename(os.path.dirname(path)) for path in glob.glob("./*/")]:
        if not name.startswith("_"):
            return name

## get object
def get_object():
    re_include = re.compile(r'^#include "param/env/objects/.*/(parameters.h|choice.h)"')
    with open('choice.h', 'r') as reader:
        line = reader.readline()
        while line and re_include.match(line) == None:
            line = reader.readline()
    return line.split("/")[3:-2]

## get flow
def get_flow():
    re_include = re.compile(r'^#include "param/env/flow/.*/(parameters.h|choice.h)"')
    with open('choice.h', 'r') as reader:
        line = reader.readline()
        while line and re_include.match(line) == None:
            line = reader.readline()
    return line.split("/")[3:-2]

## get init
def get_init():
    re_include = re.compile(r'^#include "param/init/objects/.*/(parameters.h|choice.h)"')
    with open('choice.h', 'r') as reader:
        line = reader.readline()
        while line and re_include.match(line) == None:
            line = reader.readline()
    return line.split("/")[3:-2]

## get post
def get_post():
    re_include = re.compile(r'^#include "param/post/objects/.*/(parameters.h|choice.h)"')
    with open('choice.h', 'r') as reader:
        line = reader.readline()
        while line and re_include.match(line) == None:
            line = reader.readline()
    return line.split("/")[3:-2]

## get abs choice dir
def get_abs_choices_dir(choices_dir):
    script_dir = os.path.dirname(os.path.realpath(__file__))
    return script_dir[:script_dir.find("interface")-1] + "/default/param/" + choices_dir

## get choices
def get_choices(choices_dir, choices_exceptions = []):
    abs_choices_dir = get_abs_choices_dir(choices_dir)
    _choices = [os.path.basename(os.path.dirname(path)) for path in glob.glob("{abs_choices_dir}/*/".format(abs_choices_dir=abs_choices_dir))]
    # build choices dict
    choices = {}
    for choice in _choices:
        if choice.startswith('__'):
            choices[choice[2:]] = choice
        elif not choice.startswith('_'):
            choices[choice] = choice
    # remove exceptions
    for exception in choices_exceptions:
        choices.pop(exception, None)
    choices.pop(get_selected(), None)
    # reurn
    return choices

## get default object
def get_default_object(abs_choices_dir):
    re_include = re.compile(r'^#include "param/env/objects/.*/(parameters.h|choice.h)"')
    with open(abs_choices_dir + '/choice.h', 'r') as reader:
        line = reader.readline()
        while line and re_include.match(line) == None:
            line = reader.readline()
    return line.split("/")[3:-2]

## get default flow
def get_default_flow(abs_choices_dir):
    re_include = re.compile(r'^#include "param/env/flow/.*/(parameters.h|choice.h)"')
    with open(abs_choices_dir + '/choice.h', 'r') as reader:
        line = reader.readline()
        while line and re_include.match(line) == None:
            line = reader.readline()
    return line.split("/")[3:-2]

## get default init
def get_default_init(abs_choices_dir):
    re_include = re.compile(r'^#include "param/init/objects/.*/(parameters.h|choice.h)"')
    with open(abs_choices_dir + '/choice.h', 'r') as reader:
        line = reader.readline()
        while line and re_include.match(line) == None:
            line = reader.readline()
    return line.split("/")[3:-2]

## get default post
def get_default_post(abs_choices_dir):
    re_include = re.compile(r'^#include "param/post/objects/.*/(parameters.h|choice.h)"')
    with open(abs_choices_dir + '/choice.h', 'r') as reader:
        line = reader.readline()
        while line and re_include.match(line) == None:
            line = reader.readline()
    return line.split("/")[3:-2]

# misc

def str_to_upper_camel_case(s):
    return s.title().replace("_", "")

def object_to_upper_snake_case(obj):
    s = ""
    for o in obj:
        if o.startswith("__"):
            o = o[2:]
        elif o.startswith("_"):
            o = o[1:]
        s += o.upper() + "_"
    return s[:-1]

def object_to_upper_camel_case(obj):
    s = ""
    for o in obj:
        if o.startswith("__"):
            o = o[2:]
        elif o.startswith("_"):
            o = o[1:]
        s += o.title().replace("_", "")
    return s

def object_to_path(obj):
    s = ""
    for o in obj:
        s += o + "/"
    return s[:-1]

# edit

## edit header
def edit_header(selected, choice):
    # edit choice.h
    re_include = re.compile(r'^#include "core/env/objects/object/.*/core.h"')
    with open('choice.h', 'r') as reader:
        line = reader.readline()
        while line and re_include.match(line) == None:
            line = reader.readline()
    upper_camel_obj = object_to_upper_camel_case(line.split("/")[4:-2])
    if not upper_camel_obj:
        re_include = re.compile(r'^#include "param/env/objects/.*/(parameters.h|choice.h)"')
        with open('choice.h', 'r') as reader:
            line = reader.readline()
            while line and re_include.match(line) == None:
                line = reader.readline()
        upper_camel_obj = object_to_upper_camel_case(line.split("/")[4:-2])
    # replace
    for line in fileinput.FileInput("choice.h", inplace=True):
        line = line.replace("/" + selected + "/", "/" + choice + "/")
        line = line.replace(upper_camel_obj + str_to_upper_camel_case(selected), upper_camel_obj + str_to_upper_camel_case(choice))
        print(line, end='')

## find and replace in subdirectory
## source https://stackoverflow.com/questions/4205854/python-way-to-recursively-find-and-replace-string-in-text-files
def find_replace(folder, file_pattern, text, replacement, condition = lambda line : True):
    for dirpath, dirs, files in os.walk(folder, topdown=True):
        files = [os.path.join(dirpath, filename) for filename in fnmatch.filter(files, file_pattern)]
        if files:
            for line in fileinput.FileInput(files, inplace=True):
                if condition(line):
                    print(line.replace(text, replacement), end='')
                else:
                    print(line, end='')

## edit choice
#def edit_choice(choice, default_obj, obj):
#    find_replace(choice, "*.h", "_" + object_to_upper_snake_case(default_obj) + "_", "_" + object_to_upper_snake_case(obj) + "_")
#    find_replace(choice, "*.h", "/" + object_to_path(default_obj) + "/", "/" + object_to_path(obj) + "/", lambda line : line.startswith('#include "param'))
#    find_replace(choice, "*.h", object_to_upper_camel_case(default_obj), object_to_upper_camel_case(obj))
def edit_choice(choice, default_obj, obj, size = 1):
    obj = obj[0:len(obj) - len(default_obj) + size]
    default_obj = default_obj[0:size]
    find_replace(choice, "*.h", "_" + object_to_upper_snake_case(default_obj) + "_", "_" + object_to_upper_snake_case(obj) + "_")
    find_replace(choice, "*.h", "/" + object_to_path(default_obj) + "/", "/" + object_to_path(obj) + "/", lambda line : line.startswith('#include "param'))
    find_replace(choice, "*.h", object_to_upper_camel_case(default_obj), object_to_upper_camel_case(obj))

# create sym links
def create_sym_links(choice, choice_alt):
    script_dir = os.path.dirname(os.path.realpath(__file__))
    interface_dir = script_dir[:script_dir.find("interface")-1] + "/interface/" + choices_dir + "/" + choice_alt
    if os.path.exists(interface_dir + "/choose.py"):
        os.symlink(os.path.relpath(interface_dir + "/choose.py", choice), choice + "/choose")
    for path in glob.glob(interface_dir + "/*/"):
        subdir = os.path.basename(os.path.dirname(path))
        if not subdir.startswith("__"):
            #if os.path.exists(path + "choose.py"):
            #    os.symlink(path + "choose.py", choice + "/" + subdir + "/choose")
            create_sym_links(choice + "/" + subdir, choice_alt + "/" + subdir)

# parse
def parse(choices_dir, choices_exceptions):
    # parser
    parser = argparse.ArgumentParser(description='Choose the type of this passive object.')
    parser.add_argument('choice', choices=get_choices(choices_dir, choices_exceptions).keys(), help='specify your choice')
    # autocompletion
    argcomplete.autocomplete(parser)
    # parse
    return parser.parse_args()

# choose
def choose(choices_dir, choices_exceptions):
    # parse args
    args = parse(choices_dir, choices_exceptions)
    # get
    selected = get_selected()
    choices = get_choices(choices_dir, choices_exceptions)
    # copy new choice
    shutil.copytree(get_abs_choices_dir(choices_dir) + "/" + choices[args.choice], args.choice, ignore=shutil.ignore_patterns('__*'))#, symlinks=True)
    # delete selected
    shutil.rmtree(selected)
    # edit
    edit_header(selected, args.choice)
    edit_choice(args.choice, get_default_object(get_abs_choices_dir(choices_dir)), get_object())
    # create sym links
    create_sym_links(args.choice, choices[args.choice])

# choose flow
def choose_flow(choices_dir, choices_exceptions):
    # parse args
    args = parse(choices_dir, choices_exceptions)
    # get
    selected = get_selected()
    choices = get_choices(choices_dir, choices_exceptions)
    # copy new choice
    shutil.copytree(get_abs_choices_dir(choices_dir) + "/" + choices[args.choice], args.choice, ignore=shutil.ignore_patterns('__*'))#, symlinks=True)
    # delete selected
    shutil.rmtree(selected)
    # edit
    edit_header(selected, args.choice)
    edit_choice(args.choice, get_default_flow(get_abs_choices_dir(choices_dir)), get_flow())
    # create sym links
    create_sym_links(args.choice, choices[args.choice])

# choose init
def choose_init(choices_dir, choices_exceptions):
    # parse args
    args = parse(choices_dir, choices_exceptions)
    # get
    selected = get_selected()
    choices = get_choices(choices_dir, choices_exceptions)
    # copy new choice
    shutil.copytree(get_abs_choices_dir(choices_dir) + "/" + choices[args.choice], args.choice, ignore=shutil.ignore_patterns('__*'))#, symlinks=True)
    # delete selected
    shutil.rmtree(selected)
    # edit
    edit_header(selected, args.choice)
    edit_choice(args.choice, get_default_init(get_abs_choices_dir(choices_dir)), get_init(), 2)
    # create sym links
    create_sym_links(args.choice, choices[args.choice])

# choose post
def choose_post(choices_dir, choices_exceptions):
    # parse args
    args = parse(choices_dir, choices_exceptions)
    # get
    selected = get_selected()
    choices = get_choices(choices_dir, choices_exceptions)
    # copy new choice
    shutil.copytree(get_abs_choices_dir(choices_dir) + "/" + choices[args.choice], args.choice, ignore=shutil.ignore_patterns('__*'))#, symlinks=True)
    # delete selected
    shutil.rmtree(selected)
    # edit
    edit_header(selected, args.choice)
    print(args.choice, get_default_post(get_abs_choices_dir(choices_dir)), get_post(), 2)
    edit_choice(args.choice, get_default_post(get_abs_choices_dir(choices_dir)), get_post(), 2)
    # create sym links
    create_sym_links(args.choice, choices[args.choice])
