#!/usr/bin/env python3

import argparse
import numpy as np
import shlex
import subprocess
import glob
import fileinput
import re

def parse():
    parser = argparse.ArgumentParser(description='Copies objects by changing parameters')
    parser.add_argument('sources', nargs='+', help='specify the name of the source object(s)')
    parser.add_argument('-p', '--prop', help='specify the property', required=True)
    parser.add_argument('-v', '--values', type=float, nargs='+', help='specify the values', required=True)
    return parser.parse_args()

def get_property_from_dir_name(name, prop):
    all_properties = name.split("__")
    for prop_name in all_properties:
        if prop_name.startswith(prop):
            return float(prop_name[len(prop)+1:].replace("o", "."))
    return np.nan

def set_property_from_dir_name(name, prop, value):
    all_properties = name.split("__")
    for i in range(len(all_properties)):
        if all_properties[i].startswith(prop):
            all_properties[i] = prop + "_" + str(value).replace(".", "o")
    name = ""
    for prop_name in all_properties:
        name += prop_name + "__"
    return name[:-2]

def file_replace(file_name, text, replacement):
    for line in fileinput.FileInput(file_name, inplace=True):
        print(re.sub(text, replacement, line), end='')

def set_parameter(dest, prop, value):
    if prop == "surftimeconst":
        for file_name in glob.glob(dest + "/**/surf/_behaviour_time_horizon/const/parameters.h", recursive=True):
            file_replace(file_name, r"value = [^\*]* \*", "value = {value} *".format(value=float(value)))
            print("edited: ", file_name)
    elif prop == "surftimeprefactor":
        for file_name in glob.glob(dest + "/**/surf/_behaviour_time_horizon/*/parameters.h", recursive=True):
            file_replace(file_name, r"prefactor = [^\*]*;", "prefactor = {value};".format(value=float(value)))
            print("edited: ", file_name)
    elif prop == "us":
        for file_name in glob.glob(dest + "/**/*active/**/*swimmer/parameters.h", recursive=True):
            file_replace(file_name, r"velocity = [^\*]* \*", "velocity = {value} *".format(value=float(value)))
            print("edited: ", file_name)
        file_replace(dest + "/group/homogeneous/parameters.h", r"size = [^\*]* \*", "size = 1/({value}*{value}) *".format(value=float(value)))
        print("edited: ", dest + "/group/homogeneous/parameters.h")
    elif prop == "rtime":
        for file_name in glob.glob(dest + "/**/*active/axis/swim/parameters.h", recursive=True):
            file_replace(file_name, r"time = [^\*]* \*", "time = {value} *".format(value=float(value)))
            print("edited: ", file_name)
    elif prop == "reorientationtime":
        for file_name in glob.glob(dest + "/**/*active/**/local_axis_swimmer/parameters.h", recursive=True):
            file_replace(file_name, r"time = [^\*]* \*", "time = {value} *".format(value=float(value)))
            print("edited: ", file_name)
    elif prop == "proportion":
        for file_name in glob.glob(dest + "/**/*passive/spheroid/parameters.h", recursive=True):
            file_replace(file_name, r"proportion = [^\*]*;", "proportion = {value};".format(value=float(value)))
            print("edited: ", file_name)
    elif prop == "filterlength":
        for file_name in glob.glob(dest + "/**/_sensor/velocity_gradients/filtered/parameters.h", recursive=True):
            file_replace(file_name, r"l = [^\*]* \*", "l = {value} *".format(value=float(value)))
            print("edited: ", file_name)
    elif prop == "swimnoise":
        for file_name in glob.glob(dest + "/**/_behaviour/navigator/swimmer_noisy/parameters.h", recursive=True):
            file_replace(file_name, r"noiseIntensity = [^\*]*;", "noiseIntensity = {value};".format(value=float(value)))
            print("edited: ", file_name)
    elif prop == "dirnoise":
        for file_name in glob.glob(dest + "/**/_sensor/direction/noisy/parameters.h", recursive=True):
            file_replace(file_name, r"noiseIntensity = [^\*]*;", "noiseIntensity = {value};".format(value=float(value)))
            print("edited: ", file_name)
    elif prop == "jnoise":
        for file_name in glob.glob(dest + "/**/_sensor/velocity_gradients/noisy/parameters.h", recursive=True):
            file_replace(file_name, r"noiseIntensity = [^\*]* \*", "noiseIntensity = {value} *".format(value=float(value)))
            print("edited: ", file_name)
    elif prop == "delay":
        for file_name in glob.glob(dest + "/**/*passive/inertial_point/parameters.h", recursive=True):
            file_replace(file_name, r"delay = [^\*]* \*", "delay = {value} *".format(value=float(value)))
            print("edited: ", file_name)

def compute(sources, prop, values):
    for source in sources:
        for value in values:
            dest = set_property_from_dir_name(source, prop, value)
            # execute command
            cmd = "./copy_object_static {source} {dest}".format(source=source, dest=dest)
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
