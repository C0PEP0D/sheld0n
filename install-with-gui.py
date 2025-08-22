#!/usr/bin/env python3

# command line program
import argparse
# directory operations
import os
import glob
# process
import subprocess

def run(args):
    # update submodules
    subprocess.run("git submodule update --init --recursive modules", cwd=".", shell=True, check=True)
    subprocess.run("git submodule update --init --recursive thirdparty/eigen", cwd=".", shell=True, check=True)
    subprocess.run("git submodule update --init thirdparty/rl-tools", cwd=".", shell=True, check=True)
    # install python requirements
    ## interface
    subprocess.run("python -m pip install cython", cwd=".", shell=True, check=True)
    subprocess.run("python -m pip install gooey", cwd=".", shell=True, check=True)
    ## post processing
    subprocess.run("python -m pip install numpy", cwd=".", shell=True, check=True)
    subprocess.run("python -m pip install matplotlib", cwd=".", shell=True, check=True)
    ## compiling
    subprocess.run("python -m pip install tbb-devel", cwd=".", shell=True, check=True)
    # switch to gui
    if os.path.exists("cases/._switch_to_gui"):
        os.rename("cases/._switch_to_gui", "cases/switch_to_gui")
    if os.path.exists("cases/switch_to_gui"):
        os.chdir('cases')
        os.system('./switch_to_gui')
        os.chdir('..')
    
def main():
    parser = argparse.ArgumentParser(description='Install dependencies.')
    args = parser.parse_args()
    # run
    run(args)

if __name__ == '__main__':
    main()
