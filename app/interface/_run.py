#!/usr/bin/env python3
import sys
import os

def main():

    script_path = __file__
    script_dir = os.path.dirname(script_path)
    script_name = os.path.basename(script_path)

    cases_dir = script_dir + "/.."

    if os.path.exists(cases_dir + "/switch_to_cli"):
        interface = "gui"
    else:
        interface = "cli"

    os.chdir(script_dir)
    if os.path.exists(cases_dir + "/../../bin/activate"):
        os.system("bash -c 'source {cases_dir}/../../bin/activate && ./.{interface}_run {argv}'".format(cases_dir=cases_dir, interface=interface, argv=" ".join(sys.argv[1:])))
    else:
        print("WARNING: Can't find the standard sheld0n virtual environment. Trying to execute anyway.")
        os.system("./.{interface}_run {argv}".format(interface=interface, argv=" ".join(sys.argv[1:])))

if __name__ == '__main__':
    main()
