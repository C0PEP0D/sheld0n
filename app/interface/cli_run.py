#!/usr/bin/env python3

# command line program
import argparse
# directory operations
import os
import glob
# process
import subprocess

def run(args):
    # cython
    sources = glob.glob('param/**/parameters_*.pyx') + glob.glob('param/solutions/**/parameters_*.pyx')
    print(sources)
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
        if "gcc" in args.compiler:
            flags += " -DCMAKE_C_COMPILER={compiler}".format(compiler=args.compiler)
            flags += " -DCMAKE_CXX_COMPILER={compiler}".format(compiler=args.compiler.replace("gcc", "g++"))
        elif "g++" in args.compiler:
            flags += " -DCMAKE_CXX_COMPILER={compiler}".format(compiler=args.compiler)
            flags += " -DCMAKE_C_COMPILER={compiler}".format(compiler=args.compiler.replace("g++", "gcc"))
            print(flags)
        else:
            flags += " -DCMAKE_CXX_COMPILER={compiler}".format(compiler=args.compiler)
    flags += " -DCMAKE_POLICY_VERSION_MINIMUM=3.5"
    # configure
    subprocess.run("{cmake_cmd} .. {flags}; exit 0".format(cmake_cmd=args.cmake_cmd, flags=flags), cwd="build", shell=True, check=True)
    # build
    subprocess.run("{cmake_cmd} --build . -j {jobs} --target run; exit 0".format(cmake_cmd=args.cmake_cmd, jobs=args.jobs), cwd="build", shell=True, check=True)
    # run
    subprocess.run("./build/run", shell=True, check=True)

def main():
    parser = argparse.ArgumentParser(description='Run the simulation')
    parser.add_argument('-d', '--debug', action='store_true', help='activates debug')
    parser.add_argument('-c', '--compiler', default='', help='specify a custom compiler to be used')
    parser.add_argument('-m', '--cmake-cmd', default='cmake', help='specify a custom cmake command to be used')
    parser.add_argument('-j', '--jobs', type=int, default=1, help='specify the number of threads used for compilation')
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
