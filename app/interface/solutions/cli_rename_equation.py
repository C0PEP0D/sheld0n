#!/usr/bin/env python3

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
    cmd = "./.cli_copy_equation {source} {name}".format(source=source, name=name)
    print("INFO: running " + cmd)
    subprocess.call(shlex.split(cmd))
    cmd = "./.cli_remove_equation {source}".format(source=source)
    print("INFO: running " + cmd)
    subprocess.call(shlex.split(cmd))

def run(args):
    compute(args.source, args.name)

def main():
    parser = argparse.ArgumentParser(description='rename an equation')
    parser.add_argument('source', choices=[equation for equation in os.listdir(".") if os.path.isdir(equation)], help='specify the name of the equation')
    parser.add_argument('name', help='specify the new name of the equation')
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
