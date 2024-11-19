#!/usr/bin/env python3

import argparse
import numpy as np
import shlex
import subprocess
import glob
import fileinput
import re

def parse():
    parser = argparse.ArgumentParser(description='Copies an equation into several others by varying their parameters.')
    parser.add_argument('sources', nargs='+', help='specify the name of the source equations')
    parser.add_argument('-p', '--prop', help='specify the property', required=True)
    parser.add_argument('-v', '--values', type=str, nargs='+', help='specify the values', required=True)
    return parser.parse_args()

def get_property_from_dir_name(name, prop):
    all_properties = name.split("__")
    for prop_name in all_properties:
        if prop_name.startswith(prop):
            return float(prop_name[len(prop)+1:].replace("o", ".").replace("m", "-"))
    return np.nan

def set_property_from_dir_name(name, prop, value):
    is_property_set = False
    all_properties = name.split("__")
    for i in range(len(all_properties)):
        if all_properties[i].startswith(prop):
            all_properties[i] = prop + "_" + str(value).replace(".", "o").replace("-", "m")
            is_property_set = True
    if not is_property_set:
        all_properties.append(prop + "_" + str(value).replace(".", "o").replace("-", "m"))
    name = ""
    for prop_name in all_properties:
        name += prop_name + "__"
    return name[:-2]

def file_replace(file_name, text, replacement):
    for line in fileinput.FileInput(file_name, inplace=True):
        print(re.sub(text, replacement, line), end='')

def set_parameter(dest, prop, value):
    file_replace(dest + "/parameters.h", r"{prop} = [^\;]*;".format(prop=prop), "{prop} = {value};".format(prop=prop, value=str(value)))

def compute(sources, prop, values):
    for source in sources:
        for value in values:
            dest = set_property_from_dir_name(source, prop, value)
            # execute command
            cmd = "./copy_equation {source} {dest}".format(source=source, dest=dest)
            print("INFO: running " + cmd)
            subprocess.call(shlex.split(cmd))
            # set parameter
            set_parameter(dest, prop, value)

def main(source, prop, values):
    compute(source, prop, values)

if __name__ == '__main__':
    # parse arguments
    args = parse()
    # call
    main(args.sources, args.prop, args.values)
