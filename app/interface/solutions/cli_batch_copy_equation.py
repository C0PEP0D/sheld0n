#!/usr/bin/env python3

# # gui
# from cli2gui import Cli2Gui # TODO: add support to nargs='+' into cli2gui
# command line program
import argparse
import numpy as np
import shlex
import subprocess
import glob
import fileinput
import re
import os

def get_property_from_dir_name(name, prop):
    all_properties = name.split("__")
    for prop_name in all_properties:
        if prop_name.startswith(prop):
            return float(prop_name[len(prop)+1:].replace("o", ".").replace("m", "-"))
    return np.nan

def set_property_from_dir_name(name, prop, value, fwidth, fprecision):
    is_property_set = False
    all_properties = name.split("__")
    for i in range(len(all_properties)):
        if all_properties[i].startswith(prop):
            all_properties[i] = prop + "_" + "{value:0>{fwidth}.{fprecision}f}".format(value=value, fwidth=fwidth, fprecision=fprecision).replace(".", "o").replace("-", "m")
            is_property_set = True
    if not is_property_set:
        all_properties.append(prop + "_" + "{value:0>{fwidth}.{fprecision}f}".format(value=value, fwidth=fwidth, fprecision=fprecision).replace(".", "o").replace("-", "m"))
    name = ""
    for prop_name in all_properties:
        name += prop_name + "__"
    return name[:-2]

def file_replace(file_name, text, replacement):
    lineno = 1
    data_array = []
    if os.path.exists(file_name):
        for line in fileinput.FileInput(file_name, inplace=True):
            text_match = re.search(text, line)
            if text_match:
                print(re.sub(text, replacement, line), end='')
                data_array.append({
                    "text":text_match[0], 
                    "replacement":replacement,
                    "lineno":lineno
                })
            else:
                print(line, end='')
            lineno += 1
    if data_array:
        for data in data_array:
            print("INFO: {file}:{lineno}: {text} ---> {replacement}".format(file=file_name, **data))

def set_parameter(dest, prop, value, factor):
    if factor:
        file_replace(dest + "/parameters.h", r" {prop} = [^\;]*;".format(prop=prop), " {prop} = {value} * {factor};".format(prop=prop, value=str(value), factor=factor))
        file_replace(dest + "/parameters.py", r" {prop} = .*$".format(prop=prop), " {prop} = {value} * {factor}".format(prop=prop, value=str(value), factor=factor))
        for file in glob.glob(dest + "/parameters_*.pyx"):
            file_replace(file, r" {prop} = .*$".format(prop=prop), " {prop} = {value} * {factor}".format(prop=prop, value=str(value), factor=factor))
    else:
        file_replace(dest + "/parameters.h", r" {prop} = [^\;]*;".format(prop=prop), " {prop} = {value};".format(prop=prop, value=str(value)))
        file_replace(dest + "/parameters.py", r" {prop} = .*$".format(prop=prop), " {prop} = {value}".format(prop=prop, value=str(value)))
        for file in glob.glob(dest + "/parameters_*.pyx"):
            file_replace(file, r" {prop} = .*$".format(prop=prop), " {prop} = {value}".format(prop=prop, value=str(value)))

def run(args):
    finteger = 0
    fprecision = 0
    for value in args.values:
        str_value = str(value)
        str_value_array = str_value.split(".")
        if len(str_value_array) == 2:
            if len(str_value_array[0]) > finteger:
                finteger = len(str_value_array[0])
            if len(str_value_array[1]) > fprecision:
                fprecision = len(str_value_array[1])
    fwidth = finteger + fprecision + 1
    for source in args.sources:
        for value in args.values:
            dest = set_property_from_dir_name(source, args.prop, value, fwidth, fprecision)
            # execute command
            cmd = "./.cli_copy_equation {source} {dest}".format(source=source, dest=dest)
            print("INFO: running " + cmd)
            subprocess.call(shlex.split(cmd))
            # set parameter
            set_parameter(dest, args.prop, value, args.factor)

# @Cli2Gui(run_function=run)
def main():
    parser = argparse.ArgumentParser(description='Copies an equation into several others by varying their parameters.')
    parser.add_argument('sources', nargs='+', choices=[equation for equation in os.listdir(".") if os.path.isdir(equation)], help='specify the name of the source equations')
    parser.add_argument('-p', '--prop', help='specify the property', required=True)
    parser.add_argument('-v', '--values', type=float, nargs='+', help='specify the values', required=True)
    parser.add_argument('-f', '--factor', help='specify a factor', default=None)
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
