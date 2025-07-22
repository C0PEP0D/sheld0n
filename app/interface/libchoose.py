#!/usr/bin/env python3

# gui
from cli2gui import Cli2Gui
# command line program
import argparse
# aame check
import re
# directory operations
import os
import shutil
import glob
# file edit
import fileinput
import fnmatch

def get_abs_choices_dir(choices_dir):
    script_dir = os.path.dirname(os.path.realpath(__file__))
    return script_dir[:script_dir.find("interface")-1] + "/default/param/" + choices_dir
 
# edit
 
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

## source https://stackoverflow.com/questions/4205854/python-way-to-recursively-find-and-replace-string-in-text-files
def find_replace(folder, file_pattern, text, replacement, condition = lambda line : True):

    print(folder)
    print(file_pattern)

    for dirpath, dirs, files in os.walk(folder, topdown=True):
        files = [os.path.join(dirpath, filename) for filename in fnmatch.filter(files, file_pattern)]

        print(files)
        
        if files:
            for line in fileinput.FileInput(files, inplace=True):
                if condition(line):
                    print(re.sub(text, replacement, line), end='')
                else:
                    print(line, end='')

def edit_add_equation_static(name):
    upper_camel_name = object_to_upper_camel_case([name])
    ## add equation to param/solutions/parameters.h
    previous_line = ''
    for line in fileinput.FileInput("parameters.h", inplace=True):
        if line == '// FLAG: INCLUDE EQUATION END\n':
            print('#include "param/solutions/{}/parameters.h"\n'.format(name), end='')

        elif line == '\t\t// FLAG: STATE INDEX STATIC EQUATION END\n':
            print('\t\t_{Name}::tParameters::StateIndex = stateIndex;\n'.format(Name=upper_camel_name), end='')
            print('\t\tstateIndex += _{Name}::tVariable::Size;\n'.format(Name=upper_camel_name), end='')

        elif line == '\t\t// FLAG: INIT STATIC EQUATION END\n':
            print('\t\t_{Name}::tParameters::init(pStateArray[0] + _{Name}::tParameters::StateIndex);\n'.format(Name=upper_camel_name), end='')

        elif line == '\t\t// FLAG: PREPARE STATIC EQUATION END\n':
            print('\t\t_{Name}::prepare(pStateArray[0] + _{Name}::tParameters::StateIndex, _{Name}::tVariable::Size, t);\n'.format(Name=upper_camel_name), end='')

        elif line == '\t\t// FLAG: STATE TEMPORAL DERIVATIVE STATIC EQUATION END\n':
            print('\t\ttView<tStateVectorDynamic>(output[0].data() + _{Name}::tParameters::StateIndex, _{Name}::tVariable::Size) = _{Name}::stateTemporalDerivative(pStateArray, pStateSize, arraySize, t);\n'.format(Name=upper_camel_name), end='')
        elif line == '\t\t// FLAG: CONSTRAIN STATIC EQUATION END\n':
            print('\t\t_{Name}::tVariable::constrain(stateArray, t, _{Name}::tParameters::StateIndex);\n'.format(Name=upper_camel_name), end='')

        elif line == '\t\t// FLAG: SAVE STATIC EQUATION END\n':
            print('\t\ts0ve::saveDouble(folder + "/" + _{Name}::tParameters::name + ".txt", pStateArray[0] + _{Name}::tParameters::StateIndex, _{Name}::tVariable::Size);\n'.format(Name=upper_camel_name), end='')

        elif line == '\t\t// FLAG: LOAD STATIC EQUATION END\n':
            print('\t\tl0ad::ascii::loadDouble(folder + "/" + _{Name}::tParameters::name + ".txt", stateArray[0].data() + _{Name}::tParameters::StateIndex, _{Name}::tVariable::Size);\n'.format(Name=upper_camel_name), end='')

        elif line == '\t\t// FLAG: POST STATIC EQUATION END\n':
            print('\t\ts0ve::saveMapToCsvDouble(folder + "/" + _{Name}::tParameters::name + ".csv", _{Name}::tParameters::post(pStateArray[0] + _{Name}::tParameters::StateIndex, t), ",", "#");\n'.format(Name=upper_camel_name), end='')
        previous_line = line
        print(line, end='')

def edit_add_equation_dynamic(name):
    upper_camel_name = object_to_upper_camel_case([name])
    ## add equation to param/solutions/parameters.h
    previous_line = ''
    for line in fileinput.FileInput("parameters.h", inplace=True):
        if line == '// FLAG: INCLUDE EQUATION END\n':
            print('#include "param/solutions/{}/parameters.h"\n'.format(name), end='')

        elif line == '\t\t// FLAG: STATE INDEX DYNAMIC EQUATION END\n':
            print('\t\t_{Name}::tParameters::StateIndex = stateIndex;\n'.format(Name=upper_camel_name), end='')
            print('\t\tstateIndex = _{Name}::tParameters::StateIndex + 1;\n'.format(Name=upper_camel_name), end='')

        elif line == '\t\t// FLAG: INIT DYNAMIC EQUATION END\n':
            print('\t\tstateArray[_{Name}::tParameters::StateIndex].resize(_{Name}::tVariable::MinSize);\n'.format(Name=upper_camel_name), end='')
            print('\t\t_{Name}::tParameters::init(stateArray[_{Name}::tParameters::StateIndex]);\n'.format(Name=upper_camel_name), end='')

        elif line == '\t\t// FLAG: PREPARE DYNAMIC EQUATION END\n':
            print('\t\t_{Name}::prepare(pStateArray[_{Name}::tParameters::StateIndex], pStateSize[_{Name}::tParameters::StateIndex], t);\n'.format(Name=upper_camel_name), end='')
        
        elif line == '\t\t// FLAG: STATE TEMPORAL DERIVATIVE DYNAMIC EQUATION END\n':
            print('\t\ttView<tStateVectorDynamic>(output[_{Name}::tParameters::StateIndex].data(), output[_{Name}::tParameters::StateIndex].size()) = _{Name}::stateTemporalDerivative(pStateArray, pStateSize, arraySize, t, _{Name}::tParameters::StateIndex);\n'.format(Name=upper_camel_name), end='')
        elif line == '\t\t// FLAG: CONSTRAIN DYNAMIC EQUATION END\n':
            print('\t\t_{Name}::tVariable::constrain(stateArray, t, _{Name}::tParameters::StateIndex);\n'.format(Name=upper_camel_name), end='')

        elif line == '\t\t// FLAG: SAVE DYNAMIC EQUATION END\n':
            print('\t\tif (pStateSize[_{Name}::tParameters::StateIndex] > 0) {{\n'.format(Name=upper_camel_name), end='')
            print('\t\t\ts0ve::saveDouble(folder + "/" + _{Name}::tParameters::name + ".txt", pStateArray[_{Name}::tParameters::StateIndex], pStateSize[_{Name}::tParameters::StateIndex]);\n'.format(Name=upper_camel_name), end='')
            print('\t\t}} // _{Name}::Flag\n'.format(Name=upper_camel_name), end='')
        elif line == '\t\t// FLAG: LOAD DYNAMIC EQUATION END\n':
            print('\t\tif(std::filesystem::exists(folder + "/" + _{Name}::tParameters::name + ".txt")) {{\n'.format(Name=upper_camel_name), end='')
            print('\t\t\tl0ad::ascii::loadVectorDouble(folder + "/" + _{Name}::tParameters::name + ".txt", stateArray[_{Name}::tParameters::StateIndex]);\n'.format(Name=upper_camel_name), end='')
            print('\t\t}} // _{Name}::Flag\n'.format(Name=upper_camel_name), end='')
        elif line == '\t\t// FLAG: POST DYNAMIC EQUATION END\n':
            print('\t\ts0ve::saveMapToCsvDouble(folder + "/" + _{Name}::tParameters::name + ".csv", _{Name}::tParameters::post(pStateArray[_{Name}::tParameters::StateIndex], pStateSize[_{Name}::tParameters::StateIndex], t), ",", "#");\n'.format(Name=upper_camel_name), end='')
        previous_line = line
        print(line, end='')

def edit_choice(choice, default_obj, obj, size = 1):
    obj = obj[0:len(obj) - len(default_obj) + size]
    default_obj = default_obj[0:size]
    # h
    find_replace(choice, "*.h", "".join(default_obj) + "_", "".join(obj) + "_")
    find_replace(choice, "*.h", "_" + "".join(default_obj), "_" + "".join(obj))
    find_replace(choice, "*.h", '"' + "".join(default_obj), '"' + "".join(obj))
    find_replace(choice, "*.h", "_" + object_to_upper_snake_case(default_obj) + "_", "_" + object_to_upper_snake_case(obj) + "_")
    find_replace(choice, "*.h", "/" + object_to_path(default_obj) + "/", "/" + object_to_path(obj) + "/", lambda line : line.startswith('#include "param'))
    find_replace(choice, "*.h", "_" + object_to_upper_camel_case(default_obj), "_" + object_to_upper_camel_case(obj))
    # py
    find_replace(choice, "*.py", "".join(default_obj) + "_", "".join(obj) + "_")
    # pyx
    find_replace(choice, "*.pyx", "".join(default_obj) + "_", "".join(obj) + "_")

# choose file

def get_choices_file(choices_dir, choices_exceptions = []):
    abs_choices_dir = get_abs_choices_dir(choices_dir)
    _choices = [os.path.basename(path) for path in glob.glob("{abs_choices_dir}/__*.h".format(abs_choices_dir=abs_choices_dir))]
    # build choices dict
    choices = {}
    for choice in _choices:
        if choice.startswith('__'):
            choices[choice[2:].split(".")[0]] = choice
        elif not choice.startswith('_'):
            choices[choice.split(".")[0]] = choice
    # remove exceptions
    for exception in choices_exceptions:
        choices.pop(exception, None)
    # reurn
    return choices

def apply_choice(args):
    choices = get_choices_file(choices_dir, choices_exceptions)
    shutil.copyfile(get_abs_choices_dir(choices_dir) + "/" + choices[args.choice], "parameters.h")

    name = os.path.basename(os.getcwd())

    if os.path.exists("parameters.py"):
        os.remove("parameters.py")
    if os.path.exists("parameters_" + name + ".pyx"):
        os.remove("parameters_" + name + ".pyx")
    if os.path.lexists("c0p.pxd"):
        os.unlink("c0p.pxd")
    if os.path.lexists("std.pxd"):
        os.unlink("std.pxd")
    if os.path.exists("parameters_" + name + ".h"):
        os.remove("parameters_" + name + ".h")
    if os.path.exists("parameters_" + name + ".cpp"):
        os.remove("parameters_" + name + ".cpp")

    if args.choice.startswith("pyx"):
        shutil.copyfile(get_abs_choices_dir(choices_dir) + "/" + choices[args.choice].replace(".h", ".pyx"), "parameters_" + name + ".pyx")
        # links
        cython_dir = os.path.dirname(os.path.realpath(__file__)).split("interface")[0] + "interface/cython/"
        os.symlink(os.path.relpath(cython_dir + "c0p.pxd", "."), "c0p.pxd")
        os.symlink(os.path.relpath(cython_dir + "std.pxd", "."), "std.pxd")
    elif args.choice.startswith("py"):
        shutil.copyfile(get_abs_choices_dir(choices_dir) + "/" + choices[args.choice].replace(".h", ".py"), "parameters.py")

    # edit
    if not name == "flow":
        edit_file(".", ["passive_particles"], [name])
        # register
        is_static = True
        is_dynamic = False
        with open("parameters.h", 'r') as file:
            for line in file:
                if line.startswith("// FLAG: DYNAMIC"):
                    is_static = False
                    is_dynamic = True
                    break
                elif line.startswith("namespace c0p {"):
                    break
        # move
        os.chdir("..")
        # remove
        upper_camel_name = object_to_upper_camel_case([name])
        for line in fileinput.FileInput("parameters.h", inplace=True):
            if (line == '#include "param/solutions/{}/parameters.h"\n'.format(name)):
                pass
            elif ('_{Name}::'.format(Name=upper_camel_name) in line):
                pass
            else:
                print(line, end='')
        # add again
        if is_static:
            edit_add_equation_static(name)
        elif is_dynamic:
            edit_add_equation_dynamic(name)
        # move back
        os.chdir(name)
    

@Cli2Gui(run_function=apply_choice)
def choose_file(choices_dir, choices_exceptions, edit=True):
    # get choices
    choices = list(get_choices_file(choices_dir, choices_exceptions).keys())
    choices.sort()
    # parser
    parser = argparse.ArgumentParser(description='Select parameters of the simulation among a selction of default parameters.')
    parser.add_argument('choice', choices=choices, help='default parameter selection')
    args = parser.parse_args()
    # apply choice
    apply_choice(args)

def edit_file(directory, default_obj, obj, size = 1):
    obj = obj[0:len(obj) - len(default_obj) + size]
    default_obj = default_obj[0:size]

    print("default: ", default_obj, "new: ", obj)
    # h
    find_replace(directory, "*.h", "".join(default_obj) + "_", "".join(obj) + "_")
    find_replace(directory, "*.h", "_" + "".join(default_obj), "_" + "".join(obj))
    find_replace(directory, "*.h", '"' + "".join(default_obj), '"' + "".join(obj))
    find_replace(directory, "*.h", "_" + object_to_upper_snake_case(default_obj) + "_", "_" + object_to_upper_snake_case(obj) + "_")
    find_replace(directory, "*.h", "/" + object_to_path(default_obj) + "/", "/" + object_to_path(obj) + "/", lambda line : line.startswith('#include "param'))
    find_replace(directory, "*.h", "_" + object_to_upper_camel_case(default_obj), "_" + object_to_upper_camel_case(obj))
    # py
    find_replace(directory, "*.py", "".join(default_obj) + "_", "".join(obj) + "_")
    # pyx
    find_replace(directory, "*.pyx", "".join(default_obj) + "_", "".join(obj) + "_")
