#!/usr/bin/env python3

# gui
from cli2gui import Cli2Gui
# command line program
import argparse
# directory operations
import os
import glob
# file edit
import subprocess

def run(args):
    # cython
    sources = glob.glob('param/solutions/**/parameters_*.pyx')
    if sources:
        subprocess.run("cython -tv --cplus {sources}; exit 0".format(sources=" ".join(sources)), shell=True, check=True)
    # create build dir
    if not os.path.exists('build'):
        os.makedirs('build')
    # build flags
    flags = "-DCMAKE_BUILD_TYPE=Release"
    if args.debug:
        flags = "-DCMAKE_BUILD_TYPE=Debug"
    if args.compiler:
        flags += " -DCMAKE_CXX_COMPILER={}".format(args.compiler)
    # configure
    subprocess.run("{cmake_cmd} .. {flags}".format(cmake_cmd=args.cmake_cmd, flags=flags), cwd="build", shell=True, check=True)
    # build
    subprocess.run("{cmake_cmd} --build . -j {jobs} --target post".format(cmake_cmd=args.cmake_cmd, jobs=args.jobs), cwd="build", shell=True, check=True)
    # run
    subprocess.run("./build/post", shell=True)

@Cli2Gui(run_function=run)
def main():
    parser = argparse.ArgumentParser(description='Run the simulation')
    parser.add_argument('-d', '--debug', action='store_true', help='activates debug')
    parser.add_argument('-c', '--compiler', default='', help='specify the compiler used')
    parser.add_argument('-m', '--cmake-cmd', default='cmake', help='specify the cmake command')
    parser.add_argument('-j', '--jobs', type=int, default=1, help='specify the number a compiling jobs')
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
