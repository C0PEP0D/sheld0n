#!/usr/bin/env python3

# command line program
import argparse
# directory operations
import os
import glob
# file edit
import subprocess
# platform
import platform
import re

def run(args):
    # cython
    sources = glob.glob('param/**/parameters_*.pyx') + glob.glob('param/solutions/**/parameters_*.pyx')
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
            if platform.system() == 'Darwin':
                flags += ' -DCMAKE_C_FLAGS="--sysroot=$(xcrun --show-sdk-path)"'
                flags += ' -DCMAKE_CXX_FLAGS="--sysroot=$(xcrun --show-sdk-path)"'
        elif "g++" in args.compiler:
            flags += " -DCMAKE_CXX_COMPILER={compiler}".format(compiler=args.compiler)
            flags += " -DCMAKE_C_COMPILER={compiler}".format(compiler=args.compiler.replace("g++", "gcc"))
            if platform.system() == 'Darwin':
                flags += ' -DCMAKE_C_FLAGS="--sysroot=$(xcrun --show-sdk-path)"'
                flags += ' -DCMAKE_CXX_FLAGS="--sysroot=$(xcrun --show-sdk-path)"'
        else:
            flags += " -DCMAKE_CXX_COMPILER={compiler}".format(compiler=args.compiler)
    flags += " -DCMAKE_POLICY_VERSION_MINIMUM=3.5"
    # configure
    subprocess.run("{cmake_cmd} .. {flags}".format(cmake_cmd=args.cmake_cmd, flags=flags), cwd="build", shell=True, check=True)
    # build
    subprocess.run("{cmake_cmd} --build . -j {jobs} --target post".format(cmake_cmd=args.cmake_cmd, jobs=args.jobs), cwd="build", shell=True, check=True)
    # run
    subprocess.run("./build/post", shell=True, check=True)

def main():
    parser = argparse.ArgumentParser(description='Run the post processing')
    parser.add_argument('-d', '--debug', action='store_true', help='activates debug')
    # define default compiler on MacOS
    if platform.system() == 'Darwin':
        # Run brew list` to get all installed packages
        result = subprocess.run(["brew", "list"], capture_output=True, text=True, check=True)
        lines = result.stdout.splitlines()
        # find gcc versions
        versions = []
        for line in lines:
            if line == "gcc":
                # unversioned gcc is usually the latest
                versions.append(float("inf"))
            match = re.fullmatch(r"gcc@(\d+)", line)
            if match:
                versions.append(int(match.group(1)))
        if versions:
            # Pick latest
            if float("inf") in versions:
                parser.add_argument('-c', '--compiler', default='g++', help='specify a custom compiler to be used')
            else:
                latest = max(versions)
                parser.add_argument('-c', '--compiler', default=f"g++-{latest}", help='specify a custom compiler to be used')
        else:
            print("WARNING : No version of GCC found using homebrew. Consider installing one if it does not compile.")
            parser.add_argument('-c', '--compiler', default='', help='specify a custom compiler to be used')
    else:
        parser.add_argument('-c', '--compiler', default='', help='specify a custom compiler to be used')
    # end of definition of default compiler
    parser.add_argument('-m', '--cmake-cmd', default='cmake', help='specify the cmake command')
    parser.add_argument('-j', '--jobs', type=int, default=1, help='specify the number a compiling jobs')
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
