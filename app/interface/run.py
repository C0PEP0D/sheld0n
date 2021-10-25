#!/usr/bin/env python3

# Command line program
import argparse
# Directory operations
import os
# File edit
import subprocess


def parse():
    parser = argparse.ArgumentParser(description='Run the simulation')
    parser.add_argument('-d', '--debug', action='store_true', help='activates debug')
    parser.add_argument('-c', '--compiler', default='', help='specify the compiler used')
    parser.add_argument('-m', '--cmake-cmd', default='cmake', help='specify the cmake command')
    parser.add_argument('-t', '--tbb-dir', default='', help='specify the path to the TBB directory')
    return parser.parse_args()

def main():
    args = parse()
    # create build dir
    if not os.path.exists('build'):
        os.makedirs('build')
    # build flags
    flags = "-DCMAKE_BUILD_TYPE=Release"
    if args.debug:
        flags = "-DCMAKE_BUILD_TYPE=Debug"
    if args.compiler:
        flags += " -DCMAKE_CXX_COMPILER={compiler}".format(compiler=args.compiler)
    if args.tbb_dir:
        flags += " -DTBB_DIR={tbb_dir}".format(tbb_dir=args.tbb_dir)
    # configure
    subprocess.run("{cmake_cmd} .. {flags}; exit 0".format(cmake_cmd=args.cmake_cmd, flags=flags), cwd="build", shell=True)
    # build
    subprocess.run("{cmake_cmd} --build . --parallel --target run; exit 0".format(cmake_cmd=args.cmake_cmd), cwd="build", shell=True)
    # run
    subprocess.run("./build/run", shell=True)

if __name__ == '__main__':
    main()
