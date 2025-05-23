#!/usr/bin/env python3

# gui
from cli2gui import Cli2Gui
# cli
import argparse
import numpy as np
import shlex
import subprocess
import glob
import fileinput
import re
import os

def compute(source, name):
    cmd = "./._copy_equation {source} {name}".format(source=source, name=name)
    print("INFO: running " + cmd)
    subprocess.call(shlex.split(cmd))
    cmd = "./._remove_equation {source}".format(source=source)
    print("INFO: running " + cmd)
    subprocess.call(shlex.split(cmd))

def run(args):
    compute(args.source, args.name)

@Cli2Gui(run_function=run)
def main():
    parser = argparse.ArgumentParser(description='rename an equation')
    parser.add_argument('source', choices=[equation for equation in os.listdir(".") if os.path.isdir(equation)], help='specify the name of the equation')
    parser.add_argument('name', help='specify the new name of the equation')
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
